//FormAI DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **azColName) {
  int i;
  fprintf(stderr, "%s: ", (const char*)data);

  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }

  printf("\n");
  return 0;
}

int main(int argc, char **argv) {
  sqlite3 *db;
  char *errMsg = 0;
  int rc;
  
  rc = sqlite3_open("users.db", &db);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  rc = sqlite3_exec(db, "SELECT * FROM users WHERE age > 18;", callback, (void*) "Results:", &errMsg);

  if (rc != SQLITE_OK ) {
    fprintf(stderr, "SQL error: %s\n", errMsg);
    sqlite3_free(errMsg);
  } 
  
  sqlite3_close(db);
  return 0; 
}