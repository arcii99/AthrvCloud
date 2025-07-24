//FormAI DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Callback function to print queried data
static int query_callback(void *data, int argc, char **argv, char **col_names) {
    for (int i=0; i<argc; i++) {
        printf("%s = %s\n", col_names[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    char *err_msg = 0;
    
    // Open database
    int rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // Create table
    const char *sql_create_table = "CREATE TABLE IF NOT EXISTS users(id INT PRIMARY KEY, name TEXT, age INT)";
    rc = sqlite3_exec(db, sql_create_table, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    
    // Insert data into table
    const char *sql_insert_data = "INSERT INTO users(id, name, age) VALUES(1, 'John', 30), (2, 'Jane', 25), (3, 'Bob', 40)";
    rc = sqlite3_exec(db, sql_insert_data, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    
    // Query all data in table
    const char *sql_query_all_data = "SELECT * FROM users";
    rc = sqlite3_exec(db, sql_query_all_data, query_callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    
    // Query data with specific condition
    const char *sql_query_data_with_condition = "SELECT * FROM users WHERE age > 30";
    rc = sqlite3_exec(db, sql_query_data_with_condition, query_callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    // Close database
    sqlite3_close(db);
    
    return 0;
}