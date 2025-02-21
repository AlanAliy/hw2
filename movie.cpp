#include "movie.h"
#include "util.h"
#include <sstream>
#include <iomanip>

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
    ostringstream os;
    os << fixed << setprecision(2) << getPrice();


    string toDisplay = getName() + "\n" +
                     "Genre: " + getGenre() + " " +  "Rating: " + getRating() + "\n" + 
                     os.str() + " " + to_string(getQty()) + "left" + "\n";
    return toDisplay;
}
