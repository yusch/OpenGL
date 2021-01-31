#include <GLUT/glut.h>

void idle(void)
{
  glutPostRedisplay();
}

void display(void)
{
  int i, j;
  static int r = 0;

  GLdouble head[8][3] = {
    { 0.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0 },
    { 1.0, 1.0, 0.0 }, { 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 1.0 }, { 1.0, 0.0, 1.0 },
    { 1.0, 1.0, 1.0 }, { 0.0, 1.0, 1.0 }
  };
   GLdouble nose[8][3] = {
    { 0.3, 0.3, 1.0 }, { 0.6, 0.3, 1.0 },
    { 0.6, 0.6, 1.0 }, { 0.3, 0.6, 1.0 },
    { 0.3, 0.3, 1.5 }, { 0.6, 0.3, 1.5 },
    { 0.6, 0.6, 1.5 }, { 0.3, 0.6, 1.5 }
  };
  GLdouble Reye[8][3] = {
    { 0.9, 0.9, 1.0 }, { 0.8, 0.9, 1.0 },
    { 0.8, 0.8, 1.0 }, { 0.9, 0.8, 1.0 },
    { 0.9, 0.9, 1.1 }, { 0.8, 0.9, 1.1 },
    { 0.8, 0.8, 1.1 }, { 0.9, 0.8, 1.1 }
  };
  GLdouble Leye[8][3] = {
    { 0.1, 0.9, 1.0 }, { 0.2, 0.9, 1.0 },
    { 0.2, 0.8, 1.0 }, { 0.1, 0.8, 1.0 },
    { 0.1, 0.9, 1.1 }, { 0.2, 0.9, 1.1 },
    { 0.2, 0.8, 1.1 }, { 0.1, 0.8, 1.1 }
  };

  int face[6][4] = {
    { 0, 3, 2, 1 }, { 1, 2, 6, 5 }, { 4, 5, 6, 7 },
    { 0, 4, 7, 3 }, { 0, 1, 5, 4 }, { 2, 3, 7, 6 }
  };
  GLdouble eyecolor[6][3] = {
    {0,0,0},{0,0,0},{0,0,0},
    {0,0,0},{0,0,0},{0,0,0}};
  GLdouble color[6][3] = {
    { 0.996, 0.863, 0.741 },{ 0.996, 0.863, 0.741 },{ 0.996, 0.863, 0.741 },
    { 0.996, 0.863, 0.741 },{ 0.996, 0.863, 0.741 },{ 0.996, 0.863, 0.741 }};
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);


  glLoadIdentity();
  gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glRotated((GLdouble)r, 0.0, 1.0, 0.0);
  
  glColor3d(0.0, 0.0, 0.0);
  
  glBegin(GL_QUADS);
  for (j = 0; j < 6; j++) {
    glColor3dv(color[j]);
    for (i = 0; i < 4; i++) {
      glVertex3dv(head[face[j][i]]);
    }
  }
  glEnd();
  
  glBegin(GL_QUADS);
  for (j = 0; j < 6; j++) {
    glColor3dv(color[j]);
    for (i = 0; i < 4; i++) {
      glVertex3dv(nose[face[j][i]]);
    }
  }
  glEnd();
  
  glBegin(GL_QUADS);
  for (j = 0; j < 6; j++) {
    glColor3dv(eyecolor[j]);
    for (i = 0; i < 4; i++) {
      glVertex3dv(Reye[face[j][i]]);
    }
  }
  glEnd();
  
  glBegin(GL_QUADS);
  for (j = 0; j < 6; j++) {
    glColor3dv(eyecolor[j]);
    for (i = 0; i < 4; i++) {
      glVertex3dv(Leye[face[j][i]]);
    }
  }
  glEnd();

  glFlush();
  glDisable(GL_DEPTH_TEST);
  glutSwapBuffers();

  if (++r >= 360) r = 0;
}

void resize(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30.0, 1.0, 1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow(argv[0]);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  glutReshapeFunc(resize);
  glutMainLoop();
}
