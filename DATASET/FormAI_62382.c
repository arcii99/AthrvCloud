//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>

int main() {
    int day, month, year, julian;
    printf("Welcome to the C Natural Language Date Converter! \n");
    printf("Please enter a date in the format (Day Month Year): ");
    scanf("%d %*c%d %d", &day, &month, &year);

    // Check if the given date is valid or not
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        printf("Invalid date entered! \n");
        return 1;
    }

    // Calculate the Julian date
    julian = (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;

    // Print the Julian date
    printf("\nThe Julian date for the given date is: %d \n", julian);

    return 0;
}