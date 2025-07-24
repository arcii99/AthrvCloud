//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include<stdio.h>
#include<ctype.h>

int main(){
    char date[15];
    char month[10];
    char monthList[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int day, year;

    printf("Enter date in natural language format (E.g. March 22nd, 2022): ");
    scanf("%s %d%s %d", month, &day, date, &year);

    // Convert month to lowercase
    for(int i=0; month[i]!='\0'; i++){
        month[i] = tolower(month[i]);
    }

    // Find the month index from monthList
    int monthIndex;
    for(int i=0; i<12; i++){
        if(strcmp(month, monthList[i]) == 0){
            monthIndex = i+1;
            break;
        }
    }

    printf("\n%d/%d/%d\n", monthIndex, day, year);
    return 0;
}