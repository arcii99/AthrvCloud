//FormAI DATASET v1.0 Category: String manipulation ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[100];              //variable to store string
    int choice=0;               //variable to store user's choice for operation
    int len=0;                  //variable to store length of string
    char newstr[100];           //variable to store the new string after manipulation
    printf("*** Welcome to String Manipulation Program ***\n\n");
    printf("Please enter a string: ");
    scanf("%s", &str);          //taking input for string
    len = strlen(str);          //calculating length of string
    printf("\n\nThe length of the given string is %d", len);
    printf("\n\nWhat operation would you like to perform on the string?\n");
    printf("1. Reverse the string\n2. Convert to uppercase\n3. Convert to lowercase\n4. Remove a specific character\n");
    printf("Please enter your choice (1/2/3/4): ");
    scanf("%d", &choice);       //taking input for user's choice
    switch(choice){

        //operation to reverse the string
        case 1: 
            printf("\n\nOriginal string: %s", str);
            for(int i=0;i<len/2;i++) {
                char temp = str[i];
                str[i] = str[len-i-1];
                str[len-i-1] = temp;
            }
            printf("\n\nReversed string: %s", str);
            break;

        //operation to convert string to uppercase
        case 2:
            printf("\n\nOriginal string: %s", str);
            for(int i=0;i<len;i++){
                if(str[i]>=97 && str[i]<=122) {        //checking if character is lowercase
                    str[i] = str[i] - 32;               //converting character to uppercase
                }
            }
            printf("\n\nString in uppercase: %s", str);
            break;

        //operation to convert string to lowercase
        case 3:
            printf("\n\nOriginal string: %s", str);
            for(int i=0;i<len;i++){
                if(str[i]>=65 && str[i]<=90) {         //checking if character is uppercase
                    str[i] = str[i] + 32;               //converting character to lowercase
                }
            }
            printf("\n\nString in lowercase: %s", str);
            break;

        //operation to remove a specific character
        case 4: 
            char ch;
            printf("\n\nPlease enter the character you want to remove: ");
            scanf("%s",&ch);                            //taking input for character to be removed
            int j=0;
            for(int i=0;i<len;i++){
                if(str[i]!=ch){                         //checking if character is not the same as the character to be removed
                    newstr[j]=str[i];                   //adding character to new string
                    j++;
                }
            }
            newstr[j]='\0';
            printf("\n\nOriginal string: %s", str);
            printf("\n\nUpdated string: %s", newstr);
            break; 
        default: printf("\n\nInvalid choice!");
    }
    return 0;
}