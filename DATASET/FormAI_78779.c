//FormAI DATASET v1.0 Category: Data recovery tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

char* recover_file(char* data, int size) {
    int* hash = (int*)calloc(size, sizeof(int)); // initialize hash table
    char* output = (char*)malloc(size * sizeof(char)); // allocate memory for recovered data
    int j = 0;
    
    for (int i = 0; i < size; i++) {
        int index = abs(data[i]) % size; // calculate hash index
        if (hash[index] == 0) { // check if slot is empty
            hash[index] = 1; // mark index as filled
            output[j] = data[i]; // copy data to output array
            j++;
        }
    }
    free(hash); // deallocate hash table memory
    return output;
}

int main() {
    char data[] = {84, 104, 105, 115, 32, 112, 114, 111, 103, 114, 97, 109, 32, 99, 97, 110, 32, 114, 101, 99, 111, 118, 101, 114, 32, 100, 97, 116, 97, 32, 102, 114, 111, 109, 32, 97, 110, 32, 101, 120, 116, 101, 114, 110, 97, 108, 32, 104, 97, 114, 100, 32, 100, 114, 105, 118, 101, 32, 111, 114, 32, 97, 32, 102, 108, 97, 115, 104, 32, 100, 114, 105, 118, 101, 46};
    int size = sizeof(data) / sizeof(char);
    
    char* recovered_data = recover_file(data, size);
    
    for (int i = 0; i < size; i++) { // print recovered data
        printf("%c", recovered_data[i]);
    }
    free(recovered_data); // deallocate recovered data memory
    return 0;
}