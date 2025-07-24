//FormAI DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILENAME_LENGTH 100

typedef struct dirent {
    char filename[MAX_FILENAME_LENGTH];
    int block_number;
} dirent;

typedef struct file_table_entry {
    char filename[MAX_FILENAME_LENGTH];
    int block_number;
    int file_size;
    int access_mode;
} file_table_entry;


typedef struct superblock {
    int total_blocks;
    int free_blocks;
    int first_free_block;
} superblock;


void create_directory() {
    FILE* directory = fopen("directory", "wb");
    fclose(directory);
}

void initialize_file_table() {
    FILE* file_table = fopen("file_table", "wb");
    file_table_entry empty_entry = {"", 0, 0, 0};
    for(int i = 0; i < 32; i++){
        fwrite(&empty_entry, sizeof(file_table_entry), 1, file_table);
    }
    fclose(file_table);
}

void initialize_block_storage() {   
    char* block_storage = malloc(BLOCK_SIZE * 4096);
    memset(block_storage, 0, BLOCK_SIZE * 4096);
    FILE* storage_file = fopen("block_storage", "wb");
    fwrite(block_storage, BLOCK_SIZE * 4096, 1, storage_file);
    fclose(storage_file);
}


void initialize_file_system() {
    create_directory();
    initialize_file_table();
    initialize_block_storage();
}

dirent* get_directory_entries() {
    FILE* directory = fopen("directory", "rb");
    dirent* directory_entries = calloc(64, sizeof(dirent));
    fread(directory_entries, sizeof(dirent), 64, directory);
    fclose(directory);
    return directory_entries;
}


void print_directory_entries() {
    dirent* directory_entries = get_directory_entries();
    printf("\nNumber of files in directory: %d\n\n", directory_entries[0].block_number);
    for(int i = 1; i < directory_entries[0].block_number + 1; i++){
        printf("%s\n", directory_entries[i].filename);
    }
    free(directory_entries);
}


int allocate_block(superblock* sb) {
    if(sb->free_blocks == 0){
        return -1;
    }
    sb->free_blocks--;
    int block_number = sb->first_free_block;
    FILE* storage_file = fopen("block_storage", "rb+");
    fseek(storage_file, block_number * BLOCK_SIZE, SEEK_SET);
    char* empty_block = calloc(BLOCK_SIZE, sizeof(char));
    fwrite(empty_block, BLOCK_SIZE, 1, storage_file);
    free(empty_block);
    fseek(storage_file, 0, SEEK_SET);
    fwrite(sb, sizeof(superblock), 1, storage_file);
    fseek(storage_file, 0, SEEK_SET);
    fclose(storage_file);
    FILE* file_table = fopen("file_table", "rb+");
    file_table_entry block_map_entry = {"", block_number, 0, 0};
    fseek(file_table, sizeof(file_table_entry) * block_number, SEEK_SET);
    fwrite(&block_map_entry, sizeof(file_table_entry), 1, file_table);
    fclose(file_table);
    sb->first_free_block += 1;
    return block_number;
}


void deallocate_block(int block_number, superblock* sb) {
    sb->free_blocks++;
    if(sb->first_free_block > block_number){
        sb->first_free_block = block_number;
    }
    FILE* storage_file = fopen("block_storage", "rb+");
    fseek(storage_file, block_number * BLOCK_SIZE, SEEK_SET);
    char* empty_block = calloc(BLOCK_SIZE, sizeof(char));
    fwrite(empty_block, BLOCK_SIZE, 1, storage_file);
    free(empty_block);
    fseek(storage_file, 0, SEEK_SET);
    fwrite(sb, sizeof(superblock), 1, storage_file);
    fseek(storage_file, 0, SEEK_SET);
    fclose(storage_file);
    file_table_entry block_map_entry = {"", block_number, 0, 0};
    FILE* file_table = fopen("file_table", "rb+");
    fseek(file_table, sizeof(file_table_entry) * block_number, SEEK_SET);
    fwrite(&block_map_entry, sizeof(file_table_entry), 1, file_table);
    fclose(file_table);
}


file_table_entry* get_file_table() {
    FILE* file_table = fopen("file_table", "rb");
    file_table_entry* file_table_entries = calloc(32, sizeof(file_table_entry));
    fread(file_table_entries, sizeof(file_table_entry), 32, file_table);
    fclose(file_table);
    return file_table_entries;
}


void print_file_table() {
    file_table_entry* file_table_entries = get_file_table();
    printf("\nFile table (filename, block number, file size, access mode):");
    for(int i = 0; i < 32; i++){
        if(file_table_entries[i].filename[0] == '\0'){
            continue;
        }
        printf("\n%s, %d, %d, %d", file_table_entries[i].filename, file_table_entries[i].block_number, file_table_entries[i].file_size, file_table_entries[i].access_mode);
    }
    free(file_table_entries);
}



void write_file_to_block_storage(int block_number, char* data) {
    FILE* storage_file = fopen("block_storage", "rb+");
    fseek(storage_file, block_number * BLOCK_SIZE, SEEK_SET);
    fwrite(data, strlen(data), 1, storage_file);
    fclose(storage_file);
}


void read_file_from_block_storage(int block_number) {
    char* buffer = calloc(BLOCK_SIZE, sizeof(char));
    FILE* storage_file = fopen("block_storage", "rb");
    fseek(storage_file, block_number * BLOCK_SIZE, SEEK_SET);
    fread(buffer, BLOCK_SIZE, 1, storage_file);
    printf("\nData: %s\n", buffer);
    fclose(storage_file);
    free(buffer);
}




int main() {
    initialize_file_system();

    superblock sb = {4096, 4096, 0};

    FILE* storage_file = fopen("block_storage", "rb+");
    fseek(storage_file, 0, SEEK_SET);
    fwrite(&sb, sizeof(superblock), 1, storage_file);
    fclose(storage_file);

    FILE* directory = fopen("directory", "rb+");
    dirent root_directory_entry = {".", 1};
    fwrite(&root_directory_entry, sizeof(dirent), 1, directory);
    fseek(directory, 4096 - sizeof(dirent), SEEK_SET);
    dirent end_of_directory = {"", -1};
    fwrite(&end_of_directory, sizeof(dirent), 1, directory);
    fclose(directory);

    allocate_block(&sb);
    printf("\nFirst free block: %d", sb.first_free_block);
    allocate_block(&sb);
    printf("\nFirst free block: %d", sb.first_free_block);
    print_directory_entries();
    print_file_table();

    char* data = "Hello world!";
    int block_number = allocate_block(&sb);
    printf("\nBlock number for new file: %d", block_number);
    write_file_to_block_storage(block_number, data);

    file_table_entry file1 = {"file1.txt", block_number, strlen(data), 0};
    FILE* file_table = fopen("file_table", "rb+");
    fseek(file_table, sizeof(file_table_entry), SEEK_SET);
    fwrite(&file1, sizeof(file_table_entry), 1, file_table);
    fclose(file_table);

    dirent root_directory = {".", 2};
    FILE* directory_file = fopen("directory", "rb+");
    fseek(directory_file, sizeof(dirent), SEEK_SET);
    fwrite(&root_directory, sizeof(dirent), 1, directory_file);
    dirent file1_directory = {"file1.txt", block_number};
    fwrite(&file1_directory, sizeof(dirent), 1, directory_file);
    fseek(directory_file, 2 * sizeof(dirent), SEEK_SET);
    fwrite(&end_of_directory, sizeof(dirent), 1, directory_file);
    fclose(directory_file);

    print_directory_entries();
    print_file_table();

    read_file_from_block_storage(block_number);

    return 0;
}