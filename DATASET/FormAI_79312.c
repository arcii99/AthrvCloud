//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: innovative
/*
* This program implements a simple threading library with cooperative threads.
* The program creates and runs a set of threads that increment a shared counter value.
* The counter is implemented as a global variable and is accessed by all threads.
* The threads are scheduled using a round-robin algorithm.
* Author: Virtual Assistant
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <ucontext.h>

#define STACK_SIZE 16384
#define MAX_THREADS 10

volatile int shared_counter = 0;

typedef struct thread_t
{
    int id;
    ucontext_t ctx;
    uint8_t *stack;
    struct thread_t *prev, *next;
} thread_t;

thread_t *running_thread = NULL;
thread_t *ready_queue = NULL;

void timer_handler(int signum)
{
    if (running_thread != NULL)
    {
        thread_t *next = ready_queue;
        if (next == NULL)
        {
            next = running_thread;
        }
        else
        {
            ready_queue = next->next;
            next->next->prev = NULL;
            next->next = NULL;
        }
        thread_t *current = running_thread;
        running_thread = next;
        swapcontext(&current->ctx, &running_thread->ctx);
    }
}

void thread_init()
{
    struct sigaction sa;
    struct itimerval timer;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = &timer_handler;

    if (sigaction(SIGALRM, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 100000;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 100000;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1)
    {
        perror("setitimer");
        exit(1);
    }
}

void thread_exit()
{
    if (running_thread != NULL)
    {
        free(running_thread->stack);
        free(running_thread);
        running_thread = NULL;
    }

    if (ready_queue != NULL)
    {
        thread_t *current = ready_queue;
        while (current != NULL)
        {
            thread_t *next = current->next;
            free(current->stack);
            free(current);
            current = next;
        }
        ready_queue = NULL;
    }
}

void thread_yield()
{
    if (running_thread != NULL)
    {
        if (ready_queue == NULL)
        {
            ready_queue = running_thread;
        }
        else
        {
            thread_t *last = ready_queue;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = running_thread;
            running_thread->prev = last;
            running_thread->next = NULL;
        }
        thread_t *current = running_thread;
        running_thread = NULL;
        swapcontext(&current->ctx, &running_thread->ctx);
    }
}

void thread_check()
{
    if (running_thread == NULL)
    {
        thread_yield();
    }
}

thread_t *thread_create(void (*func)())
{
    static int id = 0;

    if (id == MAX_THREADS)
    {
        fprintf(stderr, "thread_create: limit of %d threads exceeded\n", MAX_THREADS);
        return NULL;
    }
    thread_t *thread = (thread_t *)malloc(sizeof(thread_t));
    if (thread == NULL)
    {
        perror("thread_create: error allocating thread structure");
        return NULL;
    }
    thread->id = ++id;
    thread->stack = (uint8_t *)malloc(STACK_SIZE);
    if (thread->stack == NULL)
    {
        perror("thread_create: error allocating stack");
        free(thread);
        return NULL;
    }

    if (getcontext(&thread->ctx) == -1)
    {
        perror("thread_create: error getting context");
        free(thread->stack);
        free(thread);
        return NULL;
    }
    thread->ctx.uc_stack.ss_sp = thread->stack;
    thread->ctx.uc_stack.ss_size = STACK_SIZE;
    thread->ctx.uc_link = NULL;
    makecontext(&thread->ctx, func, 0);

    thread->prev = NULL;
    thread->next = NULL;

    return thread;
}

void thread_wait(thread_t *thread)
{
    free(thread->stack);
    free(thread);
}

void increment_counter()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        thread_check();
        shared_counter++;
        printf("Thread %d: counter = %d\n", running_thread->id, shared_counter);
        thread_yield();
    }
}

int main()
{
    thread_init();

    thread_t *t1 = thread_create(increment_counter);
    thread_t *t2 = thread_create(increment_counter);
    thread_t *t3 = thread_create(increment_counter);
    thread_t *t4 = thread_create(increment_counter);

    while (shared_counter < 40)
    {
        thread_check();
        thread_yield();
    }

    thread_wait(t1);
    thread_wait(t2);
    thread_wait(t3);
    thread_wait(t4);

    thread_exit();

    return 0;
}