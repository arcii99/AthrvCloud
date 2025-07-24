//FormAI DATASET v1.0 Category: Audio processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

    char input[100], c;
    int i, j, k;

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    //Converting all characters to lowercase
    for(i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    //Replacing "love" with "adore"
    char *result = strstr(input, "love");
    if(result != NULL){
        char new_str[] = "adore";
        memcpy(result, new_str, strlen(new_str));
    }

    //Replacing "heart" with "soul"
    result = strstr(input, "heart");
    if(result != NULL){
        char new_str[] = "soul";
        memcpy(result, new_str, strlen(new_str));
    }

    //Inserting "my" before "love"
    result = strstr(input, "adore");
    if(result != NULL){
        int position = result - input;
        char new_str[] = "my adore";
        memmove(&input[position+6], &input[position], strlen(input)-position);
        memcpy(&input[position], new_str, strlen(new_str));
    }

    //Inserting "forever" after "soul"
    result = strstr(input, "soul");
    if(result != NULL){
        int position = result - input;
        char new_str[] = "forever soul";
        memmove(&input[position+4], &input[position], strlen(input)-position);
        memcpy(&input[position], new_str, strlen(new_str));
    }

    printf("Your romanticized string is: %s", input);

    return 0;
}