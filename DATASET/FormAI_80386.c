//FormAI DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <sqlite3.h>

int main(void) {
    sqlite3 *db;
    int rc = sqlite3_open("employees.db", &db); //open or create the database
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *error = NULL;
    const char *sql = "CREATE TABLE employee_info (id INT, name TEXT, age INT, job_title TEXT)";
    rc = sqlite3_exec(db, sql, NULL, NULL, &error); //create a table
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", error);
        sqlite3_free(error);
    }

    sqlite3_close(db);
    return 0;
}