//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned int calculateChecksum(char* data, size_t size) {
    unsigned int csum = 0;
    for(size_t i = 0; i < size; ++i) {
        csum += (unsigned int)data[i];
    }
    return csum;
}

int main() {
    char* data = NULL;
    size_t size = 0;
    
    printf("Enter the data: ");
    getline(&data, &size, stdin);
    // remove the newline character
    data[strcspn(data, "\n")] = '\0';
    
    unsigned int checksum = calculateChecksum(data, strlen(data));
    printf("Checksum of '%s': %u\n", data, checksum);
    
    free(data);
    return 0;
}