#ifndef EDIT_BOOK_H
#define EDIT_BOOK_H

#include <vector>
#include "bookInfo.h"

/**
 * @file editBook.h
 * @brief Declares the editBook function which modifies fields of a
 *        selected book record from the inventory.
 */

/**
 * @brief Allows full editing of a selected book record.
 *
 * The user selects a book (via lookup), views all fields, and can
 * modify each field (title, ISBN, author, etc.) one at a time.
 * Changes are staged in a temporary record and applied only when
 * the user selects "Save".
 *
 * @param inventory Reference to the inventory vector.
 *
 * @post If saved, the selected entry in inventory is updated.
 */
void editBook(std::vector<bookInfo>& inventory);

#endif
