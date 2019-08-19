//*******************************************************************************
// Driver for class Book, Librarian, Borrower, Library, and User
//*******************************************************************************
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "library.h"
#include "book.h"
#include "user.h"

using namespace std;

int main()
{
	Librarian librarian("John", "Beaglow", 5);
	Borrower borrower("Scutt", "Philips", 3); // At most Scutt can borrow 3 Books at a time

	const Book book1("Programming and Problem Solving", "Nell Dale", 2010);
	const Book book2("An Introduction to Software and Hardware Interfacing", "Han-Way Huang", 2006);
	const Book book3("An Introduction to Software Engineering", "Random Guy", 2006);
	const Book book4("An Introduction to Computer Engineering", "Random Guy 2", 2006);
	const Book book5("Clean Code", "Random Guy 3", 2006);

	Library library(5);
	library.addBook(book1);
	library.addBook(book2);	
	library.addBook(book3);
	library.addBook(book4);
	library.addBook(book5);

	int position;
	char choice;
	while (true)
	{
		library.showBooks();
		borrower.showBooks();

		cout << "Do you want to Borrow - B/b or Return R/r books? " << endl;
		cin >> choice;
		
		switch (choice)
		{
			case 'B': case 'b' :
			{
				cout << "What Book would you like to rent ? Enter the Position : " << endl;
				cin >> position;
				librarian.lendBook(library, borrower, position);
				break;
			}
			case 'R': case 'r' :
			{
				cout << "What Book would you like to retrun ? Enter the Position : " << endl;
				cin >> position;
				borrower.returnBook(library, position);
				break;
			}
			default:
				break;
		}
		system("cls");
	}
	
	system("pause");
	return 0;
}