#include <GLUT/glut.h>
//コンパイルコマンド==>gcc og101.c -framework GLUT -framework OpenGL -Wno-deprecated
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glColor3d(1.0, 0.0, 0.0);
  glVertex2d(-0.7, -0.7);
  glColor3d(0.0, 1.0, 0.0);
  glVertex2d(0.7, -0.7);
  glColor3d(0.0, 0.0, 1.0);
  glVertex2d(0.0, 0.7);
  glEnd();
  glFlush();
}

void resize(int w, int h) /*-関数追加-*/
{
  glViewport(0, 0, w, h);
  glLoadIdentity();
  glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

int main(int argc, char *argv[])
{
  glutInitWindowPosition(100, 100);	/*-追加-*/
  glutInitWindowSize(320, 240);		/*-追加-*/
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);		/*-追加-*/
  glutMainLoop();
  return 0;
}
