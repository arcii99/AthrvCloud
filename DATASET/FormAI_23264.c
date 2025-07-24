//FormAI DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
    char inputString[100]; //String to hold user input
    int i, length, isKeyword; //Variables to iterate through inputString, length of inputString and check if the word is a keyword
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"}; //List of keywords in C programming language

    printf("Enter a C syntax statement:\n");
    fgets(inputString, 100, stdin); //Get user input
    length = strlen(inputString); //Get length of user input

    //Loop through inputString to check if it is a keyword
    for(i=0; i<length; i++){
        isKeyword = 0; //Initialize isKeyword to false
        char currentStr[10] = ""; //String to hold current word being evaluated
        int j = 0; //Variable to iterate through currentStr

        //If the current character is a letter or underscore, continue building the currentStr
        while(isalpha(inputString[i]) || inputString[i]=='_'){
            currentStr[j] = inputString[i];
            j++;
            i++;
        }

        //Check if currentStr matches any keyword in the keywords list
        for(int k=0; k<32; k++){
            if(strcmp(currentStr, keywords[k])==0){
                printf("%s is a C keyword.\n", currentStr);
                isKeyword = 1; //Set isKeyword to true
                break; //Exit loop if keyword is found
            }
        }

        //If the word is not a keyword, print it
        if(!isKeyword){
            printf("%s is not a C keyword.\n", currentStr);
        }
    }

    return 0;
}