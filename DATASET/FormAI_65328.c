//FormAI DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    for(i=0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {
        printf("Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } else {
        printf("Database opened successfully\n");
    }

    char create_table[500] = "CREATE TABLE IF NOT EXISTS MyTable (ID INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Age INTEGER, Address VARCHAR(255));";

    rc = sqlite3_exec(db, create_table, 0, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        printf("Error creating table: %s\n", sqlite3_errmsg(db));
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    } else {
        printf("Table created successfully\n");
    }

    char insert[500] = "INSERT INTO MyTable (Name, Age, Address) VALUES ('John', 25, '123 Main St');";
    rc = sqlite3_exec(db, insert, 0, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        printf("Error inserting data: %s\n", sqlite3_errmsg(db));
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    } else {
        printf("Data inserted successfully\n");
    }

    char select[500] = "SELECT * FROM MyTable;";
    rc = sqlite3_exec(db, select, callback, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        printf("Error selecting data: %s\n", sqlite3_errmsg(db));
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);
    return 0;
}