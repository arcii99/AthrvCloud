//FormAI DATASET v1.0 Category: Data mining ; Style: excited
// Welcome to the exciting world of data mining in C!
// In this program, we'll be exploring customer data from a grocery store.
// Our goal is to find patterns in customers' purchasing habits.
// Let's dive in!

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    int num_purchases;
    float avg_purchase_amt;
} customer;

int main() {

    // First, we'll create an array of customer data.
    customer customers[5] = {
        {"Alice", 28, 10, 38.75},
        {"Bob", 45, 5, 52.60},
        {"Charlie", 35, 12, 24.80},
        {"Dave", 50, 8, 17.20},
        {"Eve", 22, 20, 12.40}
    };

    printf("Welcome to our grocery store data mining program!\n");
    printf("We have data on %d customers.\n\n", sizeof(customers)/sizeof(customers[0]));

    // Next, let's find the average age of our customers.
    int total_age = 0;
    for (int i = 0; i < sizeof(customers)/sizeof(customers[0]); i++) {
        total_age += customers[i].age;
    }
    float avg_age = (float)total_age / (sizeof(customers)/sizeof(customers[0]));
    printf("The average age of our customers is %.1f.\n", avg_age);

    // Now, let's find the customer who makes the largest average purchase.
    float max_avg_purchase = 0;
    char max_avg_purchase_name[50] = "";
    for (int i = 0; i < sizeof(customers)/sizeof(customers[0]); i++) {
        if (customers[i].avg_purchase_amt > max_avg_purchase) {
            max_avg_purchase = customers[i].avg_purchase_amt;
            strcpy(max_avg_purchase_name, customers[i].name);
        }
    }
    printf("The customer who makes the largest average purchase is %s, with an average purchase of $%.2f.\n", max_avg_purchase_name, max_avg_purchase);

    // Lastly, let's find the total number of purchases made by customers under the age of 30.
    int num_purchases_under_30 = 0;
    for (int i = 0; i < sizeof(customers)/sizeof(customers[0]); i++) {
        if (customers[i].age < 30) {
            num_purchases_under_30 += customers[i].num_purchases;
        }
    }
    printf("Customers under the age of 30 made a total of %d purchases.\n", num_purchases_under_30);

    return 0;
}