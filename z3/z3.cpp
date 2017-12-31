// z3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Book.h"
#include <vector>
#include <algorithm>

using namespace std;

struct less_title
{
	inline bool operator() (Book& b1, Book& b2)
	{
		return b1.getTytul().compare(b2.getTytul());
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
	
	vector <Book> vec;

	vec.push_back(b1);
	vec.push_back(b2);
	vec.push_back(b3);
	vec.push_back(b4);
	vec.push_back(b5);

	for (int i = 0; i < vec.size(); i++)
		vec[i].toString();

	sort(vec.begin(), vec.end(), less_page());

	for (int i = 0; i < vec.size(); i++)
		vec[i].toString();

    return 0;
}

