//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TIMEOUT 5
#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 4096

int main() {
    char url[MAX_URL_LENGTH];
    char cmd[MAX_URL_LENGTH+20];
    char response[MAX_RESPONSE_LENGTH];
    int status, count = 0;

    while (1) {
        printf("Enter a URL to monitor: ");
        fgets(url, MAX_URL_LENGTH, stdin);
        url[strcspn(url, "\n")] = 0; // remove newline character

        sprintf(cmd, "curl -IsS %s --connect-timeout %d", url, TIMEOUT); // create command string
        status = system(cmd); // execute command and capture exit status

        if (WEXITSTATUS(status) == 0) { // successful response
            printf("%s is UP\n", url);
            count = 0; // reset counter
        }
        else { // unsuccessful response
            printf("%s is DOWN\n", url);
            count++; // update counter
        }

        if (count >= 3) { // if site is down for three consecutive checks
            printf("ALERT! %s has been down for 3 checks\n", url);
            count = 0; // reset counter
            sprintf(cmd, "echo '%s is down' | mail -s 'Website Down' admin@example.com", url); // create email command string
            system(cmd); // send email
        }

        printf("Press Ctrl-C to exit or Enter to continue\n");
        sleep(10); // wait for 10 seconds before checking again
    }

    return 0;
}