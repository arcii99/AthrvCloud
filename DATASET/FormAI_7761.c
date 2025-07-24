//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    // Initializing variables
    int lane1[100]={0}, lane2[100]={0}, lane3[100]={0};
    int count1=0, count2=0, count3=0, total_count=0, time=1;
    int i, j, k, n;

    // Generating traffic flow for 10 minutes
    while(time<=10){

        printf("\n Traffic Flow Simulation for Minute %d \n", time);
        printf("------------------------------------ \n");

        // Generating traffic for Lane 1
        for(i=count1; i<100; i++){
            if(rand()%2==1){
                lane1[i]=1;
                total_count++;
                count1++;
            }
        }

        // Generating traffic for Lane 2
        for(j=count2; j<100; j++){
            if(rand()%2==1){
                lane2[j]=1;
                total_count++;
                count2++;
            }
        }

        // Generating traffic for Lane 3
        for(k=count3; k<100; k++){
            if(rand()%2==1){
                lane3[k]=1;
                total_count++;
                count3++;
            }
        }

        // Printing the traffic flow
        printf("Lane 1 : ");
        for(n=0; n<100; n++){
            printf("%d ", lane1[n]);
        }
        printf("\n");

        printf("Lane 2 : ");
        for(n=0; n<100; n++){
            printf("%d ", lane2[n]);
        }
        printf("\n");

        printf("Lane 3 : ");
        for(n=0; n<100; n++){
            printf("%d ", lane3[n]);
        }
        printf("\n");

        // Updating the traffic flow after every minute
        for(n=0; n<100; n++){
            if(n>0){
                lane1[n-1]=lane1[n];
                lane2[n-1]=lane2[n];
                lane3[n-1]=lane3[n];
            }
            if((n==99) && (count1==100 || count2==100 || count3==100)){
                lane1[99]=0;
                lane2[99]=0;
                lane3[99]=0;
            }
            if((n==99) && (count1<100 && count2<100 && count3<100)){
                lane1[99]=0;
                lane2[99]=0;
                lane3[99]=0;
                if(lane1[n-1]==1){
                    count1--;
                }
                if(lane2[n-1]==1){
                    count2--;
                }
                if(lane3[n-1]==1){
                    count3--;
                }
            }
        }

        // Printing the total traffic count
        printf("\n Total Traffic Count : %d \n", total_count);

        time++; // Incrementing the minute count

    }

    return 0;

}