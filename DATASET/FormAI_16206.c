//FormAI DATASET v1.0 Category: Database querying ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

void callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   const char* data = "Callback function called";

   rc = sqlite3_open("test.db", &db);

   if(rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   char *sql = "SELECT * from COMPANY";

   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

   if(rc!=SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
   return 0;
}