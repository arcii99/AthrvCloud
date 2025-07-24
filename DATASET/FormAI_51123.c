//FormAI DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);

   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }

   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *conn;
   char *errmsg;
   int rc;

   rc = sqlite3_open("example.db", &conn);

   if(rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(conn));
      sqlite3_close(conn);
      return 1;
   } 

   char *sql_stmt = "SELECT * FROM contacts WHERE name LIKE '%John%' OR email LIKE '%example%';";
   const char* data = "Callback function called";
   
   rc = sqlite3_exec(conn, sql_stmt, callback, (void*)data, &errmsg);
   if(rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", errmsg);
      sqlite3_free(errmsg);
   } else {
      printf("Operation done successfully\n");
   }

   sqlite3_close(conn);
   return 0;
}