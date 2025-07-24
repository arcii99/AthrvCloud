//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>

int main() {
    int month, day, year;
    char c;

    printf("Enter a date in natural language (e.g. January 1st, 2022): ");
    scanf("%*s %d%c %d", &day, &c, &year);

    switch(c) {
        case 's': // July, August, September
            scanf("%*s"); // skip "pt"
            month = 9;
            break;
        case 'y': // May
            month = 5;
            break;
        case 'r': // April, March
            if(getchar() == 'i') { // April
                month = 4;
            } else { // March
                month = 3;
            }
            break;
        case 'n': // June, January
            if(getchar() == 'u') { // June
                month = 6;
            } else { // January
                month = 1;
            }
            break;
        case 'f': // February
            month = 2;
            break;
        case 'a': // July, August, December
            getchar(); // skip "u" in July and August
            c = getchar();
            if(c == 'c') { // December
                month = 12;
            } else if(c == 'l') { // July
                month = 7;
            } else { // August
                month = 8;
            }
            break;
        case 'o': // October
            month = 10;
            break;
        case 'd': // November
            month = 11;
            break;
        default:
            printf("Invalid input!\n");
            return 1;
    }

    printf("The equivalent date in standard format is %02d/%02d/%d.\n", month, day, year);

    return 0;
}