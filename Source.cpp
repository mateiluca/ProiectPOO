#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Classes.h"

using namespace std;

string coms[200] = { "CREATE TABLE","DROP TABLE","DISPLAY TABLE", "INSERT INTO", "DELETE FROM", "SELECT", "UPDATE", "EXIT"};
vector<table> t;
bool toExit = false;
ofstream outFile;



string DeleteWSpace(string a)
{
	while (a[0] == ' ')
	{
		a = a.substr(1);
	}
	return a;
}

void CreateTable(string p, string auc)
{
	vector<string> mem;
	string aux, tName;
	size_t in;
	int nPar = 0, wLen = 0, nr = 0;
	//     Open ( || Close ) || Word || Next , || End ; 
	bool toO, toC, toW, isW, toN, toEnd;
	if (p.find(' ') == NULL)
	{
		if (p.find('(') == NULL)
		{
			cout << "Parametrii nu au fost introdusi bine" << endl;
			return;
		}
		else
		{
			tName = p.substr(0, p.find('('));
		}
	}
	else
	{
		tName = p.substr(0, p.find(' '));
	}
	aux = p.substr(tName.length());
	
	toW = false;
	isW = false;
	toO = true;
	toC = false;
	toN = false;
	toEnd = false;
	for (int i = 0; i < aux.length(); i++)
	{
		bool enter = false;
		if (nPar > 4)
		{
			cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
		}

		if (aux[i] == ' ')
		{
			enter = true;
			if (isW == true)
			{
				isW = false;
				mem.insert(mem.begin() + nr, aux.substr(in, wLen));
				wLen = 0;
				nPar++;
				nr++;
				if (nPar < 4)
				{
					toN = true;
				}
				else
				{
					toC = true;
				}
			}
		}

		if (aux[i] == ',')
		{
			enter = true;
			if (toN)
			{
				toN = false;
				toW = true;
			}
			else if (isW)
			{
				isW = false;
				mem.insert(mem.begin() + nr, aux.substr(in, wLen));
				wLen = 0;
				nPar++;
				nr++;
				if (nPar < 4)
				{
					toW = true;
				}
				else
				{
					cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
				}
			}
			else
			{
				cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
			}
		}

		if (aux[i] == '(')
		{
			enter = true;
			if (toO == true)
			{
				toO = false;
				toW = true;
				toEnd = false;
			}
			else
			{
				cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
			}
		}

		if (aux[i] == ')')
		{
			enter = true;
			if (toC == true)
			{
				toC = false;
				toO = true;
				toEnd = true;
			}
			else if (isW)
			{
				isW = false;
				mem.insert(mem.begin() + nr, aux.substr(in, wLen));
				wLen = 0;
				nPar++;
				nr++;
				if (nPar == 4)
				{
					nPar = 0;
					toEnd = true;
					toO = true;
				}
				else
				{
					cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
				}
			}
			else
			{
				cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
			}
		}

		if (enter == false && (toW || isW))
		{
			if (toW)
			{
				in = i;
			}
			toW = false;
			isW = true;
			wLen++;
		}
	
	}

	if (toEnd)
	{
		bool ex = false;
		for (int i = 0; i < t.size(); i++)
		{
			if (t[i].numeTabel == tName)
			{
				cout << "Tabelul deja exista";
				ex = true;
			}
		}
		if (ex == false)
		{
			outFile << auc + "\n";
			table auxT(tName, mem);
			t.insert(t.begin() + t.size(), auxT);
		}
	}
	else
	{
		cout << "nu nu";
	}

}

void DropTable(string p, string auc)
{
	string tName;
	int pos;
	p = DeleteWSpace(p);
	tName = p.substr(0, p.find(' '));
	bool ex = false;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].numeTabel == tName)
		{
			ex = true;
			pos = i;
		}
	}

	if (ex == true)
	{
		outFile << auc;
		t.erase(t.begin() + pos);
	}
	else
	{
		cout << "Tabelul nu exista";
	}
}

void DisplayTable(string p)
{
	string tName;
	int pos;
	p = DeleteWSpace(p);
	tName = p.substr(0, p.find(' '));
	bool ex = false;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].numeTabel == tName)
		{
			ex = true;
			pos = i;
		}
	}

	if (ex == true)
	{
		t[pos].Display();
	}
	else
	{
		cout << "Tabelul nu exista";
	}
}

