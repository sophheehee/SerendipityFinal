/***************************************************
* Programmer: Sophia Omar
* Assignment: G3 -- Add & Look Up Book
* Due Date: 14 October 2025
* Purpose: Main Menu Driver for Bookseller program
*****************************************************/
#include <iostream>
#include <iomanip>
#include <limits>
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "bookInfo.h"
#include "lookUp.h"
#include "utilities.h"
using namespace std; 

//Function Prototypes
void displayMainHeader(); 
void displayMainList(); 
void clear(); 


int main(){
	//Variable & Vector Declarations
		vector<bookInfo> database; 
		database.reserve(20); 
	
		int choice;  //Switch for menu
		
	
		
	do {
			
		//Display Header
			clear(); 
			displayMainHeader();
			displayMainList();
		//Prompt for input and validate for int
		choice = readChoice("Enter Choice (1-4):", 1, 4); 

		//Menu Choice 
		switch(choice){
		case 1:
			clear();   
			cashier();
			break; 
		case 2: 
			clear(); 
			invMenu(database); 
			break; 
		case 3:
			clear(); 
			reports();
			break; 
		case 4:
				break; 
			//exits loop
		}
		
		if (choice !=4) {
			pauseEnter(); 
		}

	} while (choice != 4); 

}

//Displays Main Menu Header
void displayMainHeader(){
		cout <<"*****SERENDIPITY BOOKSELLERS*****\n";
		cout <<"\t  Main Menu\n\n"; 
	
}
//Displays Menu Options
void displayMainList(){
	cout <<"What would you like to do?\n";
	cout << "1. Cashier\n"; 
	cout << "2. Inventory\n"; 
	cout << "3. Reports\n";
	cout << "4. Exit\n\n";
}
