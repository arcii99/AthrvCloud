//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

/* This function will be passed to the sqlite_exec() method
   as a parameter to be executed as the callback function */
static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;

    for (i = 0; i < argc; i++) {
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
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    /* Create table */
    char *sql = "CREATE TABLE users ("
                "id INT PRIMARY KEY NOT NULL,"
                "name TEXT NOT NULL,"
                "email TEXT UNIQUE NOT NULL"
                ");";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    /* Insert data into table */
    sql = "INSERT INTO users (id, name, email) "
            "VALUES (1, 'John Doe', 'johndoe@example.com'); "
            "INSERT INTO users (id, name, email) "
            "VALUES (2, 'Jane Doe', 'janedoe@example.com'); "
            "INSERT INTO users (id, name, email) "
            "VALUES (3, 'Jim Doe', 'jimdoe@example.com'); "
            "INSERT INTO users (id, name, email) "
            "VALUES (4, 'Jake Doe', 'jakedoe@example.com'); ";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    /* Select data from table */
    sql = "SELECT * FROM users WHERE id > 1 AND name LIKE '%Doe'";

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }


    sqlite3_close(db);

    return 0;
}