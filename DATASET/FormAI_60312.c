//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DATABASE_NAME "mydatabase.db"

// Function to query database
static int query_database(void *data, int argc, char **argv, char **col_names)
{
    printf("Query Results:\n");
    for(int i = 0; i < argc; i++)
    {
        printf("%s: %s\n", col_names[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main()
{
    sqlite3 *db;
    char *error_msg = NULL;

    // Open database connection
    int rc = sqlite3_open(DATABASE_NAME, &db);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Error opening the database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    // Execute SQL statement to create a table
    char *sql_create_table = "CREATE TABLE IF NOT EXISTS mytable (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)";
    rc = sqlite3_exec(db, sql_create_table, NULL, 0, &error_msg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Error creating table: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    // Insert records into the table
    char *sql_insert_record_1 = "INSERT INTO mytable (id, name, age) VALUES (1, 'John', 30)";
    rc = sqlite3_exec(db, sql_insert_record_1, NULL, 0, &error_msg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Error inserting record: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    char *sql_insert_record_2 = "INSERT INTO mytable (id, name, age) VALUES (2, 'Jane', 25)";
    rc = sqlite3_exec(db, sql_insert_record_2, NULL, 0, &error_msg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Error inserting record: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    // Query database with SELECT statement
    char *sql_select_record = "SELECT * FROM mytable WHERE age > 26";
    rc = sqlite3_exec(db, sql_select_record, query_database, NULL, &error_msg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Error selecting record: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    // Close database connection
    sqlite3_close(db);
    return EXIT_SUCCESS;
}