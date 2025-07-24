//FormAI DATASET v1.0 Category: Data validation ; Style: innovative
// Unique C Data Validation Example Program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char name[50];
    int age;
    double salary;
    
    // Accept String input and validate for alphabetical values only
    do {
        printf("Please enter your name (letters only): ");
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = 0; // remove the newline character from the input
        
        for(int i=0; i<strlen(name); i++){
            if(isalpha(name[i]) == 0){
                printf("Invalid Input! Please enter alphabets only.\n");
                name[0] = '\0'; // Set the first element to null to re-iterate the loop
                break;
            }
        }
    }while(name[0] == '\0'); // loop until a valid input is received
    
    // Accept numeric input for age and validate for integer values only
    do{
        printf("Please enter your age (integer only): ");
        char input_age[50];
        fgets(input_age, 50, stdin);
        input_age[strcspn(input_age, "\n")] = 0; // remove the newline character from the input
        
        // Check if each character is a digit
        int valid = 1;
        for(int i=0; i<strlen(input_age); i++){
            if(isdigit(input_age[i]) == 0){
                printf("Invalid Input! Please enter integers only.\n");
                valid = 0; // Set valid variable to 0 indicating invalid input
                break;
            }
        }
        if(valid){ // if the input is a valid integer value
            age = atoi(input_age); // convert string to integer
        }
    }while(age <= 0); // loop until a valid input is received
    
    // Accept numeric input for salary and validate for positive decimal values only
    do{
        printf("Please enter your salary (positive decimal only): ");
        char input_salary[50];
        fgets(input_salary, 50, stdin);
        input_salary[strcspn(input_salary, "\n")] = 0; // remove the newline character from the input
        
        // Check if each character is either a digit or a decimal point
        int valid = 1;
        for(int i=0; i<strlen(input_salary); i++){
            if(isdigit(input_salary[i]) == 0 && input_salary[i] != '.'){
                printf("Invalid Input! Please enter a positive decimal number.\n");
                valid = 0; // Set valid variable to 0 indicating invalid input
                break;
            }
        }
        if(valid){ // if the input is a valid decimal value
            salary = atof(input_salary); // convert string to double
        }
    }while(salary <= 0); // loop until a valid input is received
    
    // Print the validated inputs
    printf("\nThank you for providing the following details:\n");
    printf("Name : %s\n", name);
    printf("Age : %d\n", age);
    printf("Salary : %.2lf\n", salary);
    
    return 0;
}