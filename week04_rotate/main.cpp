#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�ƥ��x�}
        glRotatef(90,0,0,1);///Z�b����90��
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
}
int main(int argc, char** argv)///��²��10��
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");
    glutDisplayFunc(display);
    glutMainLoop();
}