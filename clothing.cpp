
#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"

using namespace std;

string Clothing::getClothSize() const {
    return clothSize_;
}

string Clothing::getBrand() const {
    return brand_;
}

set<string> Clothing::keywords() const {
    set<string>key_name = parseStringToWords(getName());
    set<string>key_brand = parseStringToWords(getBrand());
    
    set<string>key_all = setUnion(key_name, key_brand);
    key_all.insert(clothSize_); //TODO maybe this isnt a keyword?

    return key_all;
}

void Clothing::dump(ostream& os) const {
    Product::dump(os);
    os << getClothSize() << "\n" << getBrand()  << endl;

}

string Clothing::displayString() const {
    ostringstream os;
    os << fixed << setprecision(2) << getPrice();

    string toDisplay = getName() + "\n" +
                     "Size: " + getClothSize() + " " +  "Brand: " + getBrand() + "\n" + 
                     os.str() + " " + to_string(getQty()) + "left" + "\n";
    return toDisplay;
}
