//FormAI DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {
    char file_name[20];
    FILE *file_ptr;
    int num_arr[20];
    int num_of_nums = 0;
    int num_sum = 0;
    float num_average;

    printf("Please enter the name of the file you want to read from: ");
    scanf("%s", file_name);

    file_ptr = fopen(file_name, "r");

    if(file_ptr == NULL) {
        printf("Error: cannot open file %s", file_name);
        return 1;
    }

    while(fscanf(file_ptr, "%d", &num_arr[num_of_nums]) == 1) {
        num_sum += num_arr[num_of_nums];
        num_of_nums++;
    }

    num_average = (float)num_sum / num_of_nums;

    printf("The numbers in %s are: ", file_name);
    for(int i = 0; i < num_of_nums; i++) {
        printf("%d ", num_arr[i]);
    }

    printf("\nThe sum of the numbers is: %d", num_sum);
    printf("\nThe average of the numbers is: %0.2f", num_average);

    fclose(file_ptr);
    return 0;
}