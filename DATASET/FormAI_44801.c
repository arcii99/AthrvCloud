//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define callback function for SELECT queries
static int select_callback(void *data, int argc, char **argv, char **colnames) {
    for(int i = 0; i < argc; i++) {
        printf("%s: %s\n", colnames[i], argv[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *conn;
    char *error;
    int res;
    
    // Open or create database
    res = sqlite3_open("mydb.db", &conn);
    if(res != SQLITE_OK) {
        printf("Error opening database: %s\n", sqlite3_errmsg(conn));
        return 1;
    }
    
    // Create table if it doesn't exist
    const char *create_table = "CREATE TABLE IF NOT EXISTS mytable (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)";
    res = sqlite3_exec(conn, create_table, NULL, NULL, &error);
    if(res != SQLITE_OK) {
        printf("Error creating table: %s\n", error);
        sqlite3_free(error);
        return 1;
    }
    
    // Insert data into table
    const char *insert_data = "INSERT INTO mytable (name, age) VALUES ('John', 25), ('Jane', 30), ('Bob', 40)";
    res = sqlite3_exec(conn, insert_data, NULL, NULL, &error);
    if(res != SQLITE_OK) {
        printf("Error inserting data: %s\n", error);
        sqlite3_free(error);
        return 1;
    }
    
    // SELECT all data from table
    const char *select_all = "SELECT * FROM mytable";
    res = sqlite3_exec(conn, select_all, select_callback, NULL, &error);
    if(res != SQLITE_OK) {
        printf("Error selecting data: %s\n", error);
        sqlite3_free(error);
        return 1;
    }
    
    // SELECT data with specific value in column
    const char *select_specific = "SELECT name, age FROM mytable WHERE age = 30";
    res = sqlite3_exec(conn, select_specific, select_callback, NULL, &error);
    if(res != SQLITE_OK) {
        printf("Error selecting data: %s\n", error);
        sqlite3_free(error);
        return 1;
    }
    
    // Update data in table
    const char *update_data = "UPDATE mytable SET age = 35 WHERE name = 'Jane'";
    res = sqlite3_exec(conn, update_data, NULL, NULL, &error);
    if(res != SQLITE_OK) {
        printf("Error updating data: %s\n", error);
        sqlite3_free(error);
        return 1;
    }
    
    // SELECT updated data
    res = sqlite3_exec(conn, select_all, select_callback, NULL, &error);
    if(res != SQLITE_OK) {
        printf("Error selecting data: %s\n", error);
        sqlite3_free(error);
        return 1;
    }
    
    // Delete data from table
    const char *delete_data = "DELETE FROM mytable WHERE age > 30";
    res = sqlite3_exec(conn, delete_data, NULL, NULL, &error);
    if(res != SQLITE_OK) {
        printf("Error deleting data: %s\n", error);
        sqlite3_free(error);
        return 1;
    }
    
    // SELECT remaining data
    res = sqlite3_exec(conn, select_all, select_callback, NULL, &error);
    if(res != SQLITE_OK) {
        printf("Error selecting data: %s\n", error);
        sqlite3_free(error);
        return 1;
    }
    
    // Close database connection
    sqlite3_close(conn);
    
    return 0;
}