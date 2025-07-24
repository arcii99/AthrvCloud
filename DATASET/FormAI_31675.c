//FormAI DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char** argv) {
  sqlite3* db;
  char* errMsg = NULL;
  int rc;
  rc = sqlite3_open("example.db", &db); // open database file
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  const char* SQL = "SELECT * FROM users WHERE age < ?"; // prepare SQL statement
  sqlite3_stmt* stmt;
  rc = sqlite3_prepare_v2(db, SQL, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  int age = 30;
  sqlite3_bind_int(stmt, 1, age); // bind parameter
  printf("Users younger than %d:\n", age);
  while (sqlite3_step(stmt) == SQLITE_ROW) { // execute query
    int id = sqlite3_column_int(stmt, 0);
    const char* name = (const char*) sqlite3_column_text(stmt, 1);
    int age = sqlite3_column_int(stmt, 2);
    printf("%d %s %d\n", id, name, age);
  }
  sqlite3_finalize(stmt); // release resources
  sqlite3_close(db);
  return 0;
}