//FormAI DATASET v1.0 Category: Data mining ; Style: creative
#include <stdio.h> 
#include <stdlib.h>

/* Define struct to hold person data */
typedef struct Person {
    char name[50];
    int age;
    int weight;
} Person;

/* Define function to find the oldest person */
Person findOldest(Person people[], int numPeople) {
    int i;
    Person oldest = people[0];
    for (i = 1; i < numPeople; i++) {
        if (people[i].age > oldest.age) {
            oldest = people[i];
        }
    }
    return oldest;
}

/* Define function to find the average weight of all people */
float findAvgWeight(Person people[], int numPeople) {
    int i;
    int totalWeight = 0;
    for (i = 0; i < numPeople; i++) {
        totalWeight += people[i].weight;
    }
    return (float) totalWeight / numPeople;
}

int main() {
    /* Create array of person data */
    Person people[5] = {
        {"Alice", 25, 130},
        {"Bob", 42, 185},
        {"Charlie", 30, 160},
        {"David", 38, 200},
        {"Emma", 21, 115}
    };

    /* Find the oldest person */
    Person oldest = findOldest(people, 5);
    printf("The oldest person is %s, who is %d years old.\n", oldest.name, oldest.age);

    /* Find the average weight of all people */
    float avgWeight = findAvgWeight(people, 5);
    printf("The average weight of all people is %.2f pounds.\n", avgWeight);

    /* Exit successfully */
    return 0;
}