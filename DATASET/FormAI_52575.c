//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[50];
    int age;
    char address[100];
} Person;

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int counter = 0;

    fp = fopen("people.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Person people[100];

    while ((read = getline(&line, &len, fp)) != -1) {
        char *token = strtok(line, ",");
        strcpy(people[counter].name, token);
        token = strtok(NULL, ",");
        people[counter].age = atoi(token);
        token = strtok(NULL, "\n");
        strcpy(people[counter].address, token);
        counter++;
    }

    printf("Name    | Age  | Address\n");
    printf("-------------------------\n");
    for (int i = 0; i < counter; i++) {
        printf("%-7s | %-3d | %s", people[i].name, people[i].age, people[i].address);
    }

    fclose(fp);

    return 0;
}