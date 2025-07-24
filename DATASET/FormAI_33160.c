//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100 // Maximum number of records in the database
#define MAX_NAME_LENGTH 50 // Maximum length of a name in the database

// Data structure to represent a record in the database
typedef struct record {
  int id;
  char name[MAX_NAME_LENGTH];
  int age;
  double salary;
} Record;

// Data structure to represent the database
typedef struct database {
  Record records[MAX_RECORDS];
  int num_records;
} Database;

// Function to add a record to the database
void add_record(Database *db, Record r) {
  if (db->num_records < MAX_RECORDS) {
    db->records[db->num_records++] = r;
  } else {
    printf("Error: database is full\n");
  }
}

// Function to remove a record from the database
void remove_record(Database *db, int id) {
  int i, found = 0;
  for (i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      found = 1;
      break;
    }
  }
  if (found) {
    for (; i < db->num_records - 1; i++) {
      db->records[i] = db->records[i+1];
    }
    db->num_records--;
  } else {
    printf("Error: record not found\n");
  }
}

// Function to print all records in the database
void print_records(Database *db) {
  int i;
  printf("ID     Name                Age    Salary\n");
  printf("=========================================\n");
  for (i = 0; i < db->num_records; i++) {
    printf("%-5d %-20s %-6d %-10.2lf\n", db->records[i].id, db->records[i].name, db->records[i].age, db->records[i].salary);
  }
}

int main() {
  Database db = {0};
  Record r1 = {1, "John Doe", 25, 50000.0};
  Record r2 = {2, "Jane Doe", 30, 60000.0};
  Record r3 = {3, "Bob Smith", 35, 70000.0};

  add_record(&db, r1);
  add_record(&db, r2);
  add_record(&db, r3);

  print_records(&db);

  remove_record(&db, 2);

  print_records(&db);

  return 0;
}