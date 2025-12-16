/***************************************************
* Programmer: Sophia Omar
* Assignment: G3 -- Add & Look Up Book
* Due Date: 14 October 2025
* Purpose: Header File for lookUp
*****************************************************/
/**
 * @file lookUp.h
 * @brief Declares lookup functions for retrieving books by title or ISBN.
 */

#ifndef LOOKUP_H
#define LOOKUP_H

#include <vector>
#include "bookInfo.h"

/**
 * @brief Unified lookup that searches by title (substring, case-insensitive)
 *        or by ISBN (exact match).
 *
 * @param database Reference to the inventory.
 * @return Index of the matched book, or -1 if no match.
 */
int lookUpBook(std::vector<bookInfo>& database);

/**
 * @brief Alternate lookup used by deleteBook to force returning an index.
 *
 * @param database Reference to inventory.
 * @param returnIndex When true, requires the function to always return
 *        a valid index or -1 on failure.
 * @return Index of selection or -1 if cancelled.
 */
int lookUpBookDEL(std::vector<bookInfo>& database, bool returnIndex);

#endif
