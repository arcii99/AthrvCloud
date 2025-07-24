//FormAI DATASET v1.0 Category: Database querying ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Definition of a structure to hold database records
typedef struct {
    int id;
    char name[50];
    int age;
    char gender[15];
} Person;

// Callback function to handle the result of a SELECT query
static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    Person *person = (Person *) data;
    for (i = 0; i < argc; i++) {
        if (strcmp(azColName[i], "id") == 0)
            person->id = atoi(argv[i]);
        else if (strcmp(azColName[i], "name") == 0)
            strcpy(person->name, argv[i]);
        else if (strcmp(azColName[i], "age") == 0)
            person->age = atoi(argv[i]);
        else if (strcmp(azColName[i], "gender") == 0)
            strcpy(person->gender, argv[i]);
    }
    return 0;
}

int main() {
    sqlite3 *db; // Pointer to the database object
    char *errMsg = 0; // Pointer to an error message
    int ret; // Return value of the SQLite functions
    Person person; // Structure to hold database records

    // Open the database or create if it doesn't exist
    ret = sqlite3_open("example.db", &db);

    if (ret) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        printf("Opened database successfully\n");
    }

    // Create a table if it doesn't exist
    const char *sql = "CREATE TABLE IF NOT EXISTS PERSON (" \
                      "ID INT PRIMARY KEY NOT NULL," \
                      "NAME TEXT NOT NULL," \
                      "AGE INT NOT NULL," \
                      "GENDER CHAR(10) NOT NULL);";

    ret = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (ret != SQLITE_OK) {
        printf("Error creating table: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully\n");
    }

    // Insert records into the table
    sql = "INSERT INTO PERSON (ID, NAME, AGE, GENDER) " \
          "VALUES (1, 'John Doe', 30, 'Male'); " \
          "INSERT INTO PERSON (ID, NAME, AGE, GENDER) " \
          "VALUES (2, 'Jane Smith', 25, 'Female');";

    ret = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (ret != SQLITE_OK) {
        printf("Error inserting records: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Records inserted successfully\n");
    }

    // Select a record from the table
    sql = "SELECT * FROM PERSON WHERE ID = 1;";

    ret = sqlite3_exec(db, sql, callback, &person, &errMsg);
    if (ret != SQLITE_OK) {
        printf("Error selecting record: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Selected record: ID = %d, NAME = %s, AGE = %d, GENDER = %s\n",
            person.id, person.name, person.age, person.gender);
    }

    // Close the database connection
    sqlite3_close(db);

    return 0;
}