//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include<stdio.h>
#include<string.h>

char* translate(char* input){
    char* output = "";      //initialize the output string
    for(int i=0; i<strlen(input); i++){   //loop through each character of input string
        if(input[i] == 'c' || input[i] == 'C'){   //if character is C or c
            strcat(output, "meow");  //append meow to output string 
        }
        else if(input[i] == ':'){  //if character is :
            strcat(output, "=^..^=");  //append =^..^= to output string
        }
        else{     //if character is anything else
            char temp[2] = {input[i], '\0'};  //create a string of single character
            strcat(output, temp);   //append the single character to output string
        }
    }
    return output;
}

int main(){
    char input[100];
    printf("Enter text to translate to C Cat Language: ");
    fgets(input, 100, stdin);   //read input string from user
    
    input[strcspn(input, "\n")] = 0;   //remove newline character from input string
    
    char* output = translate(input);   //call translate function to get the output string
    printf("Translation: %s", output);  //print the output string
    
    return 0;
}