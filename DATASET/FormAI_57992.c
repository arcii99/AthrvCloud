//FormAI DATASET v1.0 Category: File Encyptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 256 // block size in bytes
#define NUM_THREADS 4 // number of threads for encryption
#define BUFFER_SIZE (BLOCK_SIZE * NUM_THREADS) // buffer size in bytes

// encryption function
void encrypt(char *buf, int len, const char *key) {
    int key_len = strlen(key);
    for (int i = 0; i < len; i++) {
        buf[i] ^= key[i % key_len];
    }
}

// thread function for encryption
void *encrypt_thread(void *arg) {
    char *buf = (char *)arg;
    encrypt(buf, BLOCK_SIZE, "my_secret_key");
    return NULL;
}

// main function
int main(int argc, char *argv[]) {
    // check command line arguments
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    // open input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Could not open input file %s\n", argv[1]);
        exit(1);
    }

    // create output file
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Could not create output file %s\n", argv[2]);
        exit(1);
    }

    // allocate buffer
    char *buf = (char *)malloc(BUFFER_SIZE);
    if (buf == NULL) {
        printf("Could not allocate buffer\n");
        exit(1);
    }

    // read input file and encrypt in parallel
    size_t bytes_read;
    while ((bytes_read = fread(buf, 1, BUFFER_SIZE, input_file)) > 0) {
        // create threads for encryption
        pthread_t threads[NUM_THREADS];
        for (int i = 0; i < NUM_THREADS; i++) {
            int offset = i * BLOCK_SIZE;
            pthread_create(&threads[i], NULL, encrypt_thread, buf + offset);
        }

        // join threads
        for (int i = 0; i < NUM_THREADS; i++) {
            pthread_join(threads[i], NULL);
        }

        // write encrypted data to output file
        fwrite(buf, 1, bytes_read, output_file);
    }

    // close files and free buffer
    fclose(input_file);
    fclose(output_file);
    free(buf);

    return 0;
}