//FormAI DATASET v1.0 Category: System administration ; Style: post-apocalyptic
/* Post-apocalyptic system administration program */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_USERS 10
#define MAX_RESOURCES 5

/* Struct for holding user information */
typedef struct user {
    char name[20];
    int id;
    int resources[MAX_RESOURCES];
} User;

/* Struct for holding resource information */
typedef struct resource {
    char name[20];
    int id;
    bool is_safe;
} Resource;

/* Function for generating random number between min and max */
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function for printing resource information */
void print_resource(Resource r) {
    printf("[ID: %d | Name: %s | Safe: %s]\n", r.id, r.name, r.is_safe ? "yes" : "no");
}

/* Function for printing user information */
void print_user(User u) {
    printf("[ID: %d | Name: %s | Resources: ", u.id, u.name);
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%d ", u.resources[i]);
    }
    printf("]\n");
}

int main() {
    /* Seed random number generator */
    srand(time(NULL));
    
    /* Initialize resources */
    Resource resources[MAX_RESOURCES] = {
        {"Water", 1, false},
        {"Food", 2, false},
        {"Medicine", 3, true},
        {"Ammunition", 4, false},
        {"Tools", 5, true}
    };
    
    /* Initialize users */
    User users[MAX_USERS] = {
        {"John", 1, {0, 0, 0, 0, 0}},
        {"Sarah", 2, {0, 0, 0, 0, 0}},
        {"Mark", 3, {0, 0, 0, 0, 0}},
        {"Emily", 4, {0, 0, 0, 0, 0}},
        {"David", 5, {0, 0, 0, 0, 0}},
        {"Beth", 6, {0, 0, 0, 0, 0}},
        {"Paul", 7, {0, 0, 0, 0, 0}},
        {"Ava", 8, {0, 0, 0, 0, 0}},
        {"Peter", 9, {0, 0, 0, 0, 0}},
        {"Linda", 10, {0, 0, 0, 0, 0}}
    };
    
    /* Print initial state */
    printf("Resources:\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        print_resource(resources[i]);
    }
    printf("\nUsers:\n");
    for (int i = 0; i < MAX_USERS; i++) {
        print_user(users[i]);
    }
    
    /* Simulate resource gathering and sharing */
    for (int i = 0; i < 10; i++) {
        /* Choose random user and resource */
        int user_index = random_number(0, MAX_USERS - 1);
        int resource_index = random_number(0, MAX_RESOURCES - 1);
        
        /* If resource is safe, increment user's resource count */
        if (resources[resource_index].is_safe) {
            users[user_index].resources[resource_index]++;
            printf("User %s (ID: %d) gathered 1 %s.\n", users[user_index].name, users[user_index].id, resources[resource_index].name);
        }
        /* If resource is not safe, decrement user's health */
        else {
            users[user_index].resources[resource_index]--;
            printf("User %s (ID: %d) lost 1 health due to unsafe %s.\n", users[user_index].name, users[user_index].id, resources[resource_index].name);
        }
        
        /* Choose random users to share resources */
        int user_index_1 = random_number(0, MAX_USERS - 1);
        int user_index_2 = random_number(0, MAX_USERS - 1);
        if (user_index_1 != user_index_2) {
            /* Choose random resource to share */
            int resource_index = random_number(0, MAX_RESOURCES - 1);
            
            /* If both users have at least one of the resource, share it */
            if (users[user_index_1].resources[resource_index] > 0 && users[user_index_2].resources[resource_index] > 0) {
                users[user_index_1].resources[resource_index]--;
                users[user_index_2].resources[resource_index]++;
                printf("User %s (ID: %d) gave 1 %s to User %s (ID: %d).\n", users[user_index_1].name, users[user_index_1].id, resources[resource_index].name, users[user_index_2].name, users[user_index_2].id);
            }
        }
    }
    
    /* Print final state */
    printf("\nFinal users state:\n");
    for (int i = 0; i < MAX_USERS; i++) {
        print_user(users[i]);
    }
    
    return 0;
}