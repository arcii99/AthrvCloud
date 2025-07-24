//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int id;
    char name[30];
    int age;
} Student;

typedef struct {
    Student data[MAX_SIZE];
    int count;
} Database;

int addStudent(Database * db, Student student) {
    if (db->count >= MAX_SIZE) {
        return 0;
    }

    db->data[db->count] = student;
    db->count++;

    return 1;
}

int removeStudent(Database * db, int id) {
    int i, index = -1;

    for (i = 0; i < db->count; i++) {
        if (db->data[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return 0;
    }

    for (i = index; i < db->count - 1; i++) {
        db->data[i] = db->data[i + 1];
    }

    db->count--;

    return 1;
}

int updateStudent(Database * db, int id, char name[30], int age) {
    int i, index = -1;

    for (i = 0; i < db->count; i++) {
        if (db->data[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return 0;
    }

    strcpy(db->data[index].name, name);
    db->data[index].age = age;

    return 1;
}

void showDatabase(Database db) {
    int i;

    printf("ID\tName\tAge\n");

    for (i = 0; i < db.count; i++) {
        printf("%d\t%s\t%d\n", db.data[i].id, db.data[i].name, db.data[i].age);
    }
}

int main() {
    Database db = {0};
    Student s1 = {1, "John", 18};
    Student s2 = {2, "Mary", 19};
    Student s3 = {3, "David", 20};

    addStudent(&db, s1);
    addStudent(&db, s2);
    addStudent(&db, s3);

    printf("Initial database:\n");
    showDatabase(db);

    printf("\n---\n\n");

    printf("Removing student with id = 2:\n");
    removeStudent(&db, 2);
    showDatabase(db);

    printf("\n---\n\n");

    printf("Updating student with id = 3:\n");
    updateStudent(&db, 3, "Robert", 22);
    showDatabase(db);

    return 0;
}