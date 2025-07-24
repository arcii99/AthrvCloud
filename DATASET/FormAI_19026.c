//FormAI DATASET v1.0 Category: Database querying ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main(int argc, char* argv[]) {
  
  sqlite3* db;
  int rc = sqlite3_open("myDatabase.db", &db);
  if (rc) {
    printf("Failed to open database.\n");
    return 1;
  } else {
    printf("Database is open.\n");
  }

  char* sql = "SELECT * FROM users WHERE age >= 18;";
  sqlite3_stmt* statement;
  rc = sqlite3_prepare_v2(db, sql, -1, &statement, NULL);
  if (rc != SQLITE_OK) {
    printf("Error preparing statement. Code: %d\n", rc);
    return 1;
  } else {
    printf("Statement prepared successfully.\n");
  }

  int result;
  while ((result = sqlite3_step(statement)) == SQLITE_ROW) {
    char id[10];
    char name[50];
    int age;

    sprintf(id, "%d", sqlite3_column_int(statement, 0));
    strcpy(name, (const char*) sqlite3_column_text(statement, 1));
    age = sqlite3_column_int(statement, 2);

    printf("%s | %s | %d\n", id, name, age);
  }

  if (result != SQLITE_DONE) {
    printf("Error getting results. Code: %d\n", result);
    return 1;
  }

  sqlite3_finalize(statement);
  sqlite3_close(db);

  return 0;
}