//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multivariable
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

#define DEG2RAD 3.14159/180.0

GLfloat angle = 0.0;
GLfloat distance = -30.0;

void drawAxes(){
    glBegin(GL_LINES);
        
    //X axis - Red Color
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(10.0,0.0,0.0);
        
    //Y axis - Green Color
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,10.0,0.0);
        
    //Z axis - Blue Color
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,10.0);
    glEnd();
}

void drawOrbit(float radius){
    //Draw orbit
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++){
        float degInRad = i*DEG2RAD;
        glVertex3f(cos(degInRad)*radius, 0, sin(degInRad)*radius);
    }
    glEnd();
}

void drawPlanet(GLfloat radius){
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    gluQuadricNormals(quadratic, GLU_SMOOTH);
    gluQuadricTexture(quadratic, GL_TRUE);
    gluSphere(quadratic, radius, 32, 32);
    gluDeleteQuadric(quadratic);
}

void drawSun(){
    GLfloat emmision[] = {1.0, 1.0, 0.0};
    GLfloat light_pos[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat diffuse[] = {1.0, 1.0, 0.0};

    glEnable(GL_LIGHTING);
    
    glMaterialfv(GL_FRONT, GL_EMISSION, emmision);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glutSolidSphere(5.0f, 32, 32);
    
    glDisable(GL_LIGHTING);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
        
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
        
    gluLookAt(0.0f,0.0f,distance,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
        
    glRotatef(angle,0.0,1.0,0.0);
    drawAxes();
        
    /*--- Draw Sun ---*/
    drawSun();

    /*--- Draw Mercury ---*/
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f);
    drawOrbit(5.0f);
    glRotatef(angle*4.0,0.0,1.0,0.0);
    glTranslatef(5.0f,0.0f,0.0f);
    drawPlanet(0.3f);
    glPopMatrix();
        
    /*--- Draw Venus ---*/
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);
    drawOrbit(7.0f);
    glRotatef(angle*3.0,0.0,1.0,0.0);
    glTranslatef(7.0f,0.0f,0.0f);
    drawPlanet(0.5f);
    glPopMatrix();
        
    /*--- Draw Earth ---*/
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 1.0f);
    drawOrbit(10.0f);
    glRotatef(angle*2.0,0.0,1.0,0.0);
    glTranslatef(10.0f,0.0f,0.0f);
    drawPlanet(0.4f);
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glRotatef(angle*10.0,0.0,1.0,0.0);
    glTranslatef(0.3f,0.0f,0.0f);
    drawPlanet(0.1f);
    glPopMatrix();
    glPopMatrix();
        
    /*--- Draw Mars ---*/
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    drawOrbit(12.0f);
    glRotatef(angle*1.5,0.0,1.0,0.0);
    glTranslatef(12.0f,0.0f,0.0f);
    drawPlanet(0.35f);
    glPopMatrix();
        
    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0,0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void idleFunc(){
    angle += 0.2;
    display();
}

int main(int argc, char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Solar System Simulation");
    glutIdleFunc(idleFunc);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}