//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>

// Custom data structure for a person's information
typedef struct {
    char name[50];
    int age;
    char gender;
    float height;
} Person;

int main() {

    // Create array of 5 people
    Person people[5];

    // Prompt user to input information for each person
    printf("Enter information for 5 people:\n");

    for(int i=0; i<5; i++) {
        printf("\nPerson %d:\n", i+1);

        printf("Name: ");
        scanf("%s", people[i].name);

        printf("Age: ");
        scanf("%d", &people[i].age);

        printf("Gender (M/F): ");
        scanf(" %c", &people[i].gender);

        printf("Height in meters: ");
        scanf("%f", &people[i].height);
    }

    // Visualize the data structure
    printf("\n\nData Visualization - People:\n");
    printf("---------------------------------------\n");
    printf("| %-15s | %-8s | %-8s | %-10s |\n", "Name", "Age", "Gender", "Height");
    printf("---------------------------------------\n");

    for(int i=0; i<5; i++) {
        printf("| %-15s | %-8d | %-8c | %-10.2f |\n", people[i].name, people[i].age, people[i].gender, people[i].height);
    }

    printf("---------------------------------------\n");

    return 0;
}