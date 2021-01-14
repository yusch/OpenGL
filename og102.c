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

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
  return 0;
}
