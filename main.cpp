#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using namespace std;

int main()
{
    Store store1;

    ifstream people_file("people.txt");
    ifstream products_file("products.txt");
    ifstream credit_file("credit_card.txt");

    if (!people_file.is_open() || !products_file.is_open()
        || !credit_file.is_open()) {
        cout << "Error opening input files." << endl;
        return 1;
    }

    int num_people;
    people_file >> num_people;
    people_file.ignore();

    for (int i = 0; i < num_people; i++) {
        string name;
        string phone;
        address addr;

        getline(people_file, name);
        getline(people_file, phone);
        getline(people_file, addr.address_line1);
        getline(people_file, addr.address_line2);
        getline(people_file, addr.city);
        getline(people_file, addr.state);
        getline(people_file, addr.zip);

        credit_card card = {};
        Person customer(name, phone, addr, card);

        store1.add_customer(customer);
    }

    int num_products;
    products_file >> num_products;
    products_file.ignore();

    for (int i = 0; i < num_products; i++) {
        product item;

        getline(products_file, item.name);
        getline(products_file, item.description);
        products_file >> item.price;
        products_file.ignore();

        store1.add_product(item);
    }

    int num_cards;
    credit_file >> num_cards;
    credit_file.ignore();

    for (int i = 0; i < num_cards; i++) {
        string name;
        credit_card card;

        getline(credit_file, name);
        credit_file >> card.cc_number;
        credit_file >> card.limit;
        credit_file >> card.current_balance;
        credit_file.ignore();

        for (int j = 0; j < store1.num_customers(); j++) {
            Person customer = store1.get_customer(j);

            if (customer.name() == name) {
                customer.person_credit_card(card);
                store1.update_customer(j, customer);
                break;
            }
        }
    }

    people_file.close();
    products_file.close();
    credit_file.close();

    cout << "Store info: " << endl << endl;
    cout << store1.store_info() << endl << endl;

    srand(time(0));

    int number_of_transactions = rand() % 89 + 11;

    for (int i = 0; i < number_of_transactions; i++) {
        int customer_index = rand() % store1.num_customers();
        int product_index = rand() % store1.num_products();
        int quantity = rand() % 10 + 1;

        Person customer = store1.get_customer(customer_index);
        product item = store1.get_product(product_index);

        bool success = store1.make_purchase(customer, item, quantity);

        if (success) {
            cout << "Successfull transaction!" << endl;
            cout << "Transaction Details:" << endl;

            transaction current_transaction =
                store1.get_transaction(store1.num_transactions() - 1);

            cout << current_transaction.transaction_info() << endl;
        }
        else {
            cout << "Unsuccessfull transaction!" << endl;
            cout << "Transaction Details:" << endl;
            cout << "Person:" << endl;
            cout << customer.person_info();
            cout << "Product:" << endl;
            cout << item.product_info();
            cout << "Purchase Quantity: " << quantity << endl << endl;
        }
    }

    cout << "Store info: " << endl << endl;
    cout << store1.store_info() << endl << endl;

    return 0;
}
