//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    printf("\nWelcome to the Internet Speed Test Application!\n\n");
    printf("We need to gather data to test your internet speed.\n");
    printf("Please wait while we perform the test...\n\n");

    //Gathering data
    srand(time(0));
    float download_speed = (float)rand()/(float)(RAND_MAX/100);
    float upload_speed = (float)rand()/(float)(RAND_MAX/100);

    //Displaying Results
    printf("The test has been completed successfully.\n\n");
    printf("Your Download Speed: %.2f Mbps\n", download_speed);
    printf("Your Upload Speed: %.2f Mbps\n", upload_speed);

    //Calculating the average speed
    float avg_speed = (download_speed + upload_speed)/2;

    //Detecting internet speed status
    if(avg_speed < 5.0){
        printf("\nBased on our test, Your internet connection is very slow.\n");
        printf("We suggest you to contact your internet service provider.\n");
    }else if(avg_speed >= 5.0 && avg_speed <= 20.0){
        printf("\nBased on our test, Your internet connection is moderate.\n");
        printf("You can consider upgrading your internet plan for better speed and performance.\n");
    }else{
        printf("\nBased on our test, Your internet connection is very fast!\n");
        printf("Enjoy your lightning-fast internet speed!\n");
    }

    printf("\nThank you for using our application!\n");
    
    return 0;
}