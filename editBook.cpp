#include <iostream>
#include <cctype>
#include <vector>
#include <iomanip>
#include <string>
#include "editBook.h"
#include "lookUp.h"
#include "bookInfo.h"
#include "utilities.h"      // <-- for clear()

// Truncate long strings for display
std::string truncString(const std::string& str, std::size_t max)
{
    if (str.length() <= max)
        return str;

    if (max <= 3)
        return str.substr(0, max);   // safety

    return str.substr(0, max - 3) + "...";
}

void showRecord(const bookInfo& b)
{
    const int MAX = 30;

    std::cout << "\nCurrent record:\n";

    std::cout << "  1) " << std::left << std::setw(17) << "Title:"
              << truncString(b.getTitle(), MAX) << '\n';

    std::cout << "  2) " << std::left << std::setw(17) << "ISBN:"
              << truncString(b.getISBN(), MAX) << '\n';

    std::cout << "  3) " << std::left << std::setw(17) << "Author:"
              << truncString(b.getAuthor(), MAX) << '\n';

    std::cout << "  4) " << std::left << std::setw(17) << "Publisher:"
              << truncString(b.getPublisher(), MAX) << '\n';

    std::cout << "  5) " << std::left << std::setw(17) << "Date Added:"
              << truncString(b.getDate(), MAX) << '\n';

    std::cout << "  6) " << std::left << std::setw(17) << "Quantity on Hand:"
              << b.getQty() << '\n';

    std::cout << "  7) " << std::left << std::setw(17) << "Wholesale:"
              << b.getWholeCost() << '\n';

    std::cout << "  8) " << std::left << std::setw(17) << "Retail:"
              << b.getRetailCost() << '\n';
}

void showEditMenu()
{
    std::cout << "\nEdit Book Menu\n"
              << "  1) Title\n"
              << "  2) ISBN\n"
              << "  3) Author\n"
              << "  4) Publisher\n"
              << "  5) Date Added\n"
              << "  6) Quantity on Hand\n"
              << "  7) Wholesale\n"
              << "  8) Retail\n"
              << "  9) Save\n"
              << "  0) Cancel\n"
              << "Choice: ";
}


