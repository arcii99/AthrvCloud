//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>

int main() {
    int day, month, year;

    printf("Welcome to the Natural Language Date Converter!\n\n");

    while (1) {
        printf("Please enter a date in the format of 'Month Day Year':\n");
        scanf("%d %d %d", &month, &day, &year);

        // Check if date is valid
        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1) {
            printf("Invalid date entered. Please try again.\n");
            continue;
        }

        // Convert month to string
        char* month_str;
        switch (month) {
            case 1: month_str = "January"; break;
            case 2: month_str = "February"; break;
            case 3: month_str = "March"; break;
            case 4: month_str = "April"; break;
            case 5: month_str = "May"; break;
            case 6: month_str = "June"; break;
            case 7: month_str = "July"; break;
            case 8: month_str = "August"; break;
            case 9: month_str = "September"; break;
            case 10: month_str = "October"; break;
            case 11: month_str = "November"; break;
            case 12: month_str = "December"; break;
        }

        // Print out natural language date
        printf("The entered date is: %s %d, %d\n\n", month_str, day, year);
    }

    return 0;
}