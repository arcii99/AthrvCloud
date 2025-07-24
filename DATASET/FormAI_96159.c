//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    sqlite3_stmt *stmt;

    /* Open database */
    rc = sqlite3_open("mydatabase.db", &db);
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    /* Prepare SQL statement */
    sql = "SELECT name, age FROM users WHERE id = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Can't prepare SQL statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    /* Bind parameter */
    int id = 123;
    rc = sqlite3_bind_int(stmt, 1, id);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Can't bind parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    /* Execute statement */
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW)
    {
        fprintf(stderr, "Can't execute SQL statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    /* Read result */
    const unsigned char *name = sqlite3_column_text(stmt, 0);
    int age = sqlite3_column_int(stmt, 1);
    printf("Name: %s\nAge: %d\n", name, age);

    /* Clean up */
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}