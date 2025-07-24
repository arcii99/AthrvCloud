//FormAI DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **col_name) {
    int i;
    fprintf(stderr, "%s:\n", (const char*) data);
    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *stmt;

    int rc = sqlite3_open(":memory:", &db);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    char *sql = "CREATE TABLE Employees(Id INT, Name TEXT, Age INT, Salary REAL);"
        "INSERT INTO Employees VALUES(1, 'John Doe', 27, 5000.0);"
        "INSERT INTO Employees VALUES(2, 'Jane Smith', 32, 7000.0);"
        "INSERT INTO Employees VALUES(3, 'Bob Johnson', 45, 9000.0);";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        exit(1);
    }

    char *data = "Callback function called";
    char *query = "SELECT * FROM Employees WHERE Salary > 6000;";

    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    rc = sqlite3_exec(db, query, callback, (void*) data, &err_msg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        exit(1);
    }

    sqlite3_close(db);
    return 0;
}