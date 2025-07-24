//FormAI DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>

#define NUM_RECORDS 100

typedef struct {
  int id;
  char name[50];
  int age;
} Record;

typedef struct {
  Record records[NUM_RECORDS];
  int num_records;
  int index[NUM_RECORDS];
} Database;

void initialize_database(Database* db) {
  db->num_records = 0;
  for (int i = 0; i < NUM_RECORDS; i++) {
    db->index[i] = -1;
  }
}

void add_record(Database* db, Record record) {
  db->records[db->num_records] = record;
  db->index[record.id] = db->num_records;
  db->num_records++;
}

Record* get_record(Database* db, int id) {
  int index = db->index[id];
  if (index == -1) {
    return NULL;
  } else {
    return &db->records[index];
  }
}

int main() {
  Database db;
  initialize_database(&db);

  Record record1 = {1, "Alice", 25};
  Record record2 = {2, "Bob", 30};

  add_record(&db, record1);
  add_record(&db, record2);

  Record* alice = get_record(&db, 1);
  printf("%s is %d years old.\n", alice->name, alice->age);

  Record* charlie = get_record(&db, 3);
  if (charlie == NULL) {
    printf("Record not found.\n");
  }

  return 0;
}