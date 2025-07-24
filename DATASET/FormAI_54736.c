//FormAI DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

// Struct to store recovered file information
typedef struct {
    char* name;
    size_t size;
    unsigned char* data;
} recovered_file;

// Function to search for deleted files and recover them
void recover_files(FILE* disk_image, unsigned int start_sector, unsigned int end_sector, char* search_pattern, recovered_file** recovered_files, int* num_files) {
    unsigned int current_sector = start_sector;
    while (current_sector < end_sector) {
        // Read current sector
        unsigned char sector[BLOCK_SIZE];
        fseek(disk_image, current_sector * BLOCK_SIZE, SEEK_SET);
        fread(sector, BLOCK_SIZE, 1, disk_image);

        // Check if sector contains deleted file header
        if (sector[0] == 0xE5 || sector[0] == 0x00) {
            // Check if file name matches search pattern
            char file_name[9];
            memcpy(file_name, sector, 8);
            file_name[8] = '\0';
            if (strstr(file_name, search_pattern) != NULL) {
                // Calculate file size and starting sector
                unsigned int file_size = *((unsigned int*)(sector + 28));
                unsigned int start_cluster = *((unsigned int*)(sector + 26));

                // Allocate memory for recovered file
                recovered_file* recovered = malloc(sizeof(recovered_file));
                recovered->name = malloc(strlen(file_name) + 1);
                strcpy(recovered->name, file_name);
                recovered->size = (size_t)file_size;
                recovered->data = malloc(recovered->size);

                // Read all clusters of file and concatenate into single buffer
                unsigned int current_cluster = start_cluster;
                unsigned char* current_data = recovered->data;
                while (1) {
                    // Calculate sector for current cluster
                    unsigned int current_sector = ((current_cluster - 2) * 4) + 19;

                    // Read current sector
                    fseek(disk_image, current_sector * BLOCK_SIZE, SEEK_SET);
                    fread(sector, BLOCK_SIZE, 1, disk_image);

                    // Copy data from sector to recovered file buffer
                    unsigned int bytes_to_copy = BLOCK_SIZE;
                    if (current_data + BLOCK_SIZE > recovered->data + recovered->size) {
                        bytes_to_copy = recovered->data + recovered->size - current_data;
                    }
                    memcpy(current_data, sector, bytes_to_copy);
                    current_data += bytes_to_copy;

                    // Check if this is the last cluster
                    if (current_cluster >= 0xFFF8) {
                        break;
                    }

                    // Move to next cluster
                    current_cluster = *((unsigned int*)(sector + ((current_cluster % 128) * 4)));
                }

                // Append recovered file to array
                (*num_files)++;
                *recovered_files = realloc(*recovered_files, (*num_files) * sizeof(recovered_file));
                (*recovered_files)[(*num_files) - 1] = *recovered;
            }
        }

        // Move to next sector
        current_sector++;
    }
}

// Main function to recover deleted files from disk image
int main(int argc, char* argv[]) {
    // Check input arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [disk image file name] [search pattern]\n", argv[0]);
        return 1;
    }

    // Open disk image file
    FILE* disk_image = fopen(argv[1], "rb");
    if (disk_image == NULL) {
        fprintf(stderr, "Error opening disk image file: %s\n", argv[1]);
        return 1;
    }

    // Get partition start and end sector
    fseek(disk_image, 0x1be, SEEK_SET);
    unsigned char partition_entry[16];
    fread(partition_entry, 16, 1, disk_image);
    unsigned int start_sector = *((unsigned int*)(partition_entry + 8));
    unsigned int end_sector = start_sector + *((unsigned int*)(partition_entry + 12));

    // Recover deleted files
    recovered_file* recovered_files = NULL;
    int num_files = 0;
    recover_files(disk_image, start_sector, end_sector, argv[2], &recovered_files, &num_files);

    // Output recovered files
    if (num_files == 0) {
        printf("No deleted files matching search pattern found.\n");
    } else {
        printf("Recovered %d deleted files:\n", num_files);
        for (int i = 0; i < num_files; i++) {
            printf("File %d:\n\tName: %s\n\tSize: %zu bytes\n", i + 1, recovered_files[i].name, recovered_files[i].size);
            // Output data if size is less than 100 bytes
            if (recovered_files[i].size <= 100) {
                printf("\tData: ");
                for (size_t j = 0; j < recovered_files[i].size; j++) {
                    printf("%02x ", recovered_files[i].data[j]);
                }
                printf("\n");
            }
        }
        // Free memory allocated for recovered files
        for (int i = 0; i < num_files; i++) {
            free(recovered_files[i].name);
            free(recovered_files[i].data);
        }
        free(recovered_files);
    }

    // Close disk image file
    fclose(disk_image);

    return 0;
}