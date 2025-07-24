//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user {
    char name[30];
    int age;
    float height;
} User;

int compareUsers(const void *a, const void *b) {
    User *userA = (User *)a;
    User *userB = (User *)b;

    // Sort by age, then height, then name
    if (userA->age != userB->age) {
        return userA->age - userB->age;
    } else if (userA->height != userB->height) {
        return (userA->height > userB->height) ? 1 : -1;
    } else {
        return strcmp(userA->name, userB->name);
    }
}

int main() {
    int numUsers = 5;
    User users[numUsers];

    // Populate user data
    strcpy(users[0].name, "John");
    users[0].age = 26;
    users[0].height = 1.78f;

    strcpy(users[1].name, "Alice");
    users[1].age = 22;
    users[1].height = 1.65f;

    strcpy(users[2].name, "Bob");
    users[2].age = 26;
    users[2].height = 1.68f;

    strcpy(users[3].name, "Jenny");
    users[3].age = 28;
    users[3].height = 1.70f;

    strcpy(users[4].name, "Dave");
    users[4].age = 20;
    users[4].height = 1.80f;

    // Print unsorted list
    printf("Before sorting:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s (age %d, %.2f m)\n", users[i].name, users[i].age, users[i].height);
    }

    // Sort users using qsort
    qsort(users, numUsers, sizeof(User), compareUsers);

    // Print sorted list
    printf("\nAfter sorting:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s (age %d, %.2f m)\n", users[i].name, users[i].age, users[i].height);
    }

    return 0;
}