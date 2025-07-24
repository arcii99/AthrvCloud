//FormAI DATASET v1.0 Category: Database querying ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void* data, int argc, char** argv, char** col_name);

int main(int argc, char** argv)
{
    sqlite3* db;
    char* error_message = NULL;
    int rc;

    /* Open the database */
    rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    /* Execute a simple SELECT query */
    char* query = "SELECT name, age FROM users WHERE age > 30";
    rc = sqlite3_exec(db, query, callback, NULL, &error_message);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error executing query: %s\n", error_message);
        sqlite3_free(error_message);
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    /* Close the database */
    sqlite3_close(db);

    return EXIT_SUCCESS;
}

static int callback(void* data, int argc, char** argv, char** col_name)
{
    int i;

    /* Print the results of the query */
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");

    return 0;
}