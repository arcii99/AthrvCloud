//FormAI DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   // Loop through each column
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
   const char* data = "Callback function called";
   
	// Open database
   rc = sqlite3_open("example.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }
   
	// Create, insert and select query strings
   char *sql_create = "CREATE TABLE COMPANY("
                        "ID INT PRIMARY KEY     NOT NULL,"
                        "NAME           TEXT    NOT NULL,"
                        "AGE            INT     NOT NULL,"
                        "ADDRESS        CHAR(50),"
                        "SALARY         REAL );";
                        
   char *sql_insert = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
                        "VALUES (1, 'Paul', 32, 'California', 20000.0 ); "
                        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
                        "VALUES (2, 'Allen', 25, 'Texas', 15000.0 ); "
                        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
                        "VALUES (3, 'Teddy', 23, 'Norway', 20000.0 );"
                        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
                        "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.0 );";
                        
   char *sql_select = "SELECT * from COMPANY";
   
   // Execute create query
   rc = sqlite3_exec(db, sql_create, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, " Table created successfully\n");
   }
   
   // Execute insert query
   rc = sqlite3_exec(db, sql_insert, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   
   // Execute select query
   rc = sqlite3_exec(db, sql_select, callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Select operation completed successfully\n");
   }
   
   sqlite3_close(db);
   return 0;
}