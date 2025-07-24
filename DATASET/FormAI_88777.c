//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int main() {
    char months[12][10] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char inputDate[20];

    printf("Enter date in natural language (Example: February 20th, 2022): ");
    fgets(inputDate, sizeof(inputDate), stdin);

    char month[10], ordinal[5];
    int day, year;

    if (sscanf(inputDate, "%s %d%s %d", month, &day, ordinal, &year) == 4) {
        int index;
        for (index = 0; index < 12; index++) {
            if (strcmp(months[index], month) == 0) {
                break;
            }
        }
        if (index >= 12 || day < 1 || day > daysInMonth[index] || year < 0) {
            printf("Invalid input!\n");
            return 1;
        }
        printf("Input is: %d-%02d-%02d\n", year, index + 1, day);
    }
    else {
        printf("Invalid input!\n");
        return 1;
    }
    return 0;
}