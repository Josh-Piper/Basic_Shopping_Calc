#include "splashkit.h"
#include "terminal_user_input.h"

const double DONUT_PRICE = 3;
const double MILKSHAKE_PRICE = 4;
const double ICE_CREAM_PRICE = 2;
const double FRIES_PRICE = 3.5;

using std::to_string;

enum customer_rank_type
{
    NONE,
    DIAMOND,
    GOLD,
    SILVER
};

struct customer_data
{
    string                  username;
    int                     age;
    int                     mobile_number;
    customer_rank_type      rank;
};

customer_data create_customer()
{
    customer_data result;
    result.rank = NONE;
    result.username = read_string("Please enter your name: ");
    result.age = read_integer("Please enter your age: ", 5, 100);
    result.mobile_number = read_integer_with_length("Please enter your phone number: ", 10);
    return result;
}

string convert_to_string(double val)
{
    string str = to_string(val);
    int dp = str.find(".");
    return str.substr(0, dp + 3);
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
    if (total >= 30) 
    {
        customer.rank = DIAMOND;
    } else if (total >= 10)
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
        default: break;
    }
    result += " Member";
    return result;
}

void print_greeting_message()
{
    write_line();
    write_line("===================================");
    write_line("Welcome to the Cashier Application");
    write_line("===================================");
    write_line();
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

bool check_customer_purchase_anything(vector<int> items)
{
    int id;
    for (int qty: items)
        if (qty == 0) id += 1;
    return (id != 4);
}

void print_customers_order(const customer_data &customer, double total, double discounted_total)
{
    string rank = get_customer_rank_as_string(customer);
    write_line();
    write_line("Your total order comes to: " + convert_to_string(total));

    if (customer.rank != NONE)
    {
         write_line("Wait you get a discount!");
        write_line("As a " + rank + " your order comes to : " + convert_to_string(discounted_total));
    }
    write_line();
}

double calculate_discount_total(const customer_data &customer ,double total)
{
    double result;
    switch (customer.rank)
    {
        case DIAMOND: result = total * 0.85; break;
        case GOLD: result = total * 0.90; break;
        case SILVER: result = total * 0.95; break;
        default: break;
    }
    return result;
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

double calculate_supercombo(const vector<int>& order_qty )
{
    double donuts_price = order_qty.at(0) * DONUT_PRICE;
    double milkshake_price = order_qty.at(1) * MILKSHAKE_PRICE;
    double ice_cream_price = order_qty.at(0) * ICE_CREAM_PRICE;
    double fries_price = order_qty.at(0) * FRIES_PRICE;
    return donuts_price + milkshake_price + ice_cream_price + fries_price;
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
}


int main()
{
    customer_data customer = create_customer();
    handle_customers_order(customer);
    return 0;
}