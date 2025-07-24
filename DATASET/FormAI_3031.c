//FormAI DATASET v1.0 Category: Database querying ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Callback function for the SQLite query
// Prints each row of the result set
static int print_row_callback(void *data, int argc, char **argv, char **column_names){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", column_names[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(){
    sqlite3 *db;
    char *error_msg = NULL;
    int rc;

    // Open the database file (will create a new file if it doesn't exist)
    rc = sqlite3_open("happy_people.db", &db);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create the table if it doesn't exist
    char *sql = "CREATE TABLE IF NOT EXISTS people ("
                "id INTEGER PRIMARY KEY,"
                "name TEXT NOT NULL,"
                "hobby TEXT NOT NULL"
                ");";
    rc = sqlite3_exec(db, sql, NULL, 0, &error_msg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return 1;
    }

    // Insert some cheerful people and their hobbies
    sql = "INSERT INTO people (name, hobby) VALUES"
          "('Alice', 'painting'),"
          "('Bob', 'dancing'),"
          "('Charlie', 'singing'),"
          "('David', 'hiking'),"
          "('Eve', 'reading'),"
          "('Frank', 'cooking'),"
          "('Grace', 'photography');";
    rc = sqlite3_exec(db, sql, NULL, 0, &error_msg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return 1;
    }

    // Query the database for all people who like to hike
    printf("People who like to hike:\n");
    sql = "SELECT * FROM people WHERE hobby='hiking';";
    rc = sqlite3_exec(db, sql, print_row_callback, NULL, &error_msg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return 1;
    }

    // Query the database for all people whose names start with 'A'
    printf("People whose names start with 'A':\n");
    sql = "SELECT * FROM people WHERE name LIKE 'A%';";
    rc = sqlite3_exec(db, sql, print_row_callback, NULL, &error_msg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", error_msg);
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return 1;
    }

    // Close the database connection
    sqlite3_close(db);

    return 0;
}