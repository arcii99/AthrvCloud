//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main(){

    char line[1024]; //buffer to store lines of the CSV file
    char* token; //pointer to current token
    int count = 0; //count of number of lines read
    int row, col;

    //open the CSV file
    FILE* csv_file = fopen("example.csv", "r");

    //while there are still lines to read, do the following
    while (fgets(line, 1024, csv_file)){

        //print the current line
        printf("Line %i:\n", count);
        printf("%s\n", line);

        //parse the line for commas (or other chosen delimiter)
        token = strtok(line, ",");

        //while there are still tokens to be read, do the following
        while (token != NULL){

            //print the current token
            printf("Token: %s\n", token);

            //get the next token in the line
            token = strtok(NULL, ",");
        }
        count++;
    }

    //close the CSV file
    fclose(csv_file);

    return 0;
}