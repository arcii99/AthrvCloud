//FormAI DATASET v1.0 Category: Text processing ; Style: cheerful
#include<stdio.h>
#include<string.h>

int main(){

    printf("Hello there! Welcome to my cheerful text processing program!\n\n");

    char input[100];
    int vowelCount = 0, consonantCount = 0;
    printf("Please enter a string of text: ");
    fgets(input, 100, stdin); //fgets reads input from console

    //converting all the letters in the input string to lowercase
    for(int i = 0; i < strlen(input); i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            input[i] = input[i] + 32;
        }
    }

    //counting the number of vowels and consonants in the input string
    for(int i = 0; i < strlen(input); i++){
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'){
            vowelCount++;
        }
        else if(input[i] >= 'a' && input[i] <= 'z'){
            consonantCount++;
        }
    }

    //displaying the results
    printf("\n\nThe input string is: %s", input);
    printf("The number of vowels in the string is: %d\n", vowelCount);
    printf("The number of consonants in the string is: %d\n", consonantCount);
    
    printf("\nThank you for using my program! Have a cheerful day!");

    return 0;
}