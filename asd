#include <string>
#include <iostream>
#include <fstream>
using namespace std;

enum platforma { Zoom, Skype, Teams, Empty };


class Participanti
{
public:
	string nume;
	int grupa;
	int varsta;
	Participanti()
	{
		nume = "Anonim";
		varsta = 18;
		grupa = 1000;
	}
};

class Videoconferinta
{
private:
	const int idConferinta;
	bool ok = false;
protected:
	char* denumire;
	platforma platfomarUtilizata;
	string oraIncepere; //formatul 00:00
public:
	int data[2]; //zilele lunii
	int nrParticipanti;
	Participanti* participanti;
	static int capacitateMaxima;
	static int numarator;

	Videoconferinta() : idConferinta(numarator++)
	{
		this->data[0] = 1;
		this->data[1] = 1;
		this->denumire = new char[strlen("") + 1];
		strcpy_s(this->denumire, strlen("") + 1, "");
		this->platfomarUtilizata = Empty;
		this->oraIncepere = "Necunoscuta";
		this->nrParticipanti = 1;
		this->participanti = new Participanti[nrParticipanti];
		Participanti p;
		this->participanti[0] = p;
	}
	Videoconferinta(const char* denumire, platforma platformaUtilizata, string oraIncepere, int nrParticipanti, Participanti* participanti, int zi, int luna) :idConferinta(numarator++)
	{
		if (zi > 0 && zi < 31 && luna>0 && luna < 13)
		{
			this->data[0] = zi;
			this->data[1] = luna;
		}
		else
		{
			this->data[0] = 1;
			this->data[1] = 1;
		}
		if (strlen(denumire) > 2)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}
		else
		{
			this->denumire = new char[strlen("") + 1];
			strcpy_s(this->denumire, 2, "");
		}
		if (oraIncepere.size() == 5)
		{
			this->oraIncepere = oraIncepere;
		}
		else
		{
			this->oraIncepere = "Necunoscuta";
		}
		if (nrParticipanti > 0 && participanti != NULL)
		{
			delete[] this->participanti;
			this->nrParticipanti = nrParticipanti;
			this->participanti = new Participanti[nrParticipanti];
			for (int i = 0; i < nrParticipanti; i++)
			{
				this->participanti[i] = participanti[i];
			}

		}

