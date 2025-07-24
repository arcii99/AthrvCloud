//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINES 1000
#define MAX_THREAD 10

struct thread_arg {
    char** lines;
    int start_index;
    int end_index;
};

// count the number of occurrences of a keyword in a range of lines
int count_keyword(char** lines, int start_index, int end_index, const char* keyword) {
    int count = 0;
    for (int i = start_index; i <= end_index; ++i) {
        if (strstr(lines[i], keyword) != NULL) {
            ++count;
        }
    }
    return count;
}

// thread function to count occurrences of a keyword in a range of lines
void* thread_func(void* arg) {
    struct thread_arg* t_arg = (struct thread_arg*) arg;
    int count = count_keyword(t_arg->lines, t_arg->start_index, 
                              t_arg->end_index, "ERROR");
    return (void*) count;
}

int main(int argc, char** argv) {
    char* lines[MAX_LINES];
    char line[256];
    int line_count = 0;

    // read log from file
    FILE* f = fopen("logfile.txt", "r");
    if (!f) {
        fprintf(stderr, "Failed to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), f)) {
        lines[line_count] = strdup(line);
        ++line_count;
    }

    fclose(f);

    // divide work among threads
    int n_threads = (line_count < MAX_THREAD) ? line_count : MAX_THREAD;
    pthread_t threads[n_threads];
    struct thread_arg args[n_threads];

    int lines_per_thread = line_count / n_threads;
    int start_index = 0;
    int end_index = lines_per_thread - 1;

    for (int i = 0; i < n_threads; ++i) {
        args[i].lines = lines;
        args[i].start_index = start_index;
        args[i].end_index = end_index;

        pthread_create(&threads[i], NULL, thread_func, &args[i]);

        start_index = end_index + 1;
        end_index += lines_per_thread;

        if (i == n_threads - 2 && end_index < line_count) {
            end_index = line_count - 1; // assign remaining lines to last thread
        }
    }

    // join threads and accumulate results
    int total_count = 0;
    for (int i = 0; i < n_threads; ++i) {
        int count;
        pthread_join(threads[i], (void**) &count);
        total_count += count;
    }

    printf("Total number of errors: %d\n", total_count);

    // free memory
    for (int i = 0; i < line_count; ++i) {
        free(lines[i]);
    }

    return 0;
}