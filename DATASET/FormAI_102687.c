//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define INTERVAL 5

/* function declarations */
int check_website(char *url);
void print_status(int status);

/* main function */
int main(int argc, char *argv[]) {
    int status;
    char *url;

    /* check if URL is provided */
    if(argc != 2) {
        printf("Please enter the website URL as command line argument.\n");
        return 0;
    }

    url = argv[1];

    /* print header */
    printf("%-20s%-20s%-20s%s\n", "Time", "Response Time", "Status Code", "Status");

    /* loop through every 5 seconds */
    while(1) {
        status = check_website(url);
        print_status(status);
        sleep(INTERVAL);
    }

    return 0;
}

/* function to check website and return status code */
int check_website(char *url) {
    int status;
    double response_time;
    time_t now;

    time(&now); /* get current time */

    /* generate curl command and save response time */
    response_time = system("curl -s -o /dev/null -w '%{time_total}' https://www.google.com");

    /* get status code */
    status = system("curl -s -o /dev/null -w '%{http_code}' https://www.google.com");

    /* print time, response time, status code, and status */
    printf("%-20.20s%-20.2f%-20d", ctime(&now), response_time, status);

    /* return status code */
    return status;
}

/* function to print status based on status code */
void print_status(int status) {
    switch(status) {
        case 200:
            printf("OK\n");
            break;
        case 400:
            printf("Bad Request\n");
            break;
        case 401:
            printf("Unauthorized\n");
            break;
        case 403:
            printf("Forbidden\n");
            break;
        case 404:
            printf("Not Found\n");
            break;
        case 500:
            printf("Internal Server Error\n");
            break;
        case 503:
            printf("Service Unavailable\n");
            break;
        default:
            printf("Unknown Status\n");
    }
}