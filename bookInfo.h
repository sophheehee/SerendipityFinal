#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/**
 * @file bookInfo.h
 * @brief Defines the bookInfo class used to store all information for
 *        a single book record within the Serendipity inventory system.
 *
 * The class stores metadata such as title, ISBN, author information,
 * quantity, and pricing. It provides setters and getters for controlled
 * access to private member variables.
 */

/**
 * @class bookInfo
 * @brief Represents a single book entry in the Serendipity inventory.
 *
 * A bookInfo object stores book metadata including identifying information
 * (title, author, ISBN), publication information (publisher, date added),
 * and inventory data (quantity on hand, wholesale and retail prices).
 */
class bookInfo {

private:
    std::string title;        ///< Book title
    std::string isbn;         ///< Book ISBN number
    std::string author;       ///< Book author's name
    std::string publisher;    ///< Publisher name
    std::string date;         ///< Date added to inventory
    int qty;                  ///< Quantity of copies available
    float whole_cost;         ///< Wholesale cost per book
    float retail_cost;        ///< Retail price per book

public:

    /**
     * @brief Default constructor initializing all fields to safe defaults.
     */
    bookInfo();

    /** @name Setters */
    ///@{

    /// @brief Sets the book title.
    void setTitle(std::string t);

    /// @brief Sets the ISBN value.
    void setISBN(std::string i);

    /// @brief Sets the author name.
    void setAuthor(std::string a);

    /// @brief Sets the publisher name.
    void setPublisher(std::string p);

    /// @brief Sets the date the book was added.
    void setDate(std::string d);

    /// @brief Sets the quantity on hand.
    void setQty(int q);

    /// @brief Sets the wholesale price.
    void setWholeCost(float w);

    /// @brief Sets the retail price.
    void setRetailCost(float r);

    ///@}

    /** @name Getters */
    ///@{

    /// @return The book's title.
    std::string getTitle() const;

    /// @return The book's ISBN.
    std::string getISBN() const;

    /// @return The author's name.
    std::string getAuthor() const;

    /// @return The publisher's name.
    std::string getPublisher() const;

    /// @return The date the book was added.
    std::string getDate() const;

    /// @return The quantity on hand.
    int getQty() const;

    /// @return The wholesale cost.
    float getWholeCost() const;

    /// @return The retail cost.
    float getRetailCost() const;

    ///@}
};

#endif
