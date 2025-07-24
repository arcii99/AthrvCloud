//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <string.h>

// Function to convert month number to month name string
void get_month_name(int month, char* month_name) {
    switch(month) {
        case 1: strcpy(month_name, "January"); break;
        case 2: strcpy(month_name, "February"); break;
        case 3: strcpy(month_name, "March"); break;
        case 4: strcpy(month_name, "April"); break;
        case 5: strcpy(month_name, "May"); break;
        case 6: strcpy(month_name, "June"); break;
        case 7: strcpy(month_name, "July"); break;
        case 8: strcpy(month_name, "August"); break;
        case 9: strcpy(month_name, "September"); break;
        case 10: strcpy(month_name, "October"); break;
        case 11: strcpy(month_name, "November"); break;
        case 12: strcpy(month_name, "December"); break;
        default: strcpy(month_name, ""); break;
    }
}

// Function to convert a date string (YYYYMMDD) to a natural language date
void convert_date(char* date_str) {
    // Extract year, month, and day from date string
    char year_str[5];
    strncpy(year_str, date_str, 4);
    year_str[4] = '\0';
    int year = atoi(year_str);
    int month = atoi(date_str + 4);
    int day = atoi(date_str + 6);
    
    // Get month name
    char month_name[10];
    get_month_name(month, month_name);
    
    // Print natural language date
    printf("\nThe date is: %s %d, %d\n", month_name, day, year);
}

int main() {
    // Example dates to convert
    char date1[] = "20220101";
    char date2[] = "20220315";
    char date3[] = "20221031";
    
    // Convert dates to natural language dates
    convert_date(date1);
    convert_date(date2);
    convert_date(date3);
    
    return 0;
}