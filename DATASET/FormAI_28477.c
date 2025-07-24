//FormAI DATASET v1.0 Category: Image compression ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8

void compress(char *filename) {
    /* Open the input file */
    FILE *input_file = fopen(filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Error: Could not open input file!\n");
        exit(EXIT_FAILURE);
    }

    /* Determine size of the input file */
    fseek(input_file, 0, SEEK_END);
    long input_size = ftell(input_file);
    rewind(input_file);

    /* Create the output file */
    char *output_filename = malloc(strlen(filename) + 5);
    strcpy(output_filename, filename);
    strcat(output_filename, ".lz78");
    FILE *output_file = fopen(output_filename, "wb");
    free(output_filename);
    if (!output_file) {
        fprintf(stderr, "Error: Could not create output file!\n");
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for the dictionary */
    char **dictionary = calloc(256, sizeof(char *));
    for (size_t i = 0; i < 256; i++) {
        dictionary[i] = malloc(2);
        dictionary[i][0] = (char)i;
        dictionary[i][1] = '\0';
    }
    size_t dict_size = 256;

    /* Compress the input file */
    size_t block_count = input_size / BLOCK_SIZE;
    char *buffer = malloc(BLOCK_SIZE + 1);
    size_t buffer_size = 0;
    char *new_sequence = NULL;
    size_t new_sequence_size = 0;
    while (1) {
        /* Read block from input file */
        size_t bytes_read = fread(buffer + buffer_size, 1, BLOCK_SIZE - buffer_size, input_file);
        buffer_size += bytes_read;
        /* Handle EOF */
        if (bytes_read < BLOCK_SIZE - buffer_size) {
            if (buffer_size > 0) {
                /* Process last block */
                new_sequence = malloc(new_sequence_size + buffer_size);
                memcpy(new_sequence, new_sequence, new_sequence_size);
                memcpy(new_sequence + new_sequence_size, buffer, buffer_size);
                new_sequence_size += buffer_size;
                unsigned short previous_index = 0;
                for (size_t i = 0; i < new_sequence_size; i++) {
                    char *sequence = malloc(2);
                    sequence[0] = new_sequence[i];
                    sequence[1] = '\0';
                    char *concatenated = malloc(strlen(dictionary[previous_index]) + strlen(sequence) + 1);
                    strcpy(concatenated, dictionary[previous_index]);
                    strcat(concatenated, sequence);
                    /* Try to find concatenated sequence in the dictionary */
                    unsigned short current_index = 0;
                    while (current_index < dict_size && strcmp(concatenated, dictionary[current_index]) != 0) {
                        current_index++;
                    }
                    /* If sequence found in dictionary, remember its index */
                    if (current_index < dict_size) {
                        previous_index = current_index;
                    }
                    /* If sequence not found in dictionary, add it to dictionary and output index of previous sequence */
                    else {
                        fwrite(&previous_index, sizeof(unsigned short), 1, output_file);
                        dictionary[dict_size] = concatenated;
                        dict_size++;
                        previous_index = (unsigned short)(dict_size - 1);
                    }
                    free(sequence);
                }
                free(new_sequence);
            }
            break;
        }
        /* Process full block */
        unsigned short previous_index = 0;
        for (size_t i = 0; i < BLOCK_SIZE; i++) {
            char *sequence = malloc(2);
            sequence[0] = buffer[i];
            sequence[1] = '\0';
            char *concatenated = malloc(strlen(dictionary[previous_index]) + strlen(sequence) + 1);
            strcpy(concatenated, dictionary[previous_index]);
            strcat(concatenated, sequence);
            /* Try to find concatenated sequence in the dictionary */
            unsigned short current_index = 0;
            while (current_index < dict_size && strcmp(concatenated, dictionary[current_index]) != 0) {
                current_index++;
            }
            /* If sequence found in dictionary, remember its index */
            if (current_index < dict_size) {
                previous_index = current_index;
            }
            /* If sequence not found in dictionary, add it to dictionary and output index of previous sequence */
            else {
                fwrite(&previous_index, sizeof(unsigned short), 1, output_file);
                dictionary[dict_size] = concatenated;
                dict_size++;
                previous_index = (unsigned short)(dict_size - 1);
            }
            free(sequence);
        }
        /* If buffer not empty, move to beginning of buffer */
        if (buffer_size > BLOCK_SIZE) {
            memmove(buffer, buffer + BLOCK_SIZE, buffer_size - BLOCK_SIZE);
            buffer_size -= BLOCK_SIZE;
        }
        /* If buffer exactly full, move to beginning of buffer */
        else if (buffer_size == BLOCK_SIZE) {
            buffer_size = 0;
        }
    }

    /* Free memory */
    fclose(input_file);
    fclose(output_file);
    free(buffer);
    for (size_t i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
}

void decompress(char *filename) {
    /* Open the input file */
    FILE *input_file = fopen(filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Error: Could not open input file!\n");
        exit(EXIT_FAILURE);
    }

    /* Determine size of the input file */
    fseek(input_file, 0, SEEK_END);
    long input_size = ftell(input_file);
    rewind(input_file);

    /* Create the output file */
    char *output_filename = malloc(strlen(filename) + 5);
    strcpy(output_filename, filename);
    strcat(output_filename, ".unlz78");
    FILE *output_file = fopen(output_filename, "wb");
    free(output_filename);
    if (!output_file) {
        fprintf(stderr, "Error: Could not create output file!\n");
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for the dictionary */
    char **dictionary = calloc(65536, sizeof(char *));
    for (size_t i = 0; i < 256; i++) {
        dictionary[i] = malloc(2);
        dictionary[i][0] = (char)i;
        dictionary[i][1] = '\0';
    }
    size_t dict_size = 256;

    /* Decompress the input file */
    unsigned short current_index = 0;
    unsigned short previous_index = 0;
    size_t bytes_read = 0;
    while (bytes_read < input_size) {
        /* Read next index from input file */
        fread(&current_index, sizeof(unsigned short), 1, input_file);
        bytes_read += sizeof(unsigned short);
        /* If index < dict_size, write corresponding dictionary entry to output file */
        if (current_index < dict_size) {
            fwrite(dictionary[current_index], strlen(dictionary[current_index]), 1, output_file);
            char *sequence = malloc(strlen(dictionary[previous_index]) + 2);
            strcpy(sequence, dictionary[previous_index]);
            sequence[strlen(sequence)] = dictionary[current_index][0];
            sequence[strlen(sequence) + 1] = '\0';
            /* Add new sequence to dictionary */
            dictionary[dict_size] = sequence;
            dict_size++;
            previous_index = current_index;
        }
        /* If index >= dict_size, write concatenation of previous sequence with first character of previous sequence to output file */
        else {
            char *sequence = malloc(strlen(dictionary[previous_index]) + 2);
            strcpy(sequence, dictionary[previous_index]);
            sequence[strlen(sequence)] = dictionary[previous_index][0];
            sequence[strlen(sequence) + 1] = '\0';
            fwrite(sequence, strlen(sequence), 1, output_file);
            /* Add new sequence to dictionary */
            dictionary[dict_size] = sequence;
            dict_size++;
            previous_index = current_index;
        }
    }

    /* Free memory */
    fclose(input_file);
    fclose(output_file);
    for (size_t i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <c/d> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strcmp(argv[1], "c") == 0) {
        printf("Compressing %s...\n", argv[2]);
        compress(argv[2]);
        printf("Done!\n");
    }
    else if (strcmp(argv[1], "d") == 0) {
        printf("Decompressing %s...\n", argv[2]);
        decompress(argv[2]);
        printf("Done!\n");
    }
    else {
        fprintf(stderr, "Invalid operation!\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}