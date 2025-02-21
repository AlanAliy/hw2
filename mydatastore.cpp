#include "mydatastore.h"
#include "util.h"
#include "product.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "user.h"
#include <stdexcept>
#include <unordered_map>

using std::string;

void MyDataStore::addProduct(Product* p) {
    productsPtr_.push_back(p);
}

void MyDataStore::addUser(User* u) {
    usersPtr_[convToLower(u->getName())] = u;
}

MyDataStore::~MyDataStore() {
    for (Product* prod: productsPtr_) {
        delete prod;
    }

    for (auto& pair: usersPtr_) {
        delete pair.second;
    }
}

void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>" << std::endl;
    
    for(Product* prod: productsPtr_) {
        prod->dump(ofile);
    }
    
    ofile << "</products>" << std::endl;
    ofile << "<users>" << std::endl;

    for(auto& pair: usersPtr_) {
        pair.second->dump(ofile); 
    }
    ofile << "</users>" << std::endl;

}


std::vector<Product*> MyDataStore::search(std::vector<string>& terms, int type) {
    
    bool oring = (type == 1);
    bool anding = (type == 0);

    std::vector<Product*> foundVals;
    std::set<string>keywords;

    //cheks if any of the terms are present in each products keywords set
    if (oring) {
        for (Product* prod: productsPtr_) {

            keywords = prod->keywords();
            for (string term: terms) {
                string termlow = convToLower(term);
                if(keywords.count(termlow) == 1) { 
                    foundVals.push_back(prod);
                    break;
                }
            }
        }
    }
    
    //checks if each product has the number of terms inputted inside its keywords set
    else if (anding) { 
        uint16_t termNum= terms.size();

        for (Product* prod: productsPtr_) {
            uint16_t counter = 0;
            std::set<string>keywordSet = prod->keywords();

            for (string& term: terms) {
                string termlow = convToLower(term);
                if(keywordSet.count(termlow) == 1) {
                counter++;
                } 
            }

            if(counter == termNum) {foundVals.push_back(prod);}
        }
    }

    else {throw std::invalid_argument("Type must be 1 or 2");}
    lastSearchResultPtr_.clear();
    lastSearchResultPtr_ = foundVals;
    return foundVals;
}

void MyDataStore::addCartSrch(uint16_t indx, std::string username, bool& error) {
    if ( indx < lastSearchResultPtr_.size()) {
        usersPtr_[convToLower(username)]->addToCart(lastSearchResultPtr_[indx]);
        error = false;
    }
    else {error = true;}

}

void MyDataStore::buyCart(std::string username, bool& error) {
    if (usersPtr_.find(convToLower(username)) != usersPtr_.end()){
    usersPtr_[convToLower(username)]->buyCart();
    error = false;
    }
    else {error = true;}
}

std::deque<Product*> MyDataStore::getUsrCart(string username,bool& error){
    if (usersPtr_.find(convToLower(username)) != usersPtr_.end()){
        error = false;
        return usersPtr_[convToLower(username)]->getCart();
    }
    else {
        error = 1;
        return  {};
        
    }
}