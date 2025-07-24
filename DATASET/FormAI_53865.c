//FormAI DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>  // SQLite library for C

int select_callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    printf("%s: ", (const char*)data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s, ", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char** argv) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("example.db", &db);  // open the database

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char query[500];  // buffer for SQLite queries
    
    // Puzzle 1:
    int x = 5;
    int y = 7;
    int sum = x + y;
    sprintf(query, "SELECT * FROM table1 WHERE column1=%d AND column2=%d", x, sum);
    sqlite3_exec(db, query, select_callback, "Result 1", &err_msg);

    // Puzzle 2:
    char str[100] = "hello world";
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        if (str[i] == 'l') {
            str[i] = 'L';
        }
    }
    sprintf(query, "SELECT * FROM table2 WHERE column1='%s' AND column2 LIKE '%%e%%'", str);
    sqlite3_exec(db, query, select_callback, "Result 2", &err_msg);

    // Puzzle 3:
    int arr[5] = {1, 3, 5, 7, 9};
    int arr_sum = 0;
    for (int i = 0; i < 5; i++) {
        arr_sum += arr[i];
    }
    sprintf(query, "SELECT * FROM table3 WHERE column1=%d AND column2>%d", arr_sum, arr[0]);
    sqlite3_exec(db, query, select_callback, "Result 3", &err_msg);

    // close the database
    sqlite3_close(db);
    return 0;
}