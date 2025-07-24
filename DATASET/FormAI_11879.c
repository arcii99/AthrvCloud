//FormAI DATASET v1.0 Category: Database querying ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum string length
#define MAX_STR_LEN 100

// Define maximum number of rows in database
#define MAX_ROWS 100

// Define struct for database row
typedef struct {
  int id;
  char name[MAX_STR_LEN];
  int age;
  char occupation[MAX_STR_LEN];
} Row;

// Define struct for database
typedef struct {
  Row rows[MAX_ROWS];
  int num_rows;
} Database;

// Function to add a row to the database
void add_row(Database* db, Row row) {
  // Check if database is full
  if (db->num_rows == MAX_ROWS) {
    printf("Error: Database is full\n");
    return;
  }

  // Add row to database
  db->rows[db->num_rows] = row;
  db->num_rows++;
}

// Function to print a row
void print_row(Row row) {
  printf("%d, %s, %d, %s\n", row.id, row.name, row.age, row.occupation);
}

// Function to print the entire database
void print_database(Database db) {
  printf("ID  Name  Age  Occupation\n");
  for (int i = 0; i < db.num_rows; i++) {
    print_row(db.rows[i]);
  }
}

// Function to query the database by name
void query_by_name(Database db, char* name) {
  printf("ID  Name  Age  Occupation\n");
  for (int i = 0; i < db.num_rows; i++) {
    if (strcmp(db.rows[i].name, name) == 0) {
      print_row(db.rows[i]);
    }
  }
}

// Main function
int main() {
  // Initialize database
  Database my_db = {0};

  // Add some rows to the database
  Row row_1 = {1, "Alice", 25, "Software Engineer"};
  add_row(&my_db, row_1);

  Row row_2 = {2, "Bob", 30, "Data Scientist"};
  add_row(&my_db, row_2);

  Row row_3 = {3, "Charlie", 35, "Project Manager"};
  add_row(&my_db, row_3);

  // Print the entire database
  printf("Entire database:\n");
  print_database(my_db);
  printf("\n");

  // Query the database by name
  printf("Querying database by name:\n");
  query_by_name(my_db, "Bob");

  return 0;
}