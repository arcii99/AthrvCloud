//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
    char* occupation;
} Person;

int main() {
    FILE* csv_file = fopen("people.csv", "r");
    if (csv_file == NULL) {
        printf("Sorry, could not open CSV file.");
        return 1;
    }
    char line[1024];
    int line_count = 0;
    Person* people = malloc(sizeof(Person));
    while (fgets(line, 1024, csv_file)) {
        if (line_count == 0) {
            line_count++;
            continue;
        }
        char* name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char* occupation = strtok(NULL, ",");
        Person person = { name, age, occupation };
        people[line_count-1] = person;
        people = realloc(people, sizeof(Person)*(line_count+1));
        line_count++;
    }
    fclose(csv_file);
    printf("There are %d people in the CSV file.\n", line_count-1);
    for (int i = 0; i < line_count-1; i++) {
        printf("Person %d:\nName: %s\nAge: %d\nOccupation: %s\n", i+1, people[i].name, people[i].age, people[i].occupation);
    }
    free(people);
    return 0;
}