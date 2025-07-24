//FormAI DATASET v1.0 Category: Data recovery tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

//Function to recover data from a damaged file
void recover_file(char* filename){
    FILE *file, *recovered_file;
    unsigned char block[BLOCK_SIZE];
    int counter = 0, file_counter = 0;

    file = fopen(filename, "rb");
    if(!file){
        printf("Error opening file!\n");
        exit(1);
    }

    while(fread(block, BLOCK_SIZE, 1, file)){
        counter++;

        if(counter == 1){
            file_counter++;
            char new_filename[20];
            sprintf(new_filename, "recovered_file_%d.txt", file_counter);
            recovered_file = fopen(new_filename, "wb");
            if(!recovered_file){
                printf("Error creating recovered file!\n");
                exit(1);
            }
        }

        if(block[0] == 0xFF && block[1] == 0xD8 && block[2] == 0xFF && (block[3] & 0xF0) == 0xE0){
            fclose(recovered_file);
            printf("JPEG file recovered!\n");
            counter = 0;
        }

        fwrite(block, BLOCK_SIZE, 1, recovered_file);

    }

    fclose(file);
}


int main(){
    recover_file("damaged_file.bin");

    return 0;
}