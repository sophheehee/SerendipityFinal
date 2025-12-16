/*************************************
* Programmer: Sophia Omar
* Assignment: G2 -- Serendipity Menu
* Due Date: 23 September 2025
* Purpose: Inventory Menu Stubs
**************************************/
/**
 * @file invmenu.h
 * @brief Declares the inventory menu driver for Serendipity.
 */

#ifndef INVMENU_H
#define INVMENU_H

#include <vector>
#include "bookInfo.h"

/**
 * @brief Displays and controls the inventory menu.
 *
 * Presents options such as search, add, edit, and delete. Loops until
 * the user chooses to return to the main menu.
 *
 * @param database Reference to the inventory vector.
 */
void invMenu(std::vector<bookInfo>& database);

#endif
