//FormAI DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// This is the funniest way to visualize data structures!!
typedef struct {
    char *name;
    int age;
    double height;
} person;

int main()
{
    // Let's create a list of people, they will be our very sophisticated data structure
    person *people = malloc(sizeof(person) * 5);
    if (!people) {
        printf("Oopsie, we couldn't allocate memory for our data structure. Sorry!\n");
        exit(1);
    }

    // Let's populate our data structure with some people with random information
    people[0].name = "Alice";
    people[0].age = 25;
    people[0].height = 1.65;

    people[1].name = "Bob";
    people[1].age = 30;
    people[1].height = 1.80;

    people[2].name = "Charlie";
    people[2].age = 40;
    people[2].height = 1.75;

    people[3].name = "Diana";
    people[3].age = 27;
    people[3].height = 1.70;

    people[4].name = "Edgar";
    people[4].age = 35;
    people[4].height = 1.85;

    // Now, let's visualize our data structure in the most hilarious way!
    printf("OUR DATA STRUCTURE IS AN ABSOLUTE BANGER!!\n\n");

    printf("|%-10s |%-10s |%-10s |\n", "Name", "Age", "Height");
    printf("|%s|%s|%s|\n", "----------", "----------", "----------");

    // Let's print out all of our people
    for (int i = 0; i < 5; i++) {
        printf("|%-10s |%-10d |%-10.2f |\n", people[i].name, people[i].age, people[i].height);
    }

    // Finally, let's free up the memory used by our data structure
    free(people);
    printf("\n\nOUR DATA STRUCTURE WAS SO GOOD THAT IT IS NOW FREE TO LIVE ITS LIFE!!\n");

    return 0;
}