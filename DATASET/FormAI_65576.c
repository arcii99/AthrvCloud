//FormAI DATASET v1.0 Category: Spell checking ; Style: introspective
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function to check if a word is spelled correctly
int spell_check(char* word);

int main() {

    char text[1000]; //input text from user
    char* word_ptr; //pointer to each word in the text
    const char delim[2] = " "; //delimiter to split the string into words
    int line_num = 1; //line number of the input text
    int word_num = 1; //word number in the line
    char* misspelled_words[50]; //array to store misspelled words
    int num_misspelled = 0; //counter for number of misspelled words
    int num_words_checked = 0; //counter for number of words checked
    int i; //loop variable

    printf("Enter text to be spell checked:\n");
    fgets(text,1000,stdin); //get text from user

    //split text into individual words
    word_ptr = strtok(text,delim);
    while (word_ptr != NULL) {
        num_words_checked++;
        if (!spell_check(word_ptr)) {
            misspelled_words[num_misspelled] = word_ptr;
            num_misspelled++;
        }
        //check for end of line
        if (word_ptr[strlen(word_ptr)-1] == '\n') {
            word_num = 1;
            line_num++;
        }
        else {
            word_num++;
        }
        word_ptr = strtok(NULL,delim);
    }

    //print out misspelled words
    if (num_misspelled == 0) {
        printf("\nNo misspelled words found!\n");
    } else {
        printf("\nMisspelled words found:\n");
        for (i = 0; i < num_misspelled; i++) {
            printf("%s\n",misspelled_words[i]);
        }
    }
    printf("\n%d words checked in %d lines\n",num_words_checked,line_num);

    return 0;
}

//function to check if a word is spelled correctly
int spell_check(char* word) {
    //for this example, we will assume any word is spelled correctly
    return 1;
}