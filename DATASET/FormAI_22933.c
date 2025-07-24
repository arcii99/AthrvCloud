//FormAI DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Random seed for generating fake data
#define SEED 1234

// Struct representing a user in the database
typedef struct {
    int id;
    char name[50];
    int age;
    char email[100];
} User;

int main() {
    // Initialize the random seed
    srand(SEED);

    // Declare and initialize an array of 100 fake users
    User users[100];
    for (int i = 0; i < 100; i++) {
        users[i].id = i + 1;
        sprintf(users[i].name, "User %d", i + 1);
        users[i].age = rand() % 41 + 18; // Random age between 18 and 58
        sprintf(users[i].email, "user%d@example.com", i + 1);
    }

    // Query the database to find all users between the ages of 25 and 35
    printf("Finding users between ages 25 and 35...\n");
    for (int i = 0; i < 100; i++) {
        if (users[i].age >= 25 && users[i].age <= 35) {
            printf("User %d (%s) is %d years old\n", users[i].id, users[i].name, users[i].age);
        }
    }

    // Query the database to find all users with an email ending in "example.com"
    printf("Finding users with emails ending in 'example.com'...\n");
    for (int i = 0; i < 100; i++) {
        if (strstr(users[i].email, "example.com") != NULL) {
            printf("User %d (%s) has email %s\n", users[i].id, users[i].name, users[i].email);
        }
    }

    // Query the database to find all users whose name contains the letter 'o'
    printf("Finding users whose name contains the letter 'o'...\n");
    for (int i = 0; i < 100; i++) {
        if (strstr(users[i].name, "o") != NULL) {
            printf("User %d (%s) has name %s\n", users[i].id, users[i].name, users[i].email);
        }
    }

    // Sort the users by age in ascending order
    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 99; j++) {
            if (users[j].age > users[j + 1].age) {
                User temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }

    // Query the database to find the youngest user
    printf("Finding the youngest user...\n");
    printf("User %d (%s) is the youngest at %d years old\n", users[0].id, users[0].name, users[0].age);

    // Query the database to find the oldest user
    printf("Finding the oldest user...\n");
    printf("User %d (%s) is the oldest at %d years old\n", users[99].id, users[99].name, users[99].age);

    return 0;
}