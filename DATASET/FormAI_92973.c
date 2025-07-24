//FormAI DATASET v1.0 Category: Database querying ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

sqlite3 *db;

// Callback function to print retrieved data
int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {

   int rc;
   char *err_msg = 0;
   
   // Open database
   rc = sqlite3_open("exampledb.db", &db);
   
   if (rc != SQLITE_OK) {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return 1;
   }else{
      fprintf(stdout, "Database opened successfully\n");
   }

   // Query database
   char *sql = "SELECT * FROM employees WHERE age > 30;";
   
   rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

   if (rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", err_msg);
      sqlite3_free(err_msg);
   } else {
      fprintf(stdout, "Query executed successfully\n");
   }

   // Close database
   sqlite3_close(db);
   
   return 0;
}