void InsertInto(string p, string auc)
{
	vector<string> mem;
	string aux, tName;
	size_t in;
	int nPar = 0, wLen = 0, nr = 0, pr;
	//     Open ( || Close ) || Word || Next , || End ; 
	bool toO, toC, toW, isW, toN, toEnd;

	p = DeleteWSpace(p);
	tName = p.substr(0, p.find(' '));
	aux = p.substr(tName.length() + 1);
	aux = DeleteWSpace(aux);

	if (aux.find("VALUES", 0) != 0)
	{
		cout << "Parametrii nu au fost introdusi corect";
		return;
	}
	aux = aux.substr(aux.rfind("VALUES", 0) + 6);

	toW = false;
	isW = false;
	toO = true;
	toC = false;
	toN = false;
	toEnd = false;
	for (int i = 0; i < aux.length(); i++)
	{
		bool enter = false;

		if (aux[i] == ' ')
		{
			enter = true;
			if (isW == true)
			{
				isW = false;
				mem.insert(mem.begin() + nr, aux.substr(in, wLen));
				wLen = 0;
				nPar++;
				nr++;
				toN = true;
				toC = true;
			}
		}

		if (aux[i] == ',')
		{
			enter = true;
			if (toN)
			{
				toN = false;
				toC = false;
				toW = true;
			}
			else if (isW)
			{
				isW = false;
				mem.insert(mem.begin() + nr, aux.substr(in, wLen));
				wLen = 0;
				nPar++;
				nr++;
				toW = true;
			}
			else
			{
				cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
			}
		}

		if (aux[i] == '(')
		{
			enter = true;
			if (toO == true)
			{
				toO = false;
				toW = true;
				toEnd = false;
			}
			else
			{
				cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
			}
		}

		if (aux[i] == ')')
		{
			enter = true;
			if (toC == true)
			{
				toC = false;
				toEnd = true;
			}
			else if (isW)
			{
				isW = false;
				mem.insert(mem.begin() + nr, aux.substr(in, wLen));
				wLen = 0;
				nPar++;
				nr++;
				toEnd = true;
			}
			else
			{
				cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
			}
		}

		if (enter == false && (toW || isW))
		{
			if (toW)
			{
				in = i;
			}
			toW = false;
			isW = true;
			wLen++;
		}

	}

	if (toEnd)
	{
		bool ex = false;
		int pos;
		for (int i = 0; i < t.size(); i++)
		{
			if (t[i].numeTabel == tName)
			{
				ex = true;
				pos = i;
			}
		}
		if (ex != false)
		{
			if (mem.size() == (t[pos].cNr.size() + t[pos].cTxt.size() + t[pos].cFloat.size()))
			{
				outFile << auc;
				t[pos].AddLine(mem);
			}
			else
			{
				cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
			}
		}
		else
		{
			cout << "Tabela nu exista";
		}
	}
	else
	{
		cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
	}


}

void DeleteFrom(string p, string auc)
{
	string aux, tName, cName, val;

	p = DeleteWSpace(p);
	tName = p.substr(0, p.find(' '));
	aux = p.substr(tName.length() + 1);
	aux = DeleteWSpace(aux);

	if (aux.find("WHERE", 0) != 0)
	{
		cout << "Parametrii nu au fost introdusi corect";
		return;
	}
	aux = aux.substr(aux.rfind("WHERE", 0) + 5);
	aux = DeleteWSpace(aux);

	cName = aux.substr(0, aux.find(' '));

	aux = aux.substr(cName.length());
	aux = DeleteWSpace(aux);

	if (aux[0] != '=')
	{
		cout << "Parametrii nu au fost introdusi corect";
		return;
	}
	aux = aux.substr(1);
	aux = DeleteWSpace(aux);

	val = aux.substr(0, aux.find(' '));

	bool ex = false;
	int pos;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].numeTabel == tName)
		{
			ex = true;
			pos = i;
		}
	}

	if (ex == true)
	{
		bool done = false;
		for (int i = 0; i < t[pos].cFloat.size(); i++)
		{
			if (t[pos].cFloat[i].numeCol == cName)
			{
				done = true;
				t[pos].cFloat.erase(t[pos].cFloat.begin() + i);
				t[pos].cFloat[i].dim--;
			}
		}
		if (!done)
		{
			for (int i = 0; i < t[pos].cNr.size(); i++)
			{
				if (t[pos].cNr[i].numeCol == cName)
				{
					done = true;
					t[pos].cNr.erase(t[pos].cNr.begin() + i);
					t[pos].cNr[i].dim--;
				}
			}
		}
		if (!done)
		{
			for (int i = 0; i < t[pos].cTxt.size(); i++)
			{
				if (t[pos].cTxt[i].numeCol == cName)
				{
					done = true;
					t[pos].cTxt.erase(t[pos].cTxt.begin() + i);
					t[pos].cTxt[i].dim--;
				}
			}
		}
		outFile << auc;
	}
	else
	{
		cout << "Tabelul nu exista";
	}

}

