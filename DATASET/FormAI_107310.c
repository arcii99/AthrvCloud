//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100

typedef struct {
    int id;
    int length;
} job;

int cmp_job(const void *a, const void *b) {
    const job *job_a = (const job *)a;
    const job *job_b = (const job *)b;
    return job_b->length - job_a->length;
}

int main() {
    int n, i;
    job jobs[MAX_JOBS];

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter the lengths of the jobs: ");
    for (i = 0; i < n; i++) {
        jobs[i].id = i;
        scanf("%d", &jobs[i].length);
    }

    qsort(jobs, n, sizeof(job), cmp_job);

    printf("Job schedule: ");
    for (i = 0; i < n; i++) {
        printf("%d ", jobs[i].id);
    }
    printf("\n");

    return 0;
}