#include "address.h"

using namespace std;

string address::address_info() {
    string info = "";

    info += address_line1 + "\n";
    info += address_line2 + "\n";
    info += city + "\n";
    info += state + "\n";
    info += zip + "\n";

    return info;
}
