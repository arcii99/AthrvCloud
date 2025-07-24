//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the structure for Romeo
struct Romeo {
    char name[20];
    int age;
    char status[20];
};

// Defining the structure for Juliet
struct Juliet {
    char name[20];
    int age;
    char status[20];
};

// Defining the structure for the relationship between Romeo and Juliet
struct Relationship {
    struct Romeo romeo;
    struct Juliet juliet;
    int years_together;
};

// Function to display the relationship status
void displayRelationshipStatus(struct Relationship r) {
    printf("%s and %s have been together for %d years and their status is '%s\n", 
    r.romeo.name, r.juliet.name, r.years_together, r.romeo.status);
}

int main() {
    struct Romeo romeo1;
    struct Juliet juliet1;
    struct Relationship relationship1;

    // Initializing the values for Romeo1
    strcpy(romeo1.name, "Romeo Montague");
    romeo1.age = 20;
    strcpy(romeo1.status, "In Love");

    // Initializing the values for Juliet1
    strcpy(juliet1.name, "Juliet Capulet");
    juliet1.age = 18;
    strcpy(juliet1.status, "In Love");

    // Initializing the values for Relationship 1
    relationship1.romeo = romeo1;
    relationship1.juliet = juliet1;
    relationship1.years_together = 3;

    // Displaying the relationship status of Romeo1 and Juliet1
    printf("\n\n\n%i %i", sizeof(romeo1), sizeof(juliet1));    
    displayRelationshipStatus(relationship1);

    return 0;
}