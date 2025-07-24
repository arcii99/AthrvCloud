//FormAI DATASET v1.0 Category: Database querying ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName){
  int i;
  printf("\n");
  for(i=0; i<argc; i++){
    printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  return 0;
}

int main(int argc, char* argv[]){
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;

  rc = sqlite3_open("happy_quotes.db", &db);
  if(rc){ 
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  const char* data = "Callback function called";
  rc = sqlite3_exec(db, "SELECT * FROM happy_quotes ORDER BY RANDOM() LIMIT 1;", callback, (void*)data, &zErrMsg);

  if(rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }

  sqlite3_close(db);
  return 0;
}