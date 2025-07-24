//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>

int main(){
    int q, n, i, x, y;
    printf("Greetings, user! I am Sisyphus and I specialize in creating geometric algorithms for fun!\n");

    printf("Please enter the number of queries: ");
    scanf("%d", &q);

    for(i = 0; i < q; i++){
        printf("Please enter the number of points: ");
        scanf("%d", &n);

        int j, k, area = 0;
        int points[n][2];

        for(j = 0; j < n; j++){
            printf("Please enter an x,y coordinate for point %d: ", j+1);
            scanf("%d %d", &x, &y);
            points[j][0] = x;
            points[j][1] = y;
        }

        for(k = 0; k < n-2; k++){
            area += (points[k+1][0] - points[k][0]) * (points[k+2][1] - points[k][1]) - (points[k+1][1] - points[k][1]) * (points[k+2][0] - points[k][0]);
        }

        if(area < 0){
            printf("Wow, that was acute!\n");
        } else if(area > 0){
            printf("That's obtuse but alright!\n");
        } else {
            printf("That's a straight line! Magnificent.\n");
        }
    }

    printf("Thank you for using Sisyphus Geometric Algorithm Creation prompt.\n");
    return 0;
}