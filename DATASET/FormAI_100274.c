//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char input_date[20], output_date[20];
    int year, month, day, month_num;
    printf("Enter date in natural language (e.g. 25th June 2021): ");
    fgets(input_date, 20, stdin);
    sscanf(input_date, "%d%*s %s %d", &day, output_date, &year);
    
    // Find month_num based on output_date
    for(int i = 0; i < 12; i++) {
        if(strcmp(output_date, months[i]) == 0) {
            month_num = i + 1; // January is 1, February is 2, etc.
            break;
        }
    }
    
    printf("The input date is: %d-%02d-%02d\n", year, month_num, day);
    return 0;
}