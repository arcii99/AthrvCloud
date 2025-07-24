//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 12

typedef struct {
  char name[MAX_NAME_LEN];
  char phone[MAX_PHONE_LEN];
} Record;

Record *database[MAX_RECORDS];

void initialize_database() {
  int i;
  for (i = 0; i < MAX_RECORDS; i++) {
    database[i] = NULL;
  }
}

void add_record(char *name, char *phone) {
  int i;
  for (i = 0; i < MAX_RECORDS; i++) {
    if (database[i] == NULL) {
      database[i] = (Record *) malloc(sizeof(Record));
      strncpy(database[i]->name, name, MAX_NAME_LEN);
      strncpy(database[i]->phone, phone, MAX_PHONE_LEN);
      return;
    }
  }
  printf("Database is full\n");
}

void delete_record(char *name) {
  int i;
  for (i = 0; i < MAX_RECORDS; i++) {
    if (database[i] != NULL && strcmp(database[i]->name, name) == 0) {
      free(database[i]);
      database[i] = NULL;
      return;
    }
  }
  printf("Record not found\n");
}

void search_record(char *name) {
  int i;
  for (i = 0; i < MAX_RECORDS; i++) {
    if (database[i] != NULL && strcmp(database[i]->name, name) == 0) {
      printf("Name: %s, Phone: %s\n", database[i]->name, database[i]->phone);
      return;
    }
  }
  printf("Record not found\n");
}

void print_database() {
  int i;
  for (i = 0; i < MAX_RECORDS; i++) {
    if (database[i] != NULL) {
      printf("Name: %s, Phone: %s\n", database[i]->name, database[i]->phone);
    }
  }
}

int main() {
  initialize_database();

  add_record("John Doe", "555-1234");
  add_record("Jane Doe", "555-5678");
  add_record("Bob Smith", "555-9876");

  search_record("Jane Doe");
  search_record("Mary Johnson");

  delete_record("Jane Doe");

  print_database();

  return 0;
}