//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include<stdio.h>

struct Point { 
    int x, y; 
}; 

struct Line { 
    struct Point p1, p2; 
};

float distance(struct Point p1, struct Point p2) { 
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); 
} 

void checkIntersection(struct Line L1, struct Line L2) {
    float o1 = checkOrientation(L1.p1, L1.p2, L2.p1); 
    float o2 = checkOrientation(L1.p1, L1.p2, L2.p2); 
    float o3 = checkOrientation(L2.p1, L2.p2, L1.p1); 
    float o4 = checkOrientation(L2.p1, L2.p2, L1.p2);

    if (o1 != o2 && o3 != o4) {
        printf("Lines intersect.\n");
    } else {
        printf("Lines do not intersect.\n");
    }
}

int checkOrientation(struct Point p, struct Point q, struct Point r) { 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 

    if (val == 0) return 0; 
    return (val > 0)? 1: 2;
} 
  
int main() { 
    struct Line L1 = { {1, 1}, {10, 10} }; 
    struct Line L2 = { {1, 10}, {10, 1} }; 

    checkIntersection(L1, L2); 

    return 0; 
}