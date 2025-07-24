//FormAI DATASET v1.0 Category: File handling ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp_read, *fp_write;
    char buffer[1000];
    int no_of_lines = 0;

    fp_read = fopen("input.txt", "r"); // opening file in read mode
    
    if(fp_read == NULL){ // file not found
        printf("OOPS! Could not open file input.txt\n");
        exit(1);
    }

    // finding total number of lines in file
    while(fgets(buffer, sizeof(buffer), fp_read)){
        no_of_lines++;
    }

    fclose(fp_read); // closing file as read operation is over

    // opening file again in write mode
    fp_write = fopen("output.txt", "w");

    if(fp_write == NULL){ // error in opening file
        printf("OOPS! Could not open file output.txt\n");
        exit(1);
    }

    // writing data to output file in the reverse order
    for(int i = no_of_lines; i > 0; i--){
        fp_read = fopen("input.txt", "r");

        if(fp_read == NULL){ // file not found
            printf("OOPS! Could not open file input.txt\n");
            exit(1);
        }

        int current_line = 1; // variable to keep track of current line number
        while(fgets(buffer, sizeof(buffer), fp_read)){
            if(current_line == i){
                fprintf(fp_write, "%s", buffer); // writing to output file
                break;
            }
            current_line++;
        }

        fclose(fp_read); // closing file as read operation is over
    }

    fclose(fp_write); // closing output file after done with writing operation

    printf("Data is written to output.txt in reverse order\n");

    return 0;
}