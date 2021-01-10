#include <iostream>
#include <string>
#include "Classes.h"

using namespace std;

string coms[200] = { "CREATE TABLE","DROP TABLE","DISPLAY TABLE", "INSERT INTO", "DELETE FROM", "SELECT", "UPDATE"};

string DeleteWSpace(string a)
{
	while (a[0] == ' ')
	{
		a = a.substr(1);
	}
	return a;
}

void CreateTable(string p)
{
	string* mem = new string[sizeof(string)];
	string aux, tName;
	size_t in;
	int nPar = 0, wLen = 0, nr = 0;
	//     Open ( || Close ) || Word || Next , || End ; 
	bool toO, toC, toW, isW, toN, toEnd;
	if (p.find(' ') == NULL)
	{
		if (p.find('(') == NULL)
		{
			cout << "Parametrii nu au fost introdusi bine";
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
	

	cout << tName << endl;
	toW = false;
	isW = false;
	toO = true;
	toC = false;
	toN = false;
	toEnd = false;
	for (int i = 0; i < aux.length(); i++)
	{
		bool enter = false;
		if (nPar > 3)
		{
			cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
		}

		if (aux[i] == ' ')
		{
			enter = true;
			if (isW == true)
			{
				isW = false;
				mem[nr] = aux.substr(in, wLen);
				wLen = 0;
				nPar++;
				nr++;
				if (nPar < 3)
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
				mem[nr] = aux.substr(in, wLen);
				wLen = 0;
				nPar++;
				nr++;
				if (nPar < 3)
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
				mem[nr] = aux.substr(in, wLen);
				wLen = 0;
				nPar++;
				nr++;
				if (nPar == 3)
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
		cout << "-FUNCTIE CREARE TABEL-";
	}
	else
	{
		cout << "nu nu";
	}

	for (int i = 0; i < nr; i++)
	{
		cout << mem[i] << endl;
	}

}

void DropTable(string p)
{
	string tName;
	p = DeleteWSpace(p);
	tName = p.substr(0, p.find(' '));
	cout << "-Functie Drop Table: " << tName;
}

void DisplayTable(string p)
{
	string tName;
	p = DeleteWSpace(p);
	tName = p.substr(0, p.find(' '));
	cout << "-Functie Display Table: " << tName;
}

void InsertInto(string p)
{
	string* mem = new string[sizeof(string)];
	string aux, tName;
	size_t in;
	int nPar = 0, wLen = 0, nr = 0;
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
		if (nPar > 3)
		{
			cout << "Functia nu a fost introdusa bine, mai incercati o data" << endl;
		}

		if (aux[i] == ' ')
		{
			enter = true;
			if (isW == true)
			{
				isW = false;
				mem[nr] = aux.substr(in, wLen);
				wLen = 0;
				nPar++;
				nr++;
				if (nPar < 3)
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
				mem[nr] = aux.substr(in, wLen);
				wLen = 0;
				nPar++;
				nr++;
				if (nPar < 3)
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
				mem[nr] = aux.substr(in, wLen);
				wLen = 0;
				nPar++;
				nr++;
				if (nPar == 3)
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
		cout << "-FUNCTIE INSERT INTO TABEL-";
	}
	else
	{
		cout << "nu nu";
	}

	for (int i = 0; i < nr; i++)
	{
		cout << mem[i] << endl;
	}

}

void DeleteFrom(string p)
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

	cout << "-FUNCTIE DELETE-";
}

void Select(string p)
{
	string* col = new string[sizeof(string)];
	string aux, tName;
	int nCol = 0;

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

		cout << "FUNCTIE SELECT LA TOT";
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
				col[nCol] = aux.substr(0, aux.find_first_of(" ,"));
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

				cout << "FUNCTIE SELECT DIN " << tName;
			}
			else
			{
				cout << "FUNCTIA NU A FOST INTRODUSA BINE";
			}
		}
	}
}

void Update(string p)
{
	string aux, tName, cNameM, valM, cNameF, valF;

	p = DeleteWSpace(p);
	tName = p.substr(0, p.find(' '));
	aux = p.substr(tName.length() + 1);
	aux = DeleteWSpace(aux);

	if (aux.find("SET", 0) != 0)
	{
		cout << "Parametrii nu au fost introdusi corect";
		return;
	}
	aux = aux.substr(aux.rfind("SET", 0) + 3);
	aux = DeleteWSpace(aux);

	cNameM = aux.substr(0, aux.find(' '));

	aux = aux.substr(cNameM.length());
	aux = DeleteWSpace(aux);

	if (aux[0] != '=')
	{
		cout << "Parametrii nu au fost introdusi corect";
		return;
	}
	aux = aux.substr(1);
	aux = DeleteWSpace(aux);

	valM = aux.substr(0, aux.find(' '));

	aux = p.substr(valM.length());
	aux = DeleteWSpace(aux);

	if (aux.find("WHERE", 0) != 0)
	{
		cout << "Parametrii nu au fost introdusi corect";
		return;
	}
	aux = aux.substr(aux.rfind("WHERE", 0) + 5);
	aux = DeleteWSpace(aux);

	cNameF = aux.substr(0, aux.find(' '));

	aux = aux.substr(cNameF.length());
	aux = DeleteWSpace(aux);

	if (aux[0] != '=')
	{
		cout << "Parametrii nu au fost introdusi corect";
		return;
	}
	aux = aux.substr(1);
	aux = DeleteWSpace(aux);

	if (aux.length() == 0)
	{
		cout << "Parametrii nu au fost introdusi corect";
		return;
	}

	valF = aux.substr(0, aux.find(' '));

	cout << "-FUNCTIE DELETE-";
}

int main()
{
	string command, par;
	
	int fNr = -1;

	while (fNr == -1)
	{
		getline(cin, command);

		for (int i = 0; i < 7; i++)
		{
			if (command.rfind(coms[i], 0) == 0)
			{
				if (coms[i].size() + 1 >= command.size())
				{
					cout << "Nu exista parametrii";
					break;
				}
				par = command.substr(coms[i].size() + 1);
				fNr = i;
				cout << i;
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
			CreateTable(par);
			break;
		case 1:
			DropTable(par);
			break;
		case 2:
			DisplayTable(par);
			break;
		case 3:
			InsertInto(par);
			break;
		case 4:
			DeleteFrom(par);
			break;
		case 5:
			Select(par);
			break;
		case 6:
			Update(par);
			break;
	}
}
