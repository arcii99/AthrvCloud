//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_SEQ_LEN 10000
#define DNA_BASES "ACTG"

char seq[MAX_SEQ_LEN];
int seq_len;

void generate_seq() {
    srand(time(NULL));
    int i;
    for(i=0; i<seq_len; i++) {
        seq[i] = DNA_BASES[rand()%4];
    }
}

void mutate_seq(int count) {
    int i;
    while(count--) {
        int index = rand() % seq_len;
        char new_base = DNA_BASES[rand()%4];
        seq[index] = new_base;
    }
}

void print_seq() {
    int i;
    for(i=0; i<seq_len; i++) {
        printf("%c", seq[i]);
        if(i%50==0 && i>0) printf("\n");
    }
}

int main() {
    seq_len = 1000;
    generate_seq();
    printf("Original Sequence:\n");
    print_seq();
    printf("\nMutated Sequence:\n");
    mutate_seq(10);
    print_seq();
    return 0;
}