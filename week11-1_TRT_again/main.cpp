#include <GL/glut.h>

void myBody()
{
    glColor3f(1,0,0);
    glutWireCube(0.6);
}
void myArm(){
    glPushMatrix();
    glColor3f(0,1,0);
    glScalef(1.5,0.5,0.5);
    glutWireCube(0.3);
    glPopMatrix();
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        //glTranslatef(-0.6,+0.3,0);
        myBody();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3,0.3,0);
    glRotatef(angle++,0,0,1);
    glTranslatef(0.45/2,0,0);
        //glTranslatef(+0.3,+0.3,0);
        //glRotatef(angle++,0,0,1);
        //glTranslatef(+0.255,+0,0);
        myArm();
    glPopMatrix();
    glutSwapBuffers();

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week11-2");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
