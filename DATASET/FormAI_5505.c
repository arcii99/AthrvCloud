//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("employees.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sql = "SELECT * FROM employees WHERE department = 'Sales';";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    printf("\nSurprise! We've found the following employees in the Sales department:\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        char *name = (char *) sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        char *department = (char *) sqlite3_column_text(stmt, 3);
        int salary = sqlite3_column_int(stmt, 4);

        printf("%d %s %d %s %d\n", id, name, age, department, salary);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}