#include "movie.h"
#include "util.h"

using namespace std;

string Movie::getRating() const {
    return rating_;
}

string Movie::getGenre() const {
    return genre_;
}

set<string> Movie::keywords() const {
    set<string>key_name = parseStringToWords(getName());
    key_name.insert(convToLower(getGenre()));

    return key_name;
}

void Movie::dump(ostream& os) const {
    Product::dump(os);
    os << getGenre() << "\n" << getRating()  << endl;

}

string Movie::displayString() const {
    string toDisplay = getName() + "\n" +
                     "Genre: " + getGenre() + " " +  "Rating: " + getRating() + "\n" + 
                     to_string(getPrice()) + " " + to_string(getQty()) + "left" + "\n";
    return toDisplay;
}
