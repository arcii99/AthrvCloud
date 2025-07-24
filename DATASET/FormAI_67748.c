//FormAI DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define a structure to represent a record in the database
typedef struct {
  int id;
  char name[30];
  char email[50];
} Record;

// Declare an array to represent the database
Record database[MAX_RECORDS];

// Declare a variable to keep track of the number of records in the database
int num_records = 0;

// Function to add a new record to the database
void add_record(int id, char *name, char *email) {
  if (num_records >= MAX_RECORDS) {
    printf("Error: Database is full\n");
    return;
  }

  // Create a new record with the given information
  Record new_record = {id, "", ""};
  strncpy(new_record.name, name, 30);
  strncpy(new_record.email, email, 50);

  // Add the new record to the database
  database[num_records] = new_record;
  num_records++;

  printf("Record added to database\n");
}

// Function to print all records in the database
void print_records() {
  if (num_records == 0) {
    printf("Database is empty\n");
    return;
  }

  printf("ID\tName\tEmail\n");
  printf("----------------------------------------\n");

  for (int i = 0; i < num_records; i++) {
    Record record = database[i];
    printf("%d\t%s\t%s\n", record.id, record.name, record.email);
  }
}

// Function to search for a record with the given ID
Record *find_record(int id) {
  for (int i = 0; i < num_records; i++) {
    Record *record = &database[i];

    if (record->id == id) {
      return record;
    }
  }

  return NULL;
}

// Function to update a record with the given ID
void update_record(int id, char *name, char *email) {
  Record *record = find_record(id);

  if (record == NULL) {
    printf("Record not found\n");
    return;
  }

  strncpy(record->name, name, 30);
  strncpy(record->email, email, 50);

  printf("Record updated\n");
}

// Function to delete a record with the given ID
void delete_record(int id) {
  for (int i = 0; i < num_records; i++) {
    Record *record = &database[i];

    if (record->id == id) {
      // Shift all records after the deleted one over by one
      for (int j = i; j < num_records - 1; j++) {
        database[j] = database[j+1];
      }

      num_records--;
      printf("Record deleted\n");
      return;
    }
  }

  printf("Record not found\n");
}

int main() {
  // Add some sample records to the database
  add_record(1, "Alice", "alice@example.com");
  add_record(2, "Bob", "bob@example.com");
  add_record(3, "Charlie", "charlie@example.com");

  // Print the records in the database
  print_records();

  // Update a record
  update_record(2, "Bobby Jr.", "bobbyjr@example.com");
  print_records();

  // Delete a record
  delete_record(3);
  print_records();

  return 0;
}