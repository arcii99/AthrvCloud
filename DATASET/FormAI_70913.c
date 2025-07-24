//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: introspective
#include <stdio.h> //for standard input and output
#include <stdlib.h> //for srand and rand
#include <time.h> //for time()

int download_speed(){
    int random_speed = rand() % 80; //generating random speed from 0 to 80
    return random_speed; //returning download speed
}

int upload_speed(){
    int random_speed = rand() % 20; //generating random speed from 0 to 20
    return random_speed; //returning upload speed
}

int main(){
    srand(time(NULL)); //seeding the random function with current time
    
    int download = download_speed(); //getting download speed
    int upload = upload_speed(); //getting upload speed
    
    printf("Running Internet Speed Test...\n");
    printf("Your download speed is: %d Mbps\n", download);
    printf("Your upload speed is: %d Mbps\n", upload);
    
    //analyzing the internet speed based on download and upload speed
    if(download >= 50 && upload >= 10){
        printf("Your internet speed is excellent!\n");
    }
    else if(download >= 30 && upload >= 5){
        printf("Your internet speed is good!\n");
    }
    else if(download >= 10 && upload >= 2){
        printf("Your internet speed is average.\n");
    }
    else{
        printf("Your internet speed is poor, please contact your internet service provider.\n");
    }
    
    return 0; //exiting the program
}