//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {
  sqlite3* db;
  char* err_msg = 0;
  
  int rc = sqlite3_open("my_database.db", &db);
  
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  } else {
    fprintf(stdout, "Database opened successfully.\n");
  }
  
  const char* query = "SELECT * FROM employees WHERE age > ?";
  sqlite3_stmt* stmt;
  rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
  
  if (rc == SQLITE_OK) {
    int age_threshold = 30;
    sqlite3_bind_int(stmt, 1, age_threshold);
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
      int id = sqlite3_column_int(stmt, 0);
      char* name = (char*) sqlite3_column_text(stmt, 1);
      int age = sqlite3_column_int(stmt, 2);
      
      printf("Employee ID: %d, Name: %s, Age: %d\n", id, name, age);
    }
  } else {
    fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
  }
  
  sqlite3_finalize(stmt);
  sqlite3_close(db);
  
  return 0;
}