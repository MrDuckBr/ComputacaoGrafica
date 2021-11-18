#include <GL/glut.h>
#include <math.h> 

#include "SOIL/SOIL.h"
  
GLfloat horzangle = -45.0,vertangle = 30.0,distance = -3.0; 
static int shoulder = -50, elbow = 310, fist = 0, finger2 = -46, finger = -46 ;
GLuint texture;



// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f,ly=0.0f;
// XZ position of the camera
float x=4.0f,z=3.0f,y=2.0f;


void drawRobot(void){
	
	glTranslatef(2.0,2.0,2.0);
	
	 glPushMatrix();//corpo
   glScalef (2.0, 3.0, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   
   
   glPushMatrix();//cabeça
   glTranslatef(0,2.5,0);
   glScalef (1.0, 1.0, 1.0);
   glutWireSphere(1.0, 20, 16); 
   glPopMatrix();
   
   
   
   glPushMatrix();
   glTranslatef (1.0, 1.3, 0.0);
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 0.5);
   glutWireCube (1.0);
   glPopMatrix();

   glTranslatef (1.0, 0.0, 0.0); // antebraco
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 0.5);
   glutWireCube (1.0);
   glPopMatrix();

	glTranslatef (1.5, 0.0, 0.0); // Pulso
   glRotatef ((GLfloat)fist, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (0.8, 0.4, 0.1);
   glutWireCube (1.0);
   glPopMatrix();   
   
   
    glPushMatrix(); // DEDO 1
		   glTranslatef (0.4, 0.0, -0.5);
		   glRotatef ((GLfloat) finger, 0.0, 0.0, 1.0);
		   
		   glTranslatef (0.2, 0.0, 0.4);
		   glPushMatrix();
			   glScalef (0.5, 0.1, 0.1);
			   glutWireCube (1.0);
		   glPopMatrix();
		   
		   glTranslatef (0.2, 0.0, 0.0);
		   glRotatef ((GLfloat) finger, 0.0, 0.0, 1.0);
		   glTranslatef (0.2, 0.0, 0.0);
		   glPushMatrix();
		        glScalef (0.3, 0.1, 0.1);
		        glutWireCube (1.0);
		   glPopMatrix();
	   glPopMatrix();
   
   glPushMatrix(); // DEDO 2
   glTranslatef (0.4, 0.0, -0.5);
		   glRotatef ((GLfloat) finger2, 0.0, 0.0, 1.0);
		   glTranslatef (0.2, 0.0, 0.6);
		   glPushMatrix();
			   glScalef (0.5, 0.1, 0.1);
			   glutWireCube (1.0);
		   glPopMatrix();
		   
		   glTranslatef (0.2, 0.0, 0.0);
		   glRotatef ((GLfloat) finger2, 0.0, 0.0, 1.0);
		   glTranslatef (0.2, 0.0, 0.0);
		   glPushMatrix();
		        glScalef (0.3, 0.1, 0.1);
		        glutWireCube (1.0);
		   glPopMatrix();
   glPopMatrix(); 
   
   
   
   

   glPopMatrix();
}

