#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "splashkit.h"
#include "terminal_user_input.h"
#include "customer.h"
#include "customer_utils.h"

using std::to_string;

customer_data create_customer()
{   
    static const int MINIMUM_AGE = 5;
    static const int MAXIMUM_AGE = 100;
    static const int MAX_PHONE_NUMBER_DIGITS = 10;

    customer_data result;
    result.rank = NONE;
    result.username = read_string("Please enter your name: ");
    result.age = read_integer("Please enter your age: ", MINIMUM_AGE, MAXIMUM_AGE);
    result.mobile_number = read_integer_with_length("Please enter your phone number: ", MAX_PHONE_NUMBER_DIGITS);
    return result;
}

void print_customer_rank_message(const customer_data &customer)
{
    string result;
    switch (customer.rank)
    {
        case DIAMOND: result = "Thanks! You are a DIAMOND member now!"; break;
        case GOLD: result = "Thanks! You are a GOLD member now!"; break;
        case SILVER: result = "Thanks! You are a SILVER member now!"; break;
        default: break;
    }
    write_line(result);
}

void check_customer_rank(customer_data &customer, double total)
{
    static const int TOTAL_NEEDED_FOR_DIAMOND_RANK = 30;
    static const int TOTAL_NEEDED_FOR_GOLD_RANK = 10;
    
    if (total >= TOTAL_NEEDED_FOR_DIAMOND_RANK) 
    {
        customer.rank = DIAMOND;
    } else if (total >= TOTAL_NEEDED_FOR_GOLD_RANK)
    {
        customer.rank = GOLD;
    } else
    {
        customer.rank = SILVER;
    }

    print_customer_rank_message(customer);
}

string get_customer_rank_as_string(const customer_data &customer)
{
    string result;
    switch (customer.rank)
    {
        case DIAMOND: result = "Diamond"; break;
        case GOLD: result = "Gold"; break;
        case SILVER: result = "Silver"; break;
        default: result = "Member"; break;
    }
    if (customer.rank != NONE) result += " Member";
    return result;
}

void print_exit_message(const customer_data& customer , bool purchased_anything)
{
    string msg = (purchased_anything) ? " buying lollies from " : " checking out ";

    write_line();
    write_line("===================================");
    write_line("It was nice serving you, " + customer.username);
    write_line("Your current rank is " + get_customer_rank_as_string(customer));
    write_line("Thank you for" + msg + " Cashier Application!");
    write_line("===================================");
    write_line();
}


void print_customers_order(const customer_data &customer, double total, double discounted_total)
{
    string rank = get_customer_rank_as_string(customer);
    write_line();
    write_line("Your total order comes to: $" + convert_to_string(total));

    if (customer.rank != NONE)
    {
         write_line("Wait you get a discount!");
        write_line("As a " + rank + " your order comes to : $" + convert_to_string(discounted_total));
    }
    write_line();
}

double calculate_discount_total(const customer_data &customer ,double total)
{
    static const double DIAMOND_DISCOUNT = 0.85;
    static const double GOLD_DISCOUNT = 0.90;
    static const double SILVER_DISCOUNT = 0.95;

    double result;
    switch (customer.rank)
    {
        case DIAMOND: result = total * DIAMOND_DISCOUNT; break;
        case GOLD: result = total * GOLD_DISCOUNT; break;
        case SILVER: result = total * SILVER_DISCOUNT; break;
        default: break;
    }
    return result;
}


void handle_customers_order(customer_data &customer)
{
    print_greeting_message();

    vector<int> order_qty = get_customers_order_quantity();
    if (!check_customer_purchase_anything(order_qty)) 
    { 
        print_exit_message(customer, false); 
        return;
    }

    double total = calculate_supercombo(order_qty);
    check_customer_rank(customer, total);

    double discounted_total = calculate_discount_total(customer ,total);
    print_customers_order(customer, total, discounted_total);

    print_exit_message(customer, true);
};

#endif