

#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"

using namespace std;

string Book::getAuthor() const {
    return author_;
}

string Book::getIsbn() const {
    return isbn_;
}

set<string> Book::keywords() const {
    set<string>key_name = parseStringToWords(getName());
    set<string>key_author = parseStringToWords(getAuthor());
    
    set<string>key_all = setUnion(key_name, key_author);
    key_all.insert(isbn_);

    return key_all;
}

void Book::dump(ostream& os) const {
    Product::dump(os);
    os << getIsbn() << "\n" << getAuthor()  << endl;

}

string Book::displayString() const {
    ostringstream os;
    os << fixed << setprecision(2) << getPrice();
    
    string toDisplay = getName() + "\n" +
                     "Author: " + getAuthor() + " " +  "ISBN: " + getIsbn() + "\n" + 
                     os.str() + " " + to_string(getQty()) + "left" + "\n";
    return toDisplay;
}
