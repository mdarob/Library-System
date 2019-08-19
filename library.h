//*******************************************************************************
// Specification File (library.h)
// This file gives the specification
// of a Book abstract data type
//*******************************************************************************
#pragma once
#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include "book.h"
#include "user.h"

class Library
{
	private:
		Book * books;
		int maxAmountOfBooks;
		int currentAmountOfBooks;
	public:
		// Constructor 
		Library(int maxAmountOfBooks);
		// Post: Library is set according to the incoming parameter the maximum amout of books library can hold
		~Library();
		// Post: Destructor deletes the dynamically allocated data (books)
		void addBook(const Book &);
		// Post: The book is added to the library
		Book & getBook(int index);
		// Post: Return the book from the library with an index
		void showBooks();
		// Post: Prints the books position in the library and unique id assigned to it
		friend void Librarian::lendBook(Library& lendBooksFromLibrary, Borrower& borrowerPerson, int index);
		// Note: A friend class can access private and protected members of other class in which it is declared as friend
};

#endif


