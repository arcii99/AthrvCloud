//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[1000]; //initialize input array to store user's input
    printf("Enter the HTML code that needs to be beautified below:\n");
    fgets(input, 1000, stdin); //read user's input and store it in input array

    int indent = 0; //initialize indent level to 0
    for(int i = 0; i < strlen(input); i++){ //loop through each character in input array
        if(input[i] == '<' && input[i+1] != '/'){ //check if opening tag is found
            printf("\n"); //start a new line for better readability
            for(int j = 0; j < indent; j++){ //add appropriate number of indents
                printf("\t"); 
            }
            printf("<"); 
            indent++; //increment indent level
        }
        else if(input[i] == '<' && input[i+1] == '/'){ //check if closing tag is found
            printf("\n"); //start a new line
            indent--; //decrement indent level
            for(int k = 0; k < indent; k++){ //add appropriate number of indents
                printf("\t"); 
            }
            printf("</"); 
        }
        else if(input[i] == '>'){ //add closing tag character and new line character
            printf(">\n");
        }
        else{ //print the character as is
            printf("%c", input[i]); 
        }
    }

    return 0;
}