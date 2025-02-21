#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <deque>
#include "product.h"
#include "movie.h"
#include "clothing.h"
#include "book.h"

/**
 * Implements User functionality and information storage
 *  You should not need to derive anything from User at this time
 */

class User {
public:
    User();
    User(std::string name, double balance, int type);
    virtual ~User();

    double getBalance() const;
    std::string getName() const;
    void deductAmount(double amt);
    virtual void dump(std::ostream& os);
    void addToCart(Product* p);
    std::deque<Product*> getCart();
    void buyCart();

private:
    std::string name_;
    double balance_;
    int type_;
    //deque so I can use the advdantages of random acces but also pop
    //front and back with good efficiency
    std::deque<Product*> cartptr_;

};
#endif
