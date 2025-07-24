//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 1000

// Define a structure for the database records
typedef struct {
  int key;
  char value[20];
} Record;

// Define a structure for the index entries
typedef struct {
  int key;
  int position;
} Index;

// Define a structure for the indexing system
typedef struct {
  Index index[MAX_SIZE];
  int num_entries;
  pthread_mutex_t lock;
} IndexingSystem;

// Function to insert a record into the database
void insert_record(Record *db, IndexingSystem *indexer, int *num_records, int key, char *value) {
  // Add the record to the database
  db[*num_records].key = key;
  strcpy(db[*num_records].value, value);
  
  // Add an entry to the index
  pthread_mutex_lock(&indexer->lock);
  indexer->index[indexer->num_entries].key = key;
  indexer->index[indexer->num_entries].position = *num_records;
  indexer->num_entries++;
  pthread_mutex_unlock(&indexer->lock);
  
  // Increment the number of records
  (*num_records)++;
}

// Function to get a record from the database
Record *get_record(Record *db, IndexingSystem *indexer, int num_records, int key) {
  Record *result = NULL;
  
  // Search the index for the requested key
  for (int i = 0; i < indexer->num_entries; i++) {
    if (indexer->index[i].key == key) {
      // Found the key, get the position in the database
      int position = indexer->index[i].position;
      
      // Verify that the position is within the range of valid positions
      if (position >= 0 && position < num_records) {
        // Return a pointer to the record
        result = &db[position];
      }
      break;
    }
  }
  
  return result;
}

// Main function
int main() {
  // Create an array to hold database records
  Record db[MAX_SIZE];
  
  // Create an indexing system
  IndexingSystem indexer;
  indexer.num_entries = 0;
  pthread_mutex_init(&indexer.lock, NULL);
  
  // Initialize the number of records to 0
  int num_records = 0;
  
  // Insert some records into the database
  insert_record(db, &indexer, &num_records, 1, "Record 1");
  insert_record(db, &indexer, &num_records, 2, "Record 2");
  insert_record(db, &indexer, &num_records, 3, "Record 3");
  
  // Get a record from the database
  Record *record = get_record(db, &indexer, num_records, 2);
  if (record != NULL) {
    printf("Record Key: %d\n", record->key);
    printf("Record Value: %s\n", record->value);
  } else {
    printf("Record not found\n");
  }
  
  // Clean up the indexing system
  pthread_mutex_destroy(&indexer.lock);
  
  return 0;
}