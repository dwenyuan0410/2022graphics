///最精簡的GLUT程式
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫圖前，先清畫面
    glColor3f(1,0.35,0);///設定色彩
    ///glutSolidTeapot(0.3);///實心的茶壺
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2f(-1,-1);
        glColor3f(0,1,0);
        glVertex2f(+1,-1);
        glColor3f(0,0,1);
        glVertex2f(0,+1);
    glEnd();
    glutSwapBuffers();///畫好後，交換出來
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區 + 3D深度功能
    glutCreateWindow("week02_show出茶壺的程式");///開GLUT視窗
    glutDisplayFunc(display);///用來顯示函式
    glutMainLoop();///主要的程式迴圈
}
