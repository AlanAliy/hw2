#include "user.h"
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << balance_ << " " << type_ << endl;
}

//add to back in adding to cart, while not adding members,
//always use front

void User::addToCart(Product* p)
{
    cartptr_.push_back(p);
}

std::deque<Product*> User::getCart() {
    return cartptr_;
}

void User::buyCart() 
{
    std::deque<Product*> temp;
    for (int i = cartptr_.size() - 1 ; i >= 0; i--) {
        Product* prodPtr = cartptr_.at(i);
        if((prodPtr->getPrice() <= balance_) && (0 < prodPtr->getQty())) {
            prodPtr->subtractQty(1);
            balance_ = balance_ - prodPtr->getPrice();
        }
        else {
            temp.push_back(prodPtr);
        }
    }
    cartptr_ = temp;
}