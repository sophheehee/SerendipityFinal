/***************************
* Programmer: Sophia Omar
* Assignment: Serendipity G4
* Due Date: 11/18/2025
* Purpose: Delete Book Function
*****************************/
#include <iostream>
#include <vector>
#include "deleteBook.h"
#include "lookUp.h"
#include "utilities.h" 
using namespace std;

void displayHeader(){
	cout <<"SERENDIPITY BOOKSELLERS\n";
		cout <<"Delete a Book\n\n"; 

} 

void deleteBook(std::vector<bookInfo>& database){
	while(true){
		
		clear(); 
		displayHeader(); 
		
		//return the index from lookup
		int index = lookUpBookDEL(database, true); 
		if (index == -1){
			cout << "No matching book found.\n"; 
			pauseEnter();
			return; // to go back to OG inv menu
		}

		//show the selection b4 delete
		clear(); 
		cout << "Current Book Selection:\n";
		cout <<"****************************************************\n";
		cout << "Title: " << database[index].getTitle() << "\n"
			  << "ISBN: " <<  database[index].getISBN() << "\n"
			  << "Author: " << database[index].getAuthor()    << "\n"
			  << "Publisher: " <<database[index].getPublisher() << "\n"
			  << "Quantity: " <<database[index].getQty() << "\n"
			  << "Wholesale: " << database[index].getWholeCost() << "\n"
				<< "Retail: " << database[index].getRetailCost() << "\n"
				<< "Date: " <<database[index].getDate() << "\n";
		cout <<"****************************************************\n";

		//confirm deletion
		char confirm = readYN("Delete this book? (y/n):");
		if(confirm == 'y' || confirm == 'Y'){
			database.erase(database.begin() + index);
			cout << "Book deleted successfully.\n";
		}else {
			cout << "\nDeletion has been canceled.\n"; 
		}
		
		// ask if they want to delete another book
		char repeat =readYN("Delete another book? (y/n): ");
		if (repeat == 'n' || repeat =='N'){
				return;
		}

	}//loop end
}//function end
