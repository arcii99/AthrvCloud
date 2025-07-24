//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include<stdio.h>
#include<string.h>

char watermark[] = "MyDigitalWatermark";

void embed_watermark(char filename[]) {
    FILE *fp = fopen(filename, "r+b");
    if(fp == NULL) {
        printf("Error opening file!");
    }
    else {
        char ch, temp;
        int i = 0, j = 0;
        fseek(fp, 0, SEEK_SET);
        while(fread(&ch, sizeof(char), 1, fp) == 1) {
            if(i < strlen(watermark)) {
                temp = ch & 0xFE;
                temp |= (watermark[i] >> j) & 0x01;
                fwrite(&temp, sizeof(char), 1, fp);
                j++;
                if(j == 8) {
                    i++;
                    j = 0;
                }
            }
            else {
                break;
            }
        }
        fclose(fp);
    }
}

int verify_watermark(char filename[]) {
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening file!");
    }
    else {
        char ch, temp;
        int i = 0, j = 0;
        fseek(fp, 0, SEEK_SET);
        while(fread(&ch, sizeof(char), 1, fp) == 1 && i < strlen(watermark)) {
            temp = ch & 0x01;
            watermark[i] &= ~(0x01 << j);
            watermark[i] |= temp << j;
            j++;
            if(j == 8) {
                i++;
                j = 0;
            }
        }
        fclose(fp);
        if(strcmp(watermark, "MyDigitalWatermark") == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char filename[] = "example.jpg";
    embed_watermark(filename);
    if(verify_watermark(filename)) {
        printf("Watermark verified successfully!");
    }
    else {
        printf("Watermark verification failed!");
    }
    return 0;
}