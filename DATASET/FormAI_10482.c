//FormAI DATASET v1.0 Category: Database querying ; Style: modular
/* Our program will utilize a modular approach to querying a
   database using the C programming language. */

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Main function to demonstrate the use of our modular database
   query code */

int main(void) {

  // Open a SQLite3 database connection
  sqlite3 *db;
  int rc = sqlite3_open("example.db", &db);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Create a SQL SELECT statement
  char *select_sql = "SELECT * FROM users WHERE age > 25;";

  // Run the SQL SELECT query and print results
  sqlite3_stmt *stmt;
  do_query(db, select_sql, &stmt);
  print_query_results(stmt);

  // Close SQLite3 database connection and free memory
  sqlite3_finalize(stmt);
  sqlite3_close(db);
  return 0;
}

/* Function to run a query on the given database connection with a
   given SQL statement and initialize the returned statement handle. */

void do_query(sqlite3 *db, char *sql, sqlite3_stmt **stmt) {
  int rc = sqlite3_prepare_v2(db, sql, -1, stmt, 0);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }
}

/* Function to print the results of a given query statement as a table. */

void print_query_results(sqlite3_stmt *stmt) {
  int cols = sqlite3_column_count(stmt);
  int result = 0;
  for (int row = 0; !result; row++) {
    printf("|");
    for (int col = 0; col < cols; col++) {
      char *val = (char *)sqlite3_column_text(stmt, col);
      printf(" %-10s |", val);
    }
    printf("\n");

    result = sqlite3_step(stmt);
  }
}