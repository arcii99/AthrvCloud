//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define a structure for a database record
struct Record {
  int id;
  char name[20];
  float salary;
};

//define a structure for the database
struct Database {
  int size;
  int next_id;
  struct Record records[10];
};

//add a record to the database
void add_record(struct Database *db, char *name, float salary) {
  db->records[db->size].id = db->next_id;
  strcpy(db->records[db->size].name, name);
  db->records[db->size].salary = salary;
  db->size++;
  db->next_id++;
}

//print the database records
void print_database(struct Database *db) {
  printf("ID\tName\tSalary\n");
  for(int i = 0; i < db->size; i++) {
    printf("%d\t%s\t%.2f\n", db->records[i].id, db->records[i].name, db->records[i].salary);
  }
}

int main() {
  struct Database db;
  db.size = 0;
  db.next_id = 1;

  //add some records to the database
  add_record(&db, "John", 50000.0);
  add_record(&db, "Jane", 60000.0);
  add_record(&db, "Bob", 70000.0);

  //print the database
  print_database(&db);

  return 0;
}