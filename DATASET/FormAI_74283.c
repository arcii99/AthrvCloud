//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {

    sqlite3 *db;
    char *err_msg = NULL;

    int rc = sqlite3_open("mydatabase.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sql = "SELECT * FROM employees WHERE age <= 30;";

    rc = sqlite3_exec(db, sql, NULL, NULL, &err_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_stmt *res;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM employees WHERE age <= 30;", -1, &res, 0);

    if (rc == SQLITE_OK) {
        
        int count = 0;
        printf("List of employees with age less than or equal to 30:\n");
        printf("--------------------------------------------------\n");

        while (sqlite3_step(res) == SQLITE_ROW) {
            int id = sqlite3_column_int(res, 0);
            char *name = sqlite3_column_text(res, 1);
            int age = sqlite3_column_int(res, 2);
            char *address = sqlite3_column_text(res, 3);

            printf("%d. %s %d %s\n", ++count, name, age, address);
        }

        sqlite3_finalize(res);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_close(db);
    return 0;
}