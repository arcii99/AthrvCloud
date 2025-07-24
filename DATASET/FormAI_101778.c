//FormAI DATASET v1.0 Category: Database querying ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

/* Callback function to handle printing of results */
int result_callback(void *data, int argc, char **argv, char **columns) {
    int i;
    printf("%s: ", (const char *)data);
    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", columns[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *error;
    int rc;

    /* Open database connection */
    rc = sqlite3_open("example.db", &db);
    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    fprintf(stdout, "Opened database.\n\n");

    /* Create table */
    char *create_table = "CREATE TABLE students (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
    rc = sqlite3_exec(db, create_table, NULL, NULL, &error);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", error);
        sqlite3_free(error);
        sqlite3_close(db);
        return 1;
    }
    fprintf(stdout, "Created table.\n\n");

    /* Insert records */
    char *insert_record_1 = "INSERT INTO students (name, age) VALUES ('John Doe', 21);";
    char *insert_record_2 = "INSERT INTO students (name, age) VALUES ('Jane Smith', 19);";
    rc = sqlite3_exec(db, insert_record_1, NULL, NULL, &error);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error inserting record 1: %s\n", error);
        sqlite3_free(error);
        sqlite3_close(db);
        return 1;
    }
    rc = sqlite3_exec(db, insert_record_2, NULL, NULL, &error);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error inserting record 2: %s\n", error);
        sqlite3_free(error);
        sqlite3_close(db);
        return 1;
    }
    fprintf(stdout, "Inserted records.\n\n");

    /* Query records */
    char *query = "SELECT name, age FROM students WHERE age > 20;";
    rc = sqlite3_exec(db, query, result_callback, (void *)"Query results", &error);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error querying database: %s\n", error);
        sqlite3_free(error);
        sqlite3_close(db);
        return 1;
    }
    fprintf(stdout, "Queried students.\n\n");

    /* Delete records */
    char *delete_record_1 = "DELETE FROM students WHERE name = 'John Doe';";
    rc = sqlite3_exec(db, delete_record_1, NULL, NULL, &error);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error deleting record 1: %s\n", error);
        sqlite3_free(error);
        sqlite3_close(db);
        return 1;
    }
    fprintf(stdout, "Deleted John Doe record.\n\n");

    /* Update record */
    char *update_record = "UPDATE students SET age = 20 WHERE name = 'Jane Smith';";
    rc = sqlite3_exec(db, update_record, NULL, NULL, &error);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error updating record: %s\n", error);
        sqlite3_free(error);
        sqlite3_close(db);
        return 1;
    }
    fprintf(stdout, "Updated Jane Smith record.\n\n");

    /* Close database connection */
    sqlite3_close(db);
    fprintf(stdout, "Closed database connection.\n");

    return 0;
}