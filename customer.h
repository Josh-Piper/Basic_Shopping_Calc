#include "splashkit.h"

/**
 * 
 * 
 */
enum customer_rank_type
{
    NONE,
    DIAMOND,
    GOLD,
    SILVER
};

/**
 * 
 * 
 */
struct customer_data
{
    string                  username;
    int                     age;
    int                     mobile_number;
    customer_rank_type      rank;
};

/**
 * 
 * 
 */
customer_data create_customer();

/**
 * 
 * 
 */
void print_customer_rank_message(const customer_data &customer);

/**
 * 
 * 
 */
void check_customer_rank(customer_data &customer, double total);

/**
 * 
 * 
 */
string get_customer_rank_as_string(const customer_data &customer);

/**
 * 
 * 
 */
void print_exit_message(const customer_data& customer , bool purchased_anything);

/**
 * 
 * 
 */
void print_customers_order(const customer_data &customer, double total, double discounted_total);

/**
 * 
 * 
 */
double calculate_discount_total(const customer_data &customer ,double total);

/**
 * 
 * 
 */
void handle_customers_order(customer_data &customer);