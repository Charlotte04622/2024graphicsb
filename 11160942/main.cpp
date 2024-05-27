#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL; ///加的程式，有顆指標，指到模型檔
GLMmodel * head = NULL;
GLMmodel * righthand = NULL;
GLMmodel * rightarm = NULL;
GLMmodel * lefthand = NULL;
GLMmodel * leftarm = NULL;
GLMmodel * body = NULL;
GLMmodel * leftleg = NULL;
GLMmodel * rightleg = NULL;
GLMmodel * pee = NULL;
GLMmodel * peee = NULL;
void drawbody(void)
{
    if(!body){
        head = glmReadOBJ("body.obj");
        if(!body) exit(0);
        glmUnitize(body);
        glmFacetNormals(body);
        glmVertexNormals(body, 90.0);
    }
    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}
void drawpeee(void)
{
    if(!peee){
        head = glmReadOBJ("peee.obj");
        if(!peee) exit(0);
        glmUnitize(peee);
        glmFacetNormals(peee);
        glmVertexNormals(peee, 90.0);
    }
    glmDraw(peee, GLM_SMOOTH | GLM_TEXTURE);
}
void drawpee(void)
{
    if(!pee){
        head = glmReadOBJ("pee.obj");
        if(!pee) exit(0);
        glmUnitize(pee);
        glmFacetNormals(pee);
        glmVertexNormals(pee, 90.0);
    }
    glmDraw(pee, GLM_SMOOTH | GLM_TEXTURE);
}
void drawrightleg(void)
{
    if(!rightleg){
        head = glmReadOBJ("rightleg.obj");
        if(!rightleg) exit(0);
        glmUnitize(rightleg);
        glmFacetNormals(rightleg);
        glmVertexNormals(rightleg, 90.0);
    }
    glmDraw(rightleg, GLM_SMOOTH | GLM_TEXTURE);
}
void drawleftleg(void)
{
    if(!leftleg){
        head = glmReadOBJ("leftleg.obj");
        if(!leftleg) exit(0);
        glmUnitize(leftleg);
        glmFacetNormals(leftleg);
        glmVertexNormals(leftleg, 90.0);
    }
    glmDraw(leftleg, GLM_SMOOTH | GLM_TEXTURE);
}
void drawhead(void)
{
    if(!head){
        head = glmReadOBJ("head.obj");
        if(!head) exit(0);
        glmUnitize(head);
        glmFacetNormals(head);
        glmVertexNormals(head, 90.0);
    }
    glmDraw(head, GLM_SMOOTH | GLM_TEXTURE);
}
void drawrightarm(void)
{
    if(!rightarm){
        rightarm = glmReadOBJ("rightarm.obj");
        if(!rightarm) exit(0);
        glmUnitize(rightarm);
        glmFacetNormals(rightarm);
        glmVertexNormals(rightarm, 90.0);
    }
    glmDraw(rightarm, GLM_SMOOTH | GLM_TEXTURE);
}
void drawrighthand(void)
{
    if(!righthand){
        righthand = glmReadOBJ("righthand.obj");
        if(!righthand) exit(0);
        glmUnitize(righthand);
        glmFacetNormals(righthand);
        glmVertexNormals(righthand, 90.0);
    }
    glmDraw(righthand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlefthand(void)
{
    if(!lefthand){
        lefthand = glmReadOBJ("lefthand.obj");
        if(!lefthand) exit(0);
        glmUnitize(lefthand);
        glmFacetNormals(lefthand);
        glmVertexNormals(lefthand, 90.0);
    }
    glmDraw(lefthand, GLM_SMOOTH | GLM_TEXTURE);
}
void drawleftarm(void)
{
    if(!leftarm){
        leftarm = glmReadOBJ("leftarm.obj");
        if(!leftarm) exit(0);
        glmUnitize(leftarm);
        glmFacetNormals(leftarm);
        glmVertexNormals(leftarm, 90.0);
    }
    glmDraw(leftarm, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlego(void)
{
    if(!pmodel){
        pmodel = glmReadOBJ("lego.obj");
        if(!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}




int angleID = 0;
float angle[20] = { }; ///float angle=0, da=-1;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidSphere( 0.1, 30, 30);
    ///glutWireCube(0.6);
    glPushMatrix();
        glRotatef(180, 0, 1, 0);
        drawlego();
        glPushMatrix();

            glTranslatef(-0.15, 0, 0);
            glRotatef(angle[0], 1, 0, 0);
            glRotatef(angle[1], 0, 1, 0);
            glRotatef(angle[2], 0, 0, 1);
            glTranslatef(-0.025, -0.05, 0);

            glPushMatrix();
                glTranslatef(0, -0.1, 0); ///(3)掛到肩上
                glRotatef(angle[3], 1, 0, 0); ///(2)轉動
                glTranslatef(-0.02, -0.2, 0); ///(1)把旋轉中心，放正中心
               ///glutSolidTeapot( 0.3 );
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    ///if(angle<-90) da = 1;
    ///if(angle>0) da = -1;
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

#include <stdio.h>
FILE * fout = NULL;
FILE * fin = NULL;

void keyboard(unsigned char key, int x, int y) {
    if(key=='r') {
        if(fin==NULL) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++) {
            fscanf(fin, "%f", & angle[i] );
        }
        glutPostRedisplay();
    }

    if(key=='s') {
        if(fout==NULL) fout = fopen("angle.txt", "w+");
        for(int i=0; i<20; i++) {
            printf("%.1f ", angle[i] );
            fprintf(fout, "%.1f ", angle[i] );
        }
        printf("\n");
        fprintf(fout, "\n");
    }
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
}
int oldX = 0, oldY = 0;
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    angle[angleID] += y - oldY; ///angle[angleID] = y;
    printf("rotating %f \n", angle[angleID]);
    oldX = x;
    oldY = y;
    glutPostRedisplay(); ///貼上便利貼,提醒GLUT要重畫畫面
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13-1_keyboard_angleID_mouse_motion_angle");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加入旋轉
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    myTexture("Face_04.png");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

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
}
