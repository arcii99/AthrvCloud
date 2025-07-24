//FormAI DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the information for each user
typedef struct {
    int id;
    char name[50];
    int age;
    char email[50];
} user;

// Function to query the database and retrieve users with inputted age
void get_users_by_age(int age) {
    FILE *fp;
    user current_user;
    int users_found = 0;

    fp = fopen("users.db", "rb");

    // Check if file was successfully opened
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Loop through each user in the file
    while (fread(&current_user, sizeof(user), 1, fp)) {
        // Check if user's age matches inputted age
        if (current_user.age == age) {
            printf("User ID: %d\n", current_user.id);
            printf("User name: %s\n", current_user.name);
            printf("User age: %d\n", current_user.age);
            printf("User email: %s\n\n", current_user.email);
            users_found++;
        }
    }

    // Close file
    fclose(fp);

    // Check if any users were found
    if (users_found == 0) {
        printf("No users found with age %d\n", age);
    }
}

// Function to add a new user to the database
void add_user(int id, char name[], int age, char email[]) {
    FILE *fp;
    user new_user;

    // Set values for new user
    new_user.id = id;
    strcpy(new_user.name, name);
    new_user.age = age;
    strcpy(new_user.email, email);

    fp = fopen("users.db", "ab");

    // Check if file was successfully opened
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Write new user to file
    fwrite(&new_user, sizeof(user), 1, fp);

    // Close file
    fclose(fp);

    printf("User successfully added to database.\n");
}

int main() {
    // Add some example users to the database
    add_user(1, "John Smith", 25, "johnsmith@gmail.com");
    add_user(2, "Emily Davis", 32, "emilydavis@yahoo.com");
    add_user(3, "David Lee", 25, "davidlee@hotmail.com");
    add_user(4, "Sara Kim", 42, "sarakhim@gmail.com");
    add_user(5, "Tom Chen", 29, "tomchen@gmail.com");

    // Query the database for users with age 25
    get_users_by_age(25);

    return 0;
}