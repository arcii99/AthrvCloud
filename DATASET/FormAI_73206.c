//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Callback function to print query results
static int print_results_callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    const char* data = "Callback function called";

    // Open database
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    // Create table
    sql = "CREATE TABLE EXAMPLE("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL);";

    rc = sqlite3_exec(db, sql, print_results_callback, (void*)data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Table created successfully\n");
    }
    // Insert data
    sql = "INSERT INTO EXAMPLE (ID,NAME,AGE) "  \
         "VALUES (1, 'John Doe', 25); " \
         "INSERT INTO EXAMPLE (ID,NAME,AGE) "  \
         "VALUES (2, 'Jane Smith', 30);" \
         "INSERT INTO EXAMPLE (ID,NAME,AGE)" \
         "VALUES (3, 'Bob Graham', 28);";

    rc = sqlite3_exec(db, sql, print_results_callback, (void*)data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Records created successfully\n");
    }
    // Query data
    sql = "SELECT * from EXAMPLE";

    rc = sqlite3_exec(db, sql, print_results_callback, (void*)data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Query results:\n");
    }
    // Close database
    sqlite3_close(db);
    return rc;
}