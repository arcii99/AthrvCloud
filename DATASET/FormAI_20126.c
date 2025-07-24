//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surprised
#include <stdio.h>
#define MAX_DEPTH 10
#define HEIGHT 40
#define WIDTH 80
 
void drawFractal(int,int,int,int,int);
char canvas[HEIGHT][WIDTH]; 
 
int main(){
    int x1=0,x2=WIDTH-1,y=HEIGHT-1;
    int i,j;
    // initialize the canvas
    for(i=0;i<HEIGHT;i++)
        for(j=0;j<WIDTH;j++)
            canvas[i][j] = '-';
    //draw the fractal
    drawFractal(x1, y, x2, y, 0); 
    //print the canvas
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++)
            printf("%c",canvas[i][j]);
        printf("\n");
    }
    return 0;
}
 
void drawFractal(int x1,int y1,int x2,int y2,int in_depth){
    if(in_depth>MAX_DEPTH) return;
 
    int x, y, length;
    double slope, theta;
    length = (x2-x1)/3;
    if(length>5){
        theta = 1.0472; // 60 in radians
        slope = 1/tan(theta);
       //draw the left segment
        y = (int)(y1 - slope * length);
        drawFractal(x1,y1,x1+length,y,in_depth+1);
       //draw the right segment
        y = (int)(y2 - slope * length);
        drawFractal(x2,y2,x2-length,y,in_depth+1);
       //draw the middle segment
        drawFractal(x1+length,y1,x2-length,y2,in_depth+1);
    }
    else{
       //color the pixel
        int i,j;
        for(i=y1;i>=y2;i--)
            for(j=x1;j<=x2;j++)
                canvas[i][j] = '*';
    }
}