//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ROWS 100
#define NUM_COLS 50

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

typedef struct {
    Student students[NUM_ROWS][NUM_COLS];
    int num_students[NUM_ROWS];
} Database;

void add_student(Database *db, int row, int col, int id, char *name, float gpa) {
    Student *s = &db->students[row][col];
    s->id = id;
    strcpy(s->name, name);
    s->gpa = gpa;

    db->num_students[row]++;
}

void print_database(Database *db) {
    for (int i = 0; i < NUM_ROWS; i++) {
        if (db->num_students[i] > 0) {
            printf("Row %d:\n", i+1);
            for (int j = 0; j < db->num_students[i]; j++) {
                Student *s = &db->students[i][j];
                printf("\tID: %d\n", s->id);
                printf("\tName: %s\n", s->name);
                printf("\tGPA: %.2f\n", s->gpa);
            }
        }
    }
}

int main() {
    Database db;
    memset(&db, 0, sizeof(Database));

    add_student(&db, 0, 0, 1001, "John Doe", 3.5);
    add_student(&db, 0, 1, 1002, "Jane Smith", 4.0);
    add_student(&db, 1, 0, 1003, "Bob Johnson", 2.8);

    printf("Initial database:\n");
    print_database(&db);

    return 0;
}