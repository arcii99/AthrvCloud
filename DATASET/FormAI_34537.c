//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Point {
    int x;
    int y;
};

typedef struct Point Point;

void generateMap(char map[][10]) {
    srand(time(NULL));
    Point startPoint;
    Point endPoint;
    int obstacleCount = 0;

    // Generating start and end points
    startPoint.x = rand()%10;
    startPoint.y = rand()%10;

    endPoint.x = rand()%10;
    endPoint.y = rand()%10;

    // Generating obstacles
    while(obstacleCount < 10) {
        int x = rand()%10;
        int y = rand()%10;

        if(map[x][y] == '.') {
            map[x][y] = '0' + rand()%9 + 1;
            obstacleCount++;
        }
    }

    // Placing start and end points on map
    map[startPoint.x][startPoint.y] = 'S';
    map[endPoint.x][endPoint.y] = 'E';
}

void printMap(char map[][10]) {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void navigate(char map[][10]) {
    int x = rand()%10;
    int y = rand()%10;

    printf("Current location: %d %d\n", x, y);
    printf("Direction: ");
    
    if(x == 0) {
        printf("South, ");
    } else if(x == 9) {
        printf("North, ");
    } else {
        if(rand()%2) {
            printf("North, ");
        } else {
            printf("South, ");
        }
    }

    if(y == 0) {
        printf("East\n");
    } else if(y == 9) {
        printf("West\n");
    } else {
        if(rand()%2) {
            printf("East\n");
        } else {
            printf("West\n");
        }
    }
}

int main() {
    char map[10][10];

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            map[i][j] = '.';
        }
    }

    generateMap(map);
    printMap(map);

    while(1) {
        navigate(map);
        // Some code for calculating distance and time to reach destination
        // and updating current location
    }

    return 0;
}