#include "stdafx.h"
#include "Book.h"

int Book::ileKonstruktorKopiujacy = 0;
int Book::ileKonstruktorParametryczny = 0;
int Book::ileKonstruktorPrzenoszacy = 0;


Book::Book(string t, string a, int ls) : tytul(t), autor(a), liczbaStron(ls)
{
	ileKonstruktorParametryczny++;
}

Book::Book(const Book & b) : tytul(b.tytul), autor(b.autor), liczbaStron(b.liczbaStron)
{
	ileKonstruktorKopiujacy++;
}

Book::Book(Book && b) : tytul(""), autor(""), liczbaStron(0)
{
	ileKonstruktorPrzenoszacy++;

	tytul = b.tytul;
	autor = b.autor;
	liczbaStron = b.liczbaStron;

	b.tytul = "";
	b.autor = "";
	b.liczbaStron = 0;	
}

Book & Book::operator=(const Book & b)
{
	ileKonstruktorKopiujacy++;

	if (this != &b)
	{
		tytul = b.tytul;
		autor = b.autor;
		liczbaStron = b.liczbaStron;
	}

	return *this;
}

Book & Book::operator=(Book && b)
{
	ileKonstruktorPrzenoszacy++;
	if (this != &b)
	{
		tytul = b.tytul;
		autor = b.autor;
		liczbaStron = b.liczbaStron;

		b.tytul = "";
		b.autor = "";
		b.liczbaStron = 0;
	}

	return *this;
}

Book::~Book()
{
}
