//FormAI DATASET v1.0 Category: Data mining ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    float income;
} Person;

int main() {
    FILE *file;
    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int num_people;
    fscanf(file, "%d", &num_people);

    Person *people = (Person*) malloc(num_people * sizeof(Person));

    for (int i = 0; i < num_people; i++) {
        fscanf(file, "%s %d %f", people[i].name, &people[i].age, &people[i].income);
    }

    int index_of_richest = 0;
    for (int i = 1; i < num_people; i++) {
        if (people[i].income > people[index_of_richest].income) {
            index_of_richest = i;
        }
    }

    printf("%s is the richest person with an income of %.2f.\n", people[index_of_richest].name, people[index_of_richest].income);

    fclose(file);
    free(people);
    return 0;
}