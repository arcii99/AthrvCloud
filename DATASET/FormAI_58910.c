//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sqlite3.h>

sqlite3 *database;
char *zErrMsg = 0;
int rc;

void *query1(void *arg)
{
    char *sql = "SELECT * FROM users WHERE age > 30";
    sqlite3_exec(database, sql, NULL, NULL, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error1: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        exit(1);
    }

    printf("Thread1 - Query1 finished execution\n");
    pthread_exit(NULL);
}

void *query2(void *arg)
{
    char *sql = "UPDATE users SET is_active = 1 WHERE age <= 30";
    sqlite3_exec(database, sql, NULL, NULL, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error2: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        exit(1);
    }

    printf("Thread2 - Query2 finished execution\n");
    pthread_exit(NULL);
}

void *query3(void *arg)
{
    char *sql = "SELECT COUNT(*) FROM users WHERE is_active = 1";
    sqlite3_stmt *stmt;
    int count = 0;

    rc = sqlite3_prepare_v2(database, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error3: %s\n", sqlite3_errmsg(database));
        sqlite3_finalize(stmt);
        exit(1);
    }

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        count = sqlite3_column_int(stmt, 0);
    }

    printf("Thread3 - Query3 finished execution. Active User count: %d\n", count);
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    rc = sqlite3_open("example.db", &database);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(database));
        sqlite3_close(database);
        exit(1);
    }

    char *sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER, is_active INTEGER)";
    sqlite3_exec(database, sql, NULL, NULL, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error creating table: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(database);
        exit(1);
    }

    sql = "INSERT INTO users (id, name, age, is_active) VALUES (1, 'John Doe', 25, 0), (2, 'Jane Doe', 35, 0), (3, 'Bob Smith', 45, 0)";
    sqlite3_exec(database, sql, NULL, NULL, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error inserting into table: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(database);
        exit(1);
    }

    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, query1, NULL);
    pthread_create(&thread2, NULL, query2, NULL);
    pthread_create(&thread3, NULL, query3, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    sqlite3_close(database);

    return 0;
}