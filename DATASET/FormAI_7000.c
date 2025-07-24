//FormAI DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define MAX_ITERATIONS 1000

double scale = 2.0;
double xoffset = -0.7;
double yoffset = 0;
double hue = 0.0;
int zoom_in = 0;
int zoom_out = 0;

void set_color(double t) {
  double r, g, b;

  if (t == -1) {
    r = 0.0;
    g = 0.0;
    b = 0.0;
  } else {
    t = fmod(t, 1.0);
    r = sin(2 * M_PI * (t + hue));
    g = sin(2 * M_PI * (t + hue + (1.0 / 3.0)));
    b = sin(2 * M_PI * (t + hue + (2.0 / 3.0)));
  }

  glColor3d(r, g, b);
}

void draw_pixel(int x, int y, double t) {
  glBegin(GL_POINTS);
  set_color(t);
  glVertex2i(x, y);
  glEnd();
}

double mbrot(double cx, double cy) {
  double zx = 0.0;
  double zi = 0.0;
  double tx = 0.0;
  double ti = 0.0;
  double t = 0.0;

  for (int i = 0; i < MAX_ITERATIONS; ++i) {
    tx = zx * zx - zi * zi + cx;
    ti = 2 * zx * zi + cy;
    if (tx * tx + ti * ti > 4) {
      t = i - log(log(sqrt(tx * tx + ti * ti))) / log(2.0);
      break;
    }
    zx = tx;
    zi = ti;
  }

  if (t == 0.0) return -1.0;
  return t / MAX_ITERATIONS;
}

void draw_fractal() {
  double t = 0.0;

  for (int i = -WINDOW_WIDTH / 2; i < WINDOW_WIDTH / 2; ++i) {
    for (int j = -WINDOW_HEIGHT / 2; j < WINDOW_HEIGHT / 2; ++j) {
      t = mbrot(xoffset + ((double) i) / (WINDOW_WIDTH / scale), yoffset + ((double) j) / (WINDOW_HEIGHT / scale));
      draw_pixel(i + WINDOW_WIDTH / 2, j + WINDOW_HEIGHT / 2, t);
    }
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  draw_fractal();
  glFlush();
}

void mouse(int button, int state, int x, int y) {
  if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
    zoom_in = 1;
  } else if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
    zoom_out = 1;
  }
}

void keyboard(unsigned char key, int x, int y) {
  if (key == 'q') {
    exit(0);
  } else if (key == 'h') {
    hue += 0.1;
  }
}

void idle() {
  if (zoom_in) {
    scale /= 2;
    xoffset += (1.0 / scale / WINDOW_WIDTH) * glutGet(GLUT_WINDOW_WIDTH);
    yoffset += (1.0 / scale / WINDOW_HEIGHT) * glutGet(GLUT_WINDOW_HEIGHT);
    zoom_in = 0;
  } else if (zoom_out) {
    scale *= 2;
    xoffset -= (1.0 / scale / WINDOW_WIDTH) * glutGet(GLUT_WINDOW_WIDTH);
    yoffset -= (1.0 / scale / WINDOW_HEIGHT) * glutGet(GLUT_WINDOW_HEIGHT);
    zoom_out = 0;
  }

  glutPostRedisplay();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Fractal Generation");

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);

  glutMainLoop();

  return 0;
}