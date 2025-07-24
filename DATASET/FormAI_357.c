//FormAI DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>

// function that checks if a system is healthy
int check_health() {
    printf("Checking system health...\n");

    // randomize health status
    srand(time(NULL));
    int health = rand() % 2;

    if (health) {
        printf("System is healthy!\n");
    } else {
        printf("System is not healthy!\n");
    }

    return health;
}

// function that fixes a broken system
void fix_system() {
    printf("Fixing system...\n");
    // some code to fix the system here...
    printf("System fixed!\n");
}

// main function to check and fix the system
int main() {
    printf("Welcome to the System Health Checker!\n");

    int health = check_health();
    if (!health) {
        fix_system();
        health = check_health();
    }

    printf("System is ready for operation!\n");

    return 0;
}