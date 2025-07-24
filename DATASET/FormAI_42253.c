//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#define MAX_LIMIT 20 
void roundRobin(int n,int burst_time[],int arrival_time[],int time_quantum){

    int i,wt[n],t[n],tbt[n], total_time=0,remaining=n;
    for(i=0;i<n;i++){
        tbt[i]=burst_time[i];
        wt[i]=0;
        t[i]=0;
    }
    while(remaining!=0){
        for(i=0;i<n;i++){
            if(tbt[i]>time_quantum){
                tbt[i]-=time_quantum;
                total_time+=time_quantum;
            }
            else if(tbt[i]>0){
                total_time+=tbt[i];
                t[i]=total_time-arrival_time[i];
                wt[i]=t[i]-burst_time[i];
                tbt[i]=0;
                remaining--;
            }
        }
    }
    int total_waiting=0;
    int total_turnaround=0;
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        total_waiting+=wt[i];
        total_turnaround+=t[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i],arrival_time[i],wt[i],t[i]);
    }
    double avg_waiting=total_waiting/n;
    double avg_turnaround=total_turnaround/n;
    printf("Average Waiting Time: %f\n",avg_waiting);
    printf("Average Turnaround Time: %f\n",avg_turnaround);
}
void firstComeFirstServed(int n,int arrival_time[],int burst_time[]){

    int i,wt[n],t[n];
    wt[0]=0;
    int total_waiting=0;
    int total_turnaround=0;
    t[0]=burst_time[0];
    total_turnaround=t[0];
    for(i=1;i<n;i++){
        wt[i]=t[i-1];
        total_waiting+=wt[i];
        t[i]=wt[i]+burst_time[i];
        total_turnaround+=t[i];
    }
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i],arrival_time[i],wt[i],t[i]);
    }
    double avg_waiting=total_waiting/n;
    double avg_turnaround=total_turnaround/n;
    printf("Average Waiting Time: %f\n",avg_waiting);
    printf("Average Turnaround Time: %f\n",avg_turnaround);

}
void shortestJobFirst(int n,int burst_time[],int arrival_time[]){
    int t[n],wt[n], total_waiting=0, i, smallest,pos;
    for(i=0;i<n;i++){
        t[i]=burst_time[i];
        wt[i]=0;
    }
    int complete=0;
    int total_turnaround=0;
    int min_arrival=9999;
	int time=0;
    while(complete!=n){
        for(i=0;i<n;i++){
            if((arrival_time[i]<=time) && (t[i]<t[smallest]) && (t[i]>0)){
                smallest=i;
            }
        }
        t[smallest]--;
        if(t[smallest]==0){
            complete++;
            wt[smallest]=(time+1)-arrival_time[smallest]-burst_time[smallest];
            if(wt[smallest]<0){
                wt[smallest]=0;
            }
            total_waiting+=wt[smallest];
            total_turnaround+=wt[smallest]+burst_time[smallest];
        }
        smallest=n-1;
        for(i=0;i<n;i++){
            if((t[i]>0) && (arrival_time[i]<=time)){
                if(t[i]<t[smallest]){
                    smallest=i;
                }
            }
        }
        time++;
    }
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i],arrival_time[i],wt[i],wt[i]+burst_time[i]);
    }
    double avg_waiting=total_waiting/n;
    double avg_turnaround=total_turnaround/n;
    printf("Average Waiting Time: %f\n",avg_waiting);
    printf("Average Turnaround Time: %f\n",avg_turnaround);
}
int main(){
    int i,n,choice;
    printf("Enter the choice for CPU scheduling Algorithm\n1.First Come First Served(FCFS)\n2.Shortest Job First(SJF)\n3.Round Robin(RR)\n");
    scanf("%d",&choice);
    printf("Enter the number of process\n");
    scanf("%d",&n);
    int burst_time[n], arrival_time[n];
    printf("Enter the burst time for each process:\n");
    for(i=0;i<n;i++){
        scanf("%d",&burst_time[i]);
    }
    printf("Enter the arrival time for each process:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arrival_time[i]);
    }
    switch(choice){

        case 1:
            firstComeFirstServed(n,arrival_time,burst_time);
            break;
        case 2:
            shortestJobFirst(n,burst_time,arrival_time);
            break;
        case 3:
            int time_quantum;
            printf("Enter the time quantum:\n");
            scanf("%d",&time_quantum);
            roundRobin(n,burst_time,arrival_time,time_quantum);
            break;

        default:
            printf("Invalid choice\n");
            break;


    }
    return 0;
}