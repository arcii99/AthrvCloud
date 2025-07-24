//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
#include <stdio.h>

int main() {
    int month, day, year;

    printf("Enter date in the format (MM DD YYYY): ");
    scanf("%d %d %d", &month, &day, &year);

    if (month < 1 || month > 12) {
        printf("Invalid month entered, are you sure you are not trying to hack me?");
    } else if (day < 1 || day > 31) {
        printf("Invalid day entered, what are you trying to do?");
    } else if (year < 1900 || year > 2100) {
        printf("Invalid year entered, are you trying to access confidential data?");
    } else {
        char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        printf("\nDate in words: %s %d, %d\n\n", months[month-1], day, year);
    }

    return 0;
}