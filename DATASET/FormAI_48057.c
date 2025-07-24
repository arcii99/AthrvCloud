//FormAI DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
    char* occupation;
} Person;

int main() {
    Person* people = malloc(sizeof(Person) * 3);
    people[0].name = "John Doe";
    people[0].age = 25;
    people[0].occupation = "Software Engineer";
    people[1].name = "Jane Doe";
    people[1].age = 23;
    people[1].occupation = "Graphic Designer";
    people[2].name = "Jim Doe";
    people[2].age = 30;
    people[2].occupation = "Project Manager";

    printf("Welcome to the Human Database!\n");
    printf("Please enter a name to search for: ");
    char query[50];
    scanf("%s", query);

    printf("Querying database...\n");

    for(int i = 0; i < 3; i++) {
        if(strcmp(people[i].name, query) == 0) {
            printf("%s is %d years old and works as a %s.\n", people[i].name, people[i].age, people[i].occupation);
            printf("Congratulations! You found your long-lost friend or maybe discovered a new enemy!");
            return 0;
        }
    }

    printf("We couldn't find anyone with that name.\n");
    printf("Sorry, I am not capable of teleporting your dream man or woman in front of you, but keep on dreaming, I tried my best though!" );
    free(people);
    return 0;
}