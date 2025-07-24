//FormAI DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data for each row of the table
struct Person {
  int id;
  char name[50];
  int age;
};

// Function to print the details of a person
void printPerson(struct Person p) {
  printf("ID: %d\n", p.id);
  printf("Name: %s\n", p.name);
  printf("Age: %d\n", p.age);
  printf("---------------------\n");
}

int main() {
  // Array of persons to represent the table in the database
  struct Person persons[5] = {
    {1, "Bob", 25},
    {2, "Alice", 30},
    {3, "Charlie", 22},
    {4, "David", 35},
    {5, "Emily", 28}
  };
  
  // Print all persons in the table
  printf("All Persons:\n");
  for (int i = 0; i < 5; i++) {
    printPerson(persons[i]);
  }
  
  // Get details of person with id = 3
  int wantedID = 3;
  printf("Details of person with ID %d:\n", wantedID);
  for (int i = 0; i < 5; i++) {
    if (persons[i].id == wantedID) {
      printPerson(persons[i]);
      break;
    }
  }
  
  // Get details of all persons with age >= 30
  int wantedAge = 30;
  printf("Details of all persons with age >= %d\n", wantedAge);
  for (int i = 0; i < 5; i++) {
    if (persons[i].age >= wantedAge) {
      printPerson(persons[i]);
    }
  }
  
  // Get details of all persons with name starting with 'B'
  char wantedNameStart = 'B';
  printf("Details of all persons with name starting with '%c'\n", wantedNameStart);
  for (int i = 0; i < 5; i++) {
    if (persons[i].name[0] == wantedNameStart) {
      printPerson(persons[i]);
    }
  }
  
  return 0;
}