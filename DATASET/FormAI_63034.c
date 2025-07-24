//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Callback function to print results
int callback(void *data, int argc, char **argv, char **colName) {
  for (int i = 0; i < argc; i++) {
    printf("%s: %s\n", colName[i], argv[i]);
  }
  printf("\n");
  return 0;
}

int main() {
  sqlite3 *db;
  char *errMsg = 0;
  int rc;

  // Open database
  rc = sqlite3_open("example.db", &db);
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return 1;
  } else {
    printf("Opened database successfully\n");
  }

  // Create table
  char *sql = "CREATE TABLE IF NOT EXISTS Employee("  \
               "ID INT PRIMARY KEY     NOT NULL," \
               "NAME           TEXT    NOT NULL," \
               "AGE            INT     NOT NULL," \
               "ADDRESS        CHAR(50)," \
               "SALARY         REAL );";

  rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", errMsg);
    sqlite3_free(errMsg);
  } else {
    printf("Table created successfully\n");
  }

  // Insert data
  sql = "INSERT INTO Employee (ID, NAME, AGE, ADDRESS, SALARY) "  \
        "VALUES (1, 'John Doe', 25, '123 Main St', 50000.00 ); " \
        "INSERT INTO Employee (ID, NAME, AGE, ADDRESS, SALARY) "  \
        "VALUES (2, 'Jane Smith', 30, '456 Oak Ave', 60000.00 ); " \
        "INSERT INTO Employee (ID, NAME, AGE, ADDRESS, SALARY) "  \
        "VALUES (3, 'Bob Johnson', 35, '789 Maple Blvd', 70000.00 );";

  rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", errMsg);
    sqlite3_free(errMsg);
  } else {
    printf("Records created successfully\n");
  }

  // Query data
  sql = "SELECT * from Employee";

  rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", errMsg);
    sqlite3_free(errMsg);
  }

  // Close database
  sqlite3_close(db);

  return 0;
}