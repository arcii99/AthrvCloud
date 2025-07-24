//FormAI DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *err_msg = 0;
    
    // Create a new database connection
    int rc = sqlite3_open("medieval.db", &db);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a new table for knights
    char *create_table = "CREATE TABLE knights(Id INT, Name TEXT, Rank TEXT, Castle TEXT);";
    
    rc = sqlite3_exec(db, create_table, 0, 0, &err_msg);
  
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    // Insert data into the table
    char *insert_data = "INSERT INTO knights VALUES(1, 'Arthur', 'King', 'Camelot');" \
                        "INSERT INTO knights VALUES(2, 'Lancelot', 'Commander', 'Camelot');" \
                        "INSERT INTO knights VALUES(3, 'Gawain', 'Knight', 'Orkney');" \
                        "INSERT INTO knights VALUES(4, 'Tristan', 'Knight', 'Lyonesse');";
    
    rc = sqlite3_exec(db, insert_data, 0, 0, &err_msg);
  
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        fprintf(stdout, "Data inserted successfully\n");
    }

    // Query the database for the knights belonging to a particular castle
    char *query = "SELECT * FROM knights WHERE Castle='Camelot';";
    
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);

    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            printf("Id: %d, Name: %s, Rank: %s, Castle: %s\n", 
                    sqlite3_column_int(stmt, 0),
                    sqlite3_column_text(stmt, 1),
                    sqlite3_column_text(stmt, 2),
                    sqlite3_column_text(stmt, 3));
        }
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    // Close the database connection
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}