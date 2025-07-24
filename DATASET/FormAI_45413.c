//FormAI DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a person
typedef struct {
    int id;
    char name[20];
    int age;
    float height;
    float weight;
} Person;

int main() {
    // Generate some random data for testing
    Person people[10] = {
        {1, "Alice", 25, 175.0, 60.0},
        {2, "Bob", 31, 180.0, 70.0},
        {3, "Charlie", 27, 170.0, 80.0},
        {4, "David", 29, 185.0, 75.0},
        {5, "Emily", 24, 165.0, 55.0},
        {6, "Frank", 33, 190.0, 90.0},
        {7, "Grace", 26, 160.0, 50.0},
        {8, "Henry", 28, 175.0, 65.0},
        {9, "Iris", 30, 170.0, 70.0},
        {10, "Jack", 32, 180.0, 80.0}
    };

    // Calculate the average age, height and weight of all people
    int num_people = sizeof(people) / sizeof(Person);
    int total_age = 0;
    float total_height = 0.0;
    float total_weight = 0.0;
    for (int i = 0; i < num_people; i++) {
        total_age += people[i].age;
        total_height += people[i].height;
        total_weight += people[i].weight;
    }
    float avg_age = (float)total_age / num_people;
    float avg_height = total_height / num_people;
    float avg_weight = total_weight / num_people;
    printf("Average age: %.1f\n", avg_age);
    printf("Average height: %.1f\n", avg_height);
    printf("Average weight: %.1f\n", avg_weight);

    // Find the person with the highest weight
    float max_weight = 0.0;
    int max_weight_index = -1;
    for (int i = 0; i < num_people; i++) {
        if (people[i].weight > max_weight) {
            max_weight = people[i].weight;
            max_weight_index = i;
        }
    }
    printf("The heaviest person is %s (id=%d)\n", people[max_weight_index].name, people[max_weight_index].id);

    // Group people by age
    int age_min = 20;
    int age_max = 40;
    int num_groups = 4;
    Person* groups[num_groups];
    int group_sizes[num_groups];
    memset(group_sizes, 0, sizeof(group_sizes));
    for (int i = 0; i < num_people; i++) {
        int age = people[i].age;
        if (age >= age_min && age <= age_max) {
            int group_index = (age - age_min) * num_groups / (age_max - age_min + 1);
            group_sizes[group_index]++;
        }
    }
    for (int i = 0; i < num_groups; i++) {
        groups[i] = (Person*)malloc(group_sizes[i] * sizeof(Person));
        group_sizes[i] = 0;
    }
    for (int i = 0; i < num_people; i++) {
        int age = people[i].age;
        if (age >= age_min && age <= age_max) {
            int group_index = (age - age_min) * num_groups / (age_max - age_min + 1);
            groups[group_index][group_sizes[group_index]] = people[i];
            group_sizes[group_index]++;
        }
    }
    for (int i = 0; i < num_groups; i++) {
        printf("Group %d:\n", i+1);
        for (int j = 0; j < group_sizes[i]; j++) {
            printf("  %s (id=%d, age=%d)\n", groups[i][j].name, groups[i][j].id, groups[i][j].age);
        }
        free(groups[i]);
    }
    
    return 0;
}