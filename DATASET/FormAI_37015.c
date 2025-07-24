//FormAI DATASET v1.0 Category: Image compression ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BITS 12
#define MAX_CODE (1 << BITS)
#define TABLE_SIZE 5021

uint16_t codetab[TABLE_SIZE];
uint8_t accumbuf = 0, accumcount = 0;
int32_t curcode, bitmask = 1;
bool compress, early_eof;

void output_code (int32_t code) {
    accumbuf |= code << accumcount; 
    accumcount += BITS;
    while (accumcount >= 8) {
        putc (accumbuf & 0xff, stdout);
        accumbuf >>= 8; 
        accumcount -= 8;
    }
    if (curcode < MAX_CODE) { 
        codetab[curcode++] = bitmask | code; 
        bitmask = (bitmask << 1) | 1; 
        if (curcode >= MAX_CODE) 
            early_eof = true;        
    }
    else if ((code = codetab[code]) != -1) 
        bitmask |= code;
    else {
        fprintf (stderr, "codetab overflow\n");
        exit (EXIT_FAILURE);
    }
}

int main () {
    int32_t predecessor, c, col, i;
    uint32_t count;
    compress = true;

    for (i = 0; i < TABLE_SIZE; i++) codetab[i] = -1;
    curcode = 256;
    predecessor = -1; 

    while ((c = getchar()) != EOF){
        col = c << BITS;
        if (predecessor >= 0) {
            count = 1;
            while ((c = getchar()) != EOF && predecessor >= 0 && predecessor < MAX_CODE) {
                col += c; 
                i = (predecessor << BITS) + c;
                if (codetab[i] == -1) {
                    if (curcode < MAX_CODE) {
                        codetab[i] = curcode++; 
                        early_eof = false;
                    }
                    else 
                        early_eof = true; 
                    output_code (predecessor);
                    predecessor = c;
                    break;
                }
                predecessor = codetab[i] & (MAX_CODE - 1);
            }
        }
        else 
            predecessor = c;
    }
    if (predecessor >= 0) 
        output_code (predecessor);
    output_code (256);

    if (accumcount > 0) 
        putc (accumbuf, stdout);
    if (early_eof) { 
        fprintf (stderr, "Warning: premature EOF ignored\n");
        exit (EXIT_FAILURE); 
    }
}