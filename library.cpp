//*******************************************************************************
// Implemetion File (library.cpp)
// This file implements the Library 
// memberfunctions.
//*******************************************************************************
#include "library.h"
#include <iostream>
#include <string>

using namespace std;

Library::Library(int maxAmountOfBooks)
{
	this->maxAmountOfBooks = maxAmountOfBooks;
	this->books = new Book[maxAmountOfBooks];
}

void Library::addBook(const Book & book)
{
	if (currentAmountOfBooks < maxAmountOfBooks)
	{
		this->books[currentAmountOfBooks] = book;
		this->currentAmountOfBooks++;
	}
	else
		cout << "No space at the library" << endl;
}

Book & Library::getBook(int index)
{
	if (index < maxAmountOfBooks)
		return books[index];
	else
		cout << "Book Does Not Exist. " << endl;
}

void Library::showBooks()
{
	for (int i = 0; i < currentAmountOfBooks; i++)
	{
		cout << "Book Id : " << getBook(i).getBookId() << endl;
		cout << "POSITION IN LIBRARY: " << i << endl;
		cout << "Title : " << getBook(i).getTitle() << "  " << endl;
		cout << "Author : " << getBook(i).getAuthor() << "  " << endl;
		cout << "Publication Year : " << getBook(i).getPublicationYear() << "  " << endl << endl;
	}
}

Library::~Library()
{
	//redesign the Library destructor to free the memory from the books in the dynamic array
	delete[] books;
}