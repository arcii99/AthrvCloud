//FormAI DATASET v1.0 Category: Data validation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
    char inputGrade[4];
    int grade;
    
    printf("Enter your grade (0-100): ");
    fgets(inputGrade, 4, stdin);
    
    // Validate input
    for(int i=0; inputGrade[i] != '\0'; i++) {
        if(!isdigit(inputGrade[i])) {
            printf("Error: Invalid input\n");
            return 1;
        }
    }
    
    // Convert input to integer
    grade = atoi(inputGrade);
    
    // Check if grade is within range
    if(grade < 0 || grade > 100) {
        printf("Error: Grade must be between 0 and 100\n");
        return 1;
    }
    
    // Output success message
    printf("Your grade is: %d\n", grade);
    
    return 0;
}