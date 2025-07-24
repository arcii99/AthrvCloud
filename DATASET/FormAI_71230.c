//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100 

int main(){
    char string[MAX_LENGTH], newString[MAX_LENGTH];
    int option, length, i, j, k;

    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);
    length = strlen(string);

    printf("What operation do you want to perform on the string?\n");
    printf("1. Reverse the string.\n");
    printf("2. Remove all vowels.\n");
    scanf("%d", &option);

    switch(option){
        case 1:{
            for(i=length-2, j=0; i>=0; i--, j++){
                newString[j] = string[i];
            }
            newString[length-1] = '\0'; 
            printf("The reversed string is: %s\n", newString);
            break;
        }
        case 2:{
            for(i=0, j=0; i<length-1; i++){
                if(string[i]!='a'&&string[i]!='e'&&string[i]!='i'&&string[i]!='o'&&string[i]!='u'&&string[i]!='A'&&string[i]!='E'&&string[i]!='I'&&string[i]!='O'&&string[i]!='U'){
                    newString[j] = string[i];
                    j++;
                }
            }
            newString[j] = '\0';
            printf("The string with vowels removed is: %s\n", newString);
            break;
        }
        default:{
            printf("Please choose a valid option.\n");
        }
    }

    return 0;
}