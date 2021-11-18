#include <GL/glut.h>
#include <math.h> 
  
GLfloat horzangle = -45.0,vertangle = 30.0,distance = -3.0; 

// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f,ly=0.0f;
// XZ position of the camera
float x=4.0f,z=3.0f,y=2.0f;


void drawHouse(void){
	
	
	//  Parede atras
	static float lystre[] = {0.86,0.62,0.12};
  glBegin( GL_POLYGON ); 
    glColor3f(1.0f,0.0f,0.0f); 
    glVertex3f(0.0f,0.0f,0.0f); 
    glVertex3f(0.0f,8.0f,0.0f); 
    glVertex3f(6.5f,9.0f,0.0f); 
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
    glVertex3f(6.5f,9.0f,0.0f); 
    glVertex3f(6.5f,9.0f,8.0f); 
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
  
//  Ch�o
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
	
	
	glBegin( GL_POLYGON );//Tras do armario
	 glColor3f(1.0f,0.0f,0.0f);
	 glVertex3f(4.9f,0.0f,1.0f); 
	 glVertex3f(4.9f,0.0f,3.0f); 
	 glVertex3f(4.9f,3.0f,3.0f); 
	 glVertex3f(4.9f,3.0f,1.0f); 
	glEnd();
	
	glBegin( GL_POLYGON );//frente do armario
	 glColor3f(1.0f,0.0f,0.0f);
	 glVertex3f(4.5f,0.0f,1.0f); 
	 glVertex3f(4.5f,0.0f,3.0f); 
	 glVertex3f(4.5f,3.0f,3.0f); 
	 glVertex3f(4.5f,3.0f,1.0f); 
	glEnd();
	
	glBegin( GL_POLYGON );//esquerda Armario
	 glColor3f(1.0f,0.0f,0.0f);
	 glVertex3f(4.5f,0.0f,1.0f); 
	 glVertex3f(4.9f,0.0f,1.0f); 
	 glVertex3f(4.9f,3.0f,1.0f); 
	 glVertex3f(4.5f,3.0f,1.0f); 
	glEnd();
	
	
	glBegin( GL_POLYGON );//direita Armario
	 glColor3f(1.0f,0.0f,1.0f);
	 glVertex3f(4.5f,0.0f,3.0f); 
	 glVertex3f(4.9f,0.0f,3.0f); 
	 glVertex3f(4.9f,3.0f,3.0f); 
	 glVertex3f(4.5f,3.0f,3.0f); 
	glEnd();
	
	
	glBegin( GL_POLYGON );//frente porta 
		 glColor3f(1.0f,1.0f,0.0f);
		 glVertex3f(4.4f,0.8f,2.0f); 
		 glVertex3f(4.4f,0.8f,2.9f); 
		 glVertex3f(4.4f,2.9f,2.9f); 
		 glVertex3f(4.4f,2.9f,2.0f); 
	glEnd();
	
	
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
 
  
int main(int argc, char* argv[]) {
  glutInit(&argc, argv);    
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA ); 
  glutInitWindowSize (600, 600); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow("OpenGL - Mouse"); 
  glutReshapeFunc(ChangeSize); 
  glutSpecialFunc(KeyboardOptions); 
  glutMouseFunc(MouseOptions);
  glutDisplayFunc(RenderScene);
  glutMainLoop(); 
  return 0;
} 	
