//FormAI DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the structure for our data
typedef struct {
    int age;
    char gender;
    float height;
    float weight;
} person;

int main() {
    // Define an array of people
    person people[5] = {{23, 'M', 1.80, 75},
                        {30, 'F', 1.60, 60},
                        {42, 'M', 1.70, 85},
                        {25, 'F', 1.75, 70},
                        {35, 'M', 1.90, 100}};

    // Determine the average age of the people
    int sum_age = 0;
    for (int i = 0; i < 5; i++) {
        sum_age += people[i].age;
    }
    float avg_age = (float)sum_age / 5;
    printf("The average age of the people is %.2f.\n", avg_age);

    // Determine the number of males and females
    int num_males = 0;
    int num_females = 0;
    for (int i = 0; i < 5; i++) {
        if (people[i].gender == 'M') {
            num_males++;
        } else if (people[i].gender == 'F') {
            num_females++;
        }
    }
    printf("There are %d males and %d females in the group.\n", num_males, num_females);

    // Determine the average height and weight of the males and females separately
    float sum_male_height = 0;
    float sum_male_weight = 0;
    int num_male = 0;
    float sum_female_height = 0;
    float sum_female_weight = 0;
    int num_female = 0;
    for (int i = 0; i < 5; i++) {
        if (people[i].gender == 'M') {
            sum_male_height += people[i].height;
            sum_male_weight += people[i].weight;
            num_male++;
        } else if (people[i].gender == 'F') {
            sum_female_height += people[i].height;
            sum_female_weight += people[i].weight;
            num_female++;
        }
    }
    float avg_male_height = sum_male_height / num_male;
    float avg_male_weight = sum_male_weight / num_male;
    float avg_female_height = sum_female_height / num_female;
    float avg_female_weight = sum_female_weight / num_female;
    printf("The average height and weight of the %d males is %.2f meters and %.2f kg, respectively.\n", num_males, avg_male_height, avg_male_weight);
    printf("The average height and weight of the %d females is %.2f meters and %.2f kg, respectively.\n", num_females, avg_female_height, avg_female_weight);

    // Determine the tallest person in the group
    float max_height = 0;
    int index_tallest;
    for (int i = 0; i < 5; i++) {
        if (people[i].height > max_height) {
            max_height = people[i].height;
            index_tallest = i;
        }
    }
    printf("The tallest person in the group is %d years old, %c, %.2f meters tall, and %.2f kg.\n", people[index_tallest].age, people[index_tallest].gender, people[index_tallest].height, people[index_tallest].weight);

    // Determine the heaviest person in the group
    float max_weight = 0;
    int index_heaviest;
    for (int i = 0; i < 5; i++) {
        if (people[i].weight > max_weight) {
            max_weight = people[i].weight;
            index_heaviest = i;
        }
    }
    printf("The heaviest person in the group is %d years old, %c, %.2f meters tall, and %.2f kg.\n", people[index_heaviest].age, people[index_heaviest].gender, people[index_heaviest].height, people[index_heaviest].weight);

    return 0;
}