void Select(string p)
{
	vector<string> col;
	string aux, tName;
	int nCol = 0, pos;

	p = DeleteWSpace(p);
	if (p.rfind("ALL FROM", 0) == 0)
	{
		aux = p.substr(8);
		aux = DeleteWSpace(aux);

		if (aux.length() == 0)
		{
			cout << "Nu exista nume";
			return;
		}
		tName = aux.substr(0, aux.find(' '));

		bool ex = false;
		for (int i = 0; i < t.size(); i++)
		{
			if (t[i].numeTabel == tName)
			{
				ex = true;
				pos = i;
			}
		}

		if (ex == true)
		{
			t[pos].Display();
		}
		else
		{
			cout << "Tabelul nu exista";
		}
	}
	else
	{
		if (p.find("FROM") == string::npos || p.find("FROM") == 0)
		{
			cout << "FUNCTIA NU A FOST INTRODUSA BINE";
			return;
		}
		else
		{
			aux = p;
			while (aux.rfind("FROM", 0) != 0)
			{
				col.insert(col.begin() + nCol, aux.substr(0, aux.find_first_of(" ,")));
				aux = aux.substr(col[nCol].length() + 1);
				aux = DeleteWSpace(aux);
				nCol++;
			}
			if (aux.length() > 4)
			{
				aux = aux.substr(4);
				aux = DeleteWSpace(aux);

				if (aux.length() == 0)
				{
					cout << "Nu exista nume";
					return;
				}

				tName = aux.substr(0, aux.find(" "));

				bool ex = false;
				for (int i = 0; i < t.size(); i++)
				{
					if (t[i].numeTabel == tName)
					{
						ex = true;
						pos = i;
					}
				}

				if (ex == true)
				{
					for (int j = 0; j < col.size(); j++)
					{
						bool done = false;
						for (int i = 0; i < t[pos].cFloat.size(); i++)
						{
							if (t[pos].cFloat[i].numeCol == col[j])
							{
								done = true;
								t[pos].cFloat[i].Display();
							}
						}
						if (!done)
						{
							for (int i = 0; i < t[pos].cNr.size(); i++)
							{
								if (t[pos].cNr[i].numeCol == col[j])
								{
									done = true;
									t[pos].cNr[i].Display();
								}
							}
						}
						if (!done)
						{
							for (int i = 0; i < t[pos].cTxt.size(); i++)
							{
								if (t[pos].cTxt[i].numeCol == col[j])
								{
									done = true;
									t[pos].cTxt[i].Display();
								}
							}
						}
					}
				}
				else
				{
					cout << "Tabelul nu exista";
				}
			}
			else
			{
				cout << "FUNCTIA NU A FOST INTRODUSA BINE";
			}
		}
	}
}

