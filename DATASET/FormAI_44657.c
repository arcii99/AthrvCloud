//FormAI DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[])
{
  // Declare variables
  sqlite3* db;
  char* errMsg = 0;
  char* sql;
  sqlite3_stmt* stmt;

  // Open database
  int rc = sqlite3_open("example.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Select all data from table
  sql = "SELECT * FROM users;";
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
  if (rc == SQLITE_OK) {
    while (sqlite3_step(stmt) == SQLITE_ROW) {
      printf("%d|%s|%s\n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2));
    }
  } else {
    fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
  }

  // Close database
  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return 0;
}