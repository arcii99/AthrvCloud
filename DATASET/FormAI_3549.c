//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LEN 1000 // maximum input length
#define MAX_OUTPUT_LEN 1000 // maximum output length

void c_cat_to_english(char* c_cat_input, char* english_output){
    char english_word[60]; // define a string to hold english word equivalent to c-cat word
    int current_index = 0;
    int output_index = 0;
    int input_len = strlen(c_cat_input);

    // iterate over each character of the c-cat input
    while(current_index < input_len){
        switch(c_cat_input[current_index]){
            case 'M':
                strcpy(english_word, "Meow");
                break;
            case 'P':
                strcpy(english_word, "Purr");
                break;
            case 'H':
                strcpy(english_word, "Hiss");
                break;
            case 'C':
                strcpy(english_word, "Chirp");
                break;
            case 'T':
                strcpy(english_word, "Trill");
                break;
            case 'F':
                strcpy(english_word, "Flick");
                break;
            case 'S':
                strcpy(english_word, "Scratch");
                break;
            case 'D':
                strcpy(english_word, "Drink");
                break;
            case 'A':
                strcpy(english_word, "Attention");
                break;
            case 'N':
                strcpy(english_word, "Nap");
                break;
            case 'E':
                strcpy(english_word, "Explore");
                break;
            case 'R':
                strcpy(english_word, "Relax");
                break;
            case 'B':
                strcpy(english_word, "Bite");
                break;
            case 'G':
                strcpy(english_word, "Groom");
                break;
            case 'K':
                strcpy(english_word, "Paw");
                break;
            case 'L':
                strcpy(english_word, "Lick");
                break;
            case 'Q':
                strcpy(english_word, "Quiet");
                break;
            case 'U':
                strcpy(english_word, "Up");
                break;
            case 'W':
                strcpy(english_word, "Warm");
                break;
            case 'Y':
                strcpy(english_word, "Yes");
                break;
            case 'Z':
                strcpy(english_word, "Zoom");
                break;
            default:
                strcpy(english_word, "");
                break;
        }

        // add the english word to the output string
        int word_len = strlen(english_word);
        for(int i=0; i<word_len; i++){
            english_output[output_index] = english_word[i];
            output_index++;
        }

        current_index++;
    }

    // terminate the output string
    english_output[output_index] = '\0';
}

int main(){
    char c_cat_input[MAX_INPUT_LEN];
    char english_output[MAX_OUTPUT_LEN];

    // get input from user
    printf("Enter your message in c cat language: ");
    fgets(c_cat_input, MAX_INPUT_LEN, stdin);
    c_cat_input[strcspn(c_cat_input, "\n")] = 0; // remove trailing newline character

    // convert c-cat to english
    c_cat_to_english(c_cat_input, english_output);

    // print output
    printf("Your message in english: %s\n", english_output);

    return 0;
}