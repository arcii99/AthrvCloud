//FormAI DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>

int main() {
    int data[10] = {4, 2, 7, 10, 9, 3, 1, 5, 8, 6};
    int min = data[0];
    int max = data[0];
    int sum = 0;
    float mean;
    int count = 0;
    int mode;
    int max_count = 0;
    
    for(int i = 0; i < 10; i++) {
        sum += data[i];
        if(data[i] < min) {
            min = data[i];
        }
        if(data[i] > max) {
            max = data[i];
        }
        for(int j = 0; j < 10; j++) {
            if(data[i] == data[j]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            mode = data[i];
        }
        count = 0;
    }
    mean = (float) sum / 10;
    
    printf("The minimum value of the data is %d\n", min);
    printf("The maximum value of the data is %d\n", max);
    printf("The mean value of the data is %.2f\n", mean);
    printf("The mode value of the data is %d\n", mode);

    return 0;
}