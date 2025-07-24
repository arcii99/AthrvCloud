//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// This program queries a database of superheroes and returns all the characters that are surprised

int main() {
  sqlite3 *db;
  char *err_msg = 0;
  int rc = sqlite3_open("superheroes.db", &db);
  
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  sqlite3_stmt *stmt;
  char *sql = "SELECT name FROM superheroes WHERE reaction = 'surprised'";
  
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
  
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  printf("The following superheroes are surprised:\n");
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    char *name = (char*)sqlite3_column_text(stmt, 0);
    printf("%s\n", name);
  }

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return 0;
}