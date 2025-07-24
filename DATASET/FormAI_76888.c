//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

int main() {
    FILE *fp = fopen("people.csv", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[100];
    char *token;

    Person people[50];
    int count = 0;

    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, ",");
        strcpy(people[count].name, token);

        token = strtok(NULL, ",");
        people[count].age = atoi(token);

        token = strtok(NULL, ",");
        people[count].height = atof(token);

        count++;
    }

    fclose(fp);

    printf("Name\tAge\tHeight\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%f\n", people[i].name, people[i].age, people[i].height);
    }

    return 0;
}