//FormAI DATASET v1.0 Category: Log analysis ; Style: genious
#include <stdio.h>
#include <string.h>

//function to parse the log file and count the occurrences of each error
void parseLog(FILE *logFile, char errors[][50], int counts[], int *numErrors) {
    char line[500];
    while(fgets(line, 500, logFile)) { //read each line of the log file
        char *error = strstr(line, "ERROR: "); //search for the string "ERROR: " in the line
        if(error != NULL) { //if "ERROR: " is found
            char errorMsg[50];
            sscanf(error+7, "%s", errorMsg); //extract the error message
            int i;
            for(i = 0; i < *numErrors; i++) { //check if this error has already been encountered
                if(strcmp(errors[i], errorMsg) == 0) { //if the error message already exists in the errors array
                    counts[i]++; //increment the count for that error message
                    break;
                }
            }
            if(i == *numErrors) { //if the error message is encountered for the first time
                strcpy(errors[*numErrors], errorMsg); //add the error message to the errors array
                counts[*numErrors] = 1; //set the count for that error message to 1
                (*numErrors)++; //increment the number of unique error messages encountered
            }
        }
    }
}

int main() {
    FILE *logFile = fopen("example.log", "r");
    char errors[50][50]; //array to store the unique error messages
    int counts[50]; //array to store the number of occurrences of each error message
    int numErrors = 0;
    parseLog(logFile, errors, counts, &numErrors); //parse the log file and count the occurrences of each error
    fclose(logFile);

    int i;
    printf("Unique Errors:\n");
    for(i = 0; i < numErrors; i++) {
        printf("%s: %d\n", errors[i], counts[i]); //print the unique error messages and their counts
    }
    return 0;
}