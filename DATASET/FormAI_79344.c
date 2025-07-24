//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName){
  int i;
  for(i=0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main(int argc, char* argv[]) {
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } else {
        printf("Successfully connected to database!\n");
    }

    char* create_table_sql = "CREATE TABLE IF NOT EXISTS Users(Id INT, Name TEXT, Age INT)";
    rc = sqlite3_exec(db, create_table_sql, callback, 0, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } else {
        printf("Table created successfully!\n");
    }

    char* insert_sql = "INSERT INTO Users(Id, Name, Age) VALUES(1, 'John Doe', 25);" 
                       "INSERT INTO Users(Id, Name, Age) VALUES(2, 'Jane Doe', 20);"; 

    rc = sqlite3_exec(db, insert_sql, callback, 0, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } else {
        printf("Records added successfully!\n");
    }

    char* select_sql = "SELECT * FROM Users WHERE Age > 21";
    rc = sqlite3_exec(db, select_sql, callback, 0, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);
    return 0;
}