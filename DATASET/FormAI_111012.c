//FormAI DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    int age;
    char gender[6];
} Person;

int main() {
    FILE *fp;
    Person p1 = {1, "Alice", 25, "Female"};
    Person p2 = {2, "Bob", 30, "Male"};

    fp = fopen("database.txt", "w+");
    if (fp == NULL) {
        printf("Error: Failed to open database file!\n");
        exit(1);
    }

    fprintf(fp, "%d %s %d %s\n", p1.id, p1.name, p1.age, p1.gender);
    fprintf(fp, "%d %s %d %s\n", p2.id, p2.name, p2.age, p2.gender);

    printf("2 records added to the database.\n");

    rewind(fp);

    Person p_read;

    while (fscanf(fp, "%d %s %d %s", &p_read.id, p_read.name, &p_read.age, p_read.gender) != EOF) {
        printf("%d %s %d %s\n", p_read.id, p_read.name, p_read.age, p_read.gender);
    }

    fclose(fp);

    return 0;
}