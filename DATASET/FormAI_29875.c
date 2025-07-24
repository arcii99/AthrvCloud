//FormAI DATASET v1.0 Category: Text Summarizer ; Style: safe
//This C Text Summarizer program will take a text file as input and produce a summary of the file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 2000 //Assuming the maximum length of a line is 2000 characters

//Function to check if a character is a punctuation mark or not
int is_punctuation(char c) {
    if(c=='?' || c=='!' || c=='.' || c==';' || c==':') {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    //Opening the input file
    FILE *input_file = fopen("input.txt", "r");

    //Checking if the input file exists or not
    if(input_file == NULL) {
        printf("Error: File does not exist!");
        return 0;
    }

    //Opening the output file
    FILE *output_file = fopen("output.txt", "w");

    //Reading the input file line by line and summarizing it
    char current_line[MAX_LINE_LENGTH];
    while(fgets(current_line, MAX_LINE_LENGTH, input_file) != NULL) {
        int line_length = strlen(current_line);
        int sentence_start_index = 0;
        int i;

        //Looping through each character in the current line
        for(i=0; i<line_length; i++) {
            //If a punctuation mark is found, printing the current sentence to the output file
            if(is_punctuation(current_line[i])) {
                int sentence_length = i - sentence_start_index + 1; //Calculating the length of the current sentence
                char current_sentence[sentence_length+1]; //Creating an array to store the current sentence
                strncpy(current_sentence, current_line+sentence_start_index, sentence_length); //Copying the current sentence to the array
                current_sentence[sentence_length] = '\0'; //Adding a null character to the end of the sentence array

                //Writing the current sentence to the output file
                fprintf(output_file, "%s", current_sentence);

                //Updating the index to the start of the next sentence
                sentence_start_index = i+1;
            }
        }

        //Printing the last sentence of the current line to the output file
        int sentence_length = i - sentence_start_index; //Calculating the length of the last sentence in the current line
        char last_sentence[sentence_length+1]; //Creating an array to store the last sentence
        strncpy(last_sentence, current_line+sentence_start_index, sentence_length); //Copying the last sentence to the array
        last_sentence[sentence_length] = '\0'; //Adding a null character to the end of the sentence array

        //Writing the last sentence to the output file
        fprintf(output_file, "%s", last_sentence);
    }

    //Closing the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Text summarization complete. Please check the output.txt file for the summary.");

    return 0;
}