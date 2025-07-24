//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LEN 50 //max length of a word
#define DICT_SIZE 100 //max size of dictionary

char dictionary[DICT_SIZE][MAX_WORD_LEN]; //dictionary array to hold valid words
int dict_size = 0; //current size of dictionary

//function to add a word to dictionary
void add_to_dict(char word[MAX_WORD_LEN]){
    strcpy(dictionary[dict_size++], word); //add the word to dictionary
}

//function to check if a word exists in dictionary
int word_exists(char word[MAX_WORD_LEN]){
    for(int i=0; i<dict_size; i++){
        if(strcmp(dictionary[i], word) == 0){
            return 1; //word exists in dictionary
        }
    }
    return 0; //word not found in dictionary
}

//function to check if a character is a valid letter
int is_letter(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1; //valid letter
    }
    return 0; //not a valid letter
}

//function to check if a word is valid
int is_valid(char word[MAX_WORD_LEN]){
    int len = strlen(word);
    if(len == 0){
        return 0; //empty word
    }
    for(int i=0; i<len; i++){
        if(!is_letter(word[i])){
            return 0; //contains non-letter character
        }
    }
    return word_exists(word); //check if word exists in dictionary
}

//function to convert a word to lowercase
void to_lower(char word[MAX_WORD_LEN]){
    int len = strlen(word);
    for(int i=0; i<len; i++){
        if(word[i] >= 'A' && word[i] <= 'Z'){
            word[i] = word[i] + 'a' - 'A'; //convert to lowercase
        }
    }
}

//function to clean the input string
void clean_str(char str[]){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(!is_letter(str[i]) && str[i] != ' '){
            str[i] = ' '; //replace non-letter characters with a space
        }
    }
}

int main(){
    char input_str[1000]; //input string
    char current_word[MAX_WORD_LEN]; //current word being checked
    int index = 0; //current index in input string
    printf("Enter a string:\n");
    fgets(input_str, sizeof(input_str), stdin); //get user input
    clean_str(input_str); //clean the input string
    //iterate through the input string
    while(index < strlen(input_str)){
        char c = input_str[index]; //current character in input string
        if(c == ' '){ //word boundary found
            if(is_valid(current_word)){ //check if the previous word was valid
                printf("%s ", current_word); //print the word if it was valid
            } else { //word not valid
                printf("*%s* ", current_word); //print the word between asterisks to indicate it is not valid
            }
            memset(current_word, 0, sizeof(current_word)); //reset current word
        } else { //add current character to current word
            current_word[strlen(current_word)] = c;
        }
        index++; //advance to next character in input string
    }
    //print the last word in the input string
    if(is_valid(current_word)){ //check if the last word was valid
        printf("%s\n", current_word); //print the word if it was valid
    } else { //word not valid
        printf("*%s*\n", current_word); //print the word between asterisks to indicate it is not valid
    }
    return 0; //exit program
}