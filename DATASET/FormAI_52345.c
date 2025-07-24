//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include<stdio.h>
 
int main()
{
    int customer_count;
    double item_price, total_price, discount, tax, final_price;
    char customer_name[50], date[15];
 
    printf("Enter name of the customer: ");
    scanf("%s", &customer_name);
 
    printf("Enter date of purchase (dd/mm/yyyy): ");
    scanf("%s", &date);
 
    printf("Enter number of items purchased: ");
    scanf("%d", &customer_count);
 
    printf("Enter price of item: ");
    scanf("%lf", &item_price);
 
    total_price = customer_count * item_price;
 
    if(total_price > 500)
    {
        discount = total_price * 0.1;
    }
    else
    {
        discount = 0;
    }
 
    tax = total_price * 0.05;
 
    final_price = total_price - discount + tax;
 
    printf("\n*********************************\n");
    printf("Customer Name: %s\n", customer_name);
    printf("Date of Purchase: %s\n", date);
    printf("Number of Items Purchased: %d\n", customer_count);
    printf("Price per Item: $%.2lf\n", item_price);
    printf("Total Price: $%.2lf\n", total_price);
    printf("Discount: $%.2lf\n", discount);
    printf("Tax: $%.2lf\n", tax);
    printf("Final Price: $%.2lf\n", final_price);
    printf("\n*********************************\n");
 
    return 0;
}