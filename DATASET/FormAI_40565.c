//FormAI DATASET v1.0 Category: Recursive ; Style: Donald Knuth
#include<stdio.h>

/*Recursive method to print koch snowflake*/
void printKochSnowflake(int level, double x1, double y1, double x2, double y2){
    //Base case
    if(level == 0){
        printf("%.2lf %.2lf\n", x1, y1);
        printf("%.2lf %.2lf\n", x2, y2);
    }
    else{
        //Finding coordinates of inner lines
        double x3 = (2 * x1 + x2) / 3.0;
        double y3 = (2 * y1 + y2) / 3.0;
        double x4 = (x1 + 2 * x2) / 3.0;
        double y4 = (y1 + 2 * y2) / 3.0;
        double x5 = (x1 + x2) / 2.0 - (y2 - y1) * 0.2886;
        double y5 = (y1 + y2) / 2.0 + (x2 - x1) * 0.2886;
        
        //Recursive call for the outer lines
        printKochSnowflake(level-1, x1, y1, x3, y3);
        printKochSnowflake(level-1, x3, y3, x5, y5);
        printKochSnowflake(level-1, x5, y5, x4, y4);
        printKochSnowflake(level-1, x4, y4, x2, y2);
    }
}

/*Main function*/
int main(){
    int level;
    printf("Enter level of Koch Snowflake: ");
    scanf("%d", &level);
    
    //Printing the vertices of koch snowflake
    double x1 = 250.0, x2 = 550.0, y1 = 50.0, y2 = 450.0;
    printKochSnowflake(level, x1, y1, x2, y2);
    return 0;
}