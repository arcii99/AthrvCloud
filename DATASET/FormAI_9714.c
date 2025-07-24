//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: ephemeral
#include <stdio.h>

enum Months {January = 1, February, March, April, May, June, July, August, September, October, November, December};

int main() {
    int date;
    int month;
    int year;
    
    printf("Enter a date in Natural Language (e.g. January 1st, 2022):\n");
    scanf("%d", &month);
    char temp;
    scanf("%c", &temp); // to get the comma
    scanf("%d", &date);
    scanf("%c", &temp); // to get the 'st', 'nd', 'rd', or 'th'
    scanf("%d", &year);
    
    switch(month) {
        case January: printf("January "); break;
        case February: printf("February "); break;
        case March: printf("March "); break;
        case April: printf("April "); break;
        case May: printf("May "); break;
        case June: printf("June "); break;
        case July: printf("July "); break;
        case August: printf("August "); break;
        case September: printf("September "); break;
        case October: printf("October "); break;
        case November: printf("November "); break;
        case December: printf("December "); break;
        default: printf("Invalid month input\n"); return 1;
    }
    
    switch(date) {
        case 1: printf("1st, "); break;
        case 2: printf("2nd, "); break;
        case 3: printf("3rd, "); break;
        case 21: printf("21st, "); break;
        case 22: printf("22nd, "); break;
        case 23: printf("23rd, "); break;
        case 31: printf("31st, "); break;
        default: printf("%dth, ", date); break;
    }
    
    printf("%d\n", year);
    
    return 0;
}