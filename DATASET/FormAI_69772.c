//FormAI DATASET v1.0 Category: Database querying ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char* argv[])
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;

    rc = sqlite3_open("events.db", &db);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    const char* query = "SELECT name, date, location FROM events WHERE type='romantic';";
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    while(sqlite3_step(stmt) == SQLITE_ROW) {
        const char* name = sqlite3_column_text(stmt, 0);
        const char* date = sqlite3_column_text(stmt, 1);
        const char* location = sqlite3_column_text(stmt, 2);

        printf("%s is happening on %s at %s.\n", name, date, location);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}