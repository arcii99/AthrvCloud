//FormAI DATASET v1.0 Category: Math exercise ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.141592653589793
#define MAX_NUM 100

int main(){
    int num, sum=0, prod=1, i;
    float average, variance, std_dev;
    srand(time(NULL));
    printf("Enter a positive integer (<= %d): ", MAX_NUM);
    scanf("%d", &num);
    int num_list[num];
    for(i=0; i<num; i++){
        num_list[i] = rand() % (MAX_NUM + 1);
        printf("%d  ", num_list[i]);
        sum += num_list[i];
        prod *= num_list[i];
    }
    average = (float) sum / num;
    printf("\nSum = %d\nProduct = %d\nAverage = %.2f\n", sum, prod, average);
    for(i=0; i<num; i++){
        variance += pow(num_list[i] - average, 2);
    }
    variance /= num;
    std_dev = sqrt(variance);
    printf("Variance = %.2f\nStandard Deviation = %.2f\n", variance, std_dev);
    printf("\nTrigonometric Values of %f radians:\n", PI/4);
    printf("Sine = %.2f\nCosine = %.2f\nTangent = %.2f\n", sin(PI/4), cos(PI/4), tan(PI/4));
    printf("\nNatural Logarithm of %.2f = %.2f\n", prod, log(prod));
    printf("Floor of Average = %.0f\nCeiling of Variance = %.0f\n", floor(average), ceil(variance));
    return 0;
}