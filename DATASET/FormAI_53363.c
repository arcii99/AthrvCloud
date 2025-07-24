//FormAI DATASET v1.0 Category: Database querying ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Function to handle database query results
static int query_callback(void *data, int argc, char **argv, char **col_names) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", col_names[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("example.db", &db); // Open database file "example.db"
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create table "students"
    char *create_table_query = "CREATE TABLE students (id INTEGER PRIMARY KEY, name TEXT, age INTEGER, grade TEXT);";
    rc = sqlite3_exec(db, create_table_query, 0, 0, &err_msg);
    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    // Insert some sample data into the "students" table
    char *insert_data_query1 = "INSERT INTO students (id, name, age, grade) VALUES (1, 'Alice', 20, 'A');";
    rc = sqlite3_exec(db, insert_data_query1, 0, 0, &err_msg);

    char *insert_data_query2 = "INSERT INTO students (id, name, age, grade) VALUES (2, 'Bob', 22, 'B');";
    rc = sqlite3_exec(db, insert_data_query2, 0, 0, &err_msg);

    char *insert_data_query3 = "INSERT INTO students (id, name, age, grade) VALUES (3, 'Charlie', 19, 'C');";
    rc = sqlite3_exec(db, insert_data_query3, 0, 0, &err_msg);
    
    // Query the "students" table for students with grade 'B'
    char *query = "SELECT * FROM students WHERE grade='B';";

    // Execute the query and handle the results with the "query_callback" function
    rc = sqlite3_exec(db, query, query_callback, 0, &err_msg);
    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    // Close the database connection
    sqlite3_close(db);
    return 0;
}