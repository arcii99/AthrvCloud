//FormAI DATASET v1.0 Category: Date and time ; Style: grateful
#include<stdio.h>
#include<time.h>

int main() {
    // Getting current date and time using time.h library
    time_t t = time(NULL);
    struct tm curr_time = *localtime(&t);

    // Printing the current date and time in a grateful way
    printf("Dear User,\n\n");
    printf("Today's Date is %02d/%02d/%d and the time is %02d:%02d:%02d.\n", 
            curr_time.tm_mday, curr_time.tm_mon + 1, curr_time.tm_year + 1900, 
            curr_time.tm_hour, curr_time.tm_min, curr_time.tm_sec);
    printf("We are so grateful that you have taken the time to use our program.\n");
    printf("We hope that our program helps you in some way or the other.\n");
    printf("Thank you for being a loyal user!\n\n");
    return 0;
}