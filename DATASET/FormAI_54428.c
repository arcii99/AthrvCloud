//FormAI DATASET v1.0 Category: Database querying ; Style: high level of detail
/* This program demonstrates how to query a database using C. Specifically, it shows
   how to select data from a SQLite database using the SQLite3 library. */

#include <stdio.h>
#include <sqlite3.h>  /* Import the SQLite3 library */

/* This is the callback function that will be called once for each row of data returned
   from the database. In this example, we simply print the results to the console. */
int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]){
   sqlite3 *db;        /* Declare a pointer to an instance of the database */
   char *zErrMsg = 0;  /* Declare a pointer to an error message string */
   int rc;             /* Declare a variable to hold the result of SQLite functions */
   char *sql;          /* Declare a pointer to a SQL statement string */

   /* Open the database */
   rc = sqlite3_open("example.db", &db);
   if(rc){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return(1);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Define the SQL query */
   sql = "SELECT * FROM COMPANY";

   /* Execute the query */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if(rc != SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records selected successfully\n");
   }

   /* Close the database */
   sqlite3_close(db);
   return 0;
}