void drawHouse(void){
	
	
	//  Parede atras
	static float lystre[] = {0.86,0.62,0.12};
  glBegin( GL_POLYGON ); 
    glColor3f(1.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.0f,0.0f); 
    glVertex3f(0.0f,8.0f,0.0f); 
    glVertex3f(4.5f,9.0f,0.0f); 
    glVertex3f(9.0f,8.0f,0.0f); 
    glVertex3f(9.0f,0.0f,0.0f); 
  glEnd(); 
  
//  Parede lateral sem janela
  glBegin( GL_QUADS ); //ok
    glColor3f(0.0f,0.0f,1.0f); 
    glVertex3f(0.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.0f,8.0f); 
    glVertex3f(0.0f,8.0f,8.0f); 
    glVertex3f(0.0f,8.0f,0.0f); 
  glEnd(); 
  
//  Telhado
  glBegin( GL_QUAD_STRIP ); //ok
    glColor3f(0.0f,1.0f,0.0f); 
    glVertex3f(0.0f,8.0f,0.0f); 
    glVertex3f(0.0f,8.0f,8.0f); 
    glVertex3f(4.5f,9.0f,0.0f); 
    glVertex3f(4.5f,9.0f,8.0f); 
    glVertex3f(9.0f,8.0f,0.0f); 
    glVertex3f(9.0f,8.0f,8.0f); 
  glEnd();  
  
//  parede da frente
  glBegin( GL_QUADS ); 
    glColor3f(1.0f,1.0f,0.0f); 
    glVertex3f(0.0f,0.0f,0.4f); 
    glVertex3f(0.0f,0.2f,0.4f); 
    glVertex3f(0.15f,0.2f,0.4f); 
    glVertex3f(0.15f,0.0f,0.4f); 
    
    
    glVertex3f(0.25f,0.0f,0.4f); 
    glVertex3f(0.25f,0.2f,0.4f); 
    glVertex3f(0.4f,0.2f,0.4f); 
    glVertex3f(0.4f,0.0f,0.4f); 
  glEnd();
  glBegin( GL_TRIANGLES ); 
    glColor3f(1.0f,1.0f,0.0f); 
    glVertex3f(0.0f,0.2f,0.4f); 
    glVertex3f(0.2f,0.3f,0.4f);
    glVertex3f(0.4f,0.2f,0.4f);  
  glEnd();
  
  
//  Parede lateral
  glBegin( GL_QUADS ); //ok
    glColor3f(0.0f,0.0f,1.0f); 
    glVertex3f(9.0f,0.0f,0.0f); 
    glVertex3f(9.0f,0.0f,8.0f); 
    glVertex3f(9.0f,8.0f,8.0f); 
    glVertex3f(9.0f,8.0f,0.0f); 
  glEnd();
  
//  Chï¿½o
  glBegin( GL_QUADS ); 	
    glColor3f(1.0f,0.0f,1.0f); 
    glVertex3f(0.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.0f,8.0f);
    glVertex3f(9.0f,0.0f,8.0f);
    glVertex3f(9.0f,0.0f,0.0f);   
  glEnd();



  glFlush();
}

