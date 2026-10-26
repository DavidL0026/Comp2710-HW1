#include "transaction.h"
#include <sstream>

using namespace std;

string transaction::transaction_info() {
    stringstream ss;

    ss << "Transaction #: " << transaction_number << "\n";
    ss << "Customer:\n";
    ss << customer.person_info();
    ss << "Product:\n";
    ss << purchased_item.product_info();
    ss << "Quantity: " << quantity << "\n";

    return ss.str();
}
