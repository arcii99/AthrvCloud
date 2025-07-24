//FormAI DATASET v1.0 Category: Database querying ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// A function to handle SQL errors
static int errorHandler(void *data, const char *errorMessage) {
    printf("Error: %s\n", errorMessage);
    return 0;
}

int main() {
    sqlite3 *db;
    int result = sqlite3_open("example.db", &db);
    
    if(result != SQLITE_OK) {
        printf("Error opening database\n");
        return 0;
    }
    
    char* query = "SELECT name, age FROM students WHERE grade = ?";
    sqlite3_stmt* statement;
    result = sqlite3_prepare_v2(db, query, strlen(query) + 1, &statement, 0);
    
    if (result != SQLITE_OK) {
        printf("Error preparing statement\n");
        sqlite3_close(db);
        return 0;
    }
    
    int grade = 10;
    result = sqlite3_bind_int(statement, 1, grade);
    
    if (result != SQLITE_OK) {
        printf("Error binding parameter\n");
        sqlite3_finalize(statement);
        sqlite3_close(db);
        return 0;
    }
    
    printf("Students in grade %d:\n", grade);
    
    while (sqlite3_step(statement) == SQLITE_ROW) {
        char* name = sqlite3_column_text(statement, 0);
        int age = sqlite3_column_int(statement, 1);
        printf("%s (%d)\n", name, age);
    }
    
    sqlite3_finalize(statement);
    sqlite3_close(db);
    return 0;
}