//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

#define TIMER_ID 0
#define TIMER_INTERVAL 10

float PI = 3.141592654;

static float angle = 0;

// Model the sun
void drawSun() {
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow
    glutSolidSphere(3.0, 20, 16); // Draw the sun as a solid sphere
}

// Model the planets
void drawPlanets(float distanceFromSun, float size) {
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glTranslatef(0.0, 0.0, distanceFromSun); // Move the planet out from the sun
    glutSolidSphere(size, 20, 16); // Draw the planet as a solid sphere
}

// Display function
void onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	drawSun(); // Draw the sun

	drawPlanets(8.0, 0.4); // Draw the first planet at distance 8 from the sun, size 0.4
	drawPlanets(12.0, 0.6); // Draw the second planet at distance 12 from the sun, size 0.6
	drawPlanets(16.0, 0.8); // Draw the third planet at distance 16 from the sun, size 0.8
	drawPlanets(20.0, 1.0); // Draw the fourth planet at distance 20 from the sun, size 1.0

	glutSwapBuffers();
}

// Animation function
void onTimer(int value) {
	if (value != TIMER_ID) {
		return;
	}

	angle += 0.1; // Increment the angle of rotation

	glutPostRedisplay(); // Update the display

	glutTimerFunc(TIMER_INTERVAL, onTimer, TIMER_ID); // Restart the timer
}

// Main function
int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Solar System");

	glutDisplayFunc(onDisplay);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 40);

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glutTimerFunc(TIMER_INTERVAL, onTimer, TIMER_ID);

	glutMainLoop();

	return 0;
}