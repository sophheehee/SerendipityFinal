/***************************************************
* Programmer: Sophia Omar
* Assignment: G3 -- Add & Look Up Book
* Due Date: 14 October 2025
* Purpose: Helper functions/Utilities for Serendipity
*****************************************************/
/**
 * @file utilities.h
 * @brief Declares utility functions used for input validation,
 *        console control, and string manipulation.
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

/**
 * @brief Clears the console screen using escape sequences.
 */
void clear();

/**
 * @brief Pauses execution until the user presses Enter.
 */
void pauseEnter();

/**
 * @brief Reads a numeric choice within a bounded range.
 *
 * @param prompt Message displayed before input.
 * @param min Minimum acceptable value.
 * @param max Maximum acceptable value.
 * @return User-selected integer between min and max.
 */
int readChoice(const std::string& prompt, int min, int max);

/**
 * @brief Reads a yes/no (Y/N) response from the user.
 *
 * @param prompt Text displayed to user.
 * @return 'y' or 'n' (lowercase).
 */
char readYN(const std::string& prompt);

/**
 * @brief Reads an entire line from the user.
 *
 * @param prompt Text prompt shown before input.
 * @return The full string entered by the user.
 */
std::string readLine(const char* prompt);

/**
 * @brief Converts a string to lowercase.
 *
 * @param s Input string.
 * @return Lowercased version of the input.
 */
std::string toLowerString(std::string s);

#endif