void drawArmario(void){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture);	
	//glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,hvit);
   
	glBegin( GL_POLYGON );//Tras do armario
	 glColor3f(1.0f,0.0f,0.0f);
	 glVertex3f(8.9f,0.0f,1.0f); 
	 glVertex3f(8.9f,0.0f,3.0f); 
	 glVertex3f(8.9f,3.0f,3.0f); 
	 glVertex3f(8.9f,3.0f,1.0f); 
	glEnd();
	
	glBegin( GL_POLYGON );//frente do armario
	 glColor3f(1.0f,0.0f,0.0f);
	 glVertex3f(8.5f,0.0f,1.0f); 
	 glVertex3f(8.5f,0.0f,3.0f); 
	 glVertex3f(8.5f,3.0f,3.0f); 
	 glVertex3f(8.5f,3.0f,1.0f); 
	glEnd();
	
	glBegin( GL_POLYGON );//esquerda Armario
	 glColor3f(1.0f,0.0f,0.0f);
	 glVertex3f(8.5f,0.0f,1.0f); 
	 glVertex3f(8.9f,0.0f,1.0f); 
	 glVertex3f(8.9f,3.0f,1.0f); 
	 glVertex3f(8.5f,3.0f,1.0f); 
	glEnd();
	
	
	glBegin( GL_POLYGON );//direita Armario
	 glColor3f(1.0f,0.0f,1.0f);
	 glVertex3f(8.5f,0.0f,3.0f); 
	 glVertex3f(8.9f,0.0f,3.0f); 
	 glVertex3f(8.9f,3.0f,3.0f); 
	 glVertex3f(8.5f,3.0f,3.0f); 
	glEnd();
	
	
	glBegin( GL_POLYGON );//frente porta direita
		 glColor3f(1.0f,1.0f,0.0f);
		 glVertex3f(8.4f,0.8f,2.05f); 
		 glVertex3f(8.4f,0.8f,2.9f); 
		 glVertex3f(8.4f,2.9f,2.9f); 
		 glVertex3f(8.4f,2.9f,2.05f); 
	glEnd();
	
	glBegin( GL_POLYGON );//frente porta esquerda
		 glColor3f(1.0f,1.0f,0.0f);
		 glVertex3f(8.4f,0.8f,1.1f); 
		 glVertex3f(8.4f,0.8f,1.95f); 
		 glVertex3f(8.4f,2.9f,1.95f); 
		 glVertex3f(8.4f,2.9f,1.10f); 
	glEnd();
	
	glBegin( GL_POLYGON );//gaveta
		 glColor3f(1.0f,1.0f,0.0f);
		 glVertex3f(8.3f,0.3f,1.1f); 
		 glVertex3f(8.3f,0.3f,1.95f); 
		 glVertex3f(8.3f,0.7f,1.95f); 
		 glVertex3f(8.3f,0.7f,1.10f); 
	glEnd();
	
	glBegin( GL_POLYGON );//gaveta direita
		 glColor3f(1.0f,1.0f,0.0f);
		 glVertex3f(8.3f,0.3f,2.05f); 
		 glVertex3f(8.3f,0.3f,2.9f); 
		 glVertex3f(8.3f,0.7f,2.9f); 
		 glVertex3f(8.3f,0.7f,2.05f); 
	glEnd();
	
}
	
	
void drawBed(void){
	glBegin( GL_QUADS );
	    glColor3f(0.0f,0.0f,0.0f); 
	    glVertex3f(2.0f,0.0f,0.0f); 
	    glVertex3f(2.0f,0.0f,2.5f); 
	    glVertex3f(2.0f,1.0f,2.5f); 
	    glVertex3f(2.0f,1.0f,0.0f); 
  	glEnd(); 

	glBegin( GL_QUADS ); 
	    glColor3f(0.0f,0.0f,0.0f); 
	    glVertex3f(2.0f,0.0f,2.5f); 
	    glVertex3f(2.0f,1.0f,2.5f); 
	    glVertex3f(0.0f,1.0f,2.5f); 
	    glVertex3f(0.0f,0.0f,2.5f); 
  	glEnd(); 

	glBegin( GL_QUADS ); 
	    glColor3f(1.0f,1.0f,1.0f); 
	    glVertex3f(0.0f,1.0f,0.0f); 
	    glVertex3f(2.0f,1.0f,0.0f); 
	    glVertex3f(2.0f,1.0f,2.5f); 
	    glVertex3f(0.0f,1.0f,2.5f); 
  	glEnd();	    
  glFlush();
}


void ligth(void){
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 }; // Ambiente
	GLfloat light_diffuse[] = { 1.0, 0.0, 1.0, 1.0 }; // Focal
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Reflexo
	GLfloat light_position[] = { 4.5, 8.5, 4.5, 0.0 };// Posicao

 glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);



   glEnable(GL_LIGHTING);
  // glEnable(GL_LIGHT0);
   glColorMaterial(GL_FRONT, GL_DIFFUSE);
glEnable(GL_COLOR_MATERIAL);
   
}

void RenderScene(void) { 
  glMatrixMode( GL_MODELVIEW ); 
  glLoadIdentity(); 
//  glTranslatef(0.0f,0.0f,distance); 
//  glRotatef(vertangle,1.0f,0.0f,0.0f); 
//  glRotatef(horzangle,0.0f,1.0f,0.0f); 
  glEnable( GL_DEPTH_TEST ); 
  glClearColor(0.0f,0.0f,0.0f,0.0f); 
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); 
  
  gluLookAt(	x, y, z,
			x+lx, y+ly,  z+lz,
			0.0f, 2.0f,  0.0f);
  
//  Linhas para demonstrar os eixos
  
  drawHouse();
  drawArmario();
  drawBed();
 // drawRobot();
  
  
   
  glutSwapBuffers(); 
} 
  
