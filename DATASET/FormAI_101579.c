//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("What? Digital watermarking program? Are you kidding me?\n");
    printf("Fine, but don't blame me if this program doesn't work!\n");
    
    typedef struct pixel{
        int r;
        int g;
        int b;
    }Pixel;
    
    Pixel image[10][10];
    char message[100] = "This is a digital watermark!";
    
    int message_len = strlen(message);
    int current_bit_index = 0;
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            image[i][j].r = i+j;
            image[i][j].g = i-j;
            image[i][j].b = i*j;
            
            if(current_bit_index<message_len*8){
                int current_byte_index = current_bit_index/8;
                int current_bit_in_byte = current_bit_index%8;
                
                char current_bit = (message[current_byte_index]>>(7-current_bit_in_byte)) & 1;
                
                if(current_bit==1){
                    image[i][j].b = image[i][j].b | 1;
                }else{
                    image[i][j].b = image[i][j].b & ~(1);
                }
            }
            current_bit_index++;
        }
    }
    
    printf("Digital watermarking completed successfully! Check the modified image: \n");
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("(%d, %d, %d) ", image[i][j].r, image[i][j].g, image[i][j].b);
        }
        printf("\n");
    }
    
    return 0;
}