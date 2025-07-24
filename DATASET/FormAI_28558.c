//FormAI DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

/* Data structure to hold information about a customer */
typedef struct {
    int age;
    char gender;
    float income;
    int num_purchases;
} Customer;

void update_customer_info(Customer *customer, int age, char gender, float income, int num_purchases) {
    /* Update customer's age */
    customer->age = age;
    
    /* Update customer's gender */
    customer->gender = gender;
    
    /* Update customer's income */
    customer->income = income;
    
    /* Update customer's number of purchases */
    customer->num_purchases = num_purchases;
}

int main() {
    /* Create an array of customers */
    Customer customers[5];
    
    /* Update customer information */
    update_customer_info(&customers[0], 25, 'M', 50000.0, 10);
    update_customer_info(&customers[1], 30, 'F', 60000.0, 15);
    update_customer_info(&customers[2], 40, 'M', 80000.0, 20);
    update_customer_info(&customers[3], 50, 'F', 100000.0, 25);
    update_customer_info(&customers[4], 60, 'M', 120000.0, 30);
    
    /* Perform data mining operations */
    int total_num_purchases = 0;
    float total_income = 0.0;
    int max_age = 0;
    char max_gender = ' ';
    for(int i = 0; i < 5; i++) {
        /* Sum up total number of purchases and income */
        total_num_purchases += customers[i].num_purchases;
        total_income += customers[i].income;
        
        /* Check for max age and gender */
        if(customers[i].age > max_age) {
            max_age = customers[i].age;
            max_gender = customers[i].gender;
        }
    }
    
    /* Print data mining results */
    printf("Total number of purchases: %d\n", total_num_purchases);
    printf("Total income: %.2f\n", total_income);
    printf("Max age: %d\n", max_age);
    printf("Gender of oldest customer: %c\n", max_gender);
    
    return 0;
}