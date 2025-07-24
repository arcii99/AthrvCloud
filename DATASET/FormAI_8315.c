//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: light-weight
#include<stdio.h>
#include<math.h>

int main(){
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    double x[n], y[n], radius = 0.0, midx, midy;
    for(int i=0;i<n;i++){
        printf("Enter the x and y-coordinate of point %d : ", i+1);
        scanf("%lf %lf", &x[i], &y[i]);
        midx += x[i];
        midy += y[i];
    }

    midx = midx/n;
    midy = midy/n;

    for(int i=0;i<n;i++){
        double dist = sqrt((x[i]-midx)*(x[i]-midx) + (y[i]-midy)*(y[i]-midy));
        if(dist > radius){
            radius = dist; // update the radius if a farther point is found
        }
    }

    printf("The smallest circle which completely covers the points has center (%lf, %lf) and radius %lf.", midx, midy, radius);

    return 0;
}