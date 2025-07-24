//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int status = 200; // assume website is running normally
    int count = 0; // count number of failed attempts
    int max_attempts = 5; // maximum number of failed attempts
    int sleep_time = 10; // number of seconds to sleep between attempts
    char* website_url = "http://www.example.com"; // website to monitor

    while (1) // loop indefinitely
    {
        // check website status
        system("curl -o /dev/null -s -w \"%{http_code}\" http://www.example.com > website_status.txt");
        FILE* fp = fopen("website_status.txt", "r");
        if (fp == NULL) {
            printf("Error reading website status file\n");
            return 1;
        }
        fscanf(fp, "%d", &status);
        fclose(fp);
        
        // check if website is down
        if (status >= 400) {
            count++;
            printf("Website is down (status code %d). Failed attempt #%d\n", status, count);
            
            // check if max failed attempts reached, if so send email alert and exit
            if (count == max_attempts) {
                system("echo \"Website is down!\" | mail -s \"Website Alert\" user@example.com"); // replace with your email address
                printf("Max failed attempts reached. Email alert sent.\n");
                return 1;
            }
        }
        else { // website is up
            printf("Website is up (status code %d)\n", status);
            count = 0;
        }
        
        sleep(sleep_time); // wait for specified time before next check
    }

    return 0;
}