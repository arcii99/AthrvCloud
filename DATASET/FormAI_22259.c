//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    time_t timer;
    struct tm *tm_info;
    char timebuffer[26];
    int threshold = 10; //adjustable threshold value to detect intrusion attempts
    int attempts = 0;

    while(1)
    {
        //get current time
        time(&timer);
        tm_info = localtime(&timer);
        strftime(timebuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        //simulate a random login attempt
        int login_success = rand() % 2;

        if(login_success == 0)
        {
            attempts++;
            printf("%s - Login failed. Attempt #%d.\n", timebuffer, attempts);
        }
        else
        {
            printf("%s - Login successful.\n", timebuffer);
        }

        //check if number of attempts exceeded threshold
        if(attempts > threshold)
        {
            printf("%s - Intrusion attempt detected! Locking account...\n", timebuffer);
            //call function to lock account
            lock_account();
            break;
        }

        //wait for 1 second to simulate real-time monitoring
        sleep(1);
    }

    return 0;
}

void lock_account()
{
    //code to lock account
    printf("Account locked!\n");
}