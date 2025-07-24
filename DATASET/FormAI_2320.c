//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *input_file;
    char *output_file;
    int num_threads;
} compression_args;

void *compress_file(void *args) {
    compression_args *comp_args = (compression_args *) args;
    char buffer[BUFFER_SIZE];
    FILE *input_fp, *output_fp;
    int num_bytes_read;
    
    input_fp = fopen(comp_args->input_file, "r");
    output_fp = fopen(comp_args->output_file, "w");
    
    while ((num_bytes_read = fread(buffer, 1, BUFFER_SIZE, input_fp))) {
        fwrite(buffer, 1, num_bytes_read, output_fp);
    }
    
    fclose(input_fp);
    fclose(output_fp);
    
    pthread_exit(NULL);
}

void compress(char *input_file, char *output_file, int num_threads) {
    compression_args comp_args[num_threads];
    pthread_t threads[num_threads];
    
    for (int i = 0; i < num_threads; i++) {
        comp_args[i].input_file = input_file;
        comp_args[i].output_file = output_file;
        comp_args[i].num_threads = num_threads;
        pthread_create(&threads[i], NULL, compress_file, &comp_args[i]);
    }
    
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    int num_threads = 4;
    
    compress(input_file, output_file, num_threads);
    
    return 0;
}