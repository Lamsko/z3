// z3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Book.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

void bubbleSort(vector<Book>& v, std::function<bool(Book& b1, Book& b2)> cmp)
{
	Book temp;
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j < v.size() - 1; j++)
		{
			if (cmp(v[j+1], v[j]))
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

struct less_title
{
	inline bool operator() (Book& b1, Book& b2)
	{
		if (b1.getTytul().compare(b2.getTytul()) < 0)
			return true;
		else
			return false;
	}
};

struct less_author
{
	inline bool operator() (Book& b1, Book& b2)
	{
		if (b1.getAutor().compare(b2.getAutor()) < 0)
			return true;
		else
			return false;
	}
};


struct less_page
{
	inline bool operator() (Book& b1, Book& b2)
	{
		return (b1.getLiczbaStron() < b2.getLiczbaStron());
	}
};

int main()
{
	Book b1("Ksiazka", "Witold", 250);
	Book b2(b1);
	Book b3 = b1;
	Book b4("Nowa ksiazka", "Marlena", 300);
	Book b5("Alicja w krainie czarow", "Lewis Carroll", 150);
	Book b6("Wladca pierscieni", "J.R.R. Tolkien", 900);
	Book b7("Ogrody Ksiezyca", "Steven Erikson", 700);
	Book b8("Droga Krolow", "Brandon Sanderson", 950);
	Book b9("Ostatnie zyczenie", "Andrzej Sapkowski", 400);
	Book b0("Gra o tron", "George R.R. Martin", 600);

	vector <Book> vec;

	vec.push_back(b1);
	vec.push_back(b2);
	vec.push_back(b3);
	vec.push_back(b4);
	vec.push_back(b5);
	vec.push_back(b6);
	vec.push_back(b7);
	vec.push_back(b8);
	vec.push_back(b9);
	vec.push_back(b0);

	cout << "Przed sortowaniem:" << endl;

	for (int i = 0; i < vec.size(); i++)
		vec[i].toString();

	bubbleSort(vec, less_title());

	cout << endl;
	cout << "Sortowanie po tytule: " << endl;

	for (int i = 0; i < vec.size(); i++)
		vec[i].toString();

	bubbleSort(vec, less_author());
	
	cout << endl;
	cout << "Sortowanie po autorze: " << endl;

	for (int i = 0; i < vec.size(); i++)
		vec[i].toString();

	bubbleSort(vec, less_page());

	cout << endl;
	cout << "Sortowanie po liczbie stron: " << endl;

	for (int i = 0; i < vec.size(); i++)
		vec[i].toString();
	cout << endl;
	cout << "Liczba wywolan konstruktora parametrycznego:" << Book::ileKonstruktorParametryczny << endl;
	cout << "Liczba wywolan konstruktora przenoszacego:" << Book::ileKonstruktorPrzenoszacy << endl;
	cout << "Liczba wywolan konstruktora kopiujacego:" << Book::ileKonstruktorKopiujacy << endl;


	cout << endl;
	cout << "Sortowanie z wykorzystaniem std::sort wywoluje konstruktor przenoszacy." << endl;
	sort(vec.begin(), vec.end(), less_author());
	cout << "Liczba wywolan konstruktora przenoszacego po wywolaniu std::sort: " << Book::ileKonstruktorPrzenoszacy << endl;

    return 0;
}

