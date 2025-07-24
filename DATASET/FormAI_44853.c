//FormAI DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent data table
typedef struct {
  int id;
  char name[10];
  int age;
} Person;

// Define a function to create a new person record
Person* newPerson(int id, char* name, int age) {
  Person* p = malloc(sizeof(Person));
  p->id = id;
  strcpy(p->name, name);
  p->age = age;
  return p;
}

int main() {
  // Create a sample data table
  Person* persons[5];
  persons[0] = newPerson(1, "Alice", 20);
  persons[1] = newPerson(2, "Bob", 22);
  persons[2] = newPerson(3, "Charlie", 25);
  persons[3] = newPerson(4, "David", 30);
  persons[4] = newPerson(5, "Emily", 21);

  // Query the data table
  printf("Query Result:\n");
  printf(" ID |  Name  | Age \n");
  printf("-------------------\n");
  for (int i = 0; i < 5; i++) {
    if (persons[i]->age < 25) {
      printf("%3d | %s | %d\n", persons[i]->id, persons[i]->name, persons[i]->age);
    }
  }

  // Cleanup the memory
  for (int i = 0; i < 5; i++) {
    free(persons[i]);
  }

  return 0;
}