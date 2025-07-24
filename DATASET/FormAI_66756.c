//FormAI DATASET v1.0 Category: Data validation ; Style: calm
#include <stdio.h>

int main() {
    // Declare variables
    int age;
    float height;
    char name[50];

    // Get user input
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    // Validate input
    if (age <= 0 || age >= 120) {
        printf("Invalid age. Please enter a value between 1 and 119.\n");
    }
    else if (height <= 0 || height >= 3) {
        printf("Invalid height. Please enter a value between 0.01 and 2.99 meters.\n");
    }
    else {
        printf("Hello, %s", name);
        printf("You are %d years old and %.2f meters tall.\n", age, height);
    }

    return 0;
}