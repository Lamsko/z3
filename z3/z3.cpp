// z3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Book.h"


int main()
{
	Book b1("Ksiazka", "Witold", 250);
	Book b2(b1);
	Book b3 = b1;
	

    return 0;
}

