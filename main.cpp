#include <GL/glut.h>
#include <math.h>


#define	stripeImageWidth 32
GLubyte stripeImage[4*stripeImageWidth];
#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

#ifdef GL_VERSION_1_1
static GLuint texName;
#endif

GLfloat horzangle = -45.0, vertangle = 30.0, distance = -3.0;
static int shoulder = -50, elbow = 310, fist = 0, finger2 = -46, finger = -46;
GLuint texture;

bool luzes = false;

static float veggfarge[] = {0.9, 0.9, 0.9, 1};
static float rod[] = {0.5, 0, 0};
static float madeira[] = {0.222, 0.184, 0.135};

// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f, ly = 0.0f;
// XZ position of the camera
float x = 4.0f, z = 4.5f, y = 2.0f;

void makeStripeImage(void)
{
   int i, j, c;
    
   for (j = 0; j < stripeImageWidth; j++) {
      stripeImage[4*j] = (GLubyte) ((j>1) ? 191 : 0);
      stripeImage[4*j+1] = (GLubyte) ((j>1) ? 191 : 0);
      stripeImage[4*j+2] = (GLubyte) ((j>1) ? 191 : 0);
      stripeImage[4*j+3] = (GLubyte) 255;
   }
   
   for (i = 0; i < checkImageHeight; i++) {
      for (j = 0; j < checkImageWidth; j++) {
         c = ((((i & 0x10) == 0) ^ ((j & 0x10)) == 0)) * 255;
			checkImage[i][j][0] = (GLubyte)c;
			checkImage[i][j][1] = (GLubyte)c;
			checkImage[i][j][2] = (GLubyte)c;
			checkImage[i][j][3] = (GLubyte)255;
      }
   }
}

/*  planes for texture coordinate generation  */
static GLfloat xequalzero[] = {1.0, 0.0, 0.0, 0.0};
static GLfloat slanted[] = {1.0, 1.0, 1.0, 0.0};
static GLfloat *currentCoeff;
static GLenum currentPlane;
static GLint currentGenMode;

