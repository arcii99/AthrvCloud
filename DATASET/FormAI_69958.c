//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include<stdio.h>
#include<string.h>

void sort(int a[], int n){
  int i, j, temp;
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
      if(a[j]>a[j+1]){
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
}

int find_waiting_time(int burst_time[], int n, int waiting_time[]){
  int i;
  waiting_time[0]=0;
  for(i=1;i<n;i++){
    waiting_time[i]=burst_time[i-1]+waiting_time[i-1]; 
  }
  return i;
}

int find_turnaround_time(int burst_time[], int n, int waiting_time[], int tat[]){
  int i;
  for(i=0;i<n;i++){
    tat[i]=burst_time[i]+waiting_time[i];
  }
  return i;
}

void findavgTime(int processes[], int n, int burst_time[]){
  int i, waiting_time[n], tat[n], total_wt=0, total_tat=0;
  
  int num=n;
  int quantum=4;
  
  int rem_bt[num];
  for(i=0;i<num;i++){
    rem_bt[i]=burst_time[i];
  }
  
  int t=0;
  while(1){
    int done=1;
    
    for(i=0;i<num;i++){
      if(rem_bt[i]>0){
        done=0;
        
        if(rem_bt[i]>quantum){
          t+=quantum;
          rem_bt[i]-=quantum;
        }
        else{
          t=t+rem_bt[i];
          waiting_time[i]=t-burst_time[i];
        rem_bt[i]=0;
        }
      }
    }
    //If all processes are done, then break.
    if(done==1)
      break;
  }
  
  find_turnaround_time(burst_time, num, waiting_time, tat);
 
    //Display Process No, Burst Time, Waiting Time and Turnaround Time
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<num;i++){
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], tat[i]);
    }
    //Calculate Total Waiting Time and Total Turnaround Time
    for(i=0;i<num;i++){
        total_wt=total_wt+waiting_time[i];
        total_tat=total_tat+tat[i];
    }
    //Display Average Waiting Time and Average Turnaround Time
    printf("Average Waiting Time=%f\n", (float)total_wt/(float)num);
    printf("Average Turnaround Time=%f\n", (float)total_tat/(float)num);
}

int main(){
  int processes[]={1, 2, 3};
  int burst_time[]={10, 5, 8};
  
  int num=sizeof processes/sizeof processes[0];
  printf("Number of Processes:%d\n\n", num);
  
  printf("Before Using Round Robin Algorithm:\n\n");
  printf("Process\tBurst Time\n");
  
  int i;
  for(i=0;i<num;i++){
    printf("%d\t%d\n", i+1, burst_time[i]);
  }
  
  printf("\nUsing Round Robin Algorithm:\n\n");
  findavgTime(processes, num, burst_time);
  
  return 0;
}