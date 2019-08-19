//*******************************************************************************
// Implemetion File (user.cpp)
// This file implements the User, Borrower, 
// and Librarian memberfunctions.
//*******************************************************************************
#include "user.h"
#include "library.h"
#include <iostream>

using namespace std;

string User::getName()
{
	return this->name;
}

string User::getLastName()
{
	return this->lastName;
}

User::User(std::string name, std::string lastName)
{
	this->name = name;
	this->lastName = lastName;
}

// Constructor initializer is used
Borrower::Borrower(string name, string lastName, int maxAmountBookCanPosses) : User(name, lastName)
{
	this->userAmountOfBooks = 0;
	this->maxAmountOfBooks = maxAmountBookCanPosses;
	this->booksInPossesion = new Book[maxAmountBookCanPosses];
}

Borrower::~Borrower()
{
	delete[] booksInPossesion;
}

Book & Borrower::getBook(int index)
{
	if (index < userAmountOfBooks)
	{
		return booksInPossesion[index];
	}
	else
		return booksInPossesion[0];
}

void  Borrower::returnBook(Library & bookToReturnTo, int index)
{
	if (index < this->userAmountOfBooks && this->userAmountOfBooks > 0)
	{
		bookToReturnTo.addBook(booksInPossesion[index]);
		for (int i = 0; i < maxAmountOfBooks - 1; i++) 
		{
			if (i >= index)
				booksInPossesion[i] = booksInPossesion[i + 1];
		}
		this->userAmountOfBooks--;
	}
	else 
	{
		
	}
}

void Borrower::showBooks()
{
	cout << endl << endl << getName() << " " << getLastName() << " Books : " << endl;
	for (int i = 0; i < userAmountOfBooks; i++)
	{
		cout << "Book Id : " << getBook(i).getBookId() << "  " << endl;
		cout << "Position in Library :" << i << "  " << endl;
		cout << "Author : " << getBook(i).getAuthor() << "  " << endl;
		cout << "Title : " << getBook(i).getTitle() << "  " << endl;
		cout << "Publication Year : " << getBook(i).getPublicationYear() << "  " << endl;
	}
	cout << endl;
}

Librarian::Librarian(std::string name, std::string lastName, int maxAmountOfBooks) : Borrower(name, lastName, maxAmountOfBooks)
{}

void Librarian::lendBook(Library& libraryToLendFrom, Borrower& personToLendTo, int position)
{
	if (libraryToLendFrom.currentAmountOfBooks > 0)
	{
		if (personToLendTo.userAmountOfBooks < personToLendTo.maxAmountOfBooks && position < libraryToLendFrom.currentAmountOfBooks)
		{			
			personToLendTo.booksInPossesion[personToLendTo.userAmountOfBooks] = libraryToLendFrom.books[position];
			for (int i = 0; i < libraryToLendFrom.maxAmountOfBooks - 1; i++)
			{
				
				if (i >= position)	// add to the books
					libraryToLendFrom.books[i] = libraryToLendFrom.books[i + 1];
			}			
			libraryToLendFrom.currentAmountOfBooks--;
			personToLendTo.userAmountOfBooks++;
		}
		else{}
	}
	else {}
}