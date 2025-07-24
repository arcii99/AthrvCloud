//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 128

// Declare a struct to hold CSV data
typedef struct {
    char **data; // 2D array to hold CSV data
    int num_rows; // Number of rows in the CSV data
    int num_columns; // Number of columns in the CSV data
} csv_data_t;

// Declare a struct to pass arguments to the thread function
typedef struct {
    int start_index;
    int end_index;
    char *filename;
    csv_data_t *csv_data;
} thread_args_t;

// Declare a function to parse a line of CSV data
void parse_csv_line(char *line, char **columns, int *num_columns) {
    char *token;
    int column_index = 0;
    token = strtok(line, ",");
    while (token != NULL && column_index < MAX_NUM_COLUMNS) {
        columns[column_index++] = token;
        token = strtok(NULL, ",");
    }
    *num_columns = column_index;
}

// Declare a thread function to parse a range of lines in a CSV file
void *parse_csv_file_thread(void *args) {
    thread_args_t *thread_args = (thread_args_t *) args;
    FILE *fp = fopen(thread_args->filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", thread_args->filename);
        return NULL;
    }
    int line_index = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && line_index < thread_args->end_index) {
        if (line_index >= thread_args->start_index) {
            char *columns[MAX_NUM_COLUMNS];
            int num_columns;
            parse_csv_line(line, columns, &num_columns);
            if (num_columns > 0) {
                for (int i = 0; i < num_columns; i++) {
                    thread_args->csv_data->data[line_index][i] = strdup(columns[i]);
                }
            }
            thread_args->csv_data->num_columns = num_columns;
        }
        line_index++;
    }
    fclose(fp);
    return NULL;
}

// Declare a function to read CSV data from a file
csv_data_t *read_csv_file(char *filename, int num_threads) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }
    int num_lines = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        num_lines++;
    }
    fclose(fp);
    csv_data_t *csv_data = malloc(sizeof(csv_data_t));
    csv_data->data = malloc(num_lines * sizeof(char *));
    for (int i = 0; i < num_lines; i++) {
        csv_data->data[i] = malloc(MAX_NUM_COLUMNS * sizeof(char *));
    }
    csv_data->num_rows = num_lines;
    csv_data->num_columns = 0;
    pthread_t threads[num_threads];
    thread_args_t thread_args[num_threads];
    int lines_per_thread = num_lines / num_threads;
    for (int i = 0; i < num_threads; i++) {
        int start_index = i * lines_per_thread;
        int end_index = (i == num_threads - 1) ? num_lines : (i + 1) * lines_per_thread;
        thread_args[i].start_index = start_index;
        thread_args[i].end_index = end_index;
        thread_args[i].filename = filename;
        thread_args[i].csv_data = csv_data;
        pthread_create(&threads[i], NULL, parse_csv_file_thread, &thread_args[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return csv_data;
}

int main() {
    csv_data_t *csv_data = read_csv_file("test.csv", 4);
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->num_columns; j++) {
            printf("%s ", csv_data->data[i][j]);
        }
        printf("\n");
    }
    return 0;
}