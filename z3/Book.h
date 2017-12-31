#pragma once
#include <string>

using namespace std;

class Book
{
public:
	Book();
	Book(string t, string a, int ls);
	Book(const Book& b);
	Book(Book&& b);
	Book& operator=(const Book&);
	Book& operator=(Book&&);
	~Book();
	const string getTytul();
	const string getAutor();
	int getLiczbaStron();
	const void toString();
	static int ileKonstruktorKopiujacy;
	static int ileKonstruktorParametryczny;
	static int ileKonstruktorPrzenoszacy;

private:
	string tytul;
	string autor;
	int liczbaStron;

};

