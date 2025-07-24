//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Function to convert date from natural language to standard date format
void convertToDate(char* sentence) {
    char months[12][10] = {"January", "February", "March", "April", "May", "June", 
                           "July", "August", "September", "October", "November", "December"};
    int month, day, year;
    char* number;
    char*ptr = strtok(sentence, " ");

    while(ptr != NULL) {
        if(isdigit(*ptr)) {
            number = ptr;
            // Checking if the number is greater than 31
            if(atoi(number) > 31) {
                year = atoi(number);
            } else {
                day = atoi(number);
            }
        } else {
            // Getting the index of the month in the array months
            for(int i=0; i<12; i++){
                if(strcmp(ptr, months[i]) == 0){
                    month = i+1;
                    break;
                }
            }
        }
        ptr = strtok(NULL, " ");
    }
    printf("The date in standard format is: %d/%d/%d\n", month, day, year);
}

int main() {
    char sentence[100];
    printf("Enter a date in natural language:\n");
    fgets(sentence, 100, stdin);
    convertToDate(sentence);
    return 0;
}