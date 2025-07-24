//FormAI DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

// A record struct doesn't need to be complex in this instance
typedef struct {
  int id;
  char name[MAX_NAME_LENGTH];
} Record;

// A simple database struct just needs to hold an array of records and the number of records
typedef struct {
  Record records[MAX_RECORDS];
  int num_records;
} Database;

// Define a function to insert a new record into the database
void insert(Record new_record, Database* db) {
  // Add the new record to the end of the array
  db->records[db->num_records] = new_record;
  db->num_records++;
}

// Define a function to print out the contents of the database
void print_database(Database db) {
  printf("ID\tName\n");
  for (int i = 0; i < db.num_records; i++) {
    printf("%d\t%s\n", db.records[i].id, db.records[i].name);
  }
}

// Define a function to search the database using a binary search
Record* binary_search(int target_id, Database db) {
  // Initialize the lower and upper bounds of the search
  int lower_bound = 0;
  int upper_bound = db.num_records - 1;

  // Loop until the lower and upper bounds meet
  while (lower_bound <= upper_bound) {
    // Calculate the midpoint of the search range
    int mid = (lower_bound + upper_bound) / 2;

    // Check if the midpoint record has the target ID
    if (db.records[mid].id == target_id) {
      // Return a pointer to the matching record
      return &(db.records[mid]);
    } else if (db.records[mid].id < target_id) {
      // If the midpoint ID is less than the target, adjust the lower bound
      lower_bound = mid + 1;
    } else {
      // If the midpoint ID is greater than the target, adjust the upper bound
      upper_bound = mid - 1;
    }
  }

  // If no matching record was found, return NULL
  return NULL;
}

int main() {
  // Initialize an empty database
  Database db;
  db.num_records = 0;

  // Insert some sample records
  insert((Record){1, "Alice"}, &db);
  insert((Record){2, "Bob"}, &db);
  insert((Record){3, "Charlie"}, &db);
  insert((Record){4, "David"}, &db);
  insert((Record){5, "Emily"}, &db);

  // Print out the contents of the database
  printf("Initial database:\n");
  print_database(db);

  // Search for a specific record
  int target_id = 3;
  Record* result = binary_search(target_id, db);
  if (result != NULL) {
    printf("Found record with ID %d: %s\n", target_id, result->name);
  } else {
    printf("No record with ID %d found\n", target_id);
  }

  return 0;
}