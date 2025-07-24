//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>

int main() {
  int coffee_price = 4; // price of a cup of coffee in dollars
  int num_coffees = 0; // number of coffees ordered

  printf("Welcome to the Cosmic Coffee Cafe!\n");

  while(1) { // infinite loop until the user decides to leave

    printf("What can we get for you today? Coffee is $4 a cup.\n");

    char order[100]; // buffer to store user input
    fgets(order, 100, stdin);

    if (strcmp(order, "exit\n") == 0) { // time to leave
      printf("Thanks for stopping by the Cosmic Coffee Cafe. Goodbye!\n");
      return 0;
    }

    if (strstr(order, "coffee") != NULL || strstr(order, "Coffee") != NULL) { // user orders coffee
      num_coffees++;
      printf("One coffee coming right up! That'll be $4, please.\n");
    } else { // user didn't order coffee
      printf("I'm sorry, I cannot process your request.\n");
    }

    printf("You have ordered %d coffees today.\n", num_coffees);
    printf("Your total comes to $%d.\n", num_coffees * coffee_price);
  }

  return 0;
}