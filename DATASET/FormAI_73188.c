//FormAI DATASET v1.0 Category: Database querying ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Callback function for SELECT query
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main(int argc, char *argv[]) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;

  // Open database connection
  rc = sqlite3_open("example.db", &db);
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Create a table in the database
  char *sql_create_table = "CREATE TABLE IF NOT EXISTS Users("
     "Id INT PRIMARY KEY     NOT NULL,"
     "Name           TEXT    NOT NULL,"
     "Age            INT     NOT NULL,"
     "Email          CHAR(50));";

  rc = sqlite3_exec(db, sql_create_table, callback, 0, &zErrMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    printf("Table created successfully\n");
  }

  // Insert data into the table
  char *sql_insert_data = "INSERT INTO Users(Id, Name, Age, Email) "
     "VALUES (1, 'John', 25, 'john@example.com'); "
     "INSERT INTO Users(Id, Name, Age, Email) "
     "VALUES (2, 'Sarah', 30, 'sarah@example.com'); "
     "INSERT INTO Users(Id, Name, Age, Email) "
     "VALUES (3, 'David', 20, 'david@example.com');";

  rc = sqlite3_exec(db, sql_insert_data, callback, 0, &zErrMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    printf("Data inserted successfully\n");
  }

  // SELECT data from the table
  char *sql_select_data = "SELECT * FROM Users WHERE Age > 25;";

  rc = sqlite3_exec(db, sql_select_data, callback, 0, &zErrMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }

  // Close database connection
  sqlite3_close(db);

  return 0;
}