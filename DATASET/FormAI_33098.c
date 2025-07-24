//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include<stdio.h>
#include<string.h>

int main(void){

    char name[100];
    int age;

    printf("Welcome to the retro User Input Sanitizer!\n");
    printf("Please enter your name:\n");
    fgets(name, sizeof(name), stdin); //gets user input for name

    //sanitize name input
    for(int i = 0; name[i] != '\0'; i++){
        if(name[i] >= 97 && name[i] <= 122){ //check if lowercase letter
            name[i] = name[i] - 32; //convert to uppercase
        } else if (name[i] == '\n'){ //check for newline char
            name[i] = '\0'; //replace with null terminator
        }
    }

    printf("Please enter your age:\n");
    scanf("%d", &age); //gets user input for age

    //sanitize age input
    while(getchar() != '\n'); //clear input buffer
    if(age < 0){ //check if age is negative
        age = age * -1; //convert to positive
    }

    //print sanitized user inputs
    printf("Hello %s, your age is %d.\n", name, age);

    return 0;
}