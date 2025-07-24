//FormAI DATASET v1.0 Category: Database querying ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {
  sqlite3 *db;
  char *errMsg = 0;
  int rc;
  
  // Open database
  rc = sqlite3_open("myDatabase.db", &db);
  
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // Execute query
  char* query = "SELECT * FROM myTable";
  sqlite3_stmt *stmt;
  
  rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
  
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // Iterate over results
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    char* name = sqlite3_column_text(stmt, 1);
    int age = sqlite3_column_int(stmt, 2);
    
    printf("id: %d | name: %s | age: %d\n", id, name, age);
  }
  
  // Clean up
  sqlite3_finalize(stmt);
  sqlite3_close(db);
  return 0;
}