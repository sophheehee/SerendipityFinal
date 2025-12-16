//COPY
/*************************************************
* Programmer: Sophia Omar
* Assignment: G2 -- Serendipity Menus
* Due Date: 23 September 2025
* Purpose: Report Printing & Header/Menu Functions
**************************************************/

#include <iostream>
#include "reports.h"
using namespace std;

//Function Definitions for Menu and Header (Sophie)
void displayRepList(){
	cout <<"What would you like to do?\n";
	cout << "1. Inventory Listing\n"; 
	cout << "2. Inventory Wholesale\n"; 
	cout << "3. Inventory Retail Value\n";
	cout << "4. Listing by Quantity\n";
	cout << "5. Listing by Cost\n"; 
	cout << "6. Listing by Age\n";
	cout << "7. Return to Main Menu\n\n"; 
	cout << "Enter Your Choice (1-7): "; 

}
void displayRepHeader(){
	cout <<"SERENDIPITY BOOKSELLERS\n";
		cout <<"Reports Menu\n\n"; 

} 
 
void reports(){
	//Variable Declarations
		int choice; //Menu Switch

do{
			
			displayRepHeader();
			displayRepList();
		//Prompt for input 
		cin >> choice; 

		//Menu Choice 
		switch(choice){
		case 1:
			//repListing()
			break; 
		case 2: 
			//repWholesale()
			break; 
		case 3:
			//repRetail()
			break; 
		case 4:
			//repQuantity()
			break; 
		case 5: 
			//repCost()
			break; 
		case 6: 
			//repAge(); 
			break; 
		case 7:
			break; //exits loop & returns to main menu
		default:
			cout << "Your choice is invalid. Please enter a choice from 1-7.";
			 cin.get(); // pauses so message is seen 

		}
		
		if (choice !=7) {
			cout <<"\n\nPress Enter to Continue..."; 
			cin.ignore(); 
			cin.get(); // pause again before clearing
			cout << "\033[H\033[2J";
		}

	} while (choice != 7); 


}










