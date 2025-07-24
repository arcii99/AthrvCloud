//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//function to convert month name to number 
int monthToNum(char* month) {
    char* months[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    for(int i=0; i<12; i++) {
        if(strcmp(month, months[i]) == 0) {
            return i+1; //returning month number starting from 1
        }
    }
    return 0; //return 0 if month name not matched
}

int main() {
    char date[20];
    printf("Enter date in Natural Language: ");
    fgets(date, 20, stdin); //getting input from user

    int day, month, year;
    char s_month[10];

    //breaking down the input into day, month and year
    sscanf(date, "%d %s %d", &day, s_month, &year);

    month = monthToNum(s_month);

    if(day<=0 || day>31 || month<=0 || month>12 || year<=0) {
        printf("Invalid Date!\n");
    }
    else {
        printf("Date in Numeric Format: %d-%02d-%02d\n", year, month, day);
    }

    return 0;
}