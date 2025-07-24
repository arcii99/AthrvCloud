//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

void check_website(char *url){
    int status = system("ping -c 1 google.com");
    if(status == 0){
        printf("%s is up and running.\n", url);
    }else{
        printf("Unable to reach %s right now.\n", url);
    }
}

int main(){
    printf("Welcome to Website Uptime Monitor program!\n");
    printf("Please enter the URL of the website you want to monitor: ");
    char url[100];
    scanf("%s", url);
    printf("\nStarting monitoring %s...\n", url);
    
    while(1){
        check_website(url);

        // Sleep for 5 seconds before pinging again
        sleep(5);
    }

    return 0;
}