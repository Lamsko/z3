#include "stdafx.h"
#include "Book.h"

int Book::ileKonstruktorKopiujacy = 0;
int Book::ileKonstruktorParametryczny = 0;
int Book::ileKonstruktorPrzenoszacy = 0;
int Book::ileOperatorKopiujacy = 0;
int Book::ileOperatorPrzenoszacy = 0;

Book::Book(string t, string a, int ls) : tytul(t), autor(a), liczbaStron(ls)
{
	ileKonstruktorParametryczny++;
}

Book::Book(const Book & b)
{
	ileKonstruktorKopiujacy++;
}

Book::Book(Book && b)
{
	ileKonstruktorPrzenoszacy++;
}

Book & Book::operator=(const Book &)
{
	ileOperatorKopiujacy++;
}

Book & Book::operator=(Book &&)
{
	ileOperatorPrzenoszacy++;
}

Book::~Book()
{
}
