//FormAI DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    sqlite3_stmt *stmt;

    // Open database
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    // Construct SQL statement
    sql = "SELECT * FROM employees WHERE age > 30";

    // Prepare statement
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    // Execute statement
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Get data from result set
        int id = sqlite3_column_int(stmt, 0);
        char *name = (char*) sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        double salary = sqlite3_column_double(stmt, 3);

        // Print data
        printf("ID = %d\n", id);
        printf("NAME = %s\n", name);
        printf("AGE = %d\n", age);
        printf("SALARY = %.2f\n", salary);
        printf("\n");
    }

    // Finalize statement
    sqlite3_finalize(stmt);

    // Close database
    sqlite3_close(db);

    return 0;
}