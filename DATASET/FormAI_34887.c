//FormAI DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct _data_block {
    unsigned char data[512];
} data_block;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "rb");
    if (!fp_in) {
        printf("Error: could not open input file\n");
        return 1;
    }

    FILE *fp_out = fopen(argv[2], "wb");
    if (!fp_out) {
        printf("Error: could not open output file\n");
        fclose(fp_in);
        return 1;
    }

    int block_count = 0;
    int data_size = 0;
    data_block *data_blocks = NULL;

    while (!feof(fp_in)) {
        data_blocks = realloc(data_blocks, (block_count + 1) * sizeof(data_block));
        data_size = fread(data_blocks[block_count].data, sizeof(unsigned char), 512, fp_in);
        if (data_size != 512) {
            break;
        }
        block_count++;
    }

    for (int i = block_count - 1; i >= 0; i--) {
        fwrite(data_blocks[i].data, sizeof(unsigned char), data_size, fp_out);
    }

    free(data_blocks);
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}