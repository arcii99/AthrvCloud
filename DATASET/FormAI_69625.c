//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void compress(char input[], char compressed[]){
    int i, j, k, freq, len = strlen(input);
    
    for(i = 0, k = 0; i < len; i++){
        compressed[k++] = input[i];
        freq = 1;
        
        while(i + 1 < len && input[i] == input[i+1]){
            freq++;
            i++;
        }
        
        if(freq > 1){
            char freq_str[MAX_SIZE];
            sprintf(freq_str, "%d", freq);
            int freq_len = strlen(freq_str);
            for(j = 0; j < freq_len; j++){
                compressed[k++] = freq_str[j];
            }           
        }
    }
    
    compressed[k] = '\0';
}

void decompress(char compressed[], char decompressed[]){
    int i, j, k, freq, len = strlen(compressed);
    
    for(i = 0, k = 0; i < len; i++){
        decompressed[k++] = compressed[i];
        
        if(i+1 < len && compressed[i+1] >= '0' && compressed[i+1] <= '9'){
            freq = compressed[i+1] - '0';
            i++;
            
            while(i+1 < len && compressed[i+1] >= '0' && compressed[i+1] <= '9'){
                freq = freq * 10 + (compressed[i+1] - '0');
                i++;
            }
            
            for(j = 0; j < freq - 1; j++){
                decompressed[k++] = compressed[i];
            }
        }
    }
    
    decompressed[k] = '\0';
}

int main(){
    char input[MAX_SIZE], compressed[MAX_SIZE], decompressed[MAX_SIZE];
    
    printf("Enter the input string: ");
    fgets(input, MAX_SIZE, stdin);
    
    compress(input, compressed);
    
    printf("The compressed string is: %s\n", compressed);
    
    decompress(compressed, decompressed);
    
    printf("The decompressed string is: %s\n", decompressed);
    
    return 0;
}