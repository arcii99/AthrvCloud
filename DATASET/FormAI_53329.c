//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include<stdio.h>
#include<string.h>
 
int main(){
    char input[1000], output[1000];
    printf("Enter the string to be processed: ");
    fgets(input, 1000, stdin); //reads input from the console including spaces
 
    //replace all the vowels with '*'
    for(int i=0; i<strlen(input); i++){
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' ||
           input[i] == 'o' || input[i] == 'u' || input[i] == 'A' ||
           input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U'){
            output[i] = '*';
        }
        else{
            output[i] = input[i];
        }
    }
 
    //Print the processed string
    printf("Processed string: %s", output);
 
    return 0;
}