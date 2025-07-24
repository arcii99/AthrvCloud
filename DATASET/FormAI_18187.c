//FormAI DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

typedef struct {
    int id;
    char* name;
    int salary;
} Employee;

int callback(void* data, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3* db;
    int rc;
    char* err_msg;

    rc = sqlite3_open("employees.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    char* create_table_sql = "CREATE TABLE IF NOT EXISTS employees (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, salary INTEGER NOT NULL)";
    rc = sqlite3_exec(db, create_table_sql, NULL, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        exit(1);
    }

    Employee e1 = { 0, "John Doe", 50000 };
    Employee e2 = { 0, "Jane Smith", 60000 };
    Employee e3 = { 0, "Bob Johnson", 70000 };

    char* insert_sql = "INSERT INTO employees (name, salary) VALUES (?1, ?2)";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, insert_sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    sqlite3_bind_text(stmt, 1, e1.name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, e1.salary);
    rc = sqlite3_step(stmt);
    sqlite3_clear_bindings(stmt);
    sqlite3_reset(stmt);

    sqlite3_bind_text(stmt, 1, e2.name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, e2.salary);
    rc = sqlite3_step(stmt);
    sqlite3_clear_bindings(stmt);
    sqlite3_reset(stmt);

    sqlite3_bind_text(stmt, 1, e3.name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, e3.salary);
    rc = sqlite3_step(stmt);
    sqlite3_clear_bindings(stmt);
    sqlite3_reset(stmt);

    char* select_sql = "SELECT * FROM employees WHERE salary > 55000";
    rc = sqlite3_exec(db, select_sql, callback, NULL, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        exit(1);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}