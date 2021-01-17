#pragma once
#include <string>
#include <vector>
#include <fstream>
using namespace std;



class colNr
{
public:
	string numeCol;
	int index;
	int dim;
	vector<int> val;

	colNr(string n, int d, int vImpl, int ind)
	{
		numeCol = n;
		index = ind;
		if (d > 0)
		{
			dim = d;
			for (int i = 0; i < d; i++)
			{
				val.insert(val.begin() + i, vImpl);
			}
		}
	}

	void Display()
	{
		cout << numeCol << ":    ";
		for (int i = 0; i < dim; i++)
		{
			cout << val[i] << "    ";
		}
		cout << endl;
	}
};

class colTxt
{
public:
	string numeCol;
	int index;
	int dim;
	vector<string> val;

	colTxt(string n, int d, string vImpl, int ind)
	{
		numeCol = n;
		index = ind;
		if (d > 0)
		{
			dim = d;
			for (int i = 0; i < d; i++)
			{
				val.insert(val.begin() + i, vImpl);
			}
		}
	}

	void Display()
	{
		cout << numeCol << ":    ";
		for (int i = 0; i < dim; i++)
		{
			cout << val[i] << "    ";
		}
		cout << endl;
	}
};

class colFloat
{
public:
	string numeCol;
	int index;
	int dim;
	vector<float> val;

	colFloat(string n, int d, float vImpl, int ind)
	{
		numeCol = n;
		index = ind;
		if (d > 0)
		{
			dim = d;
			for (int i = 0; i < d; i++)
			{
				val.insert(val.begin() + i, vImpl);
			}
		}
	}

	void Display()
	{
		cout << numeCol << ":    ";
		for (int i = 0; i < dim; i++)
		{
			cout << val[i] << "    ";
		}
		cout << endl;
	}
};

class table
{
public:
	string numeTabel;
	vector<colNr> cNr;
	vector<colTxt> cTxt;
	vector<colFloat> cFloat;



	table()
	{
		numeTabel = "";
	}

	table(string n, vector<string> com)
	{
		numeTabel = n;
		int ind = 0;
		for (int i = 0; i < com.size(); i = i + 4, ind ++)
		{
			if (com[i + 1] == "integer")
			{
				colNr c(com[i], stoi(com[i + 2]), stoi(com[i + 3]), ind);
				cNr.insert(cNr.begin() + cNr.size(), c);
			}
			else if (com[i + 1] == "text")
			{
				colTxt c(com[i], stoi(com[i + 2]), com[i + 3], ind);
				cTxt.insert(cTxt.begin() + cTxt.size(), c);
			}
			else if (com[i + 1] == "float")
			{
				colFloat c(com[i], stoi(com[i + 2]), stof(com[i + 3]), ind);
				cFloat.insert(cFloat.begin() + cFloat.size(), c);
			}
			else
			{
				cout << "Parametrii nu au fost introdusi bine";
			}
		}
	}

	void AddLine(vector<string> com)
	{
		for (int i = 0; i < (cNr.size() + cTxt.size() + cFloat.size()); i++)
		{
			bool found = false;
			for (int j = 0; j < cNr.size() && !found; j++)
			{
				if (cNr[j].index == i)
				{
					found = true;
					cNr[j].val.push_back(stoi(com[i]));
					cNr[j].dim++;
				}
			}
			for (int j = 0; j < cFloat.size() && !found; j++)
			{
				if (cFloat[j].index == i)
				{
					found = true;
					cFloat[j].val.push_back(stof(com[i]));
					cFloat[j].dim++;
				}
			}
			for (int j = 0; j < cTxt.size() && !found; j++)
			{
				if (cTxt[j].index == i)
				{
					found = true;
					cTxt[j].val.push_back(com[i]);
					cTxt[j].dim++;
				}
			}
		}
	}

	void Display()
	{
		cout << numeTabel << endl;
		for (int i = 0; i < (cNr.size() + cTxt.size() + cFloat.size()); i++)
		{
			bool found = false;
			for (int j = 0; j < cNr.size() && !found; j++)
			{
				if (cNr[j].index == i)
				{
					found = true;
					cout << i << ".    " << cNr[j].numeCol << "    ";
					for (int k = 0; k < cNr[j].dim; k++)
					{
						cout << cNr[j].val[k] << "    ";
					}
					cout << endl;
				}
			}
			for (int j = 0; j < cFloat.size() && !found; j++)
			{
				if (cFloat[j].index == i)
				{
					found = true;
					cout << i << ".    " << cFloat[j].numeCol << "    ";
					for (int k = 0; k < cFloat[j].dim; k++)
					{
						cout << cFloat[j].val[k] << "    ";
					}
					cout << endl;
				}
			}
			for (int j = 0; j < cTxt.size() && !found; j++)
			{
				if (cTxt[j].index == i)
				{
					found = true;
					cout << i << ".    " << cTxt[j].numeCol << "    ";
					for (int k = 0; k < cTxt[j].dim; k++)
					{
						cout << cTxt[j].val[k] << "    ";
					}
					cout << endl;
				}
			}
		}
	}
	/*
	void ToFile()
	{
		string numeFis;
		numeFis = numeTabel + ".txt";
		out.open(numeFis, ios::out | ios::trunc);
		for (int i = 0; i < (cNr.size() + cTxt.size() + cFloat.size()); i++)
		{
			bool found = false;
			for (int j = 0; j < cNr.size() && !found; j++)
			{
				if (cNr[j].index == i)
				{
					found = true;
					out << i << ".    " << cNr[j].numeCol << "    ";
					for (int k = 0; k < cNr[j].dim; k++)
					{
						out << cNr[j].val[k] << "    ";
					}
					out << endl;
				}
			}
			for (int j = 0; j < cFloat.size() && !found; j++)
			{
				if (cFloat[j].index == i)
				{
					found = true;
					out << i << ".    " << cFloat[j].numeCol << "    ";
					for (int k = 0; k < cFloat[j].dim; k++)
					{
						out << cFloat[j].val[k] << "    ";
					}
					out << endl;
				}
			}
			for (int j = 0; j < cTxt.size() && !found; j++)
			{
				if (cTxt[j].index == i)
				{
					found = true;
					out << i << ".    " << cTxt[j].numeCol << "    ";
					for (int k = 0; k < cTxt[j].dim; k++)
					{
						out << cTxt[j].val[k] << "    ";
					}
					out << endl;
				}
			}
		}
	}*/
};