void editBook(std::vector<bookInfo>& inventory)
{
    // 1. If no books, bail immediately
    if (inventory.empty())
    {
        clear();    // keep experience consistent
        std::cout << "\nNo books in inventory.\n";
        return;
    }

    bool edit = true;

    while (edit)
    {
        // Fresh screen for each lookup cycle
        clear();

        // 2. Get index from lookup  (-1 if user cancels / not found)
        int idx = lookUpBookDEL(inventory, true);

        // 3. Handle not-found / cancel case according to the spec
        if (idx == -1)
        {
            std::cout << "\nBook not found.\n";

            char again;
            while (true)
            {
                std::cout << "Edit another? (y/n): ";
                if (std::cin >> again)
                {
                    std::cin.ignore(1000, '\n');
                    again = static_cast<char>(
                        std::tolower(static_cast<unsigned char>(again)));
                    if (again == 'y' || again == 'n')
                        break;
                }
                std::cout << "  !! Please enter y or n.\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

            if (again == 'n')
            {
                // return to inventory menu caller
                return;
            }
            else
            {
                // go back to lookup another book
                continue;
            }
        }

        // extra safety: if somehow idx is out of range, just bail
        if (idx < 0 || static_cast<std::size_t>(idx) >= inventory.size())
        {
            std::cout << "Internal error: invalid index from lookUpBook.\n";
            return;
        }

        // 4. At this point, idx must be valid
        bookInfo original = inventory[idx];
        bookInfo temp = original;

        bool done = false; // to exit editing this book

        while (!done)
        {
            // Clear before showing the record + menu so they’re always at the top
            clear();

            showRecord(temp);
            showEditMenu();

            char choice;
            if (!(std::cin >> choice))
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input.\n";
                continue;
            }
            std::cin.ignore(1000, '\n');      // eat newline

            switch (choice)
            {
            case '1': // title
            {
                std::string s;
                std::cout << "Current Title: " << temp.getTitle() << '\n';
                std::cout << "New Title: ";
                std::getline(std::cin, s);
                temp.setTitle(s);
                break;
            }

            case '2': // ISBN (string, handle duplicates)
            {
                std::string s;
                std::cout << "Current ISBN: " << temp.getISBN() << '\n';
                std::cout << "New ISBN: ";
                std::getline(std::cin, s);

                if (s == temp.getISBN())
                    break; // nothing changed

                bool dup = false;
                for (std::size_t i = 0; i < inventory.size(); ++i)
                {
                    if (static_cast<int>(i) == idx)
                        continue;

                    if (inventory[i].getISBN() == s)
                    {
                        dup = true;
                        break;
                    }
                }

                if (dup)
                {
                    std::cout << "WARNING: Another record already uses this ISBN.\n";
                    char ok;
                    while (true)
                    {
                        std::cout << "Keep this duplicate ISBN anyway? (y/n): ";
                        if (std::cin >> ok)
                        {
                            std::cin.ignore(1000, '\n');
                            ok = static_cast<char>(
                                std::tolower(static_cast<unsigned char>(ok)));
                            if (ok == 'y' || ok == 'n')
                                break;
                        }
                        std::cout << "  !! Please enter y or n.\n";
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                    }
                    if (ok == 'n')
                    {
                        std::cout << "ISBN change cancelled.\n";
                        break;
                    }
                }

                temp.setISBN(s);
                break;
            }

            case '3': // Author
            {
                std::string s;
                std::cout << "Current Author: " << temp.getAuthor() << '\n';
                std::cout << "New Author: ";
                std::getline(std::cin, s);
                temp.setAuthor(s);
                break;
            }

            case '4': // Publisher
            {
                std::string s;
                std::cout << "Current Publisher: " << temp.getPublisher() << '\n';
                std::cout << "New Publisher: ";
                std::getline(std::cin, s);
                temp.setPublisher(s);
                break;
            }

            case '5': // Date Added (string)
            {
                std::string s;
                std::cout << "Current Date Added: " << temp.getDate() << '\n';
                std::cout << "New Date Added: ";
                std::getline(std::cin, s);
                temp.setDate(s);
                break;
            }

            case '6': // Quantity on hand: int >= 0
            {
                std::cout << "Current Quantity: " << temp.getQty() << '\n';

                int q;
                while (true)
                {
                    std::cout << "New Quantity (>= 0): ";
                    if (std::cin >> q && q >= 0)
                    {
                        std::cin.ignore(1000, '\n');
                        break;
                    }
                    std::cout << "  !! Please enter an integer >= 0.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }

                temp.setQty(q);
                break;
            }

            case '7': // Wholesale: float >= 0.0
            {
                std::cout << "Current Wholesale: " << temp.getWholeCost() << '\n';

                float w;
                while (true)
                {
                    std::cout << "New Wholesale (>= 0.0): ";
                    if (std::cin >> w && w >= 0.0f)
                    {
                        std::cin.ignore(1000, '\n');
                        break;
                    }
                    std::cout << "  !! Please enter a number >= 0.0.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }

                temp.setWholeCost(w);
                break;
            }

            case '8': // Retail: float >= 0.0
            {
                std::cout << "Current Retail: " << temp.getRetailCost() << '\n';

                float r;
                while (true)
                {
                    std::cout << "New Retail (>= 0.0): ";
                    if (std::cin >> r && r >= 0.0f)
                    {
                        std::cin.ignore(1000, '\n');
                        break;
                    }
                    std::cout << "  !! Please enter a number >= 0.0.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }

                temp.setRetailCost(r);
                break;
            }

            case '9': // Save changes
            {
                inventory[idx] = temp;   // apply staged changes
                std::cout << "\nChanges saved.\n";
                done = true;
                break;
            }

            case '0': // Cancel changes
            {
                std::cout << "\nEdit cancelled. Original record kept.\n";
                done = true;
                break;
            }

            default:
                std::cout << "Please choose 0-9.\n";
                break;
            }
        }

        // After save/cancel, ask to edit another
        char again;
        while (true)
        {
            std::cout << "\nEdit another book? (y/n): ";
            if (std::cin >> again)
            {
                std::cin.ignore(1000, '\n');
                again = static_cast<char>(
                    std::tolower(static_cast<unsigned char>(again)));
                if (again == 'y' || again == 'n')
                    break;
            }
            std::cout << "  !! Please enter y or n.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        edit = (again == 'y');
        // On next loop iteration, clear() will run before the next lookup
    }
}
