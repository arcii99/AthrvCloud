//FormAI DATASET v1.0 Category: Data recovery tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    char disk_name[20]; 
    printf("Enter the name of the disk drive: ");
    scanf("%s", disk_name); 

    FILE *disk = fopen(disk_name, "rb"); 
    if (disk == NULL) {
        printf("Error: could not open the specified disk drive.\n");
        exit(1);
    }

    int magic_number = 1234; 
    int num_sectors, sector_size; 
    fread(&num_sectors, sizeof(int), 1, disk); 
    fread(&sector_size, sizeof(int), 1, disk); 

    if (sector_size != 512) {
        printf("Error: this program only works with 512-byte sectors.\n");
        exit(1);
    }

    int i, j; 
    char sector[512]; 
    for (i = 0; i < num_sectors; i++) {
        fread(sector, sizeof(char), 512, disk); 
        if (sector[0] == magic_number && sector[1] == magic_number) {
            for (j = 2; j < 510; j += 2) {
                char temp = sector[j]; 
                sector[j] = sector[j+1]; 
                sector[j+1] = temp; 
            }
            fseek(disk, -512, SEEK_CUR); 
            fwrite(sector, sizeof(char), 512, disk); 
        }
    }

    printf("Data recovery complete!\n");
    fclose(disk); 
    return 0; 
}