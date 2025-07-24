//FormAI DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct customer {
    int customer_id;
    char customer_name[50];
    float purchase_history[12];
    float happiness_level;
};

int main() {

    // create an array of customers
    struct customer customers[5];

    // initialize the customers with some sample data
    customers[0].customer_id = 1;
    strcpy(customers[0].customer_name, "Alice");
    customers[0].purchase_history[0] = 50.0;
    customers[0].purchase_history[1] = 30.0;
    customers[0].purchase_history[2] = 70.0;
    customers[0].purchase_history[3] = 90.0;
    customers[0].purchase_history[4] = 80.0;
    customers[0].purchase_history[5] = 60.0;
    customers[0].purchase_history[6] = 40.0;
    customers[0].purchase_history[7] = 20.0;
    customers[0].purchase_history[8] = 30.0;
    customers[0].purchase_history[9] = 60.0;
    customers[0].purchase_history[10] = 70.0;
    customers[0].purchase_history[11] = 80.0;

    customers[1].customer_id = 2;
    strcpy(customers[1].customer_name, "Bob");
    customers[1].purchase_history[0] = 10.0;
    customers[1].purchase_history[1] = 30.0;
    customers[1].purchase_history[2] = 20.0;
    customers[1].purchase_history[3] = 50.0;
    customers[1].purchase_history[4] = 40.0;
    customers[1].purchase_history[5] = 20.0;
    customers[1].purchase_history[6] = 30.0;
    customers[1].purchase_history[7] = 40.0;
    customers[1].purchase_history[8] = 50.0;
    customers[1].purchase_history[9] = 60.0;
    customers[1].purchase_history[10] = 40.0;
    customers[1].purchase_history[11] = 30.0;

    customers[2].customer_id = 3;
    strcpy(customers[2].customer_name, "Charlie");
    customers[2].purchase_history[0] = 50.0;
    customers[2].purchase_history[1] = 40.0;
    customers[2].purchase_history[2] = 60.0;
    customers[2].purchase_history[3] = 70.0;
    customers[2].purchase_history[4] = 80.0;
    customers[2].purchase_history[5] = 90.0;
    customers[2].purchase_history[6] = 80.0;
    customers[2].purchase_history[7] = 70.0;
    customers[2].purchase_history[8] = 60.0;
    customers[2].purchase_history[9] = 50.0;
    customers[2].purchase_history[10] = 40.0;
    customers[2].purchase_history[11] = 30.0;

    customers[3].customer_id = 4;
    strcpy(customers[3].customer_name, "David");
    customers[3].purchase_history[0] = 70.0;
    customers[3].purchase_history[1] = 80.0;
    customers[3].purchase_history[2] = 90.0;
    customers[3].purchase_history[3] = 80.0;
    customers[3].purchase_history[4] = 70.0;
    customers[3].purchase_history[5] = 60.0;
    customers[3].purchase_history[6] = 50.0;
    customers[3].purchase_history[7] = 40.0;
    customers[3].purchase_history[8] = 30.0;
    customers[3].purchase_history[9] = 20.0;
    customers[3].purchase_history[10] = 10.0;
    customers[3].purchase_history[11] = 20.0;

    customers[4].customer_id = 5;
    strcpy(customers[4].customer_name, "Emily");
    customers[4].purchase_history[0] = 30.0;
    customers[4].purchase_history[1] = 40.0;
    customers[4].purchase_history[2] = 30.0;
    customers[4].purchase_history[3] = 30.0;
    customers[4].purchase_history[4] = 40.0;
    customers[4].purchase_history[5] = 50.0;
    customers[4].purchase_history[6] = 60.0;
    customers[4].purchase_history[7] = 70.0;
    customers[4].purchase_history[8] = 80.0;
    customers[4].purchase_history[9] = 90.0;
    customers[4].purchase_history[10] = 80.0;
    customers[4].purchase_history[11] = 70.0;

    // calculate the happiness level for each customer based on their purchase history
    for (int i = 0; i < 5; i++) {
        float average_purchase = 0;
        for (int j = 0; j < 12; j++) {
            average_purchase += customers[i].purchase_history[j];
        }
        average_purchase = average_purchase / 12.0;

        float variance = 0;
        for (int j = 0; j < 12; j++) {
            variance += pow((customers[i].purchase_history[j] - average_purchase), 2);
        }
        variance = variance / 12.0;

        customers[i].happiness_level = (average_purchase - variance) / 10.0;
    }

    // print out the happiness level for each customer
    printf("Customer Happiness Levels:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s: %.2f\n", customers[i].customer_id, customers[i].customer_name, customers[i].happiness_level);
    }

    return 0;
}