//FormAI DATASET v1.0 Category: Data validation ; Style: lively
#include <stdio.h>

int main() {
    int age; //declare the variable 'age' as an integer
    
    printf("Enter your age: "); //prompt the user to enter their age
    scanf("%d", &age); //read the user's input into the variable 'age'
    
    if (age < 0) { //check if the user's age is negative
        printf("Invalid age! Age cannot be negative.\n"); //display an error message
        return 0; //terminate the program
    }
    
    if (age > 120) { //check if the user's age is too high
        printf("Invalid age! Age cannot be greater than 120.\n"); //display an error message
        return 0; //terminate the program
    }
    
    printf("Congratulations, you entered a valid age!"); //display a success message if the user's input passes both validation checks
    return 0; //terminate the program
}