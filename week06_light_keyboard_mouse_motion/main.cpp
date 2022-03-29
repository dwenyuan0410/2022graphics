#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
///複製上週的程式碼
float x=150, y=150, z=0, scale=1.0, angle=0.0;///新增angle變數
int oldX=0, oldY=0, now=1;///now選擇功能
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glTranslatef((x-150)/150.0, -(y-150)/150.0, z);///複製
        glScalef(scale,scale,scale);///複製
        glRotatef(angle,0,1,0);///新增旋轉(對y軸轉動)
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key, int mouseX, int mouseY)
{
    if(key=='1'||key=='w'||key=='W') now=1;
    if(key=='2'||key=='e'||key=='E') now=2;
    if(key=='3'||key=='r'||key=='R') now=3;
}
///複製上週的程式碼
void mouse(int button, int state, int mouseX, int mouseY)
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX, int mouseY)
{
    if(now==1){
        x+=(mouseX-oldX); y+=(mouseY-oldY);///移動
    }else if(now==2){
        angle+=(mouseX-oldX);///轉動
    }else if(now==3){///縮放
        if(mouseX-oldX >0) scale *= 1.01;
        if(mouseX-oldX <0) scale *= 0.99;
    }

    oldX=mouseX; oldY=mouseY;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);
    ///上面複製，所以下面也要跟著跟動
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    ///從原本程式裡複製出的，放在glutCreateWindow()之後，才能使用
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
    return EXIT_SUCCESS;
}
