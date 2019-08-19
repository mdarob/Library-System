//*******************************************************************************
// Implemetion File (book.cpp)
// This file implements the Book 
// memberfunctions.
//*******************************************************************************
#include <iostream>
#include "book.h"

using namespace std;

int Book::numOfBooksCreated = 0;

Book::Book(string title, string author, int publicationYear)
{
	this->title = title;
	this->author = author;
	this->publicationYear = publicationYear;
	this->bookId = Book::numOfBooksCreated++;
}

Book::Book(const Book& bookToCopy)
{
	this->title = bookToCopy.getTitle();
	this->author = bookToCopy.getAuthor();
	this->publicationYear = bookToCopy.getPublicationYear();
	this->bookId = Book::numOfBooksCreated++;
}

Book::Book()
{
	title = " ";
	author = " ";
	publicationYear = 0;
	bookId = 0;
}



string Book::getTitle() const
{
	return this->title;
}

string Book::getAuthor() const
{
	return this->author;
}

int Book::getPublicationYear() const
{
	return this->publicationYear;
}

int Book::getBookId() const
{
	return this->bookId;
}