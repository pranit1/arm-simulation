#include <stdio.h>
#include <stdlib.h>
//#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
//#include <math.h>
static int shoulder = 0, elbow = 0,wrist=0,finger=0.0,finger2=0.0,finger3=0.0,text=0.0;
int i=0;
char c[]="MARK I";

void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
}
void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glTranslatef (-1.0, 0.0, 0.0);//establish a pivot point
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);//to pivot the cube
   glTranslatef (1.0, 0.0, 0.0);//translate back to centre of cube
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);//cube is scaled
   glutWireCube (1.0);//draw cube
   glColor3f(0.0,1.0,0.0);
   glPopMatrix();

//Elbow
/* to build elbow we need to move local co-ordinate system to next pivot point.Since co-ordinate is previously rotated,the x-axis is already oriented along the length of rotated arm.therefore translating along the x axis moves the local coordinate to next point.this can be done for indefinite number of segments
*/
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (1.0);
   glColor3f(1.0,0.0,0.0);
   glPopMatrix();

//Wrist
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) wrist, 0.0, 0.0, 0.0);
   glTranslatef (0.3, 0.0, 0.0);
   glPushMatrix();
   glScalef (0.6, 0.7, 0.8);
   glutWireCube (1.0);
   glPopMatrix();
//finger1
/*For finger do the same as shoulder and elbow take the size of cube as 0.3 andscale it to shrink the size and add another segment to make it more realistic
*/
   glPushMatrix();
   glTranslatef (0.0, 0.3, 0.2);
   glRotatef ((GLfloat) finger, 0.0, 0.0, 1.0);
   glTranslatef (0.3, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.5, 0.3, 0.2);
   glutWireCube (0.3);
   glPopMatrix();
   glTranslatef (0.3, 0.0, 0.0);
   glRotatef ((GLfloat) finger, 0.0, 0.0, 1.0);
   glTranslatef (0.2, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.5, 0.3, 0.2);
   glutWireCube (0.3);
   glPopMatrix();
   glTranslatef (0.3, 0.0, 0.0);
   glRotatef ((GLfloat) finger, 0.0, 0.0, 1.0);
   glTranslatef (0.2, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.5, 0.3, 0.2);
   glutWireCube (0.3);
   glPopMatrix();
   glPopMatrix();

//finger1
/*finger2
for finger 2 repeat the same procedure as above except translate its z axis to 0.4*/
   glPushMatrix();
   glTranslatef (0.0, 0.3, 0.4);
   glRotatef ((GLfloat) finger2, 0.0, 0.0, 1.0);
   glTranslatef (0.25, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.5, 0.3, 0.2);
   glutWireCube (0.25);
   glPopMatrix();
   glTranslatef (0.25, 0.0, 0.0);
   glRotatef ((GLfloat) finger2, 0.0, 0.0, 1.0);
   glTranslatef (0.2, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.5, 0.3, 0.2);
   glutWireCube (0.25);
   glPopMatrix();
   glTranslatef (0.25, 0.0, 0.0);
   glRotatef ((GLfloat) finger2, 0.0, 0.0, 1.0);
   glTranslatef (0.2,0.0, 0.0);
   glPushMatrix();
   glScalef (1.5, 0.3, 0.2);
   glutWireCube (0.25);
   glPopMatrix();
   glPopMatrix();

//finger2

   //finger3

/* for finger 3 do the same aa above except change its z axis to 0.6*/
    glPushMatrix();
    glTranslatef (0.0, 0.3, 0.6);
    glRotatef ((GLfloat) finger3, 0.0, 0.0, 1.0);
    glTranslatef (0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef (1.5, 0.3, 0.2);
    glutWireCube (0.2);
    glPopMatrix();
    glTranslatef (0.2, 0.0, 0.0);
    glRotatef ((GLfloat) finger3, 0.0, 0.0, 1.0);
    glTranslatef (0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef (1.5, 0.3, 0.2);
    glutWireCube (0.2);
    glPopMatrix();
    glTranslatef (0.2, 0.0, 0.0);
    glRotatef ((GLfloat) finger3, 0.0, 0.0, 1.0);
    glTranslatef (0.1,0.0, 0.0);
    glPushMatrix();
    glScalef (1.5, 0.3, 0.2);
    glRasterPos3f(0.5,0.0,0.0);
    glRotatef((GLfloat)text,0.0,0.0,0.0);
    printf("%d\t %d\n",elbow,text);
    for(i=0;c[i]!='\0';i++)
    {
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[i]);
    }

    glutWireCube (0.2);
    glPopMatrix();
    glPopMatrix();
             
             //Finger3
    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -9.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'a':  //rotate shoulder anti clockwise
         shoulder = (shoulder + 5) % 360;
         glutPostRedisplay();
         break;
      case 'q'://rotate shoulder clockwise
         shoulder = (shoulder - 5) % 360;
         glutPostRedisplay();
         break;
      case 'e':  //rotate elbow anti clockwise
         elbow = (elbow + 5) % 360;
	text=(text-5)%360;
         glutPostRedisplay();
         break;
      case 'd'://rotetes elbow clockwise
         elbow = (elbow - 5) % 360;
	text=(text+5)%360;
         glutPostRedisplay();
         break;
      case 'h':
          finger= (finger - 5) % 80;//rotate finger 1
          glutPostRedisplay();
         break;
      case 'g':
          finger2= (finger2 - 3) % 80;//rotate finger 2
          glutPostRedisplay();
          break;
      case 'j':
           finger3= (finger3 - 3) % 80;//rotate finger 3
           glutPostRedisplay();
           break;

       
       default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (640, 720);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