void drawRobot(void)
{
	
	glEnable(GL_TEXTURE_1D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_1D, texName);
	   glEnable(GL_TEXTURE_GEN_S);

	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(5.0, 2.5, 1.0);
	glScalef(0.4,0.4,0.4);
	glPushMatrix(); //corpo
	glScalef(2.0, 3.0, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

glPushMatrix(); //cabe?a
    glTranslatef(0, 2.5, 0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidSphere(1.0, 20, 16);

    glPushMatrix();//EYES
    glTranslatef(-0.5,0.1,0.9);
    glScalef(0.2,0.2,0.2);
    glColor3f(1,1,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,0.1,0.9);
    glScalef(0.2,0.2,0.2);
    glColor3f(1,1,0);
    glutSolidCube(1);
    glPopMatrix();


    glPopMatrix();
    

	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(1.0, 1.3, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.4, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0); // antebraco
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.4, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(1.5, 0.0, 0.0); // Pulso
	glRotatef((GLfloat)fist, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.8, 0.4, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix(); // DEDO 1
	glTranslatef(0.4, 0.0, -0.5);
	glRotatef((GLfloat)finger, 0.0, 0.0, 1.0);

	glTranslatef(0.2, 0.0, 0.4);
	glPushMatrix();
	glScalef(0.5, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(0.2, 0.0, 0.0);
	glRotatef((GLfloat)finger, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); // DEDO 2
	glTranslatef(0.4, 0.0, -0.5);
	glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.0, 0.6);
	glPushMatrix();
	glScalef(0.5, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(0.2, 0.0, 0.0);
	glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	
	//Outro braco
	
	glPushMatrix();
	glTranslatef(-1.0, 1.3, 0.0);
	glRotatef(180,0,1,0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.4, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0); // antebraco
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.4, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(1.5, 0.0, 0.0); // Pulso
	glRotatef((GLfloat)fist, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.8, 0.4, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix(); // DEDO 1
	glTranslatef(0.4, 0.0, -0.5);
	glRotatef((GLfloat)finger, 0.0, 0.0, 1.0);

	glTranslatef(0.2, 0.0, 0.4);
	glPushMatrix();
	glScalef(0.5, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(0.2, 0.0, 0.0);
	glRotatef((GLfloat)finger, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); // DEDO 2
	glTranslatef(0.4, 0.0, -0.5);
	glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.0, 0.6);
	glPushMatrix();
	glScalef(0.5, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(0.2, 0.0, 0.0);
	glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	
	//Pernas
	
	
	
	glColor3f(0.5f, 0.5f, 1.0f);
	glTranslatef(0,-2,0);
    glPushMatrix();
    glScalef(2.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

	glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(-0.5,-2.1,0.0);
    glPushMatrix();
    glScalef(0.8, 4.0, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    glTranslatef(1,0.0,0.0);
    glPushMatrix();
    glScalef(0.8, 4.0, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glDisable(GL_TEXTURE_1D);
    glDisable(GL_TEXTURE_GEN_S);
}

void drawHouse(void)
{

	//  Parede atras

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.1f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 8.0f, 0.0f);
	glVertex3f(4.5f, 9.0f, 0.0f);
	glVertex3f(9.0f, 8.0f, 0.0f);
	glVertex3f(9.0f, 0.0f, 0.0f);
	glEnd();

	//  Parede lateral sem janela
	glMaterialfv(GL_FRONT, GL_DIFFUSE, rod);
	//glMaterialfv(GL_FRONT,GL_AMBIENT,rod);
	glBegin(GL_QUADS); //ok
	glColor3f(0.5f,1.0f,1.5f);
	// glNormal3f(-1,0,0); //innvendig
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 8.0f);
	glVertex3f(0.0f, 8.0f, 8.0f);
	glVertex3f(0.0f, 8.0f, 0.0f);
	glEnd();

	//  Telhado
	glBegin(GL_QUAD_STRIP); //ok
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 8.0f, 0.0f);
	glVertex3f(0.0f, 8.0f, 8.0f);
	glVertex3f(4.5f, 9.0f, 0.0f);
	glVertex3f(4.5f, 9.0f, 8.0f);
	glVertex3f(9.0f, 8.0f, 0.0f);
	glVertex3f(9.0f, 8.0f, 8.0f);
	glEnd();

	//  parede da frente
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 8.0f);
	glVertex3f(0.0f, 8.0f, 8.0f);
	glVertex3f(4.5f, 9.0f, 8.0f);
	glVertex3f(9.0f, 8.0f, 8.0f);
	glVertex3f(9.0f, 0.0f, 8.0f);
	glEnd();	

	//  Parede lateral
	glBegin(GL_QUADS); //ok
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(9.0f, 0.0f, 0.0f);
	glVertex3f(9.0f, 0.0f, 8.0f);
	glVertex3f(9.0f, 8.0f, 8.0f);
	glVertex3f(9.0f, 8.0f, 0.0f);
	glEnd();

	//  Ch?o
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 8.0f);
	glVertex3f(9.0f, 0.0f, 8.0f);
	glVertex3f(9.0f, 0.0f, 0.0f);
	glEnd();

	glFlush();
}

void drawArmario(void)
{
	glMaterialfv(GL_FRONT, GL_DIFFUSE, madeira);
	glBegin(GL_POLYGON); //Tras do armario
	glVertex3f(8.9f, 0.0f, 1.0f);
	glVertex3f(8.9f, 0.0f, 3.0f);
	glVertex3f(8.9f, 5.0f, 3.0f);
	glVertex3f(8.9f, 5.0f, 1.0f);
	glEnd();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, madeira);
	
	glBegin(GL_POLYGON); //frente do armario
	glColor3f(0.545f,0.27f,0.074f);
	glVertex3f(8.5f, 0.0f, 1.0f);
	glVertex3f(8.5f, 0.0f, 3.0f);
	glVertex3f(8.5f, 5.0f, 3.0f);
	glVertex3f(8.5f, 5.0f, 1.0f);
	glEnd();

	glBegin(GL_POLYGON); //esquerda Armario
	glVertex3f(8.5f, 0.0f, 1.0f);
	glVertex3f(8.9f, 0.0f, 1.0f);
	glVertex3f(8.9f, 5.0f, 1.0f);
	glVertex3f(8.5f, 5.0f, 1.0f);
	glEnd();

	glBegin(GL_POLYGON); //direita Armario
	glVertex3f(8.5f, 0.0f, 3.0f);
	glVertex3f(8.9f, 0.0f, 3.0f);
	glVertex3f(8.9f, 5.0f, 3.0f);
	glVertex3f(8.5f, 5.0f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON); //frente porta direita
	glColor3f(0.82f, 0.4117f, 0.1176f);
	glVertex3f(8.4f, 0.8f, 2.05f);
	glVertex3f(8.4f, 0.8f, 2.9f);
	glVertex3f(8.4f, 4.7f, 2.9f);
	glVertex3f(8.4f, 4.7f, 2.05f);
	glEnd();

	glBegin(GL_POLYGON); //frente porta esquerda
	glVertex3f(8.4f, 0.8f, 1.1f);
	glVertex3f(8.4f, 0.8f, 1.95f);
	glVertex3f(8.4f, 4.7f, 1.95f);
	glVertex3f(8.4f, 4.7f, 1.10f);
	glEnd();

	glBegin(GL_POLYGON); //gaveta
	glVertex3f(8.4f, 0.3f, 1.1f);
	glVertex3f(8.4f, 0.3f, 1.95f);
	glVertex3f(8.4f, 0.7f, 1.95f);
	glVertex3f(8.4f, 0.7f, 1.10f);
	glEnd();

	glBegin(GL_POLYGON); //gaveta direita
	glVertex3f(8.4f, 0.3f, 2.05f);
	glVertex3f(8.4f, 0.3f, 2.9f);
	glVertex3f(8.4f, 0.7f, 2.9f);
	glVertex3f(8.4f, 0.7f, 2.05f);
	glEnd();
}

void drawBed(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 4.5f);
	glVertex3f(2.0f, 1.0f, 4.5f);
	glVertex3f(2.0f, 1.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 4.5f);
	glVertex3f(2.0f, 1.0f, 4.5f);
	glVertex3f(0.0f, 1.0f, 4.5f);
	glVertex3f(0.0f, 0.0f, 4.5f);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
#ifdef GL_VERSION_1_1
	glBindTexture(GL_TEXTURE_2D, texName);
#endif

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0, 3.0);
	glVertex3f(2.0f, 1.0f, 0.0f);
	glTexCoord2f(3.0, 3.0);
	glVertex3f(2.0f, 1.0f, 4.5f);
	glTexCoord2f(3.0, 0.0);
	glVertex3f(0.0f, 1.0f, 4.5f);
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);
}

