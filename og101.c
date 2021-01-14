#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glColor3d(1.0, 0.0, 0.0);
	glVertex2d(-0.7, -0.7);
	glVertex2d(0.7, -0.7);
	glVertex2d(0.0, 0.7);
	glEnd();
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == '\033') exit(0);  /* '\033' は ESC の ASCII コード */
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
  return 0;
}
