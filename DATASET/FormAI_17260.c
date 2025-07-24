//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

int main(){

    char curr_char;
    char prev_char = '\0';
    int unique_chars_count = 0;
    bool is_prev_space = false;

    printf("Enter the input string to scan for intrusion detection:\n");

    while((curr_char = getchar()) != EOF){

        // Check if curr_char is uppercase letter and prev_char is not uppercase letter
        if(isupper(curr_char) && !isupper(prev_char)){
            unique_chars_count++;
        }
        // Check if curr_char is lowercase letter and prev_char is not lowercase letter
        else if(islower(curr_char) && !islower(prev_char)){
            unique_chars_count++;
        }
        // Check if curr_char is digit and prev_char is not digit
        else if(isdigit(curr_char) && !isdigit(prev_char)){
            unique_chars_count++;
        }
        // Check if curr_char is whitespace and prev_char is not whitespace
        else if(isspace(curr_char) && !is_prev_space){
            unique_chars_count++;
            is_prev_space = true;
        }
        else{
            // Do nothing
        }

        prev_char = curr_char;
    }

    printf("Number of unique character types found: %d\n", unique_chars_count);

    // Check if count of unique character types exceeds threshold
    if(unique_chars_count > 3){
        printf("Intrusion detected!\n");
    }
    else{
        printf("No intrusion detected.\n");
    }

    return 0;
}