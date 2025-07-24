//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMonthNumber(char *month) {
    int monthNumber = 0;
    char months[12][3] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; i++) {
        if (!strcasecmp(month, months[i])) {
            monthNumber = i + 1;
            break;
        }
    }
    return monthNumber;
}

void convertDate(char *dateString) {
    char *day, *month, *year, *part;
    day = strtok(dateString, "-");
    month = strtok(NULL, "-");
    year = strtok(NULL, "-");
    if (day == NULL || month == NULL || year == NULL) {
        printf("Error: Invalid input\n");
        return;
    }
    int d = atoi(day);
    int m = getMonthNumber(month);
    int y = atoi(year);
    if (m == 0) {
        printf("Error: Invalid month\n");
        return;
    }
    if (d < 1 || d > 31) {
        printf("Error: Invalid day\n");
        return;
    }
    if (y < 1 || y > 9999) {
        printf("Error: Invalid year\n");
        return;
    }
    printf("Output: %02d/%02d/%d\n", m, d, y);
}

int main() {
    char input[20], c;
    printf("Input date in format DD-Mon-YYYY: ");
    fgets(input, 20, stdin);
    if ((c = getchar()) != '\n' && c != EOF) {
        printf("Error: Input too long\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';
    convertDate(input);
    return 0;
}