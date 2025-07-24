//FormAI DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define INTERVAL 2 // Interval in seconds between job executions
#define MAX_JOBS 5 // Maximum number of jobs in the queue

int job_queue[MAX_JOBS]; // Array to store jobs

void job_one() {
   printf("Job One executed successfully!\n");
}

void job_two() {
   printf("Job Two executed successfully!\n");
}

void job_three() {
   printf("Job Three executed successfully!\n");
}

void job_four() {
   printf("Job Four executed successfully!\n");
}

void job_five() {
   printf("Job Five executed successfully!\n");
}

void register_job(int job_number) {
   int i = 0;
   while(i < MAX_JOBS && job_queue[i] != 0) {
       i++;
   }
   if(i == MAX_JOBS) {
       printf("Error: Maximum job limit reached!\n");
   } else {
       job_queue[i] = job_number;
       printf("Job %d registered successfully.\n", job_number);
   }
}

void unregister_job(int job_number) {
   int i = 0;
   while(i < MAX_JOBS && job_queue[i] != job_number) {
       i++;
   }
   if(i == MAX_JOBS) {
       printf("Error: Job not found!\n");
   } else {
       job_queue[i] = 0;
       printf("Job %d unregistered successfully.\n", job_number);
   }
}

void show_jobs() {
   printf("Registered Jobs: ");
   for(int i=0; i<MAX_JOBS; i++) {
       if(job_queue[i] != 0) {
           printf("%d ", job_queue[i]);
       }
   }
   printf("\n");
}

void execute_job(int job_number) {
   switch(job_number) {
       case 1:
           job_one();
           break;
       case 2:
           job_two();
           break;
       case 3:
           job_three();
           break;
       case 4:
           job_four();
           break;
       case 5:
           job_five();
           break;
       default:
           printf("Error: Job not found!\n");
           break;
   }
}

void schedule_jobs() {
   static int job_index = 0;
   execute_job(job_queue[job_index]);
   job_index = (job_index + 1) % MAX_JOBS;
   alarm(INTERVAL);
}

void handle_sigint(int sig) {
   printf("Received SIGINT signal, stopping job scheduler.\n");
   exit(0);
}

int main() {
   signal(SIGINT, handle_sigint);
   alarm(INTERVAL);

   register_job(1);
   register_job(3);
   register_job(5);
   show_jobs();

   while(1) {
       pause();
   }
   return 0;
}