		this->platfomarUtilizata = platfomarUtilizata;
	}

	~Videoconferinta()
	{
		if (this->denumire != NULL)
		{
			delete[] this->denumire;
		}
		if (this->participanti != nullptr)
		{
			delete[] this->participanti;
		}
	}

	Videoconferinta(const Videoconferinta& v) :idConferinta(v.idConferinta)
	{
		if (v.data[0] > 0 && v.data[0] < 31 && data[1]>0 && data[1] < 13)
		{
			this->data[0] = v.data[0];
			this->data[1] = v.data[1];
		}
		else
		{
			this->data[0] = 1;
			this->data[1] = 1;
		}
		if (strlen(v.denumire) > 2)
		{
			this->denumire = new char[strlen(v.denumire) + 1];
			strcpy_s(this->denumire, strlen(v.denumire) + 1, v.denumire);
		}
		else
		{
			this->denumire = new char[strlen("") + 1];
			strcpy_s(this->denumire, 2, "");
		}
		if (v.oraIncepere.size() == 5)
		{
			this->oraIncepere = v.oraIncepere;
		}
		else
		{
			this->oraIncepere = "Necunoscuta";
		}
		if (v.nrParticipanti > 0 && v.participanti != nullptr)
		{
			this->nrParticipanti = v.nrParticipanti;
			this->participanti = new Participanti[v.nrParticipanti];
			for (int i = 0; i < v.nrParticipanti; i++)
			{
				this->participanti[i] = v.participanti[i];
			}
		}
		else
		{
			this->nrParticipanti = 1;
			this->participanti = new Participanti[nrParticipanti];
			Participanti p;
			this->participanti[0] = p;
		}
		this->platfomarUtilizata = v.platfomarUtilizata;
	}

	Videoconferinta& operator= (const Videoconferinta& v)
	{
		if (this != &v)
		{
			if (this->participanti != nullptr)
			{
				delete[] this->participanti;
			}
			if (this->denumire != NULL)
			{
				delete[] this->denumire;
			}
			if (strlen(v.denumire) > 2)
			{
				this->denumire = new char[strlen(v.denumire) + 1];
				strcpy_s(this->denumire, strlen(v.denumire) + 1, v.denumire);
			}
			else
			{
				this->denumire = new char[strlen("") + 1];
				strcpy_s(this->denumire, 2, "");
			}
			if (v.oraIncepere.size() == 5)
			{
				this->oraIncepere = v.oraIncepere;
			}
			else
			{
				this->oraIncepere = "Necunoscuta";
			}
			if (v.nrParticipanti > 0 && v.participanti != nullptr)
			{
				this->nrParticipanti = v.nrParticipanti;
				this->participanti = new Participanti[v.nrParticipanti];
				for (int i = 0; i < v.nrParticipanti; i++)
				{
					this->participanti[i] = v.participanti[i];
				}
			}
			else
			{
				this->nrParticipanti = 1;
				this->participanti = new Participanti[nrParticipanti];
				Participanti p;
				this->participanti[0] = p;
			}
			if (v.data[0] > 0 && v.data[0] < 31 && data[1]>0 && data[1] < 13)
			{
				this->data[0] = v.data[0];
				this->data[1] = v.data[1];
			}
			else
			{
				this->data[0] = 1;
				this->data[1] = 1;
			}
			this->platfomarUtilizata = v.platfomarUtilizata;
			return *this;
		}
	}

	bool operator <(Videoconferinta v)
	{
		if (data[1] == v.data[1])
		{
			return data[0] < v.data[0];
		}
		else
		{
			return data[1] < v.data[1];
		}
	}

	bool operator== (Videoconferinta v)
	{
		return data[0] == v.data[0] && data[1] == v.data[1];
	}

	Videoconferinta& operator += (Videoconferinta v)
	{
		this->nrParticipanti += v.nrParticipanti;
		return *this;
	}

	Videoconferinta& operator ++(int)
	{
		Videoconferinta copie = *this;
		this->data[0]++;
		return copie;
	}

	operator int()
	{
		return nrParticipanti;
	}

	Participanti& operator[](int pos)
	{
		if (pos >= 0 && pos < nrParticipanti)
		{
			return this->participanti[pos];
		}
	}

	char* operator()()
	{
		return getDenumire();
	}

	char* getDenumire()
	{
		return this->denumire;
	}

	bool operator !()
	{
		return !ok;
	}

	bool operator != (Videoconferinta v)
	{
		return ok != v.ok;
	}

	friend ostream& operator << (ostream& out, const Videoconferinta& v)
	{
		out << "Denumire: "<< v.denumire << endl;
		return out;
	}

	friend ofstream& operator << (ofstream& out, const Videoconferinta& v)
	{
		out << "Denumire: " << v.denumire << endl;
		return out;
	}

	friend istream& operator >> (istream& in, Videoconferinta& v)
	{
		if (v.denumire != NULL)
		{
			delete[] v.denumire;
		}
		char aux[100];
		in.getline(aux, 99);
		v.denumire = new char[strlen(aux) + 1];
		strcpy_s(v.denumire, strlen(aux) + 1, aux);
		return in;
	}

	friend ifstream& operator >> (ifstream& in, Videoconferinta& v)
	{
		if (v.denumire != NULL)
		{
			delete[] v.denumire;
		}
		char aux[100];
		in.getline(aux, 99);
		v.denumire = new char[strlen(aux) + 1];
		strcpy_s(v.denumire, strlen(aux) + 1, aux);
		return in;
	}

	void setDenumire(const char* denumire)
	{
		if (strlen(denumire) > 2)
		{
			if (this->denumire != NULL)
			{
				delete[] this->denumire;
			}
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire), denumire);
		}
	}
};
int Videoconferinta::numarator = 1;
int Videoconferinta::capacitateMaxima = 50;

class VideoconferintaScoala : public Videoconferinta
{
public:
	int nrElevi;
	string* elevi;

	VideoconferintaScoala()
	{
		nrElevi = 1;
		elevi = new string[nrElevi];
		elevi[0] = "Gigel";
	}

	VideoconferintaScoala(const char* denumire, platforma platformaUtilizata, string oraIncepere, int nrParticipanti, Participanti* participanti, int zi, int luna, int nrElevi, string* elevi) : Videoconferinta(denumire, platformaUtilizata, oraIncepere, nrParticipanti, participanti, zi, luna)
	{
		if (nrElevi > 0 && elevi != NULL)
		{
			this->nrElevi = nrElevi;
			this->elevi = new string[nrElevi];
			for (int i = 0; i < nrElevi; i++)
			{
				this->elevi[i] = elevi[i];
			}
		}
	}
};

Videoconferinta& operator++(Videoconferinta& v)
{
	Videoconferinta::capacitateMaxima++;
	return v;
}

int main()
{
	Participanti p1;
	Participanti p2;
	Participanti p3;
	Participanti participanti[] = { p1, p2, p3 };
	string nume[] = { "Ion", "Gigea", "Sandu" };
	Videoconferinta v;
	Videoconferinta v2("POO", Zoom, "14:43", 3, participanti, 1, 1);
	VideoconferintaScoala vS("POO", Zoom, "14:43", 3, participanti, 1, 1, 3, nume);
	v = v2;
	//cout << v.getDenumire()<<endl;
	//cout<< (v == v2)<<endl;
	//cout << Videoconferinta::capacitateMaxima<<endl;
	v++;
	//cout << Videoconferinta::capacitateMaxima<<endl;
	v += v2;
	v[0].grupa = 1054;
	VideoconferintaScoala a;
	cout << v[0].grupa;
	cout << vS.nrElevi << endl << vS.data[1] << endl << vS.elevi[1];
	ifstream in("input.txt");
	in >> v;
	ofstream out("output.txt");
	out << v;

}
