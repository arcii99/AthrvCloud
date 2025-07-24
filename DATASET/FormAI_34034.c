//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    int rc;
    char *sql;
    char *errmsg;
    sqlite3_stmt *stmt;
    
    printf("Oh my goodness, I just found out how easy it is to query a SQLite database using C!\n\n");
    
    rc = sqlite3_open("myDatabase.db", &db);
    
    if (rc) {
        printf("Uh oh, something went wrong when trying to open the database (%s)\n", sqlite3_errmsg(db));
        return 1;
    } else {
        printf("Yay! The database has been opened successfully!\n\n");
    }
    
    sql = "SELECT * FROM myTable";
    
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    
    if (rc != SQLITE_OK) {
        printf("Oops, looks like there was an error when preparing the SQL query: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    } else {
        printf("The SQL query has been prepared successfully.\n\n");
    }
    
    rc = sqlite3_step(stmt);
    
    if (rc != SQLITE_ROW) {
        printf("Uh oh, something went wrong when executing the SQL query (%s)\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    } else {
        printf("The first row of the query results has been retrieved successfully!\n\n");
    }
    
    int id = sqlite3_column_int(stmt, 0);
    char *name = sqlite3_column_text(stmt, 1);
    double score = sqlite3_column_double(stmt, 2);
    
    printf("The values retrieved from the first row are:\nID: %d\nName: %s\nScore: %lf\n\n", id, name, score);
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    printf("Wow, that was so simple and straightforward! I can't wait to tell all my programmer friends about this amazing SQLite-C combo!\n");
    
    return 0;
}