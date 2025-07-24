//FormAI DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>

// Define a struct called 'Person' with the following properties: 'name', 'age', and 'address'
struct Person {
    char name[30];
    int age;
    char address[50];
};

int main() {
    // Create an instance of the 'Person' struct and initialize its properties
    struct Person person1 = {"John Doe", 30, "123 Main St"};

    // Print out the person's information
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Address: %s\n", person1.address);

    // Update the person's age to 31
    person1.age = 31;

    // Print out the person's updated information
    printf("Updated Age: %d\n", person1.age);
    
    // Create an array of 'Person' structs and initialize their properties
    struct Person people[2] = {{"Jane Smith", 25, "456 Oak Ave"}, {"Bob Johnson", 45, "789 Cherry St"}};

    // Loop through the array and print out each person's information
    for (int i = 0; i < 2; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Address: %s\n", people[i].address);
    }
    
    return 0;
}