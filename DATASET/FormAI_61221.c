//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *argv[]) {

  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  sqlite3_stmt *stmt;

  /* Open database */
  rc = sqlite3_open("example.db", &db);

  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return(0);
  }else{
    fprintf(stdout, "Opened database successfully\n");
  }

  /* Create SQL statement */
  const char* sql = "SELECT * from PERSONS";

  /* Prepare statement */
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

  if( rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
  }

  /* Execute statement */
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    char *name = (char*)sqlite3_column_text(stmt, 1);
    int age = sqlite3_column_int(stmt, 2);
    printf("ID = %d NAME = %s AGE = %d\n", id, name, age);
  }

  /* Finalize statement and close database */
  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return 0;
}