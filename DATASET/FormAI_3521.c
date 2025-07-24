//FormAI DATASET v1.0 Category: Fractal Generation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//function to build fractal pattern in recursive fashion
void generateFractal(int x, int y, int length, int angle, int level) {
    if(level == 0) {
        return;
    }
    int x2 = x + length * cos(angle * M_PI / 180.0);
    int y2 = y + length * sin(angle * M_PI / 180.0);
    printf("drawLine(%d, %d, %d, %d);\n", x, y, x2, y2);
    generateFractal(x2, y2, length/2, angle+45, level-1);
    generateFractal(x2, y2, length/2, angle-45, level-1);
}

int main() {
    int LEVEL;
    printf("Enter the level of fractal to be generated (1-10): ");
    scanf("%d", &LEVEL);
    if(LEVEL < 1 || LEVEL > 10) {
        printf("Invalid Input! Please enter a level between 1 and 10.\n");
        return 0;
    }
    int LENGTH = 800, ANGLE = 90;
    srand(time(NULL));
    printf("import graphics\n");
    printf("win = graphics.GraphWin('Fractal Pattern', %d, %d)\n", LENGTH, LENGTH);
    printf("win.setBackground('white')\n");
    printf("def drawLine(x1, y1, x2, y2):\n");
    printf("    line = graphics.Line(graphics.Point(x1, y1), graphics.Point(x2, y2))\n");
    printf("    line.draw(win)\n");
    printf("drawLine(0, %d, %d, %d);\n", LENGTH/2, LENGTH, LENGTH/2);
    generateFractal(0, LENGTH/2, LENGTH, ANGLE, LEVEL);
    printf("win.getMouse()\n");
    printf("win.close()\n");
    return 0;
}