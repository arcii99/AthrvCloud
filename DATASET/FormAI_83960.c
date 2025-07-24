//FormAI DATASET v1.0 Category: Database querying ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// callback function to print query results
static int callback(void *data, int argc, char **argv, char **col_name) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db; // database object
    char *err_msg = 0; // error message
    int rc;

    // open the database file, or create it if it doesn't already exist
    rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // create a table named "students" with columns "id", "name", and "age"
    char *create_sql = "CREATE TABLE students(id INT PRIMARY KEY, name TEXT, age INT);";
    rc = sqlite3_exec(db, create_sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // insert some data into the "students" table
    char *insert_sql1 = "INSERT INTO students(id, name, age) VALUES(1, 'John', 20);";
    rc = sqlite3_exec(db, insert_sql1, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    char *insert_sql2 = "INSERT INTO students(id, name, age) VALUES(2, 'Jane', 22);";
    rc = sqlite3_exec(db, insert_sql2, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    char *insert_sql3 = "INSERT INTO students(id, name, age) VALUES(3, 'Bob', 19);";
    rc = sqlite3_exec(db, insert_sql3, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    printf("Data inserted successfully\n");

    // execute a SELECT query on the "students" table, retrieving all columns for students with age less than or equal to 20
    char *select_sql = "SELECT * FROM students WHERE age <= 20;";
    rc = sqlite3_exec(db, select_sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    // close the database
    sqlite3_close(db);

    return 0;
}