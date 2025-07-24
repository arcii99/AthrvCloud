//FormAI DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void checkResult(int resultCode, char *errMsg) {
    if (resultCode != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", errMsg);
        sqlite3_free(errMsg);
        exit(EXIT_FAILURE);
    }
}

int printResult(void *data, int argc, char **argv, char **colNames) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", colNames[i], argv[i]);
    }
    printf("--------\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *errMsg = NULL;
    int resultCode;

    resultCode = sqlite3_open("example.db", &db);
    checkResult(resultCode, "Could not open database");

    resultCode = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS students (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)", NULL, NULL, &errMsg);
    checkResult(resultCode, errMsg);

    resultCode = sqlite3_exec(db, "INSERT INTO students(id, name, age) VALUES(1, 'John Doe', 18)", NULL, NULL, &errMsg);
    checkResult(resultCode, errMsg);

    resultCode = sqlite3_exec(db, "INSERT INTO students(id, name, age) VALUES(2, 'Jane Doe', 19)", NULL, NULL, &errMsg);
    checkResult(resultCode, errMsg);

    resultCode = sqlite3_exec(db, "SELECT * FROM students", printResult, NULL, &errMsg);
    checkResult(resultCode, errMsg);

    sqlite3_close(db);
    return 0;
}