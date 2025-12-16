//COPY
/***************************
NAME: Christian Schoffstoll
Assignment: G2
Due: 9/23
Purpose: Active cash register accepting
quantity, book name, isbn, cost per unit,
and printing full receipt with calculated subtotal and taxed total
***************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "cashier.h"
#include "utilities.h"
using namespace std;

int cashier() {

	string dte = ""; //user entered date
	int qty = 0; //number of copies being purchased
	string isbn = ""; //user enters the book's ISBN
	string title = ""; //user entered book title
	float price = 0; //retail price of book
	float sub = 0; //subtotal value gets updated by reference in calcTot()
	float total = 0; //total price of purchase

	//asks user to enter date in American form and stores value
	cout << "Please enter today's date (MM/DD/YYYY): ";
	getline(cin, dte);

	//asks user to enter the title of book and stores value
	cout << "\n\nPlease enter book's title: ";
	getline(cin, title);

	//asks user to enter book's ISBN (10 digits) and stores value
	cout << "\n\nPlease enter book's ISBN: ";
	getline(cin, isbn);

	//asks user to enter price of said book and stores value
	cout << "\n\nPlease enter book's price: ";
	cin >> price;

	//asks user to enter the amount of said book being purchased
	cout << "\n\nPlease enter how many copies: ";
	cin >> qty;

	total = calcTot(qty, price, sub); //function call

	printRecipt(dte, title, qty, isbn, price, sub, total); //function call

	
	return 0;
}
/******************* printRecipt() **************************
Definition: Accepts a string for the date, string for the 
book's title, integer for ammount of book, string for book's 
ISBN, float for book's base price, float for subtotal of 
purchase, and a float for the total cost

Purpose: Prints all the information provided in a receipt 
styled format 
************************************************************/



void printRecipt(string date, string title, int qty, string isbn, float price, float sub, float total) {
	clear(); 
	//only cout statements for formating to display receipt
	cout <<  "\n\n\n\n*" << setfill('-') << setw(70) << "*";
	cout << "\n*" << setfill(' ') <<  setw(70) << "*" << "\n*Serendipty Book Sellers" << setw(48) << " * ";
	cout << "\n*Date: " << date << setw(54) << "*";
	cout << "\n*" << setw(70) << "*" << "\n*Qty    ISBN" << setw(15) << "Title" << setw(28)
		 << "Price" << setw(12) << "Total" << "   *\n";
	cout << "*" << setfill('-') << setw(70) << "*";
	cout << "\n*" << setfill(' ') << setw(3) << qty << setw(17) << isbn << " " << left << setw(28) << title
		 << "$" << fixed << right << setprecision(2) << setw(8) << price << setw(4) << "$"
		 << setw(7) << price * qty << "*";
	cout << "\n*" << setw(70) <<  "*";
	cout << "\n*" << setw(61) << "Subtotal    " << "$" << setw(7) << sub << "*";
	cout << "\n*" << setw(52) << "Tax" << setw(10) << "$" << setw(7)
		 << (qty * price) * (0.06) << "*";
	cout << "\n*" << setw(54) << "Total" << setw(8) << "$" << setw(7) << total << "*";
	cout << "\n*" << setw(70) << "*";
	cout << "\n* Thank You For Shopping at Serendipity!" << setw(31) << "*";
	cout << "\n*" << setfill('-') << setw(70) << "*";

}

/******************* calcTot() *******************
Definition: Accepts an integer for the ammount of
an item being purchased, float for the price of
item, and pass by referrance float to uptade
value of subtotal in main

Purpose: Returns the calculated total of item with
tax, and saves subtotal value for later use
*************************************************/



float calcTot(int qty, float price, float &sub) {

	//multiplies price of item by ammount of item and stores value in subtotal variable
	sub = qty * price;

	return sub + (sub * 0.06); //returns the calculated total with 6% sales tax

}
