//FormAI DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   rc = sqlite3_open("test.db", &db);

   if(rc){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   sql = "CREATE TABLE MATH(DIVIDEND INT, DIVISOR INT, QUOTIENT INT);"
         "INSERT INTO MATH VALUES(55, 5, 11);"
         "INSERT INTO MATH VALUES(72, 8, 9);" 
         "INSERT INTO MATH VALUES(68, 10, 6);" 
         "INSERT INTO MATH VALUES(126, 7, 18);" 
         "SELECT * FROM MATH WHERE DIVIDEND < DIVISOR;";

   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if(rc != SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }

   sqlite3_close(db);
   return 0;
}