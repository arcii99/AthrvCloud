//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

char* days_in_month[] = {"31", "28", "31", "30", "31", "30", "31", "31", "30", "31", "30", "31"};

struct Date {
    int day;
    int month;
    int year;
};

int is_leap_year(int year) {
    if(year % 400 == 0) {
        return 1;
    }
    else if(year % 100 == 0) {
        return 0;
    }
    else if(year % 4 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

struct Date convert_date(char* date_str) {
    struct Date converted_date;
    char delim[] = "-";
    char* ptr = strtok(date_str, delim);
    int i = 0;
    while(ptr != NULL) {
        if(i == 0) {
            converted_date.day = atoi(ptr);
        }
        else if(i == 1) {
            converted_date.month = atoi(ptr);
        }
        else {
            converted_date.year = atoi(ptr);
        }
        ptr = strtok(NULL, delim);
        i++;
    }
    return converted_date;
}

int get_days_in_month(int month, int year) {
    if(month == 2 && is_leap_year(year)) {
        return 29;
    }
    else {
        return atoi(days_in_month[month-1]);
    }
}

char* get_month_name(int month) {
    return month_names[month-1];
}

void print_date(struct Date date) {
    printf("%s %d, %d", get_month_name(date.month), date.day, date.year);
}

struct Date add_days(struct Date date, int days_added) {
    int total_days = date.day + days_added;
    int days_in_current_month = get_days_in_month(date.month, date.year);
    while(total_days > days_in_current_month) {
        total_days -= days_in_current_month;
        date.month++;
        if(date.month > 12) {
            date.month = 1;
            date.year++;
        }
        days_in_current_month = get_days_in_month(date.month, date.year);
    }
    date.day = total_days;
    return date;
}

int main() {
    char date_str[11];
    printf("Enter a date in the format of MM-DD-YYYY: ");
    fgets(date_str, 11, stdin);
    struct Date original_date = convert_date(date_str);
    int days_to_add;
    printf("Enter the number of days to add to the date: ");
    scanf("%d", &days_to_add);
    struct Date new_date = add_days(original_date, days_to_add);
    print_date(original_date);
    printf(" + %d days = ", days_to_add);
    print_date(new_date);
    printf("\n");
    return 0;
}