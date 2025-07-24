//FormAI DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a record's key
#define MAX_KEY_LENGTH 20

// Define a structure to hold each record in the database
typedef struct {
  char key[MAX_KEY_LENGTH];
  int value;
} Record;

// Define a structure to hold the database and its index
typedef struct {
  Record records[MAX_RECORDS];
  int count;
  int index[MAX_RECORDS];
} Database;

// Define a function to insert a record into the database
void insertRecord(Database* db, char* key, int value) {
  // Make sure the database is not full
  if (db->count >= MAX_RECORDS) {
    printf("Error: Database is full\n");
    return;
  }

  // Create a new record with the given key and value
  Record newRecord;
  strcpy(newRecord.key, key);
  newRecord.value = value;

  // Find the correct position to insert the record based on its key
  int i;
  for (i = db->count - 1; i >= 0; i--) {
    if (strcmp(db->records[db->index[i]].key, key) < 0) {
      break;
    }
    db->index[i + 1] = db->index[i];
  }
  db->index[i + 1] = db->count;

  // Insert the record into the database and increment the count
  db->records[db->count] = newRecord;
  db->count++;
}

// Define a function to find a record in the database by its key
Record* findRecord(Database* db, char* key) {
  // Use a binary search to find the record with the given key
  int low = 0;
  int high = db->count - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int cmp = strcmp(db->records[db->index[mid]].key, key);
    if (cmp == 0) {
      return &db->records[db->index[mid]];
    } else if (cmp < 0) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return NULL;
}

// Define a main function to test the database indexing system
int main() {
  // Create a new database
  Database db;
  db.count = 0;

  // Insert some records into the database
  insertRecord(&db, "apple", 10);
  insertRecord(&db, "banana", 20);
  insertRecord(&db, "cherry", 30);

  // Find a record in the database and print its value
  Record* record = findRecord(&db, "banana");
  if (record != NULL) {
    printf("Value of banana is %d\n", record->value);
  } else {
    printf("Error: Record not found\n");
  }

  // Insert another record into the database
  insertRecord(&db, "orange", 40);

  // Find a record in the database and print its value
  record = findRecord(&db, "orange");
  if (record != NULL) {
    printf("Value of orange is %d\n", record->value);
  } else {
    printf("Error: Record not found\n");
  }

  // Insert a record with a duplicate key into the database
  insertRecord(&db, "cherry", 50);

  // Find a record in the database and print its value
  record = findRecord(&db, "cherry");
  if (record != NULL) {
    printf("Value of cherry is %d\n", record->value);
  } else {
    printf("Error: Record not found\n");
  }

  return 0;
}