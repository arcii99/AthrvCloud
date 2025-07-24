//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayResult(char *result);

int main() {
    char inputDate[20];
    char outputDate[20];
    char outputFormat[20];
    char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Enter the date in Cyberpunk style (YYYY/XXX/M/D): ");
    fgets(inputDate, 20, stdin);
    inputDate[strcspn(inputDate, "\n")] = 0;

    int year = atoi(strtok(inputDate, "/"));
    int dayOfYear = atoi(strtok(NULL, "/"));
    int monthIndex = dayOfYear / 28 + 1;
    int dayOfMonth = dayOfYear % 28 + 1;

    if(year < 2077) {
        strcpy(outputFormat, "DD-MM-YYYY");
        sprintf(outputDate, "%02d-%02d-%04d", dayOfMonth, monthIndex, year);
    } else {
        strcpy(outputFormat, "MMM D YYYY");
        sprintf(outputDate, "%s %d %04d", month[monthIndex - 1], dayOfMonth, year);
    }

    char finalOutput[50];
    strcpy(finalOutput, "The date in the Cyberpunk era is: ");
    strcat(finalOutput, outputDate);
    strcat(finalOutput, " (");
    strcat(finalOutput, outputFormat);
    strcat(finalOutput, ")");

    displayResult(finalOutput);

    return 0;
}

void displayResult(char *result) {
    printf("\n\n*************************************\n");
    printf("%s", result);
    printf("\n*************************************\n");
}