//FormAI DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>

int main() {
  // Define arrays to hold example customer data
  float purchases[10] = {12.50, 8.75, 17.20, 23.00, 9.99, 14.00, 7.85, 16.75, 18.25, 21.50};
  int customer_ids[10] = {1234, 5678, 9012, 3456, 7890, 2345, 6789, 1203, 4567, 8901};

  // Calculate the average purchase amount
  float total_spent = 0;
  for (int i = 0; i < 10; i++) {
    total_spent += purchases[i];
  }
  float average_purchase = total_spent / 10;
  printf("The average purchase amount is $%.2f\n", average_purchase);

  // Find the customer with the highest purchase amount
  float highest_purchase = 0;
  int highest_purchase_customer_id;
  for (int i = 0; i < 10; i++) {
    if (purchases[i] > highest_purchase) {
      highest_purchase = purchases[i];
      highest_purchase_customer_id = customer_ids[i];
    }
  }
  printf("Customer %d had the highest purchase amount of $%.2f\n", highest_purchase_customer_id, highest_purchase);

  // Count the number of customers who spent more than $15
  int num_big_spenders = 0;
  for (int i = 0; i < 10; i++) {
    if (purchases[i] > 15) {
      num_big_spenders++;
    }
  }
  printf("%d customers spent more than $15\n", num_big_spenders);

  return 0;
}