#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include "product.h"
#include "util.h"

class Movie: public Product {
public:
    Movie(const std::string& category ,const std::string& name, double price, int qty, const std::string& genre,const std::string& rating) 
        : Product(category, name, price, qty) 
        {
            genre_ = genre;
            rating_ = rating;
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
    
    std::string getGenre() const;
    std::string getRating() const;


protected:
    std::string genre_;
    std::string rating_;
    
};

#endif