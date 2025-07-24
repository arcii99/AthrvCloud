//FormAI DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {

  printf("Connecting to database...\n");

  // Initialize database connection object
  sqlite3 *db;
  int rc = sqlite3_open("users.db", &db);

  if (rc) {
    fprintf(stderr, "Error connecting to database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  printf("Connected to database successfully!\n");

  // Define query
  const char *query = "SELECT * FROM users;";

  // Execute query and handle results
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  printf("Querying database for user information...\n");

  // Loop through query results and print to console
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    const char *username = sqlite3_column_text(stmt, 1);
    const char *email = sqlite3_column_text(stmt, 2);
    printf("ID: %d | Username: %s | Email: %s\n", id, username, email);
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  printf("Query complete! Exiting program...\n");

  return 0;
}