//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include<stdio.h>
int burst_time[20], wait_time[20], temp[20], turn_time[20], p[20], priority[20];
int main() {
    int i,j,n,total=0,pos,temp1,count,time_quantum,flag=0;
    float avg_wait, avg_turn;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);
    for(i = 0;i < n;i++) {
        printf("Enter the details for Process[%d]\n", i+1);
        printf("Enter Burst Time: ");
        scanf("%d", &burst_time[i]);
        temp[i]=burst_time[i];
        printf("Enter Priority: ");
        scanf("%d", &priority[i]);
        p[i]=i+1;
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);
    printf("\nProcess ID\t\tBurst Time\t Priority\t Waiting Time\t Turnaround Time");
    for(count=0,i=0;total!=n;){
        for(temp1=0,j=n-1;j>=0;j--) {
            if(temp[j] != 0 && temp[j]<=time_quantum) {
                count += temp[j];
                temp[j]=0;
                flag=1;
            }
            else if(temp[j]>0) {
                temp[j]-=time_quantum;
                count+=time_quantum;
            }
            if(temp[j]==0 && flag==1) {
                total++;
                turn_time[j]=count;
                wait_time[j]=turn_time[j]-burst_time[j];
                printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t %d", p[j], burst_time[j], priority[j], wait_time[j], turn_time[j]);
                avg_wait+=wait_time[j];
                avg_turn+=turn_time[j];
                flag=0;
            }
            if(j==0) {
                j=n;
            }
        }
    }
    printf("\nAverage Waiting Time: %f", avg_wait/n);
    printf("\nAverage Turnaround Time: %f", avg_turn/n);
    return 0;
}