//FormAI DATASET v1.0 Category: Pattern printing ; Style: romantic
#include <stdio.h>

int main()
{
    int n = 10;
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=i; j++){
            printf("# ");
        }
        printf("\n");
    }
    for(int i=n-1; i>=1 ; i--){
        for(int j=1; j<=i; j++){
            printf("# ");
        }
        printf("\n");
    }

    printf("\n");

    for(int i=1; i<=n ; i++){
        for(int j=i; j<n; j++){
            printf("  ");
        }
        for(int k=1; k<=(2*i-1); k++){
            printf("* ");
        }
        printf("\n");
    }
    for(int i=n-1; i>=1; i--){
        for(int j=i; j<=n-1; j++){
            printf("  ");
        }
        for(int k=1; k<=(2*i-1); k++){
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(int i=1; i<=n ; i++){
        for(int j=i; j<n; j++){
            printf("  ");
        }
        for(int k=1; k<=(2*i-1); k++){
            if(i%2==1){
                printf("S ");
            }
            else{
                printf("L ");
            }
        }
        printf("\n");
    }
    for(int i=n-1; i>=1; i--){
        for(int j=i; j<=n-1; j++){
            printf("  ");
        }
        for(int k=1; k<=(2*i-1); k++){
            if(i%2==1){
                printf("S ");
            }
            else{
                printf("L ");
            }
        }
        printf("\n");
    }

    return 0;
}