#include "splashkit.h"
#include "terminal_user_input.h"
#include "customer.h"
#include "customer_utils.h"

int main()
{
    customer_data customer = create_customer();
    handle_customers_order(customer);
    return 0;
}