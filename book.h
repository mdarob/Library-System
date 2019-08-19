//*******************************************************************************
// Specification File (book.h)
// This file gives the specification
// of a Book abstract data type
//*******************************************************************************
#pragma once
#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <iostream>

using namespace std;

class Book
{
	private:
		string title;
		string author;
		int publicationYear;		
		int bookId;
	public:
		// Constructors
		Book();
		// Post: title,	author, publicationYear, bookId have been set to null
		Book(string title, string author, int publicationYear);
		// Post: Book is set according to the incoming parameters and give each 
		//		 of the book an unique ID number
		Book(const Book &);	
		// Post: The copy constructor for book class use references to pass the actual book(not a copy) 
		//		 in order to preserve the UNIQUE ID given during creation.
		static int numOfBooksCreated;
		// Pre: numOfBooksCreated initialize with 0
		// Post: numOfBooksCreated is set to the number of books that were created
		string getTitle() const;
		// Post: Return the title of the book
		//		 Note: const prevents the compiler to assign data to private data member
		string getAuthor() const;
		// Post:Return the author's name of the book
		int getPublicationYear() const;
		// Post: Return the Publication Year of the book
		int getBookId() const;
		// Post: Return the unique Book Id		
};

#endif
