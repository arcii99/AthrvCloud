//FormAI DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char id[10];
    char name[50];
    int age;
} Person;

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Person *personArray;
    int numPersons = 0;
    int i, j;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        numPersons++;
    }

    personArray = (Person *) malloc(numPersons * sizeof(Person));

    rewind(fp);

    for (i = 0; i < numPersons; i++) {
        fgets(line, MAX_LINE_LENGTH, fp);
        sscanf(line, "%s %s %d", personArray[i].id, personArray[i].name, &personArray[i].age);
    }

    fclose(fp);

    printf("All persons in database:\n");
    for (i = 0; i < numPersons; i++) {
        printf("%s %s %d\n", personArray[i].id, personArray[i].name, personArray[i].age);
    }

    printf("Persons over the age of 30:\n");
    for (i = 0; i < numPersons; i++) {
        if (personArray[i].age > 30) {
            printf("%s %s %d\n", personArray[i].id, personArray[i].name, personArray[i].age);
        }
    }

    printf("Sorting by age...\n");
    for (i = 0; i < numPersons-1; i++) {
        for (j = i+1; j < numPersons; j++) {
            if (personArray[i].age > personArray[j].age) {
                Person temp = personArray[i];
                personArray[i] = personArray[j];
                personArray[j] = temp;
            }
        }
    }

    printf("All persons in database (sorted by age):\n");
    for (i = 0; i < numPersons; i++) {
        printf("%s %s %d\n", personArray[i].id, personArray[i].name, personArray[i].age);
    }

    free(personArray);

    return 0;
}