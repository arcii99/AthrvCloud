//FormAI DATASET v1.0 Category: Fractal Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

/* Window size */
int width = 600, height = 600;

/* Fractal level */
int level = 0;

/* Translation values */
float x_trans = 0.0, y_trans = 0.0;

/* Function to draw a Koch curve */
void koch_curve(float x1, float y1, float x2, float y2, int level) {
    float angle = M_PI / 3.0;
    float x_diff = x2 - x1;
    float y_diff = y2 - y1;
    float dist = sqrt(x_diff * x_diff + y_diff * y_diff);
    float unit_x = x_diff / dist;
    float unit_y = y_diff / dist;
    float p_x = x1 + unit_x * dist / 3.0;
    float p_y = y1 + unit_y * dist / 3.0;
    float q_x = x2 - unit_x * dist / 3.0;
    float q_y = y2 - unit_y * dist / 3.0;
    float r_x = p_x + cos(angle) * (q_x - p_x) - sin(angle) * (q_y - p_y);
    float r_y = p_y + sin(angle) * (q_x - p_x) + cos(angle) * (q_y - p_y);
    if (level == 0) {
        glVertex2f(x1, y1);
        glVertex2f(p_x, p_y);
        glVertex2f(r_x, r_y);
        glVertex2f(q_x, q_y);
        glVertex2f(x2, y2);
    } else {
        koch_curve(x1, y1, p_x, p_y, level - 1);
        koch_curve(p_x, p_y, r_x, r_y, level - 1);
        koch_curve(r_x, r_y, q_x, q_y, level - 1);
        koch_curve(q_x, q_y, x2, y2, level - 1);
    }
}

/* Display callback function */
void display() {
    /* Clear the screen */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Set the color to blue */
    glColor3f(0.0, 0.0, 1.0);

    /* Start drawing the Koch curve */
    glBegin(GL_LINE_STRIP);
    koch_curve(-0.5, 0.0, 0.5, 0.0, level);
    glEnd();

    /* Swap buffers */
    glutSwapBuffers();
}

/* Reshape callback function */
void reshape(int w, int h) {
    /* Set the new window size */
    width = w;
    height = h;

    /* Set the viewport */
    glViewport(0, 0, w, h);

    /* Set the projection matrix */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

/* Keyboard callback function */
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27: /* ESC key */
            exit(0);
        case '+':
            level++;
            break;
        case '-':
            if (level > 0)
                level--;
            break;
        case 'w':
            y_trans += 0.1;
            break;
        case 's':
            y_trans -= 0.1;
            break;
        case 'd':
            x_trans += 0.1;
            break;
        case 'a':
            x_trans -= 0.1;
            break;
    }

    /* Redisplay the scene */
    glutPostRedisplay();
}

/* Main function */
int main(int argc, char **argv) {
    /* Initialize GLUT and create a window */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Fractal Generation");

    /* Set the display, reshape, and keyboard callback functions */
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    /* Set the background color to white */
    glClearColor(1.0, 1.0, 1.0, 1.0);

    /* Enter the main loop */
    glutMainLoop();
    return 0;
}