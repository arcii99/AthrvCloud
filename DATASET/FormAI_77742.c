//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **szColName);

int main(){
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  char *sql;
  const char* data = "Callback function called";

  rc = sqlite3_open("mydatabase.db", &db);

  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return(0);
  }else{
    fprintf(stderr, "Opened database successfully\n");
  }

  // Querying the database for all data in the table 'persons'
  sql = "SELECT * FROM persons";

  rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

  if( rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }else{
    fprintf(stdout, "Query executed successfully\n");
  }

  sqlite3_close(db);
  return 0;
}

int callback(void *NotUsed, int argc, char **argv, char **szColName){
  int i;
  for(i=0; i<argc; i++){
    printf("%s = %s\n", szColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("%s\n", (char*)NotUsed);

  return 0;
}