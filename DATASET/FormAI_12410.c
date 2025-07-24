//FormAI DATASET v1.0 Category: Date and time ; Style: imaginative
#include<stdio.h>
#include<time.h>

int main(){

    //Getting the current time of the system
    time_t currentTime;
    time(&currentTime);

    //converting the time to local time
    struct tm *localTime = localtime(&currentTime);
    
    //Printing the current time
    printf("The current time is: %d:%d:%d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    
    //Asking user to enter the desired date
    printf("Please enter a date in the following format DD-MM-YYYY: \n");
    char inputDate[10];
    scanf("%s", inputDate);

    //Converting date to struct tm format
    struct tm date = { 0 };
    date.tm_year = (inputDate[6] - 48) * 1000 + (inputDate[7] - 48) * 100 + (inputDate[8] - 48) * 10 + (inputDate[9] - 48) - 1900;
    date.tm_mon = (inputDate[3] - 48) * 10 + (inputDate[4] - 48) - 1;
    date.tm_mday = (inputDate[0] - 48) * 10 + (inputDate[1] - 48);   

    //Converting the entered date to a timestamp
    time_t chosenDate = mktime(&date);

    //Checking if the input date is greater than the current date
    if(difftime(currentTime, chosenDate) < 0){
        printf("Please enter a date prior to today's date.");
    }

    else{
        //Calculating the number of days between the two dates
        double seconds = difftime(currentTime, chosenDate);
        double days = seconds / (60 * 60 * 24);

        printf("The difference between the selected date and today's date is %.0f days\n", days);
    }

    return 0;
}