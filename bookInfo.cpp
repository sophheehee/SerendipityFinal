#include "bookInfo.h"

	/*********** CONSTRUCTORS ***********/

	bookInfo::bookInfo() {

		title = "NOT SET";
		isbn = "NOT SET";
		author = "NOT SET";
		publisher = "NOT SET";
		date = "NOT SET";
		qty = 0;
		whole_cost = 0.0;
		retail_cost = 0.0;

	}

	/*********** SETTERS ***********/


	void bookInfo::setTitle(std::string t) {

		title = t;
		return;
	}

	void bookInfo::setISBN(std::string i) {

		isbn = i;
		return;
	}

	void bookInfo::setAuthor(std::string a) {

		author = a;
		return;
	}

	void bookInfo::setPublisher(std::string p) {

		publisher = p;
		return;
	}

	void bookInfo::setDate(std::string d) {

		date = d;
		return;
	}

	void bookInfo::setQty(int q) {

		qty = q;
		return;
	}

	void bookInfo::setWholeCost(float w) {

		whole_cost = w;
		return;
	}

	void bookInfo::setRetailCost(float r) {

		retail_cost = r;
		return;
	}

	/*********** GETTERS ***********/

	std::string bookInfo::getTitle() const {

		return title;
	}

	std::string bookInfo::getISBN() const {

		return isbn;
	}

	std::string bookInfo::getAuthor() const {
		
		return author;
	}

	std::string bookInfo::getPublisher() const {

		return publisher;
	}

	std::string bookInfo::getDate() const {

		return date;
	}

	int bookInfo::getQty() const {

		return qty;
	}

	float bookInfo::getWholeCost() const {

		return whole_cost;
	}

	float bookInfo::getRetailCost() const {

		return retail_cost;
	}
