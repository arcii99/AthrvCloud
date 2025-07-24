//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Function to check the website uptime by creating a socket connection 
bool checkWebsiteUptime(char* url){
    //Create a socket connection using C socket programming
    //Assume the socket is successfully created and connected
    return true;
}

int main(){
    char* url = "www.example.com";
    bool websiteUp = false;
    int upTimeCounter = 0;
    int downTimeCounter = 0;
    time_t current_time;
    struct tm* time_info;
    char timeString[9];

    while(true){
        websiteUp = checkWebsiteUptime(url);
        if(websiteUp){
            upTimeCounter++;

            //Printing the uptime statistics
            time(&current_time);
            time_info = localtime(&current_time);
            strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
            printf("%s - Website is up\n", timeString);

            //Checking if the website was down before, if yes, printing the downtime statistics
            if(downTimeCounter > 0){
                printf("Website was down for %d seconds\n", downTimeCounter);
                downTimeCounter = 0;
            }
        }
        else{
            downTimeCounter++;

            //Printing the downtime statistics
            time(&current_time);
            time_info = localtime(&current_time);
            strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
            printf("%s - Website is down\n", timeString);

            //Checking if the website was up before, if yes, printing the uptime statistics
            if(upTimeCounter > 0){
                printf("Website was up for %d seconds\n", upTimeCounter);
                upTimeCounter = 0;
            }
        }

        //Delay for 10 seconds before checking the status again
        sleep(10);
    }
    return 0;
}