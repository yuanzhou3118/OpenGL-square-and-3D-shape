#include <GLUT/glut.h>

static const float vertex_list[][3] = {
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    -0.5f, 0.5f, -0.5f,
    0.5f, 0.5f, -0.5f,
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
};



static const GLint index_list[][2] = {
    {0, 1},
    {2, 3},
    {4, 5},
    {6, 7},
    {0, 2},
    {1, 3},
    {4, 6},
    {5, 7},
    {0, 4},
    {1, 5},
    {7, 3},
    {2, 6}
};


void DrawCube(void) {
    int i,j;
    
    glBegin(GL_LINES);
    for(i=0; i<12; ++i) // 12 条线段
 
    {
        for(j=0; j<2; ++j) // 每条线段 2个顶点
 
        {
            glVertex3fv(vertex_list[index_list[i][j]]);
        }
    }
    glEnd();
}

static float rotate = 0;
static int times = 0;

void renderScenery(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
 
    times++;
    if(times > 100)
    {
        times = 0;
    }
 
    if(times % 100 == 0)
    {
        rotate += 10;
    }
    
    glRotatef(rotate, 0, 1, 0);
    glRotatef(rotate, 1, 0, 0);
 
    glColor3f(0, 0, 1);
 
    DrawCube();
 
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, const char * argv[]) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Square");
    
    glutDisplayFunc(renderScenery);
    glutIdleFunc(renderScenery);
    glutMainLoop();
}

