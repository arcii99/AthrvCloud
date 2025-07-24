//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>

void embed(int data[], int watermark[], int n) {
    for(int i=0;i<n;i++) {
        data[i] |= watermark[i]; // bitwise OR operation to embed the watermark
    }
}

int extract(int data[], int watermark[], int n) {
    int num_changes = 0;
    for(int i=0;i<n;i++) {
        int original_data = data[i]; // store original data in a temporary variable
        data[i] ^= watermark[i]; // bitwise XOR operation to extract the watermark
        if(data[i] != original_data) { // if the data has changed, increment num_changes
            num_changes++;
        }
    }
    return num_changes;
}

int main() {
    int data[] = {1, 2, 3, 4, 5}; // sample data
    int watermark[] = {1, 0, 1, 0, 1}; // sample watermark
    int n = sizeof(data)/sizeof(data[0]); // calculate size of data array
    
    printf("Data before embedding watermark: ");
    for(int i=0;i<n;i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    embed(data, watermark, n); // embed the watermark

    printf("Data after embedding watermark: ");
    for(int i=0;i<n;i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    int extracted_watermark[n]; // array to store extracted watermark
    int num_changes = extract(data, extracted_watermark, n); // extract the watermark

    printf("Extracted watermark: ");
    for(int i=0;i<n;i++) {
        printf("%d ", extracted_watermark[i]);
    }
    printf("\n");

    printf("Number of changes made to data during extraction: %d\n", num_changes);

    return 0;
}