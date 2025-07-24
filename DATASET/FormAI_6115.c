//FormAI DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Query all records in the student table
void get_all_students(sqlite3 *db)
{
    sqlite3_stmt *stmt;
    const char *query = "SELECT * FROM student";

    if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("All Students:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }

    sqlite3_finalize(stmt);
}

// Query a specific record in the student table by id
void get_student_by_id(sqlite3 *db, int id)
{
    sqlite3_stmt *stmt;
    const char *query = "SELECT * FROM student WHERE id = ?";

    if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    } else {
        printf("Student not found!\n");
    }

    sqlite3_finalize(stmt);
}

int main()
{
    sqlite3 *db;
    char *err_msg = 0;

    if (sqlite3_open("students.db", &db) != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Create the student table if it does not exist
    const char *create_table_query = "CREATE TABLE IF NOT EXISTS student ("
                                     "id INTEGER PRIMARY KEY,"
                                     "name TEXT NOT NULL,"
                                     "age INTEGER NOT NULL"
                                     ");";

    if (sqlite3_exec(db, create_table_query, 0, 0, &err_msg) != SQLITE_OK) {
        printf("Error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }

    // Insert some example data
    const char *insert_query_1 = "INSERT INTO student (id, name, age) VALUES (1, 'John', 22);";
    const char *insert_query_2 = "INSERT INTO student (id, name, age) VALUES (2, 'Sarah', 19);";
    const char *insert_query_3 = "INSERT INTO student (id, name, age) VALUES (3, 'Bob', 20);";

    if (sqlite3_exec(db, insert_query_1, 0, 0, &err_msg) != SQLITE_OK ||
        sqlite3_exec(db, insert_query_2, 0, 0, &err_msg) != SQLITE_OK ||
        sqlite3_exec(db, insert_query_3, 0, 0, &err_msg) != SQLITE_OK) {
        printf("Error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }

    // Query all students
    get_all_students(db);

    // Query a single student by id
    get_student_by_id(db, 2);

    // Close the database connection
    sqlite3_close(db);

    return 0;
}