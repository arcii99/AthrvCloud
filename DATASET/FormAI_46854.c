//FormAI DATASET v1.0 Category: Database querying ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {
  sqlite3 *db;
  sqlite3_stmt *stmt;

  // Open database
  int rc = sqlite3_open("happy_database.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Create table if it does not exist
  char *create_table_query = "CREATE TABLE IF NOT EXISTS happy_table ("
                             "id INT PRIMARY KEY,"
                             "name TEXT NOT NULL,"
                             "happy_level INT NOT NULL);";
  rc = sqlite3_exec(db, create_table_query, NULL, NULL, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error creating table: %s", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Insert some happy data
  char *insert_query = "INSERT INTO happy_table (id, name, happy_level)"
                       "VALUES (1, 'Barney', 10),"
                              "(2, 'Ted', 8),"
                              "(3, 'Robin', 7),"
                              "(4, 'Lily', 9),"
                              "(5, 'Marshall', 8);";
  rc = sqlite3_exec(db, insert_query, NULL, NULL, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error inserting data: %s", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  // Query the data
  char *query = "SELECT name, happy_level FROM happy_table WHERE happy_level > 7;";
  rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error preparing query: %s", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  printf("Happiest people:\n");

  // Print results
  while (sqlite3_step(stmt) != SQLITE_DONE) {
    const char *name = sqlite3_column_text(stmt, 0);
    int happy_level = sqlite3_column_int(stmt, 1);
    printf("%s: %d\n", name, happy_level);
  }

  // Clean up
  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return 0;
}