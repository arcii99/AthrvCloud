//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <string.h>

// Define the structure of our database table
typedef struct {
    int id;
    char username[50];
    char password[50];
    int age;
} User;

// Define our array of users (our "database")
User users[100];

// Define the number of users currently in the database
int num_users = 0;

// Function to add a new user to the database
void add_user(int id, char *username, char *password, int age) {
    User new_user;
    new_user.id = id;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    new_user.age = age;
    users[num_users] = new_user;
    num_users++;
}

// Function to print a user's information
void print_user(User u) {
    printf("User ID: %d\n", u.id);
    printf("Username: %s\n", u.username);
    printf("Password: %s\n", u.password);
    printf("Age: %d\n", u.age);
}

// Function to search for a user by ID
User find_user_by_id(int id) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (users[i].id == id) {
            return users[i];
        }
    }
    // If we didn't find the user, return an empty user struct
    User empty_user;
    empty_user.id = -1;
    return empty_user;
}

// Function to update a user's password by ID
void update_password(int id, char *new_password) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (users[i].id == id) {
            strcpy(users[i].password, new_password);
            printf("Password updated!\n");
            return;
        }
    }
    printf("User not found!\n");
}

// Main program function
int main() {
    // Add some users to our database
    add_user(1, "jane_doe", "password123", 25);
    add_user(2, "john_doe", "qwerty", 30);

    // Find and print a user by ID
    User user1 = find_user_by_id(1);
    print_user(user1);

    // Update a user's password
    update_password(2, "new_password");

    // Print all users in the database
    int i;
    for (i = 0; i < num_users; i++) {
        printf("User %d:\n", i+1);
        print_user(users[i]);
    }

    return 0;
}