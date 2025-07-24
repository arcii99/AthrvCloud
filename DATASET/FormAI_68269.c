//FormAI DATASET v1.0 Category: QR code generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

//define the QR code matrix size 
#define MAX_N 50 

//define the QR code mask patterns to choose from 
#define MASK_000 0 
#define MASK_001 1 
#define MASK_010 2 
#define MASK_011 3 
#define MASK_100 4 
#define MASK_101 5 
#define MASK_110 6 
#define MASK_111 7 

//create a struct for QR code 
typedef struct {
    int size; 
    bool data[MAX_N][MAX_N]; 
}QRCode; 

//initialize QR code with all bits set to 0 
void QRCode_initialize(QRCode* code) { 
    memset(code->data, false, sizeof(code->data)); 
    code->size = MAX_N; 
} 

//check if a given cell can be part of QR code or not 
bool QRCode_isValidCell(int row, int col) { 
    if (row < 0 || col < 0 || row >= MAX_N || col >= MAX_N) {
        return false; 
    }
    return true; 
} 

//apply given mask pattern to the QR code 
void QRCode_applyMask(int pattern, QRCode* code) {
    int size = code->size; 
    bool mask[MAX_N][MAX_N]; 

    for(int row=0; row<size; row++) { 
        for(int col=0; col<size; col++) {
            mask[row][col] = false; 
            
            switch(pattern) {
                case MASK_000: 
                    mask[row][col] = (row+col)%2 == 0; 
                    break; 
                case MASK_001: 
                    mask[row][col] = row%2 == 0; 
                    break; 
                case MASK_010: 
                    mask[row][col] = col%3 == 0; 
                    break; 
                case MASK_011: 
                    mask[row][col] = (row+col)%3 == 0; 
                    break; 
                case MASK_100: 
                    mask[row][col] = (row/2+col/3)%2 == 0; 
                    break;
                case MASK_101: 
                    mask[row][col] = (row*col)%2 + (row*col)%3 == 0; 
                    break; 
                case MASK_110: 
                    mask[row][col] = ((row*col)%2 + (row*col)%3)%2 == 0; 
                    break; 
                case MASK_111: 
                    mask[row][col] = ((row+col)%2 + (row*col)%3)%2 == 0; 
                    break; 
            }
        } 
    } 

    for(int row=0; row<size; row++) { 
        for(int col=0; col<size; col++) {
            if(QRCode_isValidCell(row, col)) {
                code->data[row][col] ^= mask[row][col]; 
            } 
        }
    } 
} 

//print QR code in the console 
void QRCode_print(QRCode* code) { 
    int size = code->size; 
    
    for(int row=0; row<size; row++) { 
        for(int col=0; col<size; col++) {
            if(code->data[row][col]) {
                printf("\033[47m  \033[0m"); 
            }
            else {
                printf("\033[40m  \033[0m"); 
            }
        } 
        printf("\n"); 
    }
    printf("\n"); 
} 

//generate QR code 
void QRCode_generate(char* data) { 
    QRCode code; 
    QRCode_initialize(&code); 
    
    //add data to QR code 
    int data_len = strlen(data); 
    int bit_index = 0; 
    for(int row=0; row<MAX_N && bit_index<data_len; row++) { 
        for(int col=0; col<MAX_N && bit_index<data_len; col++) { 
            if(QRCode_isValidCell(row, col)) {
                code.data[row][col] = ((data[bit_index/8]>>(7-bit_index%8)) & 1) == 1; 
                bit_index++; 
            }
        } 
    } 
    
    //add version and error correction level data to QR code 
    int version = 1; 
    int error_correction_level = 1; 
    int end_index = (version*4+17)*(version*4+17)-16-10; 
    for(int i=data_len; i<end_index; i++) {
        if(i%2 == 0) {
            code.data[i/(version*4+17)][i%(version*4+17)] = true; 
        }
        else {
            code.data[i/(version*4+17)][i%(version*4+17)] = false; 
        }
    }
    
    //apply mask patterns to the QR code 
    QRCode_applyMask(MASK_000, &code); 
    QRCode_applyMask(MASK_001, &code); 
    QRCode_applyMask(MASK_010, &code); 
    QRCode_applyMask(MASK_011, &code); 
    QRCode_applyMask(MASK_100, &code); 
    QRCode_applyMask(MASK_101, &code); 
    QRCode_applyMask(MASK_110, &code); 
    QRCode_applyMask(MASK_111, &code); 
    
    //print the generated QR code 
    QRCode_print(&code); 
} 

int main() { 
    char data[] = "Hello, World!"; 
    QRCode_generate(data); 
    
    return 0; 
}