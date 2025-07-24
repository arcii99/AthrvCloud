//FormAI DATASET v1.0 Category: Database querying ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main()
{
  // open the database
  sqlite3 *db;
  int rc = sqlite3_open("example.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // create a table (if it doesn't already exist)
  const char *create_table = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, age INTEGER)";
  rc = sqlite3_exec(db, create_table, NULL, NULL, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to create table: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // insert some rows into the table
  const char *insert_data = "INSERT INTO users (name, age) VALUES ('Alice', 23), ('Bob', 35), ('Charlie', 42)";
  rc = sqlite3_exec(db, insert_data, NULL, NULL, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to insert data: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // select all rows from the table
  const char *select_all = "SELECT * FROM users";
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, select_all, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to prepare select statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // iterate over the results and print them
  printf("id\t\tname\t\tage\n");
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *name = sqlite3_column_text(stmt, 1);
    int age = sqlite3_column_int(stmt, 2);
    printf("%d\t\t%s\t\t%d\n", id, name, age);
  }
  
  // clean up resources
  sqlite3_finalize(stmt);
  sqlite3_close(db);
  return 0;
}