//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: energetic
#include <stdio.h>
#include <string.h>

void naturalLanguageToNum(char sentence[]) {
    char months[12][20] = { "January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December" };
    char daySuffix[3][4] = { "st", "nd", "rd" };
    char punctuation[6][4] = { ",", ".", "!", "?", ";", ":" };

    int year = 0, month = 0, day = 0, dayNumSuffix = 0;
    char delim[] = " ";
    char *ptr = strtok(sentence, delim);

    while (ptr != NULL) {
        if (strchr(punctuation[0], ptr[strlen(ptr)-1]) != NULL) {
            ptr[strlen(ptr)-1] = '\0';
        } else if (strchr(punctuation[1], ptr[strlen(ptr)-1]) != NULL) {
            ptr[strlen(ptr)-1] = '\0';
        }

        if (ptr[0] >= '0' && ptr[0] <= '9') {
            int val = atoi(ptr);

            if (val > 31) {
                year = val;
            } else if (val > 12 && year != 0) {
                day = val;
            } else if (val <= 12 && month == 0) {
                month = val;
            } else if (dayNumSuffix == 0 && val <= 31 && month != 0) {
                day = val;
            }
        } else if (strstr(ptr, months[0]) != NULL) {
            month = 1;
        } else if (strstr(ptr, months[1]) != NULL) {
            month = 2;
        } // repeat for all months

        if (strcmp(ptr, daySuffix[0]) == 0 && dayNumSuffix == 0 && day > 0 && day < 31) {
            dayNumSuffix = 1;
        } else if (strcmp(ptr, daySuffix[1]) == 0 && dayNumSuffix == 0 && day > 0 && day < 31) {
            dayNumSuffix = 2;
        } else if (strcmp(ptr, daySuffix[2]) == 0 && dayNumSuffix == 0 && day > 0 && day < 31) {
            dayNumSuffix = 3;
        }

        ptr = strtok(NULL, delim);
    }

    printf("\nEntered date: %d%s %s %d\n", day, daySuffix[dayNumSuffix-1], months[month-1], year);
}

int main() {
    char sentence[100];
    printf("Enter date in natural language: ");
    fgets(sentence, 100, stdin);

    naturalLanguageToNum(sentence);

    return 0;
}