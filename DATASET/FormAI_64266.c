//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h> //include standard input-output header file

int main() // declaring main function
{
    int a, b, c, d; //declaring four integer variables
    printf("Welcome to the Alien Language Translator Program\n"); //displaying welcome message for the user
    printf("Enter the first digit of the Alien Language Code: \n"); //prompting the user to enter first digit of the code
    scanf("%d", &a); //taking user input for first digit of the code
   
   //checking if the entered digit is correct, if not, prompting the user to enter again
    while (a != 1){
        printf("Invalid Input. Please enter the correct first digit of the Alien Language Code: \n");
        scanf("%d", &a);
    }
    
    printf("Enter the second digit of the Alien Language Code: \n"); //prompting the user to enter second digit of the code
    scanf("%d", &b); //taking user input for second digit of the code

   //checking if the entered digit is correct, if not, prompting the user to enter again
    while (b != 2){
        printf("Invalid Input. Please enter the correct second digit of the Alien Language Code: \n");
        scanf("%d", &b);
    }

    printf("Enter the third digit of the Alien Language Code: \n");//prompting the user to enter third digit of the code
    scanf("%d", &c); //taking user input for third digit of the code

   //checking if the entered digit is correct, if not, prompting the user to enter again
    while (c != 3){
        printf("Invalid Input. Please enter the correct third digit of the Alien Language Code: \n");
        scanf("%d", &c);
    }

    printf("Enter the fourth digit of the Alien Language Code: \n");//prompting the user to enter fourth digit of the code
    scanf("%d", &d); //taking user input for fourth digit of the code
   
   //checking if the entered digit is correct, if not, prompting the user to enter again
    while (d != 4){
        printf("Invalid Input. Please enter the correct fourth digit of the Alien Language Code: \n");
        scanf("%d", &d);
    }

    printf("\nAlien Language Code Validated Successfully!\n\n"); //displaying message for successful validation of the code
    printf("The Alien Language Code translates to: \n"); //displaying message for the translation
    printf("Hello World!\n"); //displaying the translated message in Alien Language
    
    return 0; //returning 0 if program runs successfully
}