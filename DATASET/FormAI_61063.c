//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("Welcome to the Internet Speed Test Application!\n");

    printf("Press enter to start the test.\n");
    getchar();  //To pause the program and wait for user input
    
    //Generating random download and upload speeds between 1 and 100
    srand(time(NULL)); //Seeds the random number generator
    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;

    //Displaying the results of the speed test
    printf("\nCalculating results...\n\n");
    printf("Your download speed is %d Mbps\n", download_speed);
    printf("Your upload speed is %d Mbps\n", upload_speed);

    //Performing analysis of the speed test results
    if(download_speed >= 50 && upload_speed >= 50){
        printf("Wow, you have a really fast internet connection! Enjoy streaming your favorite shows and movies!\n");
    }
    else if(download_speed >= 20 && upload_speed >= 20){
        printf("Not bad, your internet speed is decent. You can browse the web and stream music without any problems.\n");
    }
    else{
        printf("Uh oh, your internet speed is quite slow. You may experience slow loading times and buffering issues while streaming.\n");
    }

    return 0;
}