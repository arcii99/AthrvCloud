//FormAI DATASET v1.0 Category: Database querying ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> // SQLite library

// Callback function to print the query results
static int print_result(void *data, int argc, char **argv, char **col_name) {
  int i;
  printf("Query Result:\n");
  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main() {
  sqlite3 *db;
  char *error_msg = NULL;
  int rc;

  // Open the database file
  rc = sqlite3_open("example.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Create a table
  char *create_sql = "CREATE TABLE users(id INTEGER PRIMARY KEY, name TEXT NOT NULL, age INTEGER);";
  rc = sqlite3_exec(db, create_sql, NULL, 0, &error_msg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", error_msg);
    sqlite3_free(error_msg);
    sqlite3_close(db);
    return 1;
  }

  // Insert some data
  char *insert_sql = "INSERT INTO users(name, age) VALUES('Alice', 25);"
                     "INSERT INTO users(name, age) VALUES('Bob', 28);"
                     "INSERT INTO users(name, age) VALUES('Charlie', 30);";
  rc = sqlite3_exec(db, insert_sql, NULL, 0, &error_msg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", error_msg);
    sqlite3_free(error_msg);
    sqlite3_close(db);
    return 1;
  }

  // Query the data
  char *query_sql = "SELECT * FROM users WHERE age > 25;";
  rc = sqlite3_exec(db, query_sql, print_result, NULL, &error_msg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", error_msg);
    sqlite3_free(error_msg);
    sqlite3_close(db);
    return 1;
  }

  // Delete the table
  char *delete_sql = "DROP TABLE users;";
  rc = sqlite3_exec(db, delete_sql, NULL, 0, &error_msg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", error_msg);
    sqlite3_free(error_msg);
    sqlite3_close(db);
    return 1;
  }

  // Close the database
  sqlite3_close(db);
  return 0;
}