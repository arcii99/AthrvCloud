//FormAI DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 1000
#define MAX_VALUES 1000

typedef struct {
  int key;
  char value[50];
} Record;

typedef struct {
  int count;
  Record records[MAX_VALUES];
} Bucket;

typedef struct {
  int count;
  Bucket* buckets[100];
} Table;

void add(Table* tbl, int key, char* value) {
  int hash = key % 100;
  Bucket* bucket = tbl->buckets[hash];

  // Create the bucket if it doesn't exist
  if (bucket == NULL) {
    bucket = malloc(sizeof(Bucket));
    bucket->count = 0;
    tbl->buckets[hash] = bucket;
  }

  // Add the record to the bucket
  Record record = { key, *value };
  bucket->records[bucket->count] = record;
  bucket->count++;
  tbl->count++;

  // Reallocate the bucket if we've run out of space
  if (bucket->count == MAX_VALUES) {
    Bucket* new_bucket = malloc(sizeof(Bucket));
    new_bucket->count = 0;
    tbl->buckets[hash] = new_bucket;
    for (int i = 0; i < MAX_VALUES; i++) {
      add(tbl, bucket->records[i].key, bucket->records[i].value);
    }
    free(bucket);
  }
}

char* get(Table* tbl, int key) {
  int hash = key % 100;
  Bucket* bucket = tbl->buckets[hash];

  // Search the bucket for the key
  for (int i = 0; i < bucket->count; i++) {
    Record record = bucket->records[i];
    if (record.key == key) {
      return record.value;
    }
  }

  return NULL;
}

int main(void) {
  Table* tbl = malloc(sizeof(Table));
  tbl->count = 0;

  add(tbl, 123, "value1");
  add(tbl, 456, "value2");
  add(tbl, 789, "value3");

  printf("%s\n", get(tbl, 123));
  printf("%s\n", get(tbl, 456));
  printf("%s\n", get(tbl, 789));

  return 0;
}