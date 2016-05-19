#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
GLint ancho =800;
GLint alto =600;
int perspectiva=0;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

GLfloat light_position [] = { 0.0, 0.0, 20.0, 0.0 };
GLfloat light_position1 [] = { 0.0, 0.0, 0.0, 1.0 };

	void reshape(int w,int h){
		
			
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if (perspectiva)
	   gluPerspective(80.0f, (float)w/(float)h, 0.2f, 30.0f);
	   
	else
	
	   glOrtho(-2,2,-2,2,-2,2);
	   
	 glMatrixMode(GL_MODELVIEW);
	 
	 ancho = w;
	 alto = h;
		}
	
	
void display()
{
   	//borrar pantalla y z-buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	//resetear transformaciones
	glLoadIdentity();
	
	//Rotar en el eje x, y, z
	
	glTranslatef(X, Y, Z);//transladar en los 3 ejes
	//otras transformaciones
	
	glScalef(scale, scale, scale);
    
	

    GLfloat mat_ambient5[] = { 0.0,0.0,0.1};
	GLfloat mat_diffuse5[] = { 1.0,1.0,1.0};
	GLfloat mat_specular5[] = {0.01,0.01,0.01};
	GLfloat mat_shininess5[] = {1.0};
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse5);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular5);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess5);
    glNormal3f(2.0, 0.0, 0.0);
    
     //glutSolidSphere(1.0,1.5,1.5);
   glutSolidTeapot(1.0);
	glShadeModel(GL_SMOOTH);
	glRotatef( rotate_x, 1.0,0.0,0.0);
	glRotatef( rotate_y, 0.0,1.0,0.0);
	glRotatef( rotate_z, 0.0,0.0,1.0);
	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glFlush();
	
	glutSwapBuffers();
}

void init(){
	glClearColor(0,0,0,0);
	//habilitar la prueba de profundiad de z-buffer
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	}

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{

	//  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;
 
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x -= 7;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x += 7;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F1)
        rotate_z -= 7;
 
    //  Solicitar actualización de visualización
    glutPostRedisplay();
	
}


int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);

    // Solicitar ventana con color real y doble buffer con Z-buffer
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowSize (ancho, alto);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Torus Smooth");
	init();
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}
