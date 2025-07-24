//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>

struct data_block {
    char contents[512];
};

int main() {
    FILE *disk_image_file = fopen("disk_image.bin", "rb");
    int block_num = 0;
    struct data_block recovered_data[100];
    
    if (disk_image_file != NULL) {
        while (fread(recovered_data[block_num].contents, 1, sizeof(struct data_block), disk_image_file)) {
            // check if block is empty (filled with zeroes)
            int is_empty = 1;
            for (int i = 0; i < sizeof(recovered_data[block_num].contents); i++) {
                if (recovered_data[block_num].contents[i] != '\0') {
                    is_empty = 0;
                    break;
                }
            }
            
            if (!is_empty) {
                printf("Recovered block %d:\n%s\n", block_num, recovered_data[block_num].contents);
            }
            
            block_num++;
            if (block_num == 100) {
                break;
            }
        }
        
        fclose(disk_image_file);
    } else {
        printf("Cannot open disk image file.\n");
    }
    
    return 0;
}