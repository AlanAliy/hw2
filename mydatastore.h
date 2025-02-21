
#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include <unordered_map>


class MyDataStore : public DataStore{

public:
    ~MyDataStore() override;

    void addProduct(Product* p) override;

    void addUser(User* u) override;

    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;

    void dump(std::ostream& ofile) override;

    void addCartSrch(uint16_t indx, std::string username, bool& error) ;

    void buyCart(std::string username, bool& error);
    
    std::deque<Product*> getUsrCart (std::string username, bool& error) ;

private:
    std::vector<Product*> productsPtr_;
    std::unordered_map<std::string, User*> usersPtr_;
    std::vector<Product*> lastSearchResultPtr_;
    //std::set<std::string> users_;

};
#endif
