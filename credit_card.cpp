#include "credit_card.h"
#include <sstream>
#include <iomanip>

using namespace std;

bool credit_card::make_purchase(double purchase_amount) {
    if (purchase_amount <= 0) {
        return false;
    }

    if (current_balance + purchase_amount > limit) {
        return false;
    }

    current_balance += purchase_amount;
    return true;
}

bool credit_card::make_payment(double payment_amount) {
    if (payment_amount <= 0 || payment_amount > current_balance) {
        return false;
    }

    current_balance -= payment_amount;
    return true;
}

string credit_card::credit_card_info() {
    stringstream ss;

    ss << fixed << setprecision(2);
    ss << "Credit card number: " << cc_number << "\n";
    ss << "Credit Card Limit: $" << limit << "\n";
    ss << "Current Balance: $" << current_balance << "\n";

    return ss.str();
}
