#include"Examination.h"

//Konstruktor bez parametru
Examination::Examination()
{
	//#ifdef _DEBUG
	//	cout << "Examination()" << endl;
	//#endif
}

//Konstruktory z parametrami
Examination::Examination(int d, int m, int y)
{
	//#ifdef _DEBUG
	//	cout << "Examination(day, month, year)" << endl;
	//#endif
	day = d;
	month = m;
	year = y;
}

Examination::Examination(double tsh, double ft3, double ft4, bool aT)
{
	//#ifdef _DEBUG
	//	cout << "Examination(tsh, ft3, ft4, antyTsh)" << endl;
	//#endif
	TSH = tsh;
	FT3 = ft3;
	FT4 = ft4;
	antyTSH = aT;
}

//Destruktor
Examination::~Examination()
{
	//#ifdef _DEBUG
	//	cout << "~Examination()" << endl;
	//#endif
}

//Ustawianie danych
void Examination::setDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
void Examination::setResults(double tsh, double ft3, double ft4, bool aT)
{
	TSH = tsh;
	FT3 = ft3;
	FT4 = ft4;
	antyTSH = aT;
}

//Pobieranie danych
string Examination::getDate()
{
	return to_string(day) + "." + to_string(month) + "." + to_string(year) + "\n";
}

string Examination::getResults()
{
	string s1 = "TSH = " + to_string(TSH);
	string s2 = "FT3 = " + to_string(FT3);
	string s3 = "FT4 = " + to_string(FT4);
	string s4 = (antyTSH ? "positive" : "negative");
	string s5 = "antyTSH: " + s4;
	string s = s1 + "\n" + s2 + "\n" + s3 + "\n" + s5 + "\n";
	return s;
}

string Examination::getExamination()
{
	return "Examination from: " + getDate() + "\nResults: " + getResults() + "\n";
}

bool Examination::operator==(const Examination &e)
{
	return ((day == e.day) && (month == e.month) && (year == e.year) &&
		(TSH == e.TSH) && (FT3 == e.FT3) && (FT4 == e.FT4) && (antyTSH == e.antyTSH));
}

ostream & operator<<(ostream & out, Examination & e)
{
	out << e.day << endl << e.month << endl << e.year << endl;
	out << e.TSH << endl << e.FT3 << endl << e.FT4 << endl << e.antyTSH;

	return out;
}

istream & operator >> (istream & is, Examination & e)
{
	string s;
	while (is.peek() == 10) getline(is, s);	//Przy wczytywniu kilku historii zostaje wisz¹cy znak '\n'

	is >> e.day;//Pierwsza nie-nowa linie zapisuje getlinem, bo ju¿ zosta³a zapisana
	is  >> e.month >> e.year;
	is >> e.TSH >> e.FT3 >> e.FT4 >> e.antyTSH;

	return is;
}
