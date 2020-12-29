#include <iostream>
#include <string>

using namespace std;

string coms[200] = { "CREATE TABLE","DROP TABLE","DISPLAY TABLE", "INSERT INTO", "DELETE FROM", "SELECT", "UPDATE"};

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
		cout << "-FUNCTIE CREARE TABEL: " << tName;
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
	tName = p.substr(0, p.find(' '));
	cout << "-Functie Drop Table: " << tName;
}

void DisplayTable(string p)
{
	string tName;
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

	tName = p.substr(0, p.find(' '));
	aux = p.substr(tName.length() + 1);
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
	cout << 4;
}

void Select(string p)
{
	cout << 5;
}

void Update(string p)
{
	cout << 6;
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
