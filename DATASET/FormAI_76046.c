//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>

int main(){
    //Introduction
    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("Please enter a date in the format Month Day Year:\n");

    //Input
    char month[10];
    int day, year;
    scanf("%s %d %d", month, &day, &year);
    
    //Processing
    char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month_num;
    for(int i=0; i<12; i++){
        if(strcmp(month, months[i]) == 0){
            month_num = i+1;
            break;
        }
    }

    //Output
    printf("The date you entered is: %d/%d/%d\n", month_num, day, year);

    return 0;
}