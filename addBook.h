/***************************************************
* Programmer: Sophia Omar
* Assignment: G3 -- Add & Look Up Book
* Due Date: 14 October 2025
* Purpose: Header File for addBook Function
*****************************************************/
/**
 * @file addBook.h
 * @brief Declares the addBook function for inserting new book records
 *        into the Serendipity inventory system.
 *
 * The addBook function provides a menu-driven interface for entering
 * book information, validating data, preventing duplicate ISBNs,
 * and appending a completed book record into the inventory vector.
 */

#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <vector>
#include "bookInfo.h"
#include "invmenu.h"

/**
 * @brief Adds a new book to the inventory.
 *
 * This function interacts with the user to populate all fields of a
 * new bookInfo record (title, author, ISBN, etc.). It performs validation
 * on numeric fields, checks for duplicate ISBNs, and only appends the
 * record to the inventory if the user chooses to save it.
 *
 * @param inventory Reference to the vector storing all book records.
 * @param capacity Maximum allowed number of books in the system
 *                 (default = 20).
 *
 * @pre `inventory.size() <= capacity`
 * @post If saved, a fully populated bookInfo record is appended to inventory.
 */
void addBook(std::vector<bookInfo>& inventory, std::size_t capacity = 20);

#endif
