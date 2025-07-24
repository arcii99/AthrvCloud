//FormAI DATASET v1.0 Category: Database querying ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Callback function to print the query results
static int callback(void* data, int argc, char** argv, char** colName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;                    // Declare a database object
    char *query;                    // Declare a query string
    sqlite3_stmt *stmt;             // Declare a prepared statement
    int rc, i;

    // Open the database
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    // Create a table
    query = "CREATE TABLE COMPANY (ID INT PRIMARY KEY NOT NULL, "
            "NAME TEXT NOT NULL, AGE INT NOT NULL, SALARY REAL NOT NULL);";
    rc = sqlite3_exec(db, query, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_free(query);
        sqlite3_close(db);
        return 1;
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    // Insert some data
    query = "INSERT INTO COMPANY (ID, NAME, AGE, SALARY) VALUES "
            "(1, 'Paul', 28, 35000.00), "
            "(2, 'Allen', 22, 50000.00), "
            "(3, 'Teddy', 34, 65000.00), "
            "(4, 'Mark', 25, 55000.00);";
    rc = sqlite3_exec(db, query, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_free(query);
        sqlite3_close(db);
        return 1;
    } else {
        fprintf(stdout, "Data inserted successfully\n");
    }

    // Select data
    query = "SELECT * FROM COMPANY;";
    rc = sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_free(query);
        sqlite3_close(db);
        return 1;
    } else {
        rc = sqlite3_step(stmt);
        while (rc != SQLITE_DONE) {
            if (rc == SQLITE_ROW) {
                for (i = 0; i < sqlite3_column_count(stmt); i++) {
                    printf("%s = %s\n", sqlite3_column_name(stmt, i), sqlite3_column_text(stmt, i));
                }
                printf("\n");
            }
            rc = sqlite3_step(stmt);
        }
    }
    
    // Delete data
    query = "DELETE FROM COMPANY WHERE ID = 4;";
    rc = sqlite3_exec(db, query, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_free(query);
        sqlite3_close(db);
        return 1;
    } else {
        fprintf(stdout, "Data deleted successfully\n");
    }

    // Close the database
    sqlite3_close(db);

    return 0;
}