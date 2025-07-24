//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum = 0;

void add(int val){
    sum += val;
}

void calcChecksum(char *data, int len){
    for (int i = 0; i < len; i++){
        add(data[i]);
        if (i % 3 == 0){
            add(i);
        }
    }
}

int main(){
    char data[100]; 
    printf("Enter string: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0;
    int len = strlen(data);
    calcChecksum(data, len);
    printf("C-CHECKSUM: %d\n", sum);
    return 0;
}