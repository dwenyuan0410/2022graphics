#include <GL/glut.h>
float angle=0, oldX=0;///初始化Angle
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle,0,0,1);///Z軸旋轉[angle]度
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x, int y)
{
    angle+=(x-oldX);
    oldX=x;
    display();///重畫畫面
}
void mouse(int button, int state, int x, int y)
{
    oldX=x;
}
int main(int argc, char** argv)///精簡基本10行
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");
    glutDisplayFunc(display);
    glutMotionFunc(motion);///mouse motion動
    glutMouseFunc(mouse);
    glutMainLoop();
}
