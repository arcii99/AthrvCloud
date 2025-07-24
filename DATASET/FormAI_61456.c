//FormAI DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define a struct called Car
struct Car {
  char make[30];
  char model[30];
  int year;
  int price;
};

int main() {
  // Create an array of Car structs
  struct Car cars[5] = {
    {"Ford", "Mustang", 2018, 35000},
    {"Chevrolet", "Camaro", 2019, 38000},
    {"Dodge", "Challenger", 2020, 42000},
    {"Honda", "Civic", 2017, 25000},
    {"Toyota", "Corolla", 2016, 20000}
  };

  // Print out all the cars in the array
  printf("All cars:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s %s, %d, $%d\n",
      cars[i].make,
      cars[i].model,
      cars[i].year,
      cars[i].price
    );
  }

  // Print out the cheapest and most expensive cars
  int cheapestIndex = 0;
  int mostExpensiveIndex = 0;
  for (int i = 1; i < 5; i++) {
    if (cars[i].price < cars[cheapestIndex].price) {
      cheapestIndex = i;
    }
    if (cars[i].price > cars[mostExpensiveIndex].price) {
      mostExpensiveIndex = i;
    }
  }
  printf("\nCheapest car:\n%s %s, %d, $%d\n",
    cars[cheapestIndex].make,
    cars[cheapestIndex].model,
    cars[cheapestIndex].year,
    cars[cheapestIndex].price
  );
  printf("\nMost expensive car:\n%s %s, %d, $%d\n",
    cars[mostExpensiveIndex].make,
    cars[mostExpensiveIndex].model,
    cars[mostExpensiveIndex].year,
    cars[mostExpensiveIndex].price
  );

  return 0;
}