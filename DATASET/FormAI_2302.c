//FormAI DATASET v1.0 Category: Database querying ; Style: Cryptic
#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char **argv) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    
    int rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    rc = sqlite3_prepare_v2(db, "SELECT * FROM users WHERE name=?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    rc = sqlite3_bind_text(stmt, 1, "Alice", -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to bind parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }
    
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        fprintf(stdout, "Name: %s, Age: %d\n", sqlite3_column_text(stmt, 0), sqlite3_column_int(stmt, 1));
    }
    
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to retrieve data: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return 0;
}