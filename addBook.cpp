/*
NAME: Christian Schoffstoll
PROGRAM: addBook.cpp
DUE: 10/14/25
FOR: Adding books to database
*/

#include "addBook.h"
#include "bookInfo.h"
#include "lookUp.h"
#include "utilities.h"
#include "invmenu.h"      // for invMenu(inventory)
#include <cctype>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

void addBookPrint(const bookInfo& b, const std::vector<bookInfo>& v);

void addBook(std::vector<bookInfo>& inventory, std::size_t capacity)
{
    // If database already full, bail out immediately
    if (inventory.size() >= capacity)
    {
        std::cout << "Database is full. No more books can be added.\n\n";
        //invMenu(inventory);
        return;
    }

    char choice = ' ';      // user menu choice
    char esc = ' ';         // Y/N when leaving
    std::string data_s;     // user string input
    int data_i = 0;         // user integer
    float data_f = 0.0f;    // user float

    // "Pending" book we are editing before saving
    bookInfo blank;

    // default values (in case default ctor doesn’t)
    blank.setTitle("NOT SET");
    blank.setISBN("NOT SET");
    blank.setAuthor("NOT SET");
    blank.setPublisher("NOT SET");
    blank.setDate("NOT SET");
    blank.setQty(0);
    blank.setWholeCost(0.0f);
    blank.setRetailCost(0.0f);

    bool adding = true;

    while (adding && inventory.size() < capacity)
    {
        addBookPrint(blank, inventory);   // show pending + DB info

        std::cin >> choice;
        std::cin.ignore(1000, '\n');      // eat leftover newline

        switch (choice)
        {
        case '1': // Title
            std::cout << "Enter Book Title: ";
            std::getline(std::cin, data_s);
            blank.setTitle(data_s);
            clear();
            break;

        case '2': // ISBN
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, data_s);
            blank.setISBN(data_s);
            clear();
            break;

        case '3': // Author
            std::cout << "Enter Author: ";
            std::getline(std::cin, data_s);
            blank.setAuthor(data_s);
            clear();
            break;

        case '4': // Publisher
            std::cout << "Enter Publisher: ";
            std::getline(std::cin, data_s);
            blank.setPublisher(data_s);
            clear();
            break;

        case '5': // Date
            std::cout << "Enter Date (MM/DD/YYYY): ";
            std::getline(std::cin, data_s);
            blank.setDate(data_s);
            clear();
            break;

        case '6': // Quantity (int >= 0)
        {
            std::cout << "Enter Quantity on Hand (>= 0): ";
            while (true)
            {
                if (std::cin >> data_i && data_i >= 0)
                {
                    std::cin.ignore(1000, '\n');
                    break;
                }
                std::cout << "  !! Please enter an integer >= 0: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            blank.setQty(data_i);
            clear();
            break;
        }

        case '7': // Wholesale (float >= 0.0)
        {
            std::cout << "Enter Wholesale Cost (>= 0.0): ";
            while (true)
            {
                if (std::cin >> data_f && data_f >= 0.0f)
                {
                    std::cin.ignore(1000, '\n');
                    break;
                }
                std::cout << "  !! Please enter a number >= 0.0: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            blank.setWholeCost(data_f);
            clear();
            break;
        }

        case '8': // Retail (float >= 0.0)
        {
            std::cout << "Enter Retail Price (>= 0.0): ";
            while (true)
            {
                if (std::cin >> data_f && data_f >= 0.0f)
                {
                    std::cin.ignore(1000, '\n');
                    break;
                }
                std::cout << "  !! Please enter a number >= 0.0: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            blank.setRetailCost(data_f);
            clear();
            break;
        }

        case '9': // Save book to database
        {
            if (inventory.size() >= capacity)
            {
                std::cout << "Database is full, cannot save new book.\n\n";
                //invMenu(inventory);
                return;
            }

            inventory.push_back(blank);

            // Reset pending book to defaults
            blank.setTitle("NOT SET");
            blank.setISBN("NOT SET");
            blank.setAuthor("NOT SET");
            blank.setPublisher("NOT SET");
            blank.setDate("NOT SET");
            blank.setQty(0);
            blank.setWholeCost(0.0f);
            blank.setRetailCost(0.0f);

            clear();

            // If we just filled the DB, force back out like your original code
            if (inventory.size() >= capacity)
            {
                std::cout << "Database is full, saving entered data.\n\n";
                std::cout << "Press ENTER to continue...";
                std::cin.ignore(1000, '\n');
               // invMenu(inventory);
                return;
            }

            break;
        }

        case '0': // Return to inventory menu
            esc = ' ';
            while (esc != 'y' && esc != 'n')
            {
                std::cout << "Return to main menu? (Y/N): ";
                std::cin >> esc;
                esc = static_cast<char>(std::tolower(static_cast<unsigned char>(esc)));
                std::cin.ignore(1000, '\n');
            }

            if (esc == 'y')
            {
                clear();
               // invMenu(inventory);
                return;
            }

            clear();
            break;

        default:
            std::cout << "Invalid choice (0-9), press ENTER:";
            std::cin.ignore(1000, '\n');
            clear();
            break;
        }
    }
}

void addBookPrint(const bookInfo& blank, const std::vector<bookInfo>& v)
{
    std::string title = blank.getTitle(); // local for title truncation

    if (title.length() > 38)  // max length 38 chars
    {
        title = title.substr(0, 35) + "...";
    }

    std::cout << std::setfill('-') << std::setw(120) << "";
    std::cout << "\n" << std::setfill(' ') << std::setw(63) << "Serendipity Booksellers";
    std::cout << "\n" << std::setw(56) << "Add Book";
    std::cout << "\n" << std::setfill('-') << std::setw(121) << "";
    std::cout << "\n " << "Database Size: " << 20  // or capacity if you pass it in
              << std::setfill(' ') << std::setw(75)
              << "Book Count : " << v.size();
    std::cout << "\n\n" << std::setw(95) << "| Pending Values " << std::setw(26) << "\n";

    std::cout << "\n 1) Book Title:" << std::setw(65) << "| " << title;
    std::cout << "\n 2) ISBN:" << std::setw(71) << "| " << blank.getISBN();
    std::cout << "\n 3) Author:" << std::setw(69) << "| " << blank.getAuthor();
    std::cout << "\n 4) Publisher:" << std::setw(66) << "| " << blank.getPublisher();
    std::cout << "\n 5) Date Added (MM/DD/YYYY):" << std::setw(52) << "| " << blank.getDate();
    std::cout << "\n 6) Quantity on Hand:" << std::setw(59) << "| " << blank.getQty() << std::setw(29);
    std::cout << "\n 7) Wholesale Cost:" << std::setw(61) << "|$"
              << std::fixed << std::setprecision(2) << blank.getWholeCost();
    std::cout << "\n 8) Retail Price:" << std::setw(63) << "|$" << blank.getRetailCost();
    std::cout << "\n 9) Save Book to Database";
    std::cout << "\n 0) Return to Inventory Menu\n\n";
}
