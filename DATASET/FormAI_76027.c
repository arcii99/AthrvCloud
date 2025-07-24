//FormAI DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(){
   sqlite3 *db; // sqlite3 object to hold the database

   // open the database
   int rc = sqlite3_open("example.db", &db);

   // check if database opened successfully
   if(rc != SQLITE_OK){
      printf("Error opening database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return 1;
   }

   // SQL query statement
   const char *query = "SELECT id, name, age FROM users WHERE age > 30";

   // prepare the query statement
   sqlite3_stmt *stmt;
   rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

   // check if query prepared successfully
   if( rc != SQLITE_OK ){
      printf("Error preparing query: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return 1;
   }

   // execute the query
   while( sqlite3_step(stmt) == SQLITE_ROW ){
      printf("ID: %d, Name: %s, Age: %d\n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_int(stmt, 2));
   }

   // finalize the statement
   sqlite3_finalize(stmt);

   // close the database
   sqlite3_close(db);

   return 0;
}