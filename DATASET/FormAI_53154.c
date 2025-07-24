//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    printf("\nWelcome to the happiest system admin program ever!\n");

    //Checking if user has root access
    if(getuid()!=0){
        printf("\nOops! You do not have sufficient permission to run this program! Please run this as root!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nGreat! Looks like you are the root user! Let's begin our cheerful system admin tasks!\n");

    //Checking current system load
    float loadavg[3];
    if(getloadavg(loadavg, 3) != -1) {
        printf("Current system load: %.2f\n", loadavg[0]);
        if(loadavg[0] > 2){
            printf("Woohoo! Looks like the system is having a party! Let's join in and reduce the load!\n");
            //We can come up with some code here to reduce the load, like suspending some processes
        }
    }

    //Checking available disk space
    FILE *fp = popen("df -h /", "r");
    if(fp == NULL){
        printf("Oops! Couldn't check disk space!\n");
    }else{
        char buf[1024];
        while(fgets(buf, sizeof(buf), fp)){
            printf("Available disk space: %s\n", buf);
            break;
        }
        pclose(fp);
    }

    //Checking network status
    FILE *netfp = popen("ping -c 1 google.com > /dev/null && echo \"UP\" || echo \"DOWN\"", "r");
    if(netfp == NULL){
        printf("Oops! Couldn't check network status!\n");
    }else{
        char buf[1024];
        while(fgets(buf, sizeof(buf), netfp)){
            printf("Network status: %s\n", buf);
            break;
        }
        pclose(netfp);
    }

    printf("\nYayy! All tasks successfully performed in the happiest way possible! Have a great day and let's spread cheer in the world of system administration!\n");

    return 0;
}