//FormAI DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int dataMining(char* filename) {
    FILE* fp;
    char line[1024];
    int linecount=0, numberofWords=0, numOfChars = 0, numOfCommas=0;
    fp=fopen(filename, "r"); // Open file for read mode
    if(fp==NULL) { // Test whether the file is opened successfully or not
        printf("Error Opening File\n");
        return 1;
    }

    while(fgets(line,1024,fp)) {  //Read one line at a time
        linecount++; // Counting number of lines
        numOfChars += strlen(line); // Counting total number of characters
        char *token = strtok(line, ","); // Parsing the line to get individual words or phrases
        while(token != NULL) {
            numberofWords++;  // Counting number of words
            if(strchr(token, '-') != NULL) {
                numOfCommas++;  // Counting number of punctuations
            }
            token = strtok(NULL, ",");
        }
    }

    fclose(fp); // Closing the file
    printf("\nTotal Number of Lines in File: %d", linecount);
    printf("\nTotal Number of Words in File: %d", numberofWords);
    printf("\nTotal Number of Characters in File: %d", numOfChars);
    printf("\nTotal Number of Punctuations in File: %d", numOfCommas);

    return 0;
}

int main() {
    int result = dataMining("murder_case_evidence.txt"); // Pass the filename containing evidence of the murder case to compute the results

    if(result == 1) {
        printf("\nData Mining Unsuccessful.\n");
    }
    else {
        printf("\nData Mining Successful\n");
    }
    
    return 0;
}