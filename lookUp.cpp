/***************************************************
* Programmer: Sophia Omar
* Assignment: G3 -- Add & Look Up Book
* Due Date: 14 October 2025 (updated 11/18/25)
* Purpose: Look Up Book Function Implementation
*****************************************************/
#include <iostream>
#include <limits>
#include <vector> 
#include "invmenu.h"
#include "bookInfo.h"
#include "utilities.h"
using namespace std; 

//Header Functions 
void displaySearchHeader(){
		cout <<"SERENDIPITY BOOKSELLERS\n";
		cout <<"Inventory Search\n\n"; 

}
/*************************Search Functions *****************/ 
//SEARCH BY TITLE (case insensitive & substring) 
static std::vector<size_t> findAllTitles(const std::vector<bookInfo>& database, const std::string& keyRaw) {
    std::vector<size_t> result;
    std::string key = toLowerString(keyRaw);
    for (size_t i = 0; i < database.size(); ++i) {
        if (toLowerString(database[i].getTitle()).find(key) != std::string::npos) {
            result.push_back(i);
        }
    }
    return result;
}

//SEARCH BY ISBN
static int searchISBN(const vector<bookInfo>& database, const string& isbn){
	for(size_t i =0; i <database.size(); ++i){
		if(database[i].getISBN() ==isbn){
			return(int)i; }
	} return -1;
} 


/**************************Print Functinos*************************/

static void printOneBook(const bookInfo& b, size_t indOne){
		cout << indOne << "." <<b.getTitle()
			 <<"\n   ISBN: "      << b.getISBN()
         << "\n   Author: "    << b.getAuthor()
         << "\n   Publisher: " << b.getPublisher()
         << "\n   Qty: "       << b.getQty()
         << "\n   Whole: $"    << b.getWholeCost()
         << "\n   Retail: $"   << b.getRetailCost()
         << "\n   Date: "      << b.getDate()
         << "\n------------------------------------------------------------\n";


}
/******************* Search Function FOR LOOK UP ONLY ********/
int lookUpBook(std::vector<bookInfo>& database){
		//Clear screen and display header
		clear(); 
		displaySearchHeader(); 	
		
		//singular input prompt
		string key = readLine("Enter Title or ISBN to Search: "); 
		if(key.empty()){
			cout <<"\n\n No Input Entered\n\n";
			pauseEnter(); 
			return -1;
		}
		
		//save search matches
		vector<size_t> matches; 
		
		//checks for the unique isbn so theres no diplicates but if not isbn then title
		int isbnIndex = searchISBN(database, key); 
		if (isbnIndex != -1){
			matches.push_back((size_t)isbnIndex);
		} else{
				matches = findAllTitles(database, key); 
			}

			//show the search results
			clear();
			cout << "***** SEARCH RESULTS *****\n\n";
			
			//if theres no matches
			if (matches.empty()){
				cout <<"No books found.\n"; 
				pauseEnter();
				return -1; 
			}
			
			// just one match
			if(matches.size() ==1){
				printOneBook(database[matches[0]],1); 
				pauseEnter();
				return -1; 
			}
		
		//more than one match
		cout << "Found " <<matches.size() << " matching book(s):\n";
		for(size_t i =0; i <matches.size(); ++i){
			printOneBook(database[matches[i]], i+1);
		}
		pauseEnter(); 
		return -1; 
}

/******************* Search Function FOR DELETE BOOK REDEFINED ********/
// as of 11/18 has unified search and can return to main inv menu
int lookUpBookDEL(std::vector<bookInfo>& database, bool returnIndex){
		//Clear screen and display header
		clear(); 
		displaySearchHeader(); 	
		
		//singular input prompt
		string key = readLine("Enter Title or ISBN to Search (press ENTER to Cancel): "); 
		if(key.empty()){
			return -1; //cancels 
		}
		
		//save search matches
		vector<size_t> matches; 
		
		//checks for the unique isbn so theres no diplicates but if not isbn then title
		int isbnIndex = searchISBN(database, key); 
		if (isbnIndex != -1){
			matches.push_back((size_t)isbnIndex);
		} else{
				matches = findAllTitles(database, key); 
			}

			//show the search results
			clear();
			cout << "***** SEARCH RESULTS *****\n\n";
			
			//if theres no matches
			if (matches.empty()){
				cout <<"No books found.\n"; 
				pauseEnter();
				return -1; 
			}
			
			
			// just one match
		if (matches.size() == 1) {
        printOneBook(database[matches[0]], 1);

        if (!returnIndex) {
            pauseEnter();
            return -1;
        }

        // ask if user wants to accept this book
        cout << "Select this book? (y/n): ";
        string answer = readLine("");
        if (answer == "y" || answer == "Y") {
            return matches[0];
        }

        return -1;
    }		
		//more than one match
	cout << "Found " << matches.size() << " matching book(s):\n";
    for (size_t i = 0; i < matches.size(); ++i) {
        printOneBook(database[matches[i]], i + 1);
    }

    if (!returnIndex) {
        pauseEnter();
        return -1;
    }

    // Ask user which match to pick
    cout << "0. Cancel\n";
    int pick = readChoice("Select a book by number: ", 0, matches.size());

    if (pick == 0)
        return -1;   // cancels

    return matches[pick - 1];   // return the actual vector index
}
