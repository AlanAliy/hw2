#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "product.h"
#include "util.h"

class Book: public Product {
public:
    Book(const std::string& category ,const std::string& name, double price, int qty, std::string& book_isbn, std::string& book_author) 
        : Product(category, name, price, qty) 
        {
            isbn_ = book_isbn;
            author_ = book_author;
        }
        
    
    /**
     * Allows for a more detailed search beyond simple keywords
     */
    // bool isMatch(std::vector<std::string>& searchTerms) const override;


  
    /**
     * Returns the appropriate keywords that this product should be associated with
     */
    std::set<std::string> keywords() const override;
    
 
    /**
     * Outputs the product info in the database format
     */
    void dump(std::ostream& os) const override;

    
     /**
     * Returns a string to display the product info for hits of the search
     */
    std::string displayString() const  override;
    
    std::string getAuthor() const;
    std::string getIsbn() const;


protected:
    std::string author_;
    std::string isbn_;
    
};

#endif