//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate user input
int validate_input(char input[]) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Function to convert Gregorian date to Julian day number
int gregorian_to_julian(int year, int month, int day) {
    int a, b, c, d, e, jd;
    if (month < 3) {
        year -= 1;
        month += 12;
    }
    a = year / 100;
    b = a / 4;
    c = 2 - a + b;
    d = 365.25 * (year + 4716);
    e = 30.6001 * (month + 1);
    jd = c + day + d + e - 1524.5;
    return jd;
}

// Function to convert Julian day number to Julian date
void julian_to_date(int jd, int *year, int *month, int *day) {
    int a, b, c, d, e, f, g;
    jd += 0.5;
    f = jd + 1401;
    g = (f - 1) / 1461;
    a = (g * 4) + 3;
    b = ((g * 1461) - 1) / 4;
    c = f - b;
    d = ((c - 1) / 365) - (c / 1461);
    e = c - (365 * d) - (d / 4);
    *year = (100 * ((g - 49) + d)) + (e / 100);
    *month = ((e % 100) + 1) / 1.02;
    *day = e - (int) (30.6001 * (*month) + 0.3);
}

int main() {
    int year, month, day, choice;
    char input[11];
    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Convert Gregorian to Julian\n");
        printf("2. Convert Julian to Gregorian\n");
        printf("3. Exit\n");
        printf("Choice: ");
        fgets(input, 11, stdin);
        choice = atoi(input);
        if (validate_input(input) && choice >= 1 && choice <= 3) {
            switch (choice) {
                case 1:
                    printf("Enter Gregorian date (YYYY-MM-DD): ");
                    fgets(input, 11, stdin);
                    if (validate_input(input) && strlen(input) == 11 &&
                        input[4] == '-' && input[7] == '-') {
                        year = atoi(strtok(input, "-"));
                        month = atoi(strtok(NULL, "-"));
                        day = atoi(strtok(NULL, "-"));
                        if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {
                            printf("Julian Day Number: %d\n", gregorian_to_julian(year, month, day));
                        } else {
                            printf("Invalid date\n");
                        }
                    } else {
                        printf("Invalid input\n");
                    }
                    break;
                case 2:
                    printf("Enter Julian Day Number: ");
                    fgets(input, 11, stdin);
                    if (validate_input(input)) {
                        int jd = atoi(input);
                        julian_to_date(jd, &year, &month, &day);
                        printf("Gregorian Date: %04d-%02d-%02d\n", year, month, day);
                    } else {
                        printf("Invalid input\n");
                    }
                    break;
                case 3:
                    printf("Goodbye!\n");
                    exit(0);
            }
        } else {
            printf("Invalid input\n");
        }
    }
    return 0;
}