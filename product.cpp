#include "product.h"
#include <sstream>
#include <iomanip>

using namespace std;

string product::product_info() {
    stringstream ss;

    ss << fixed << setprecision(2);
    ss << "Name: " << name << "\n";
    ss << "Description: " << description << "\n";
    ss << "Price: $" << price << "\n";

    return ss.str();
}
