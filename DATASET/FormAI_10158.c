//FormAI DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
 
sqlite3 *db;

int main(int argc, char const *argv[]) {
  
  char *zErrMsg = 0;
  int rc ;
  char *sql;
  
  /* Initializing the database */
  rc = sqlite3_open("mydb.db", &db);
  
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n",
        sqlite3_errmsg(db));
    return (0);
  } else {
    fprintf(stderr, "Opened database successfully\n");
  }
  
  /* Creating table */
  sql = "CREATE TABLE Student("
        "ID INT PRIMARY KEY NOT NULL,"
        "NAME CHAR(50) NOT NULL,"
        "AGE INT NOT NULL);";  

  rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
  
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error creating table: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Table created successfully\n");
  }
  }
