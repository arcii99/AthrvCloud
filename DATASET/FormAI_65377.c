//FormAI DATASET v1.0 Category: Database querying ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {
  // open the database
  sqlite3* db;
  int rc = sqlite3_open("mydatabase.db", &db);

  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }

  // execute a query
  const char* query = "SELECT * FROM users WHERE age > ?;";
  sqlite3_stmt* stmt;

  rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

  if (rc) {
    fprintf(stderr, "Error preparing query: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }

  int age = 18;

  rc = sqlite3_bind_int(stmt, 1, age);

  if (rc) {
    fprintf(stderr, "Error binding parameter: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    exit(1);
  }

  // fetch results
  printf("Users older than %d:\n", age);

  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char* name = sqlite3_column_text(stmt, 1);
    int age = sqlite3_column_int(stmt, 2);

    printf("ID=%d, Name=%s, Age=%d\n", id, name, age);
  }

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Error fetching results: %s\n", sqlite3_errmsg(db));
  }

  // cleanup
  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return 0;
}