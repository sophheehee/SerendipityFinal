/***************************
* Programmer: Sophia Omar
* Assignment: Serendipity G4
* Due Date: 11/18/2025
* Purpose: Delete Book Function Header
*****************************/
/**
 * @file deleteBook.h
 * @brief Declares the deleteBook function which removes a selected
 *        record from the inventory.
 */

#ifndef DELETE_BOOK_H
#define DELETE_BOOK_H

#include <vector>
#include "bookInfo.h"

/**
 * @brief Deletes a book from the inventory.
 *
 * This function allows the user to search for a book, select it,
 * display its details, and confirm deletion. If confirmed, the
 * record is erased from the vector and remaining entries shift to
 * fill the gap.
 *
 * @param database Reference to the inventory vector.
 *
 * @post If confirmed, inventory shrinks by one entry.
 */
void deleteBook(std::vector<bookInfo>& database);

#endif
