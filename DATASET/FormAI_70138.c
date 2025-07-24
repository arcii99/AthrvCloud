//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to convert date string to timestamp
time_t convertToTimestamp(char date[]){
    struct tm tmDate;

    memset(&tmDate, 0, sizeof(struct tm));
    strptime(date, "%d-%m-%Y", &tmDate); // convert date string to tm struct

    time_t timeStamp = mktime(&tmDate); // convert tm struct to timestamp
    return timeStamp;
}

// function to convert timestamp to date string
void convertToDate(time_t timeStamp, char formattedDate[]){
    struct tm *tmDate = localtime(&timeStamp); // convert timestamp to tm struct

    strftime(formattedDate, 20, "%d-%m-%Y", tmDate); // format date string from tm struct
}

int main(){
    char date[11];
    time_t timeStamp;
    char formattedDate[11];

    printf("Enter date in format dd-mm-yyyy: ");
    scanf("%s", date);

    if(strlen(date) != 10){
        printf("Invalid date format!\n");
        return 0;
    }

    timeStamp = convertToTimestamp(date); // convert date string to timestamp
    convertToDate(timeStamp, formattedDate); // convert timestamp to date string

    if(strcmp(formattedDate, date) == 0){ // check if converted date string matches original date string
        printf("Date entered: %s\n", date);
        printf("Timestamp: %ld\n", timeStamp);
        printf("Date in timestamp format: %s\n", formattedDate);
    }
    else{
        printf("Invalid date entered!\n");
    }

    return 0;
}