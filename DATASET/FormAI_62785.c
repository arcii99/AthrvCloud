//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 1000

// Define a struct to represent a person's information
typedef struct Person {
    int age;
    float height;
    float weight;
    int hasHeartDisease;
} Person;

// Generate a random person
Person generateRandomPerson() {
    Person p;
    p.age = rand() % 81 + 20; // Age between 20 and 100
    p.height = (float)(rand() % 200 + 100) / 100.0; // Height between 1 and 3 meters
    p.weight = (float)(rand() % 100 + 30) / 10.0; // Weight between 3 and 13 kg
    p.hasHeartDisease = rand() % 2; // 50/50 chance of having heart disease
    return p;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate a list of random people
    Person data[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = generateRandomPerson();
    }

    // Calculate average age, height, and weight
    float avgAge = 0.0;
    float avgHeight = 0.0;
    float avgWeight = 0.0;
    for (int i = 0; i < DATA_SIZE; i++) {
        avgAge += data[i].age;
        avgHeight += data[i].height;
        avgWeight += data[i].weight;
    }
    avgAge /= DATA_SIZE;
    avgHeight /= DATA_SIZE;
    avgWeight /= DATA_SIZE;

    // Print out results
    printf("Average age: %.2f\n", avgAge);
    printf("Average height: %.2f meters\n", avgHeight);
    printf("Average weight: %.2f kg\n", avgWeight);

    // Calculate percentage of people with heart disease
    int numDiseased = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        if (data[i].hasHeartDisease)
            numDiseased++;
    }
    float percentDiseased = (float)numDiseased / (float)DATA_SIZE;
    printf("Percentage of people with heart disease: %.2f%%\n", percentDiseased * 100.0);

    return 0;
}