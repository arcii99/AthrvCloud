//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    unsigned char data[BLOCK_SIZE];
} block;

typedef struct {
    char filename[100];
    int file_size;
    int start_block;
} file_info;

void read_blocks(int start_block, int num_blocks, block *out_blocks, FILE *image) {
    fseek(image, BLOCK_SIZE * start_block, SEEK_SET);
    fread(out_blocks, sizeof(block), num_blocks, image);
}

int search_dir(char *filename, block *dir_blocks, int num_blocks, file_info *out_file) {
    for (int i = 0; i < num_blocks; i++) {
        for (int j = 0; j < BLOCK_SIZE; j += sizeof(file_info)) {
            file_info *current_file = (file_info *)&dir_blocks[i].data[j];
            if (strcmp(current_file->filename, filename) == 0) {
                strncpy(out_file->filename, filename, 100);
                out_file->file_size = current_file->file_size;
                out_file->start_block = current_file->start_block;
                return 1;
            }
        }
    }
    return 0;
}

void recover_file(char *filename, FILE *image) {
    block boot_block;
    fread(&boot_block, sizeof(block), 1, image);

    block dir_blocks[boot_block.data[9]];
    read_blocks(boot_block.data[8], boot_block.data[9], dir_blocks, image);

    file_info target_file;
    if (!search_dir(filename, dir_blocks, boot_block.data[9], &target_file)) {
        printf("Could not find file %s\n", filename);
        return;
    }

    FILE *output_file = fopen(filename, "wb");

    block file_blocks[target_file.file_size / BLOCK_SIZE + 1];
    read_blocks(target_file.start_block, target_file.file_size / BLOCK_SIZE + 1, file_blocks, image);

    fwrite(file_blocks, sizeof(block), target_file.file_size / BLOCK_SIZE + 1, output_file);

    fclose(output_file);

    printf("Recovered %s\n", filename);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    FILE *image = fopen(argv[1], "rb");
    if (!image) {
        printf("Could not open image file %s\n", argv[1]);
        return 1;
    }

    char filename[100];
    printf("Enter filename to recover: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;

    recover_file(filename, image);

    fclose(image);
    return 0;
}