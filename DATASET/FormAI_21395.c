//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SEQUENCES 100
#define MAX_LENGTH 1000

/* Function to print the sequence */
void print_sequence(int seq[MAX_LENGTH], int seq_length) {
    for (int i = 0; i < seq_length; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");
}

/* Function to generate random sequence */
void generate_random_sequence(int seq[MAX_LENGTH], int seq_length) {
    srand(time(NULL));
    for (int i = 0; i < seq_length; i++) {
        seq[i] = rand() % 4; // random DNA base - A,C,G,T
    }
}

/* Function to read sequence from file */
int read_sequence_from_file(int seq[MAX_LENGTH], char *filename) {
    FILE *fp;
    int seq_length = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    int base;
    while (fscanf(fp, "%d", &base) == 1) {
        seq[seq_length] = base;
        seq_length++;
    }
    fclose(fp);
    return seq_length;
}

/* Function to write sequence to file */
void write_sequence_to_file(int seq[MAX_LENGTH], int seq_length, char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    for (int i = 0; i < seq_length; i++) {
        fprintf(fp, "%d ", seq[i]);
    }
    fclose(fp);
}

/* Function to simulate genome sequencing */
void genome_sequencing_simulator() {
    int sequences[MAX_SEQUENCES][MAX_LENGTH];
    int num_sequences;
    printf("Enter the number of DNA sequences to simulate: ");
    scanf("%d", &num_sequences);

    /* Generate or read sequence */
    for (int i = 1; i <= num_sequences; i++) {
        printf("Sequence #%d :\n", i);
        int seq[MAX_LENGTH];
        int seq_length;
        printf("Choose an option :\n");
        printf(" 1. Generate Random Sequence\n");
        printf(" 2. Read Sequence from File\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter the length of the sequence (max %d): ", MAX_LENGTH);
                scanf("%d", &seq_length);
                if (seq_length > MAX_LENGTH) {
                    printf("Invalid sequence length!\n");
                    continue;
                }
                generate_random_sequence(seq, seq_length);
                break;
            case 2:
                char filename[100];
                printf("Enter the filename: ");
                scanf("%s", filename);
                seq_length = read_sequence_from_file(seq, filename);
                if (seq_length == -1) {
                    printf("Could not read sequence from file!\n");
                    continue;
                }
                break;
            default:
                printf("Invalid option!\n");
                continue;
        }
        sequences[i-1][0] = seq_length;
        for (int j = 1; j <= seq_length; j++) {
            sequences[i-1][j] = seq[j-1];
        }
    }

    /* Generate fake reads */
    int reads[MAX_SEQUENCES][MAX_LENGTH];
    int num_reads;
    printf("Enter the number of reads to simulate: ");
    scanf("%d", &num_reads);
    srand(time(NULL));
    for (int i = 1; i <= num_reads; i++) {
        int seq_num = rand() % num_sequences;
        int seq_length = sequences[seq_num][0];
        int read_length = rand() % (seq_length/2) + seq_length/2; // reads of random length
        int start_position = rand() % (seq_length - read_length);
        for (int j = start_position; j < start_position + read_length; j++) {
            reads[i-1][j-start_position] = sequences[seq_num][j+1];
        }
    }

    /* Write sequences and reads to file */
    write_sequence_to_file(sequences[0], sequences[0][0]+1, "sequences.txt");
    for (int i = 1; i <= num_reads; i++) {
        char filename[100];
        sprintf(filename, "read%d.txt", i);
        write_sequence_to_file(reads[i-1], MAX_LENGTH, filename);
    }

    /* Print results */
    printf("Sequences:\n");
    for (int i = 1; i <= num_sequences; i++) {
        int seq_length = sequences[i-1][0];
        printf("Sequence #%d: ", i);
        print_sequence(sequences[i-1]+1, seq_length);
    }
    printf("Reads:\n");
    for (int i = 1; i <= num_reads; i++) {
        printf("Read #%d: ", i);
        print_sequence(reads[i-1], MAX_LENGTH);
    }
}

int main() {
    genome_sequencing_simulator();
    return 0;
}