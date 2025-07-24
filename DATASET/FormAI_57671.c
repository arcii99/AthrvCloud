//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 //maximum length of a line in the CSV file
#define MAX_FIELDS 20 //maximum number of fields in a row

int read_csv(char* filename, char*** fields_arr_ptr) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s", filename);
        return -1;
    }

    char* line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char)); //allocate memory for a line
    char* field = (char*) malloc(MAX_LINE_LENGTH * sizeof(char)); //allocate memory for a field
    char** fields_arr = (char**) malloc(MAX_FIELDS * sizeof(char*)); //allocate memory for an array of fields
    int num_fields = 0; //number of fields in a row

    while(fgets(line, MAX_LINE_LENGTH, fp)) { //read the file line by line
        line[strcspn(line, "\n")] = 0; //remove the new line character '\n'
        
        char* temp_line = strdup(line); //create a copy of the line to avoid modifying the original line
        int field_num = 0; //field number in the current row

        while((field = strsep(&temp_line, ",")) != NULL) { //split the line into fields using ',' as a delimiter
            
            if(num_fields >= MAX_FIELDS) { //check if the maximum number of fields is exceeded
                printf("Error: Maximum number of fields exceeded\n");
                return -1;
            }

            fields_arr[field_num] = strdup(field); //add the field to the array of fields
            field_num++;
            num_fields++;
        }
        free(temp_line); //free the memory allocated for the copy of the line
        *fields_arr_ptr = fields_arr; //pass the array of fields to the calling function
    }

    free(line); //free the memory allocated for a line
    fclose(fp); //close the file

    return num_fields; //return the total number of fields in the CSV file
}

int main() {
    char** fields_arr = NULL;
    int num_fields = read_csv("example.csv", &fields_arr); //read the CSV file and get the array of fields

    if(num_fields == -1) { //check if there is an error in reading the file
        printf("Error reading CSV file");
        return -1;
    }

    printf("Total number of fields in the CSV file: %d\n", num_fields);

    for(int i = 0; i < num_fields; i++) {
        printf("%s, ", fields_arr[i]); //print each field
    }

    printf("\n");

    return 0;
}