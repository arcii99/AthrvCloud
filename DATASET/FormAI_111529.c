//FormAI DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **colName);

int main(int argc, char **argv) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  char *sql;
  char *startDate = "2021-01-01"; // start date for query
  char *endDate = "2021-12-31";   // end date for query

  // Open database
  rc = sqlite3_open("experiment_data.db", &db);
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }
  fprintf(stdout, "Opened database successfully\n");

  // Prepare SQL statement
  sql = "SELECT * FROM experiments WHERE date BETWEEN ? AND ?";
  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
    fprintf(stderr, "Can't prepare SQL statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(1);
  }

  // Bind parameters to SQL statement
  if (sqlite3_bind_text(stmt, 1, startDate, -1, SQLITE_STATIC) != SQLITE_OK) {
    fprintf(stderr, "Can't bind start date: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    exit(1);
  }
  if (sqlite3_bind_text(stmt, 2, endDate, -1, SQLITE_STATIC) != SQLITE_OK) {
    fprintf(stderr, "Can't bind end date: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    exit(1);
  }

  // Execute SQL statement
  rc = sqlite3_step(stmt);
  while (rc == SQLITE_ROW) {
    // Retrieve data from current row
    int id = sqlite3_column_int(stmt, 0);
    char *name = (char *)sqlite3_column_text(stmt, 1);
    char *date = (char *)sqlite3_column_text(stmt, 2);
    char *outcome = (char *)sqlite3_column_text(stmt, 3);

    // Print data to console
    printf("ID = %d\n", id);
    printf("Name = %s\n", name);
    printf("Date = %s\n", date);
    printf("Outcome = %s\n\n", outcome);

    // Move to next row
    rc = sqlite3_step(stmt);
  }
  sqlite3_finalize(stmt);

  // Close database
  sqlite3_close(db);
  return 0;
}

int callback(void *data, int argc, char **argv, char **colName) {
  int i;
  fprintf(stderr, "%s: ", (const char *)data);
  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}