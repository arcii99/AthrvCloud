//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sqlite3.h>

#define DATABASE_FILE "example.db"

sqlite3 *db;

void *select_records(void *arg) {
    char *query = "SELECT * FROM users WHERE age > 25";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            char *name = sqlite3_column_text(stmt, 1);
            int age = sqlite3_column_int(stmt, 2);
            printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
        }
    } else {
        fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
    pthread_exit(NULL);
}

void *insert_record(void *arg) {
    int *data = (int *) arg;
    int id = data[0];
    char *name = (char *) data[1];
    int age = data[2];
    char query[100];

    sprintf(query, "INSERT INTO users (id, name, age) VALUES (%d, '%s', %d)", id, name, age);

    if (sqlite3_exec(db, query, NULL, NULL, NULL) != SQLITE_OK) {
        fprintf(stderr, "Error inserting record: %s\n", sqlite3_errmsg(db));
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;
    char *name1 = "John";
    char *name2 = "Jane";
    int age1 = 30;
    int age2 = 25;

    if (sqlite3_open(DATABASE_FILE, &db) != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    char *create_table_query = "CREATE TABLE IF NOT EXISTS users (id INT PRIMARY KEY NOT NULL, name TEXT NOT NULL, age INT NOT NULL)";

    if (sqlite3_exec(db, create_table_query, NULL, NULL, NULL) != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    int insert_data1[3] = {id1, *name1, age1};
    int insert_data2[3] = {id2, *name2, age2};

    pthread_create(&thread1, NULL, insert_record, (void *) insert_data1);
    pthread_create(&thread2, NULL, insert_record, (void *) insert_data2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_create(&thread1, NULL, select_records, NULL);
    pthread_create(&thread2, NULL, select_records, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sqlite3_close(db);
    return 0;
}