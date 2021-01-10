#pragma once
#include <string>
using namespace std;

class table
{
public:
	string numeTabel;
	colNr* col1;
	colTxt* col1;
	colFloat* col1;
};

class colNr
{
public:
	string numeCol;
	int dim;
	float* val;

	colNr(int d, float vImpl)
	{
		if (d > 0)
		{
			dim = d;
			val = new float(d);
			for (int i = 0; i < d; i++)
			{
				val[i] = vImpl;
			}
		}
	}
};

class colTxt
{
public:
	string numeCol;
	int dim;
	string* val;
};

class colFloat
{
public:
	string nCol;
	int dim;
	float* val;
};
