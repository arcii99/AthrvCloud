//FormAI DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main(int argc, char** argv) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    char* errmsg;
    int rc;

    rc = sqlite3_open("jokes.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char* create_table = "CREATE TABLE IF NOT EXISTS jokes(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "question VARCHAR(100) NOT NULL,"
                         "punchline VARCHAR(100) NOT NULL);";

    rc = sqlite3_exec(db, create_table, NULL, 0, &errmsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return 1;
    }

    char* insert_joke1 = "INSERT INTO jokes(question, punchline) VALUES('Why do programmers prefer dark mode?', 'Because light attracts bugs.');";
    char* insert_joke2 = "INSERT INTO jokes(question, punchline) VALUES('Why did the SQL query cross the road?', 'To get to the other SELECT.');";
    char* insert_joke3 = "INSERT INTO jokes(question, punchline) VALUES('Why did the programmer quit his job?', 'He didn't get arrays.');";

    rc = sqlite3_exec(db, insert_joke1, NULL, 0, &errmsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    }

    rc = sqlite3_exec(db, insert_joke2, NULL, 0, &errmsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    }

    rc = sqlite3_exec(db, insert_joke3, NULL, 0, &errmsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errmsg);
        sqlite3_free(errmsg);
    }

    char* select_jokes = "SELECT * FROM jokes;";

    rc = sqlite3_prepare_v2(db, select_jokes, -1, &stmt, 0);

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("Question: %s\n", sqlite3_column_text(stmt, 1));
        printf("Punchline: %s\n", sqlite3_column_text(stmt, 2));
        printf("\n");
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}