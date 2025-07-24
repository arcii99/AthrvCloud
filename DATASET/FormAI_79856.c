//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {
   sqlite3 *db;
   char *err_msg = 0;

   int rc = sqlite3_open("example.db", &db);

   if (rc != SQLITE_OK) {
       fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
       sqlite3_close(db);

       return 1;
   }

   char *sql = "CREATE TABLE users("
               "id INTEGER PRIMARY KEY,"
               "name TEXT,"
               "age INT);"
               "INSERT INTO users (id, name, age) VALUES (1, 'John', 30);"
               "INSERT INTO users (id, name, age) VALUES (2, 'Mary', 25);";

   rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

   if (rc != SQLITE_OK) {
       fprintf(stderr, "SQL error: %s\n", err_msg);
       sqlite3_free(err_msg);
       sqlite3_close(db);

       return 1;
   }

   sqlite3_close(db);

   return 0;
}