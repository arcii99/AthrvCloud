//FormAI DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_PHONE_LEN 20
#define MAX_USERS 1000

typedef struct User {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
} User;

int num_users = 0;
User users[MAX_USERS];

void add_user(char* name, char* email, char* phone) {
    User user;
    strcpy(user.name, name);
    strcpy(user.email, email);
    strcpy(user.phone, phone);
    users[num_users] = user;
    num_users++;
}

void search_user(char* name) {
    int i;
    for(i=0; i<num_users; i++) {
        if(strcmp(users[i].name, name)==0) {
            printf("Name: %s\nEmail: %s\nPhone: %s\n", users[i].name, users[i].email, users[i].phone);
            return;
        }
    }
    printf("User not found\n");
}

void print_users() {
    int i;
    for(i=0; i<num_users; i++) {
        printf("Name: %s\nEmail: %s\nPhone: %s\n", users[i].name, users[i].email, users[i].phone);
        printf("--------------------\n");
    }
}

int main() {
    add_user("John Doe", "johndoe@example.com", "123-456-7890");
    add_user("Jane Smith", "janesmith@example.com", "111-222-3333");
    add_user("Mike Johnson", "mikejohnson@example.com", "444-555-6666");

    search_user("Jane Smith");

    printf("All users:\n");
    print_users();

    return 0;
}