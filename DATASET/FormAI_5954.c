//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
#include<stdio.h>
#include<math.h>

int main(){
    int x1,y1,x2,y2;
    float distance;
    
    //Taking input of the two points
    printf("Enter the coordinates of the first point(x1,y1) : ");
    scanf("%d%d",&x1,&y1);
    printf("Enter the coordinates of the second point(x2,y2) : ");
    scanf("%d%d",&x2,&y2);
    
    //Calculating the Euclidean distance between the two points
    distance=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    
    //Displaying the distance between the two points
    printf("\nO Romeo, Romeo! Wherefore art thou Romeo?\n");
    printf("Here, Juliet, I stand. What distance shall I cross for thee?\n");
    printf("The distance between us is %f, my love.\n",distance);
    
    return 0;
}