void ligth(void)
{
	GLfloat lightDiffuse[] = {1.0f, 1.0f, 0.0f, 1.0f}; // amarelo difuso: cor onde a luz atinge diretamente a superfície do objeto
	GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 0.1f}; // ambiente vermelho: cor aplicada em todos os lugares
	GLfloat lightPosition[] = {4.5f, 10.0f, 4.5f, 0.0f};
	GLfloat direction[] = {5.0, 1.0, 5.0};
	// Componente de luz ambiente
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	// Componente de luz difusa
	//glLightfv (GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	// Posição da luz
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1.0);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 70.0);

	
    if(!luzes){
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

    }else{
    	glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
    }
    glEnable(GL_COLOR_MATERIAL);
}

void RenderScene(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//  glTranslatef(0.0f,0.0f,distance);
	//  glRotatef(vertangle,1.0f,0.0f,0.0f);
	//  glRotatef(horzangle,0.0f,1.0f,0.0f);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(x, y, z,
			  x + lx, y + ly, z + lz,
			  0.0f, 2.0f, 0.0f);

	//  Linhas para demonstrar os eixos

	drawHouse();
	drawArmario();
	drawBed();
	
   
	 drawRobot();

	glutSwapBuffers();
}

void ChangeSize(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100, width / height, 0.01, 50.0);
}


void KeyboardOptions(int key, int x, int y)
{
	float fraction = 0.1f;
	if (key == GLUT_KEY_LEFT)
	{
		angle -= 0.05f;
		lx = sin(angle);
		lz = -cos(angle);
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		angle += 0.05f;
		lx = sin(angle);
		lz = -cos(angle);
	}
	else if (key == GLUT_KEY_UP)
	{
		x += lx * fraction;
		z += lz * fraction;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		x -= lx * fraction;
		z -= lz * fraction;
	}

	else if (key == 27)
		exit(0);
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
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
		fist = (fist + 5) % 360;
		glutPostRedisplay();
		break;
	case 'g':
		fist = (fist - 5) % 360;
		glutPostRedisplay();
		break;
	case 'T':
		finger = (finger + 2) % 360;
		glutPostRedisplay();
		break;
	case 't':
		finger = (finger - 2) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		finger2 = (finger2 + 2) % 360;
		glutPostRedisplay();
		break;
	case 'y':
		finger2 = (finger2 - 2) % 360;
		glutPostRedisplay();
		break;
	case 'l':
		luzes = !luzes;
        ligth();
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
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			horzangle += 15;
			RenderScene();
		}
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			horzangle -= 15;
			RenderScene();
		}
	}

	glutPostRedisplay();
}

void init()
{ glClearColor (0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);

   makeStripeImage();
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

#ifdef GL_VERSION_1_1
   glGenTextures(1, &texName);
   glBindTexture(GL_TEXTURE_2D, texName);
#endif
   glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0,
                GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
                
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight,
				 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);

   currentCoeff = xequalzero;
   currentGenMode = GL_OBJECT_LINEAR;
   currentPlane = GL_OBJECT_PLANE;
   glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
   glTexGenfv(GL_S, currentPlane, currentCoeff);


   glEnable(GL_AUTO_NORMAL);
   glEnable(GL_NORMALIZE);
   glFrontFace(GL_CW);
   glMaterialf (GL_FRONT, GL_SHININESS, 64.0);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
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

