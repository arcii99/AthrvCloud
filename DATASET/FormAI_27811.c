//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertDate(char* date) {
    char months[12][4] = {"jan", "feb", "mar", "apr", "may", "jun", 
                          "jul", "aug", "sep", "oct", "nov", "dec"};
    int month, day, year;
    
    // Parse input date string
    sscanf(date, "%d-%3s-%d", &day, &months[0], &year);
    
    // Convert month string to integer
    for(int i = 0; i < 12; i++) {
        if(strcmp(months[i], &months[0]) == 0) {
            month = i+1;
            break;
        }
    }
    
    // Output converted date string
    printf("Converted date: %02d-%02d-%d\n", month, day, year);
}

int main() {
    char date[11];  // Maximum length of date string is 10 characters
    printf("Enter date in format (dd-mmm-yyyy): ");
    fgets(date, 11, stdin);
    convertDate(date);
    return 0;
}