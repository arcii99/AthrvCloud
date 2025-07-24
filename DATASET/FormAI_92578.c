//FormAI DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 512

typedef struct __attribute__((__packed__)) {
    unsigned char* data;
    int size;
} Block;

typedef struct {
    Block* blocks;
    int num_blocks;
} Data;

Block read_block(FILE* fp) {
    Block b;
    b.data = malloc(BLOCK_SIZE);
    b.size = fread(b.data, 1, BLOCK_SIZE, fp);
    return b;
}

void destroy_block(Block b) {
    free(b.data);
}

Data read_data(FILE* fp) {
    Data d;
    d.blocks = malloc(sizeof(Block));
    d.num_blocks = 0;

    while(!feof(fp)) {
        Block b = read_block(fp);
        if(b.size > 0) {
            d.num_blocks++;
            d.blocks = realloc(d.blocks, d.num_blocks * sizeof(Block));
            d.blocks[d.num_blocks-1] = b;
        }
        else {
            destroy_block(b);
        }
    }

    return d;
}

void destroy_data(Data d) {
    for(int i = 0; i < d.num_blocks; i++) {
        destroy_block(d.blocks[i]);
    }
    free(d.blocks);
}

void write_data(Data d, FILE* fp) {
    for(int i = 0; i < d.num_blocks; i++) {
        fwrite(d.blocks[i].data, 1, d.blocks[i].size, fp);
    }
}

Data recover_data(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        exit(1);
    }

    Data d = read_data(fp);
    fclose(fp);

    return d;
}

void save_data(Data d, char* filename) {
    FILE* fp = fopen(filename, "wb");
    if(fp == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        exit(1);
    }

    write_data(d, fp);
    fclose(fp);
}

int main(int argc, char** argv) {
    if(argc < 3) {
        fprintf(stderr, "Usage: %s <infile> <outfile>\n", argv[0]);
        exit(1);
    }

    char* infile = argv[1];
    char* outfile = argv[2];

    Data d = recover_data(infile);
    save_data(d, outfile);

    destroy_data(d);

    return 0;
}