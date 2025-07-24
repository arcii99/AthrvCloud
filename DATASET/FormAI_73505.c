//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){
    time_t begin,end;
    double time_spent;

    printf("Enter the URL to be monitored: ");
    char url[100];
    scanf("%s",url);

    while(1){
        begin = time(NULL);
        int response = system(url);

        if(response == 0){
            printf("%s is up! \n",url);
        }
        else{
            printf("%s is down! \n",url);
        }

        end = time(NULL);
        time_spent = (double)(end-begin);

        printf("Time Elapsed: %.2lf seconds \n",time_spent);

        sleep(5);
    }

    return 0;
}