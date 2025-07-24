//FormAI DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

/* Define signal handler function */
void signal_handler(int signo);

/* Set up timer */
void alarm_handler(int sig, siginfo_t *si, void *uc);

/* Function to randomly generate a task */
int generate_task();

/* Global variables */
int tasks[10];
int task_index = 0;

int main()
{
    int rc;
    struct sigaction sa;
    struct sigevent sevp;
    timer_t my_timer;

    /* Define signal handler for SIGUSR1 */
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = alarm_handler;
    sigemptyset(&sa.sa_mask);
    rc = sigaction(SIGUSR1, &sa, NULL);
    if (rc < 0) {
        perror("sigaction");
        exit(1);
    }

    /* Create timer */
    sevp.sigev_notify = SIGEV_SIGNAL;
    sevp.sigev_signo = SIGUSR1;
    sevp.sigev_value.sival_ptr = &my_timer;
    rc = timer_create(CLOCK_REALTIME, &sevp, &my_timer);
    if (rc < 0) {
        perror("timer_create");
        exit(1);
    }

    /* Set timer */
    struct itimerspec timer_val;
    timer_val.it_value.tv_sec = 1;
    timer_val.it_value.tv_nsec = 0;
    timer_val.it_interval.tv_sec = 2;
    timer_val.it_interval.tv_nsec = 0;
    rc = timer_settime(my_timer, 0, &timer_val, NULL);
    if (rc < 0) {
        perror("timer_settime");
        exit(1);
    }

    /* Loop infinitely */
    while (1) {
        sleep(1);
    }

    return 0;
}

/* Function to generate and print task */
int generate_task() {
    int task = rand() % 100 + 1;
    printf("Task %d generated!\n", task);
    return task;
}

/* Signal handler function */
void signal_handler(int signo) {
    printf("Caught signal %d!\n", signo);
}

/* Timer handler function */
void alarm_handler(int sig, siginfo_t *si, void *uc) {
    tasks[task_index] = generate_task();
    task_index++;
    if (task_index >= 10) {
        /* All tasks generated, stop timer */
        struct itimerspec stop_timer_val;
        stop_timer_val.it_value.tv_sec = 0;
        stop_timer_val.it_value.tv_nsec = 0;
        stop_timer_val.it_interval.tv_sec = 0;
        stop_timer_val.it_interval.tv_nsec = 0;
        timer_settime(*(timer_t *) si->si_value.sival_ptr, 0, &stop_timer_val, NULL);
        printf("All tasks generated! Stopping timer.\n");
        exit(0);
    }
}