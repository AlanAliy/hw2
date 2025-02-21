#ifndef CLOTHING_H
#define CLOTHING_H


#include <string>
#include <iostream>
#include "product.h"
#include "util.h"

class Clothing: public Product {
public:
    Clothing(const std::string& category ,const std::string& name, double price, int qty, std::string& size, std::string& brand) 
        : Product(category, name, price, qty) 
        {
            clothSize_ = size;
            brand_ = brand;
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
    
    
    std::string getClothSize() const;
    std::string getBrand() const;


protected:
    std::string clothSize_;
    std::string brand_;
    
};

#endif