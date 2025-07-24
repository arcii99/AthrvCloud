//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include<stdio.h>

int main() {
    printf("Oh boy, I can't believe this code actually works!\n\n");

    printf("Let's say you have 'n' tasks to do and each task has a deadline and a penalty.\n");
    printf("Your goal is to complete all tasks before their deadline in order to minimize the penalty.\n\n");

    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    int i, j;
    int t[n], d[n], p[n], s[n];
    int max_deadline = 0;

    for(i = 0; i < n; i++) {
        printf("\nEnter details for task %d:\n", i+1);
        printf("Time taken to complete task %d: ", i+1);
        scanf("%d", &t[i]);
        printf("Deadline for task %d: ", i+1);
        scanf("%d", &d[i]);
        printf("Penalty for task %d: ", i+1);
        scanf("%d", &p[i]);

        // initialize array s with -1
        s[i] = -1;

        // update max deadline
        if(d[i] > max_deadline) {
            max_deadline = d[i];
        }
    }

    // sort tasks in ascending order of penalties
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(p[j] < p[i]) {
                int temp = t[i];
                t[i] = t[j];
                t[j] = temp;
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int k, index, flag;
    int curr_time = 0;
    for(k = 0; k < max_deadline; k++) {
        flag = 0;
        int min_penalty = 9999;
        for(i = 0; i < n; i++) {
            // skip tasks that have already been scheduled
            if(s[i] != -1) {
                continue;
            }
            // check if task can be completed before its deadline
            if(curr_time + t[i] <= d[i]) {
                // check if task penalty is less than current minimum penalty
                if(p[i] < min_penalty) {
                    min_penalty = p[i];
                    index = i;
                    flag = 1;
                }
            }
        }
        // schedule the task with minimum penalty if it exists
        if(flag) {
            s[index] = curr_time;
            curr_time += t[index];
        } else {
            curr_time++;
        }
    }

    int total_penalty = 0;
    printf("\n\nScheduled Tasks:\n");
    printf("{ Task | Time Taken | Deadline | Penalty | Start Time | End Time }\n");
    for(i = 0; i < n; i++) {
        printf("{ %5d | %10d | %8d | %7d | %10d | %9d }\n", i+1, t[i], d[i], p[i], s[i], s[i]+t[i]);
        total_penalty += p[i]*(s[i]+t[i]-d[i]);
    }

    printf("\n\nTotal Penalty: %d\n\n", total_penalty);
    printf("Surprise! The greedy algorithm worked like a charm.");
    return 0;
}