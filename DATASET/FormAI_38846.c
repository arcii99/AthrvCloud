//FormAI DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *error_message = 0;
    int rc;

    rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    const char *create_table = "CREATE TABLE Cars(Id INT, Name TEXT, Price INT)";

    rc = sqlite3_exec(db, create_table, 0, 0, &error_message);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "Error creating table: %s\n", error_message);
        sqlite3_free(error_message);
    } else {
        printf("Table created successfully\n");
    }

    const char *insert_data = "INSERT INTO Cars VALUES(1, 'Audi', 52642); "
                              "INSERT INTO Cars VALUES(2, 'Mercedes', 57127); "
                              "INSERT INTO Cars VALUES(3, 'Skoda', 9000); "
                              "INSERT INTO Cars VALUES(4, 'Volvo', 29000); "
                              "INSERT INTO Cars VALUES(5, 'Bentley', 350000); "
                              "INSERT INTO Cars VALUES(6, 'Citroen', 21000); "
                              "INSERT INTO Cars VALUES(7, 'Hummer', 41400); "
                              "INSERT INTO Cars VALUES(8, 'Volkswagen', 21600)";

    rc = sqlite3_exec(db, insert_data, 0, 0, &error_message);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "Error inserting data: %s\n", error_message);
        sqlite3_free(error_message);
    } else {
        printf("Data inserted successfully\n");
    }

    const char *select_query = "SELECT * FROM Cars";

    sqlite3_stmt *statement;

    rc = sqlite3_prepare_v2(db, select_query, -1, &statement, 0);

    if (rc == SQLITE_OK ) {
        int column_count = sqlite3_column_count(statement);

        while (sqlite3_step(statement) == SQLITE_ROW) {
            for (int i = 0; i < column_count; i++) {
                printf("%s: %s\n", sqlite3_column_name(statement, i), sqlite3_column_text(statement, i));
            }
        }
    } else {
        fprintf(stderr, "Error selecting data: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(statement);

    sqlite3_close(db);
    
    return 0;
}