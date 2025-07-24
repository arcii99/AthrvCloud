//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: safe
#include <stdio.h> 

struct point 
{  
    int x;  
    int y;  
};  

int min(int x, int y) 
{  
    return (x < y) ? x : y;  
}  

int max(int x, int y) 
{  
    return (x > y) ? x : y;  
}  

int distSq(struct point p, struct point q) 
{  
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);  
}  

int isSquare(struct point p1, struct point p2, struct point p3, struct point p4) 
{  
    int d2 = distSq(p1, p2);  
    int d3 = distSq(p1, p3);  
    int d4 = distSq(p1, p4);  

    if (d2 == 0 || d3 == 0 || d4 == 0) 
        return 0;  

    if (d2 == d3 && 2 * d2 == d4 && 2*distSq(p2, p4) == distSq(p2, p3)) 
    {  
        return 1;  
    }  

    if (d3 == d4 && 2 * d3 == d2 && 2*distSq(p3, p2) == distSq(p3, p4)) 
    {  
        return 1;  
    }  

    if (d2 == d4 && 2 * d2 == d3 && 2*distSq(p2, p3) == distSq(p2, p4)) 
    {  
        return 1;  
    }  

    return 0;  
}  

int main() 
{  
    struct point p1 = {20, 10}, p2 = {10, 20}, p3 = {20, 20}, p4 = {10, 10};  
    isSquare(p1, p2, p3, p4)? printf("Yes"): printf("No");  
    return 0;  
}