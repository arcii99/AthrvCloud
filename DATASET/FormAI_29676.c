//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to represent a row in the database
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

// Declare a struct to represent the database
typedef struct {
    Employee *rows;
    int num_rows;
} Database;

// Function to load data from a CSV file into a Database
void load_csv(Database *db, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[100];
    db->num_rows = 0;
    while (fgets(line, sizeof(line), fp)) {
        db->num_rows++;
    }

    rewind(fp);
    db->rows = malloc(sizeof(Employee) * db->num_rows);

    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, ",");
        db->rows[i].id = atoi(token);

        token = strtok(NULL, ",");
        strncpy(db->rows[i].name, token, sizeof(db->rows[i].name));

        token = strtok(NULL, ",");
        db->rows[i].age = atoi(token);

        token = strtok(NULL, ",");
        db->rows[i].salary = atof(token);

        i++;
    }

    fclose(fp);
}

// Function to print all data in the database
void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("%d, %s, %d, %f\n", db->rows[i].id, db->rows[i].name, db->rows[i].age, db->rows[i].salary);
    }
}

// Function to query the database and get a subset of the rows based on age
Database *query_database_by_age(Database *db, int age) {
    Database *new_db = malloc(sizeof(Database));
    new_db->num_rows = 0;

    for (int i = 0; i < db->num_rows; i++) {
        if (db->rows[i].age == age) {
            new_db->num_rows++;
        }
    }

    new_db->rows = malloc(sizeof(Employee) * new_db->num_rows);

    int j = 0;
    for (int i = 0; i < db->num_rows; i++) {
        if (db->rows[i].age == age) {
            new_db->rows[j] = db->rows[i];
            j++;
        }
    }

    return new_db;
}

int main() {
    // Load data from csv file
    Database db;
    load_csv(&db, "employees.csv");

    // Print all of the employee data in the database
    printf("All Employee Data:\n");
    print_database(&db);

    // Query the database by age
    int age = 25;
    printf("Results for employees with age %d:\n", age);
    Database *new_db = query_database_by_age(&db, age);
    print_database(new_db);

    // Free memory
    free(db.rows);
    free(new_db->rows);
    free(new_db);

    return 0;
}