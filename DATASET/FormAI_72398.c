//FormAI DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to mimic the Database table structure
typedef struct {
  int id;
  char name[50];
  int age;
} Person;

int main() {
  // Define the array to store the Database records
  Person people[100];

  // Define the variables to get user input
  char input[50];
  int id, age;

  // Initialize the Database with some example data
  people[0].id = 1;
  strcpy(people[0].name, "John");
  people[0].age = 25;

  people[1].id = 2;
  strcpy(people[1].name, "Mary");
  people[1].age = 30;

  people[2].id = 3;
  strcpy(people[2].name, "Tom");
  people[2].age = 20;

  int num_people = 3;

  // Print the instructions for the user
  printf("Welcome to the Database simulator!\n");
  printf("You can add a new record with the 'add' command.\n");
  printf("You can search for a record with the 'search' command.\n");
  printf("You can delete a record with the 'delete' command.\n");
  printf("You can exit the program with the 'exit' command.\n");

  // Start the main loop for the program
  while (1) {
    // Get user input
    printf("Command: ");
    scanf("%s", input);

    // Handle the add command
    if (strcmp(input, "add") == 0) {
      printf("Enter the new person's name: ");
      scanf("%s", people[num_people].name);

      printf("Enter the new person's age: ");
      scanf("%d", &age);
      people[num_people].age = age;

      people[num_people].id = people[num_people-1].id + 1;

      printf("New person added with ID %d.\n", people[num_people].id);

      num_people++;
    }

    // Handle the search command
    else if (strcmp(input, "search") == 0) {
      printf("Enter the ID of the person you want to search for: ");
      scanf("%d", &id);

      int found = 0;

      for (int i = 0; i < num_people; i++) {
        if (people[i].id == id) {
          printf("Record found!\n");
          printf("ID: %d\n", people[i].id);
          printf("Name: %s\n", people[i].name);
          printf("Age: %d\n", people[i].age);
          found = 1;
        }
      }

      if (!found) {
        printf("Record not found.\n");
      }
    }

    // Handle the delete command
    else if (strcmp(input, "delete") == 0) {
      printf("Enter the ID of the person you want to delete: ");
      scanf("%d", &id);

      int found = 0;

      for (int i = 0; i < num_people; i++) {
        if (people[i].id == id) {
          printf("Record deleted!\n");
          found = 1;

          // Shift all the records after the deleted one back
          for (int j = i; j < num_people - 1; j++) {
            people[j] = people[j+1];
          }

          num_people--;
        }
      }

      if (!found) {
        printf("Record not found.\n");
      }
    }

    // Handle the exit command
    else if (strcmp(input, "exit") == 0) {
      printf("Exiting program.\n");
      return 0;
    }

    // Handle invalid commands
    else {
      printf("Invalid command.\n");
    }
  }
}