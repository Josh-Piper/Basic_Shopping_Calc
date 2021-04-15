#include "splashkit.h"
#include "terminal_user_input.h"

const double DONUT_PRICE = 3;
const double MILKSHAKE_PRICE = 4;
const double ICE_CREAM_PRICE = 2;
const double FRIES_PRICE = 3.5;

/**
 * 
 * 
 */
void print_greeting_message();

/**
 * 
 * 
 */
bool check_customer_purchase_anything(vector<int> items);

/**
 * 
 * 
 */
vector<int> get_customers_order_quantity();

/**
 * 
 * 
 */
double calculate_supercombo(const vector<int>& order_qty);