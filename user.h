//*******************************************************************************
// Specification File (user.h)
// This file gives the specification
// of a User, Borrower and Librarian abstract data type
//*******************************************************************************
#pragma once
#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
#include <iostream>
#include "book.h"

using namespace std;

class Library;

class User
{
	protected:
		string name;     // User name
		string lastName; // User last name
	public:
		// Constructor
		User(string name, string lastName);
		// Post: Constructor with name and lastName as a parameter
		string getName();
		// Post: Return the name of the User
		string getLastName();
		// Post: Return the lastName of the User
};

class Borrower : public User
{
	protected:
		friend class Librarian;
		Book * booksInPossesion;
		int maxAmountOfBooks;
		int userAmountOfBooks;
	public:
		// Constructors
		Borrower(string, string, int);
		// Post: Borrower is set according to the incoming parameters such as name, 
		//		 lastname, and maximum book can rent as received by the parameters
		Borrower(const Borrower &) = delete;
		// Pre: The borrower with his possesions is an unique object ! You shouldn't 
		//		be able to copy any of borrower type objects
		// Post: This constructor prevents the user to so, The method is 
		//		 deleted hence, no one can do Borrower b2 = b1;
		Borrower & operator = (const Borrower &) = delete;
		// Pre: The borrower with his possesions is an unique object ! You shouldn't 
		//		be able to copy any of borrower type objects
		// Post: This constructor prevents the user to so, The method is 
		//		 deleted hence, no one can do b2 = b1;	
		Book & getBook(int index);
		// Post: Return the booksInPossesion index at the library
		void returnBook(Library & libraryToReturnTo, int index);
		// Pre:  User must rent a book in order to return
		// Post: Allows the Borrower to return the book
		void showBooks(); 
		// Pre:  The books must be added to in order to show book
		// Post: Prints to the console the book Borrower and Library have in possesion
		// Destructor
		~Borrower();
		// Post: deleted booksInPossesion	
};

class Librarian : public Borrower
{
	public:
		Librarian(string name, string lastName, int maxAmountOfBooks);
		// Post: Librarian name, lastname and maxAmountOfBooks library can posses 
		//		 is set according to the assigned parameters 
		void lendBook(Library &, Borrower &, int);
		// Pre: There should be books at the library before renting
		// Post: Lended books to the user
};

#endif // USER_H_INCLUDED