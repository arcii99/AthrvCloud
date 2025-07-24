//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// struct for holding periodic table data
struct Element {
  char symbol[3];
  char name[30];
  int atomic_number;
};

// function for populating the periodic table
void init_periodic_table(struct Element periodic_table[]) {
  // data source: https://en.wikipedia.org/wiki/List_of_chemical_elements
  struct Element hydrogen = {"H", "Hydrogen", 1};
  periodic_table[0] = hydrogen;

  struct Element helium = {"He", "Helium", 2};
  periodic_table[1] = helium;

  struct Element lithium = {"Li", "Lithium", 3};
  periodic_table[2] = lithium;

  // add more elements as needed
}

// function for getting input from user
void get_input(char *input) {
  printf("Enter your selection: ");
  scanf("%s", input);
}

// function for checking if input is valid
bool is_valid_input(char *input) {
  if (strlen(input) != 1) {
    printf("Invalid input. Please enter a single character.\n");
    return false;
  }

  if (input[0] < 'A' || input[0] > 'Z') {
    printf("Invalid input. Please enter a capital letter.\n");
    return false;
  }

  return true; // input is valid
}

// function for finding an element in the periodic table
struct Element find_element(char *input, struct Element periodic_table[]) {
  int atomic_number = input[0] - 'A' + 1;
  return periodic_table[atomic_number - 1];
}

int main() {
  // initialize periodic table
  struct Element periodic_table[118];
  init_periodic_table(periodic_table);

  while (true) {
    // display options to user
    printf("Select an element:\n");
    for (int i = 0; i < 118; i++) {
      printf("%s ", periodic_table[i].symbol);
      if (i % 10 == 9) { // line break after every 10 elements
        printf("\n");
      }
    }
    printf("\n");

    // get user input
    char input[2];
    get_input(input);

    // check if input is valid
    if (!is_valid_input(input)) {
      continue; // prompt user again
    }

    // find element in periodic table
    struct Element element = find_element(input, periodic_table);
    printf("You selected %s, which has an atomic number of %d.\n", element.name, element.atomic_number);
  }

  return 0; // never reached, but included for completeness
}