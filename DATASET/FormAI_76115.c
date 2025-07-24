//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include<stdio.h>
#include<time.h>
 
// function to test internet speed
void test_speed(){
    time_t start, stop;
    double time_elapsed;
    FILE *fp;
    char ch, url[]="http://speedtest.tele2.net/100MB.zip";
    fp = fopen("100MB.zip", "wb");
    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }
    // start timer
    time(&start);
    printf("Downloading 100MB file from http://speedtest.tele2.net\n");
    // download file
    while(1){
        ch = fgetc(stdin);
        if(ch == EOF){
            break;
        }
        fputc(ch, fp);
    }
    fclose(fp);
    // stop timer
    time(&stop);
    time_elapsed = difftime(stop, start);
    printf("Time elapsed: %.2lf seconds\n", time_elapsed);
    // calculate internet speed
    double speed = 100/time_elapsed;
    printf("Your internet speed is %.2lf Mbps\n", speed);
}
 
int main(){
    printf("Welcome to the Internet Speed Test Application\n");
    test_speed();
    return 0;
}