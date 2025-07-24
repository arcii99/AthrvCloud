//FormAI DATASET v1.0 Category: Database querying ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int age;
    float height;
    float weight;
} Person;

int main() {
    FILE *data_file;
    data_file = fopen("people_data.dat", "w");

    if (data_file == NULL) {
        printf("Error opening data file.");
        exit(1);
    }

    int num_people = 5;
    Person people[num_people];

    // Generate random data for the people
    srand(0);
    for (int i = 0; i < num_people; i++) {
        people[i].age = (rand() % 30) + 20; // Ages between 20 and 50
        people[i].height = ((float)rand() / RAND_MAX) * (1.9 - 1.5) + 1.5; // Heights between 1.5 and 1.9
        people[i].weight = ((float)rand() / RAND_MAX) * (110 - 60) + 60; // Weights between 60 and 110
    }

    // Write data to file
    for (int i = 0; i < num_people; i++) {
        fwrite(&people[i], sizeof(Person), 1, data_file);
    }

    // Query the data
    int min_age = 25;
    float min_height = 1.7;

    printf("People who are at least %d years old and taller than %f meters:\n", min_age, min_height);

    rewind(data_file);

    for (int i = 0; i < num_people; i++) {
        Person p;
        fread(&p, sizeof(Person), 1, data_file);

        bool meets_criteria = (p.age >= min_age) && (p.height >= min_height);

        if (meets_criteria) {
            printf("Person %d: Age=%d, Height=%.2f, Weight=%.2f\n", i+1, p.age, p.height, p.weight);
        }
    }

    // Close the file
    fclose(data_file);

    return 0;
}