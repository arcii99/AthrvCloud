//FormAI DATASET v1.0 Category: Data validation ; Style: innovative
#include <stdio.h>
#include <ctype.h>

int main() {
    char name[50];
    printf("Please enter your name: ");
    scanf("%[^\n]", name);
    
    // Check if name contains only letters and spaces
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            printf("Invalid input: please enter only letters and spaces.\n");
            return 1;  // Exit program with error code 1
        }
    }
    printf("Hello, %s!\n", name);
    
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    // Check if age is between 1 and 100
    if (age < 1 || age > 100) {
        printf("Invalid input: please enter an age between 1 and 100.\n");
        return 1;  // Exit program with error code 1
    }
    printf("You are %d years old.\n", age);
    
    double weight;
    printf("Please enter your weight in kilograms (e.g. 70.5): ");
    scanf("%lf", &weight);
    
    // Check if weight is between 1 and 500 
    if (weight < 1 || weight > 500) {
        printf("Invalid input: please enter a weight between 1 and 500 kilograms.\n");
        return 1;  // Exit program with error code 1
    }
    printf("Your weight is %.1lf kilograms.\n", weight);
    
    printf("Thank you for using our program!\n");
    return 0;  // Exit program with success code 0
}