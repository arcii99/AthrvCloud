//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These are the maximum lengths of each field
#define MAX_NAME_LENGTH 50
#define MAX_AGE_LENGTH 3
#define MAX_SALARY_LENGTH 10

// This is the maximum number of records that can be stored in the database
#define MAX_RECORDS 1000

// This is the size of each record in bytes
#define RECORD_SIZE (MAX_NAME_LENGTH + MAX_AGE_LENGTH + MAX_SALARY_LENGTH)

// This struct represents a single record in the database
typedef struct {
  char name[MAX_NAME_LENGTH]; // name of the employee
  int age; // age of the employee
  float salary; // salary of the employee
} Employee;

// This struct represents the entire database
typedef struct {
  Employee records[MAX_RECORDS]; // an array of all records in the database
  int num_records; // the number of records currently in the database
} Database;

// This function writes a record to the database
void write_record(Database *db, Employee record) {
  if (db->num_records < MAX_RECORDS) {
    db->records[db->num_records] = record;
    db->num_records++;
  }
}

// This function reads a record from the database
Employee read_record(Database *db, int index) {
  if (index >= 0 && index < db->num_records) {
    return db->records[index];
  } else {
    Employee empty_record;
    memset(&empty_record, 0, sizeof(Employee));
    return empty_record;
  }
}

// This function prints out all the records in the database
void print_database(Database *db) {
  int i;
  for (i = 0; i < db->num_records; i++) {
    printf("%s, %d, %.2f\n", db->records[i].name, db->records[i].age, db->records[i].salary);
  }
}

// This function creates an index for searching the database by name
char **build_name_index(Database *db) {
  char **index = malloc(sizeof(char *) * db->num_records);
  int i;
  for (i = 0; i < db->num_records; i++) {
    index[i] = &(db->records[i].name[0]);
  }
  return index;
}

// This function creates an index for searching the database by age
int *build_age_index(Database *db) {
  int *index = malloc(sizeof(int) * db->num_records);
  int i;
  for (i = 0; i < db->num_records; i++) {
    index[i] = db->records[i].age;
  }
  return index;
}

// This function creates an index for searching the database by salary
float *build_salary_index(Database *db) {
  float *index = malloc(sizeof(float) * db->num_records);
  int i;
  for (i = 0; i < db->num_records; i++) {
    index[i] = db->records[i].salary;
  }
  return index;
}

int main() {
  Database db;
  memset(&db, 0, sizeof(Database));

  Employee employee1 = {"John Doe", 25, 50000.00};
  write_record(&db, employee1);

  Employee employee2 = {"Mary Smith", 32, 60000.00};
  write_record(&db, employee2);

  Employee employee3 = {"Bob Johnson", 47, 70000.00};
  write_record(&db, employee3);

  char **name_index = build_name_index(&db);
  int *age_index = build_age_index(&db);
  float *salary_index = build_salary_index(&db);

  printf("All records in the database:\n");
  print_database(&db);

  printf("\nSearching for employees with name starting with 'J':\n");
  int i;
  for (i = 0; i < db.num_records; i++) {
    if (name_index[i][0] == 'J') {
      printf("%s, %d, %.2f\n", db.records[i].name, db.records[i].age, db.records[i].salary);
    }
  }

  printf("\nSearching for employees with age greater than 30:\n");
  for (i = 0; i < db.num_records; i++) {
    if (age_index[i] > 30) {
      printf("%s, %d, %.2f\n", db.records[i].name, db.records[i].age, db.records[i].salary);
    }
  }

  printf("\nSearching for employees with salary greater than 60000:\n");
  for (i = 0; i < db.num_records; i++) {
    if (salary_index[i] > 60000.0) {
      printf("%s, %d, %.2f\n", db.records[i].name, db.records[i].age, db.records[i].salary);
    }
  }

  free(name_index);
  free(age_index);
  free(salary_index);

  return 0;
}