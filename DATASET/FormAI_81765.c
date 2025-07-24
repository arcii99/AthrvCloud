//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
#include<stdio.h>
#include<stdlib.h>

//Declare function to ping website
int ping(char* url)
{
    char command[50];
    sprintf(command, "ping -c 3 %s", url);
    return system(command);
}

int main()
{
    char* website = "www.google.com";
    int status;

    //Infinite loop to keep monitoring the website
    while(1)
    {
        //Ping the website and get the status code
        status = ping(website);

        //If the website is down, print message and try to ping again after 10 seconds
        if(status != 0)
        {
            printf("Website %s is down!\n", website);
            printf("Trying to reconnect in 10 seconds...\n");
            sleep(10); //Pause for 10 seconds
            continue; //Start the loop again
        }

        //If the website is up, print message and wait for 60 seconds before pinging again
        printf("Website %s is up and running...\n", website);
        sleep(60); //Pause for 60 seconds
    }

    return 0;
}