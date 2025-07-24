//FormAI DATASET v1.0 Category: Database querying ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

/* Callback function to handle query result */
static int query_callback(void *data, int argc, char **argv, char **col_name) {
  int i;
  for(i=0; i<argc; i++) {
    printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main(int argc, char **argv) {
  sqlite3 *db;
  char *err_msg = 0;
  int rc;

  /* Open database */
  rc = sqlite3_open("test.db", &db);
  if(rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  /* Create table */
  char *sql = "CREATE TABLE IF NOT EXISTS customers("
              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
              "name TEXT NOT NULL,"
              "age INTEGER NOT NULL,"
              "gender CHAR(10) NOT NULL);";
  rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
  if(rc != SQLITE_OK) {
    fprintf(stderr, "Cannot create table: %s\n", err_msg);
    sqlite3_free(err_msg);
    sqlite3_close(db);
    return 1;
  }

  /* Insert data */
  sql = "INSERT INTO customers(name, age, gender) VALUES('John', 30, 'Male'), ('Jane', 25, 'Female'), ('Bob', 35, 'Male');";
  rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
  if(rc != SQLITE_OK) {
    fprintf(stderr, "Cannot insert data: %s\n", err_msg);
    sqlite3_free(err_msg);
    sqlite3_close(db);
    return 1;
  }

  /* Query data */
  sql = "SELECT * FROM customers WHERE age > ?";
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
  if(rc != SQLITE_OK) {
    fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  int age_limit = 28;
  sqlite3_bind_int(stmt, 1, age_limit);
  rc = sqlite3_step(stmt);
  while(rc == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    char *name = sqlite3_column_text(stmt, 1);
    int age = sqlite3_column_int(stmt, 2);
    char *gender = sqlite3_column_text(stmt, 3);
    printf("%d, %s, %d, %s\n", id, name, age, gender);
    rc = sqlite3_step(stmt);
  }
  sqlite3_finalize(stmt);

  /* Close database */
  sqlite3_close(db);
  return 0;
}