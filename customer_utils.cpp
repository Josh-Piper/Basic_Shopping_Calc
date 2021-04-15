#ifndef CUSTOMER_UTILS_H
#define CUSTOMER_UTILS_H

#include "splashkit.h"
#include "terminal_user_input.h"
#include "customer_utils.h"

void print_greeting_message()
{
    write_line();
    write_line("===================================");
    write_line("Welcome to the Cashier Application");
    write_line("===================================");
    write_line();
}

bool check_customer_purchase_anything(vector<int> items)
{
    int id;
    for (int qty: items)
        if (qty == 0) id += 1;
    return (id != 4);
}

vector<int> get_customers_order_quantity()
{
    vector<int> result;
    result.push_back(read_integer("How many donuts would you like: ", 0, INT_MAX));
    result.push_back(read_integer("How many milkshakes would you like: ", 0, INT_MAX));
    result.push_back(read_integer("How many icecreams would you like: ", 0, INT_MAX));
    result.push_back(read_integer("How many fries would you like: ", 0, INT_MAX));
    return result;
}

double calculate_supercombo(const vector<int>& order_qty)
{
    double donuts_price = order_qty.at(0) * DONUT_PRICE;
    double milkshake_price = order_qty.at(1) * MILKSHAKE_PRICE;
    double ice_cream_price = order_qty.at(0) * ICE_CREAM_PRICE;
    double fries_price = order_qty.at(0) * FRIES_PRICE;
    return donuts_price + milkshake_price + ice_cream_price + fries_price;
}

#endif