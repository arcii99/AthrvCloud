//FormAI DATASET v1.0 Category: Educational ; Style: realistic
#include<stdio.h>

int main(){
    char name[50]; // declare a character array to store the user's name
    int age; // declare a variable to store user's age
    float gpa; // declare a variable to store user's gpa

    // ask for user's name
    printf("Enter your name: ");
    scanf("%s", name);

    // ask for user's age
    printf("Enter your age: ");
    scanf("%d", &age);

    // ask for user's gpa
    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    // print the user's information
    printf("Name: %s \n", name);
    printf("Age: %d \n", age);
    printf("GPA: %.2f \n", gpa);

    // check if the user's gpa is above 3.0
    if(gpa > 3.0){
        printf("Congratulations, you are eligible for the Dean's List!");
    }
    else{
        printf("Sorry, you are not eligible for the Dean's List.");
    }

    return 0;
}