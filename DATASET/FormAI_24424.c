//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct Date {
    int day;
    int month;
    int year;
};

int is_leap_year(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

int get_days_in_month(int month, int year) {
    if(month == 1 && is_leap_year(year)) {
        return 29;
    }
    else {
        return days_in_month[month];
    }
}

int is_valid_date(struct Date input_date) {
    if(input_date.month < 1 || input_date.month > 12 || input_date.day < 1 || input_date.day > get_days_in_month(input_date.month-1, input_date.year) || input_date.year < 1) {
        return 0;
    }
    else {
        return 1;
    }
}

int get_total_days(struct Date input_date) {
    int total_days = input_date.day;
    for(int i = 0; i < input_date.month - 1; i++) {
        total_days += get_days_in_month(i, input_date.year);
    }
    return total_days;
}

void convert_input_date(char* input_date_string, struct Date* output_date) {
    char *p = strtok(input_date_string, "/");
    int count = 0;
    while (p != NULL) {
        switch(count) {
            case 0:
                output_date->month = atoi(p);
                break;
            case 1:
                output_date->day = atoi(p);
                break;
            case 2:
                output_date->year = atoi(p);
                break;
        }
        count++;
        p = strtok(NULL, "/");
    }
}

int main() {
    char input_date_string[20];
    struct Date input_date;
    int total_days_input, total_days_today;
    int days_difference;

    printf("Enter date in format MM/DD/YYYY: ");
    fgets(input_date_string, 20, stdin);
    convert_input_date(input_date_string, &input_date);

    if(!is_valid_date(input_date)) {
        printf("Invalid date entered. Exiting.\n");
        return 1;
    }

    total_days_input = get_total_days(input_date);
    total_days_today = get_total_days((struct Date){.day=1, .month=1, .year=2022});

    days_difference = total_days_today - total_days_input;

    printf("Input date: %d/%d/%d\n", input_date.month, input_date.day, input_date.year);
    printf("Days until January 1, 2022: %d\n", days_difference);

    return 0;
}