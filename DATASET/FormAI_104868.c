//FormAI DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  return 0;
}

int main(int argc, char *argv[]) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  const char *sql;

  rc = sqlite3_open("example.db", &db);
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  sql = "CREATE TABLE users("
        "id INTEGER PRIMARY KEY,"
        "name TEXT NOT NULL,"
        "email TEXT NOT NULL UNIQUE);";

  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    printf("Table created successfully\n");
  }

  sql = "INSERT INTO users(id,name,email)"
        "VALUES(1,'John Doe','john.doe@example.com'),"
        "(2,'Jane Doe','jane.doe@example.com'),"
        "(3,'Bob Smith','bob.smith@example.com');";

  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    printf("Records created successfully\n");
  }

  sql = "SELECT * FROM users WHERE name='John Doe'";

  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    printf("Operation completed successfully\n");
  }

  sqlite3_close(db);

  return 0;
}