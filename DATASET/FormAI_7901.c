//FormAI DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for (i=0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char *argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   rc = sqlite3_open("mydatabase.db", &db);

   if (rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      exit(1);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   // Create table
   sql = "CREATE TABLE Users (" \
         "ID INT PRIMARY KEY     NOT NULL," \
         "Name           TEXT    NOT NULL," \
         "Age            INT     NOT NULL," \
         "City           TEXT    NOT NULL);";

   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if (rc != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   
   // Insert data
   sql = "INSERT INTO Users (ID, Name, Age, City) " \
         "VALUES (1, 'John Doe', 25, 'New York'); " \
         "INSERT INTO Users (ID, Name, Age, City) " \
         "VALUES (2, 'Jane Doe', 30, 'London'); " \
         "INSERT INTO Users (ID, Name, Age, City) " \
         "VALUES (3, 'Bob Smith', 35, 'Los Angeles');";

   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if (rc != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }

   // Select data
   sql = "SELECT * from Users";

   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if (rc != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }

   sqlite3_close(db);
   return 0;
}