void ChangeSize(GLsizei width,GLsizei height) { 
  glViewport(0,0,width,height); 
  glMatrixMode( GL_PROJECTION ); 
  glLoadIdentity(); 
  gluPerspective(100,width/height,0.01,50.0); 
} 
  
void MoveLeft(void) { 
  horzangle -= 5; 
  RenderScene(); 
} 
  
void MoveRight(void) { 
  horzangle += 5; 
  RenderScene(); 
} 
  
void MoveUp(void) { 
  vertangle -= 5; 
  RenderScene(); 
} 
  
void MoveDown(void) { 
  vertangle += 5; 
  RenderScene(); 
} 
  
void MoveFoward(void) { 
  distance += 0.5; 
  RenderScene(); 
} 
  
void MoveBackward(void) { 
  distance -= 0.5; 
  RenderScene(); 
} 


void KeyboardOptions(int key, int x, int y)
{
	float fraction = 0.1f;
	 if (key == GLUT_KEY_LEFT) {
		angle -= 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
	} else if (key == GLUT_KEY_RIGHT) {
        angle += 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
	} else if (key == GLUT_KEY_UP) {
        x += lx * fraction;
			z += lz * fraction;
	} else if (key == GLUT_KEY_DOWN) {
			x -= lx * fraction;
			z -= lz * fraction;
	}
	
	else if(key == 27 ) exit(0);
    glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 's':
         shoulder = (shoulder + 5) % 360;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder = (shoulder - 5) % 360;
         glutPostRedisplay();
         break;
      case 'e':
         elbow = (elbow + 5) % 360;
         glutPostRedisplay();
         break;
      case 'E':
         elbow = (elbow - 5) % 360;
         glutPostRedisplay();
         break;
    case 'G':
         fist= (fist + 5) % 360;
         glutPostRedisplay();
         break;
      case 'g':
         fist = (fist - 5) % 360;
         glutPostRedisplay();
         break;
    case 'T':
         finger= (finger + 2) % 360;
         glutPostRedisplay();
         break;
      case 't':
         finger = (finger - 2) % 360;
         glutPostRedisplay();
         break;
    case 'Y':
         finger2= (finger2 + 2) % 360;
         glutPostRedisplay();
         break;
      case 'y':
         finger2 = (finger2 - 2) % 360;
         glutPostRedisplay();
         break;
    case 'l':
    	   glEnable(GL_LIGHT0);
    	   break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
   glutPostRedisplay();
}
void MouseOptions(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON){
      if (state == GLUT_UP) {
        horzangle += 15; 
        RenderScene(); 
      }  
    } else if (button == GLUT_RIGHT_BUTTON){
      if (state == GLUT_UP) {
        horzangle -= 15; 
        RenderScene();
      }  
    }
         
    glutPostRedisplay();
}
 
void init(){
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 }; // Ambiente
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 0.5 }; // Focal
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Reflexo
	GLfloat light_position[] = { 3.0, 2.0, 4.0, 1.0 };// Posicao

 glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);



   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glColorMaterial(GL_FRONT, GL_DIFFUSE);
glEnable(GL_COLOR_MATERIAL);
} 
  
  /*
void textures()
{
	#include “SDL.h”
 SDL_Surface * bmpFile = SDL_LoadBMP("madeira.bmp");

 glPixelStorei(GL_UNPACK_ALIGNMENT,4);
 glGenTextures(1,&texture);
 glBindTexture(GL_TEXTURE_2D,texture);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

 gluBuild2DMipmaps(GL_TEXTURE_2D, 3,bmpFile->w, bmpFile->h, GL_BGR_EXT, GL_UNSIGNED_BYTE,bmpFile->pixels);

SDL_FreeSurface(bmpFile);
}	*/

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);    
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA ); 
  glutInitWindowSize (600, 600); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow("OpenGL - Mouse"); 
  init();
  glutReshapeFunc(ChangeSize); 
  glutSpecialFunc(KeyboardOptions); 
  glutKeyboardFunc(keyboard);
  glutMouseFunc(MouseOptions);
  glutDisplayFunc(RenderScene);
  glutMainLoop(); 
  return 0;
} 	
