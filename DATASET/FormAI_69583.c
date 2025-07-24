//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <pthread.h>

#define UNUSED(x) (void)(x)

volatile int stop_running = 0;

typedef struct {
    char* memory_buffer;
    size_t buffer_size;
    long* values[3];
    FILE* out_stream;
} memory_snapshot_arguments;

long calculate_used_memory() {
    struct sysinfo sys_info;
    if (sysinfo(&sys_info) != 0) {
        return -1;
    }

    long used_memory = sys_info.totalram - sys_info.freeram;
    used_memory -= sys_info.bufferram + sys_info.sharedram;
    return used_memory * sys_info.mem_unit;
}

void* memory_snapshot_printer(void* ptr) {
    if (!ptr) {
        return NULL;
    }

    memory_snapshot_arguments* arguments = (memory_snapshot_arguments*) ptr;
    UNUSED(arguments->memory_buffer);
    UNUSED(arguments->buffer_size);

    fprintf(arguments->out_stream, "Time,Total,Used,Free\n");

    while (!stop_running) {
        long snapshot_values[3];
        snapshot_values[0] = calculate_used_memory();
        snapshot_values[1] = snapshot_values[0] + (long)(sysconf(_SC_PAGE_SIZE));
        snapshot_values[2] = get_avphys_pages() * (long)(sysconf(_SC_PAGE_SIZE));
        *(arguments->values[0]) = snapshot_values[0];
        *(arguments->values[1]) = snapshot_values[1];
        *(arguments->values[2]) = snapshot_values[2];

        time_t now = time(NULL);
        char* time_string = ctime(&now);
        time_string[strlen(time_string) - 1] = 0;

        fprintf(arguments->out_stream, "%s,", time_string);
        fprintf(arguments->out_stream, "%lu,", snapshot_values[0]);
        fprintf(arguments->out_stream, "%lu,", snapshot_values[1]);
        fprintf(arguments->out_stream, "%lu\n", snapshot_values[2]);
        fflush(arguments->out_stream);

        sleep(1);
    }

    return NULL;
}

void print_memory_usage() {
    long used_memory = calculate_used_memory();
    if (used_memory == -1) {
        printf("Error while calculating memory usage\n");
        return;
    }

    printf("Total memory used: %lu\n", used_memory);
}

void start_monitoring_memory() {
    pthread_t monitor_thread;

    char* memory_buffer = (char *) malloc(256);
    long snapshot_values[3] = {0, 0, 0};
    FILE* out_stream = fopen("memory_snapshot.csv", "w+");
    if (!out_stream) {
        printf("Error opening output file\n");
        free(memory_buffer);
        return;
    }

    memory_snapshot_arguments arguments = {
        .memory_buffer = memory_buffer,
        .buffer_size = 256,
        .values = {&snapshot_values[0], &snapshot_values[1], &snapshot_values[2]},
        .out_stream = out_stream
    };

    pthread_create(&monitor_thread, NULL, memory_snapshot_printer, (void*) &arguments);
    printf("Monitoring memory usage... (press ENTER to stop)\n");
    getchar();

    stop_running = 1;
    pthread_join(monitor_thread, NULL);

    free(memory_buffer);
    fclose(out_stream);
}

int main() {
    char option;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Print current memory usage\n");
        printf("2. Start monitoring memory usage\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &option);
        printf("\n");

        switch (option) {
            case '1': print_memory_usage(); break;
            case '2': start_monitoring_memory(); break;
            case '3': return 0;
            default: printf("Invalid option\n");
        }
    }
}