void Update(string p, string auc)
{
	string aux, tName, cNameM, valM, cNameF, valF;

	p = DeleteWSpace(p);
	tName = p.substr(0, p.find(' '));
	aux = p.substr(tName.length() + 1);
	aux = DeleteWSpace(aux);

	if (aux.find("SET", 0) != 0)
	{
		cout << "Parametrii nu au fost introdusi corect1";
		return;
	}
	aux = aux.substr(3);
	aux = DeleteWSpace(aux);

	cNameM = aux.substr(0, aux.find(' '));

	aux = aux.substr(cNameM.length());
	aux = DeleteWSpace(aux);
	cout << aux << endl;
	if (aux[0] != '=')
	{
		cout << "Parametrii nu au fost introdusi corect2";
		return;
	}
	aux = aux.substr(1);
	aux = DeleteWSpace(aux);
	cout << aux << endl;
	valM = aux.substr(0, aux.find(' '));

	aux = aux.substr(valM.length());
	aux = DeleteWSpace(aux);
	cout << aux << endl;

	
	if (aux.find("WHERE", 0) != 0)
	{
		cout << "Parametrii nu au fost introdusi corect3";
		return;
	}
	aux = aux.substr(5);
	aux = DeleteWSpace(aux);

	cNameF = aux.substr(0, aux.find(' '));

	aux = aux.substr(cNameF.length());
	aux = DeleteWSpace(aux);

	if (aux[0] != '=')
	{
		cout << "Parametrii nu au fost introdusi corect4";
		return;
	}
	aux = aux.substr(1);
	aux = DeleteWSpace(aux);

	if (aux.length() == 0)
	{
		cout << "Parametrii nu au fost introdusi corect5";
		return;
	}

	valF = aux.substr(0, aux.find(' '));

	bool ex = false;
	int pos;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].numeTabel == tName)
		{
			ex = true;
			pos = i;
		}
	}

	if (ex == true)
	{
		bool done = false;
		for (int i = 0; i < t[pos].cFloat.size(); i++)
		{
			if (t[pos].cFloat[i].numeCol == cNameF)
			{
				for (int j = 0; j < t[pos].cFloat[i].val.size(); j++)
				{
					if (t[pos].cFloat[i].val[j] == stof(valF))
					{
						for (int k = 0; k < t[pos].cFloat.size(); k++)
						{
							if (t[pos].cFloat[i].numeCol == cNameM)
							{
								done = true;
								t[pos].cFloat[i].val[j] = stof(valM);
							}
						}
						for (int k = 0; k < t[pos].cNr.size(); k++)
						{
							if (t[pos].cNr[i].numeCol == cNameM)
							{
								done = true;
								t[pos].cNr[i].val[j] = stoi(valM);
							}
						}
						for (int k = 0; k < t[pos].cTxt.size(); k++)
						{
							if (t[pos].cTxt[i].numeCol == cNameM)
							{
								done = true;
								t[pos].cTxt[i].val[j] = valM;
							}
						}
					}
				}
			}
		}
		if (!done)
		{
			for (int i = 0; i < t[pos].cNr.size(); i++)
			{
				if (t[pos].cNr[i].numeCol == cNameF)
				{
					for (int j = 0; j < t[pos].cNr[i].val.size(); j++)
					{
						if (t[pos].cNr[i].val[j] == stoi(valF))
						{
							for (int k = 0; k < t[pos].cFloat.size(); k++)
							{
								if (t[pos].cFloat[i].numeCol == cNameM)
								{
									done = true;
									t[pos].cFloat[i].val[j] = stof(valM);
								}
							}
							for (int k = 0; k < t[pos].cNr.size(); k++)
							{
								if (t[pos].cNr[i].numeCol == cNameM)
								{
									done = true;
									t[pos].cNr[i].val[j] = stoi(valM);
								}
							}
							for (int k = 0; k < t[pos].cTxt.size(); k++)
							{
								if (t[pos].cTxt[i].numeCol == cNameM)
								{
									done = true;
									t[pos].cTxt[i].val[j] = valM;
								}
							}
						}
					}
				}
			}
		}
		if (!done)
		{
			for (int i = 0; i < t[pos].cTxt.size(); i++)
			{
				if (t[pos].cTxt[i].numeCol == cNameF)
				{
					for (int j = 0; j < t[pos].cTxt[i].val.size(); j++)
					{
						if (t[pos].cTxt[i].val[j] == valF)
						{
							for (int k = 0; k < t[pos].cFloat.size(); k++)
							{
								if (t[pos].cFloat[i].numeCol == cNameM)
								{
									done = true;
									t[pos].cFloat[i].val[j] = stof(valM);
								}
							}
							for (int k = 0; k < t[pos].cNr.size(); k++)
							{
								if (t[pos].cNr[i].numeCol == cNameM)
								{
									done = true;
									t[pos].cNr[i].val[j] = stoi(valM);
								}
							}
							for (int k = 0; k < t[pos].cTxt.size(); k++)
							{
								if (t[pos].cTxt[i].numeCol == cNameM)
								{
									done = true;
									t[pos].cTxt[i].val[j] = valM;
								}
							}
						}
					}
				}
			}
		}
		outFile << auc;
	}
}

void Exit()
{
	/*for (int i = 0; i < t.size(); i++)
	{
		t[i].ToFile();
	}*/
	outFile.close();
	toExit = true;
}

void Menu()
{
	string command, par, c;

	int fNr = -1;

	while (fNr == -1)
	{
		getline(cin, command);

		for (int i = 0; i < 8; i++)
		{
			if (command.rfind(coms[i], 0) == 0)
			{
				if (i != 7)
				{
					if (coms[i].size() + 1 >= command.size())
					{
						cout << "Nu exista parametrii";
						break;
					}
					par = command.substr(coms[i].size() + 1);
				}
				fNr = i;
			}
		}

		if (fNr == -1)
		{
			cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
		}
	}

	switch (fNr)
	{
	case 0:
		CreateTable(par, command);
		break;
	case 1:
		DropTable(par, command);
		break;
	case 2:
		DisplayTable(par);
		break;
	case 3:
		InsertInto(par, command);
		break;
	case 4:
		DeleteFrom(par, command);
		break;
	case 5:
		Select(par);
		break;
	case 6:
		Update(par, command);
		break;
	case 7:
		Exit();
		break;
	}
}

int main()
{
	outFile.open("commands.txt", ios_base::app);
	cout << "ALEGETI O COMANDA: CREATE TABLE, DROP TABLE, DISPLAY TABLE, INSERT INTO, DELETE FROM, SELECT, UPDATE, EXIT" << endl;
	while (toExit == false)
	{
		Menu();
	}
}
