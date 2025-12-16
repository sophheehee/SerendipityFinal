
/*************************************
* Programmer: Christian Schoffstoll
* Assignment: G2 - Serendipity
* Due Date: 23 September 2025
* Purpose: Cashier Function Stubs
***************************************/
/**
 * @file cashier.h
 * @brief Declares functions used by the Serendipity cashier module.
 *
 * The cashier module calculates totals, prints receipts, and processes
 * the sale of a single book.
 */

#ifndef CASHIER_H
#define CASHIER_H

#include <string>

/**
 * @brief Main cashier driver function.
 *
 * Displays prompts to the user, collects book sale details, computes
 * totals, and prints a formatted receipt.
 *
 * @return Status code (0 on success).
 */
int cashier();

/**
 * @brief Prints a formatted receipt for a book sale.
 *
 * @param title Book title.
 * @param isbn Book ISBN.
 * @param qty Quantity purchased.
 * @param date Sale date.
 * @param wholesale Wholesale cost.
 * @param retail Retail price.
 * @param total Final calculated total.
 */
void printRecipt(std::string title, std::string isbn,
                 int qty, std::string date,
                 float wholesale, float retail, float total);

/**
 * @brief Calculates the total price of a sale.
 *
 * @param qty Quantity purchased.
 * @param retail Retail price per unit.
 * @param total Reference to the total to be written.
 * @return The final total.
 */
float calcTot(int qty, float retail, float& total);

#endif
