//FormAI DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Run-length Encoding Algorithm*/
void RLE_compress(char *input_str, char *output_str) {
    int len = strlen(input_str);
    int count;
    
    for (int i=0; i<len; i+=count) {
        count = 1;
        while ((i+count < len) && (input_str[i] == input_str[i+count])) {
            count++;
        }
        sprintf(output_str+strlen(output_str),"%d%c",count,input_str[i]); //Add to output string
    }
}

/* Run-length Decoding Algorithm*/
void RLE_decompress(char *input_str, char *output_str) {
    int len = strlen(input_str);
    int count;
    char num_buffer[10] = "";
    
    for (int i=0; i<len; i++) {
        if (isdigit(input_str[i])) { //Get the number of consecutive repeats
            num_buffer[strlen(num_buffer)] = input_str[i];
        } else { //Repeat the character for the given number of counts and add to output string
            count = atoi(num_buffer);
            for (int j=0; j<count; j++) {
                sprintf(output_str+strlen(output_str),"%c",input_str[i]);
            }
            memset(num_buffer,0,strlen(num_buffer)); //Clear buffer for next set of numbers
        }
    }
}

int main() {
    char input_str[] = "AAAAABBBBCCCCDDDEEEFFFGGGGHHHIJJKKKLLLMMNOOPQQQRRRRSSSTTT";
    char compressed_str[100] = "";
    char decompressed_str[100] = "";
    
    RLE_compress(input_str, compressed_str);
    printf("Compressed String: %s\n",compressed_str);
    
    RLE_decompress(compressed_str, decompressed_str);
    printf("Decompressed String: %s\n",decompressed_str);
    
    return 0;
}