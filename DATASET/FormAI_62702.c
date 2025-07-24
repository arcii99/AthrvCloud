//FormAI DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int callback(void*, int, char**, char**);

int main() {
  sqlite3 *db;
  char *err_msg;
  
  // open database
  int rc = sqlite3_open("mydatabase.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // execute query
  char *query = "SELECT * FROM employees WHERE age > 25";
  rc = sqlite3_exec(db, query, callback, 0, &err_msg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to query the database: %s\n", sqlite3_errmsg(db));
    sqlite3_free(err_msg);
    sqlite3_close(db);
    return 1;
  }
  
  // close the database
  sqlite3_close(db);
  
  return 0;
}

int callback(void *data, int argc, char **argv, char **column_names) {
  int i;
  for(i = 0; i < argc; i++) {
    printf("%s = %s\n", column_names[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}