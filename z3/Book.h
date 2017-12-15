#pragma once
#include <string>

using namespace std;

class Book
{
public:
	Book(string t, string a, int ls);
	Book(const Book& b);
	Book(Book&& b);
	Book& operator=(const Book&);
	Book& operator=(Book&&);
	~Book();
private:
	string tytul;
	string autor;
	int liczbaStron;
	static int ileKonstruktorParametryczny;
	static int ileKonstruktorKopiujacy;
	static int ileKonstruktorPrzenoszacy;
	static int ileOperatorKopiujacy;
	static int ileOperatorPrzenoszacy;
};

