//FormAI DATASET v1.0 Category: Random ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, j, count = 0, size = 10, num;
    int arr[10];
    srand(time(NULL));

    printf("Random Numbers Between 1 and 10:\n");
    for(i=0; i<size; i++){
        num = rand()%10 + 1;
        arr[i] = num;
        printf("%d ", num);
    }

    printf("\n");

    for(i=1; i<=10; i++){
        count = 0;
        for(j=0; j<size; j++){
            if(arr[j] == i){
                count++;
            }
        }
        if(count == 1){
            printf("The number %d occurs only once.\n",i);
        }else if(count > 1){
            printf("The number %d occurs %d times.\n",i,count);
        }else{
            printf("The number %d does not occur.\n",i);
        }
    }

    return 0;
}