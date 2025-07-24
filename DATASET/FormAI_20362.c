//FormAI DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Function to check if string is valid */
int is_str_valid(char *str){
    int i;
    for(i = 0; i < strlen(str); i++){
        if(!isalpha(str[i]) && !isspace(str[i])){
            return 0;
        }
    }
    return 1;
}

/* Function to convert string to lowercase */
void convert_lowercase(char *str){
    int i;
    for(i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }
}

/* Function to remove leading and trailing whitespace */
void trim(char *str){
    char *end;

    /* Trim leading whitespace */
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0) return; /* All whitespace */

    /* Trim trailing whitespace */
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    /* Write new null terminator */
    *(end+1) = 0;
}

/* Function to spell check a given string */
void spell_check(char *input, FILE *dict){
    char word[100];
    int i, found, line_count = 0;

    /* Convert input to lowercase and trim whitespace */
    convert_lowercase(input);
    trim(input);

    /* Split input into words */
    char *token = strtok(input, " ");
    while(token != NULL){

        /* Check if word is valid */
        if(is_str_valid(token)){

            /* Reset dictionary file position */
            fseek(dict, 0, SEEK_SET);
            found = 0;

            /* Check if word is in dictionary */
            while(fgets(word, sizeof(word), dict)){

                /* Convert dictionary word to lowercase and trim whitespace */
                convert_lowercase(word);
                trim(word);

                /* Check if word matches dictionary word */
                if(strcmp(token, word) == 0){
                    found = 1;
                    break;
                }
            }

            /* Print message if word is not found */
            if(!found){
                printf("Error at line %d: '%s' is not in dictionary\n", line_count+1, token);
            }
        }

        /* Get next word in input */
        token = strtok(NULL, " ");
        line_count++;
    }
}

int main(){
    char input[1000];
    int i;
    FILE *dict = fopen("dictionary.txt", "r");

    /* Check if dictionary file exists */
    if(!dict){
        printf("Error: Could not open dictionary file\n");
        return 0;
    }

    /* Get input from user */
    printf("Enter text to be spell checked:\n");
    fgets(input, sizeof(input), stdin);

    /* Check spelling */
    spell_check(input, dict);

    /* Close dictionary file */
    fclose(dict);

    return 0;
}