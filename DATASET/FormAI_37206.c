//FormAI DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {
  // initialize SQLite connection
  sqlite3 *db;
  if (sqlite3_open("example.db", &db) != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }

  // execute query to create table
  char *create_table_sql = "CREATE TABLE users (id INT PRIMARY KEY, name TEXT)";
  if (sqlite3_exec(db, create_table_sql, NULL, NULL, NULL) != SQLITE_OK) {
    fprintf(stderr, "Cannot create table: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }

  // execute query to insert data into table
  char *insert_data_sql = "INSERT INTO users (id, name) VALUES (1, 'John Smith'), (2, 'Jane Doe')";
  if (sqlite3_exec(db, insert_data_sql, NULL, NULL, NULL) != SQLITE_OK) {
    fprintf(stderr, "Cannot insert data: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }

  // execute query to retrieve data from table
  char *retrieve_data_sql = "SELECT * FROM users WHERE name LIKE '%Smith%'";
  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(db, retrieve_data_sql, -1, &stmt, NULL) != SQLITE_OK) {
    fprintf(stderr, "Cannot prepare select statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    char *name = (char*)sqlite3_column_text(stmt, 1);
    printf("ID: %d, Name: %s\n", id, name);
  }
  sqlite3_finalize(stmt);

  // execute query to drop table
  char *drop_table_sql = "DROP TABLE users";
  if (sqlite3_exec(db, drop_table_sql, NULL, NULL, NULL) != SQLITE_OK) {
    fprintf(stderr, "Cannot drop table: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }

  // close SQLite connection
  sqlite3_close(db);
  return 0;
}