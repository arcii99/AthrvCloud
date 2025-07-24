//FormAI DATASET v1.0 Category: Data mining ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the struct for the data to be mined
struct data {
    int id;
    float age;
    char sex;
};

int main() {
    // Create an array of the data
    struct data people[5] = {
        {101, 23.5, 'M'},
        {102, 31.0, 'F'},
        {103, 42.9, 'M'},
        {104, 28.7, 'F'},
        {105, 19.3, 'M'}
    };

    // Print the data before mining
    printf("Before mining:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d \t Age: %.1f \t Sex: %c \n", people[i].id, people[i].age, people[i].sex);
    }

    // Find the average age of the people
    float sum_age = 0;
    for (int i = 0; i < 5; i++) {
        sum_age += people[i].age;
    }
    float avg_age = sum_age/5;
    printf("\nThe average age is: %.1f\n", avg_age);

    // Find the oldest person
    float max_age = 0;
    int oldest_person_index = 0;
    for (int i = 0; i < 5; i++) {
        if (people[i].age > max_age) {
            max_age = people[i].age;
            oldest_person_index = i;
        }
    }
    printf("\nThe oldest person is: ID %d, Age %.1f, Sex %c\n", people[oldest_person_index].id, people[oldest_person_index].age, people[oldest_person_index].sex);

    // Find the total number of males
    int num_males = 0;
    for (int i = 0; i < 5; i++) {
        if (people[i].sex == 'M') {
            num_males++;
        }
    }
    printf("\nThere are a total of %d males.\n", num_males);

    // End of program
    return 0;
}