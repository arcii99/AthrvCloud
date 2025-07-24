//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a person
typedef struct {
  int id;
  char name[50];
  int age;
} Person;

#define MAX_PEOPLE 1000

// Define a struct to represent the entire database
typedef struct {
  Person people[MAX_PEOPLE];
  int count;
} Database;

// Initialize an empty database
void init_database(Database *db) {
  db->count = 0;
}

// Add a person to the database
void add_person(Database *db, int id, const char *name, int age) {
  // Create a new person
  Person new_person = { id, "", age };
  strncpy(new_person.name, name, sizeof(new_person.name) - 1);
  
  // Add the person to the database
  db->people[db->count] = new_person;
  db->count++;
}

// Find a person by ID
Person *find_person_by_id(Database *db, int id) {
  for (int i = 0; i < db->count; i++) {
    if (db->people[i].id == id) {
      return &db->people[i];
    }
  }
  return NULL;
}

// Print out a person's information
void print_person(Person *person) {
  printf("%d: %s, %d\n", person->id, person->name, person->age);
}

// Print out the entire database
void print_database(Database *db) {
  printf("People in database:\n");
  for (int i = 0; i < db->count; i++) {
    print_person(&db->people[i]);
  }
}

int main() {
  // Create and initialize the database
  Database db;
  init_database(&db);
  
  // Add some people to the database
  add_person(&db, 1, "Alice", 25);
  add_person(&db, 2, "Bob", 30);
  add_person(&db, 3, "Charlie", 35);
  
  // Print out the entire database
  print_database(&db);
  
  // Find a person by ID and print their information
  Person *p = find_person_by_id(&db, 2);
  if (p != NULL) {
    printf("Found person with ID 2: ");
    print_person(p);
  } else {
    printf("Could not find person with ID 2\n");
  }
  
  return 0;
}