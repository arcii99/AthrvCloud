//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

/*Function that extracts metadata from file and saves it to structured data*/
void extract_metadata(char* filename){
    FILE *fp;
    char ch = ' ';
    char line[MAX_STRING_LENGTH];
    char *token;

    //open the file
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    //initialize metadata struct
    struct metadata {
        char author[MAX_STRING_LENGTH];
        char date[MAX_STRING_LENGTH];
        char description[MAX_STRING_LENGTH];
    } data;

    //initialize counter variables
    int author_index = 0;
    int date_index = 0;
    int description_index = 0;

    /*Read the file line by line and extract metadata*/
    while(ch != EOF){
        fgets(line, sizeof(line), fp);
        token = strtok(line, ":\n");

        /*Assign author, date and description fields based on keywords*/
        while(token != NULL){
            if(strcmp(token, "Author") == 0){
                token = strtok(NULL, ":\n");
                strncpy(data.author, token, MAX_STRING_LENGTH);
                author_index++;
            } else if(strcmp(token, "Date") == 0){
                token = strtok(NULL, ":\n");
                strncpy(data.date, token, MAX_STRING_LENGTH);
                date_index++;
            } else if(strcmp(token, "Description") == 0){
                token = strtok(NULL, ":\n");
                strncpy(data.description, token, MAX_STRING_LENGTH);
                description_index++;
            }
            token = strtok(NULL, ":\n");
        }
        ch = fgetc(fp);
    }

    //Print the metadata values and exit gracefully
    printf("Author: %s\n", data.author);
    printf("Date: %s\n", data.date);
    printf("Description: %s\n", data.description);

    //Check if all three fields are present and exit with appropriate messages
    if(author_index == 0){
        printf("Error: Author field is missing\n");
        exit(1);
    }
    if(date_index == 0){
        printf("Error: Date field is missing\n");
        exit(1);
    }
    if(description_index == 0){
        printf("Error: Description field is missing\n");
        exit(1);
    }

    printf("Metadata extraction successful!\n");
    fclose(fp);
}

/*Main function that takes filename as input and calls metadata extraction function*/
int main(int argc, char* argv[]){
    if(argc > 1){
        extract_metadata(argv[1]);
    } else {
        printf("Error: No input file provided\n");
        exit(1);
    }
    return 0;
}