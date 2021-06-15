#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
const int screenHeight = 800; // window height is 800
const int screenWidth = 600 ; //window width is 600
//<<<<<<<<<<<<<<<<<<<<< Prototypes >>>>>>>>>>>>>>>>>>
	void exit(int) ;
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
        glClearColor(1.0,1.0,1.0,0.0);       // set white background color
        glColor3f(0.0f, 0.0f, 0.0f);          // set the drawing color 
 	glPointSize(4.0);		       // a ?dot? is 4 by 4 pixels
 	glLineWidth(4.0);		      
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	//glOrtho(0.0, 640.0, 0.0, 480.0, -1.0, 1.0);
	//glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);
	glOrtho(-1.5, 1.5, -1.5, 1.5, -1.5, 1.5);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
//  	glBegin(GL_POINTS);
//	glBegin(GL_LINE_STRIP) ;
//	glBegin(GL_LINE_LOOP) ;
	glBegin(GL_POLYGON);
	glVertex2i(289, 190);        // Dubhe 
	glVertex2i(320,  128) ;        // Merak
	glVertex2i(239,  67) ;        // Phecda 
	glVertex2i(194,  101) ;       // Megrez
	glVertex2i(129,  83) ;       // Alioth
	glVertex2i(75,  73) ;       // Mizar
	glVertex2i(74,  74) ;       // Alcor
	glEnd();
	glFlush();          // send all output to display 
}


void drawPoint(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//just draws a point at center of screen
	glBegin(GL_POINTS);
		glVertex3f(0.0f, 0.0f, 0.0f);
		

	glEnd();
	glFlush();
}

void drawLine(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.0f);
	
		//glColor3f(0.0, 1.0, 1.0);
		//glVertex3f(-0.875f, 0.375f, 0.0f);
		//glVertex3f(-0.375f, 0.375f, 0.0f);
	glEnd();
	glFlush();
}

void ngon(int n)
{
	glClear(GL_COLOR_BUFFER_BIT); // clear screen
	float degree, vertx, verty, rotate, degToRad;
	rotate = 360.0/n;	//set vertex rotation amount
	degree = rotate/2 + 180;
	degToRad = 180/3.14159; //convert deg to radian
	glBegin(GL_POLYGON);
	for(int i =0; i<n; i++, degree += rotate)
	{
		vertx = .5 * sin(degree/degToRad); //coordinate for next x vert
		verty = .5 * sin((90 - degree)/degToRad); //coordinate for next y vertex
		glVertex3f(vertx, verty, 0);
	}
	glEnd();
	glFlush();
}

void drawCube(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
/*
	glTranslatef(1.5, 0.0f, -7.0f);
	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, -1.0f);
		glVertex3f( 1.0f, 1.0f, -1.0f);
      		glVertex3f(-1.0f, 1.0f, -1.0f);
      		glVertex3f(-1.0f, 1.0f,  1.0f);
      		glVertex3f( 1.0f, 1.0f,  1.0f);
*/
		
	//added	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glEnable(GL_DEPTH_TEST);

	//rotate to see more faces of cube
	glRotatef(20.0f, 0.5f, 0.25f, -0.75f);

	//
	//glEnable(GL_DEPTH_TEST);
	//


	//create 6 different colored squares to form cube
	glBegin(GL_QUADS);	
		glEnable(GL_DEPTH_TEST);
		//top square
/*
		glColor3f(0.0f, 1.0f, -1.0f);//Green
		
		glVertex3f( 1.0f, 1.0f, -1.0f);
      		glVertex3f(-1.0f, 1.0f, -1.0f);
      		glVertex3f(-1.0f, 1.0f,  1.0f);
      		glVertex3f( 1.0f, 1.0f,  1.0f);
*/

		//CUBE*************
		//top square
		glColor3f(0.0f, 1.0f, -1.0f); //Green
		glVertex3f(0.5f, 0.5f, -0.5f);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glVertex3f(0.5f, 0.5f, 0.5f);

		//bottom square
		glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      		glVertex3f( 0.5f, -0.5f,  0.5f);
      		glVertex3f(-0.5f, -0.5f,  0.5f);
      		glVertex3f(-0.5f, -0.5f, -0.5f);
      		glVertex3f( 0.5f, -0.5f, -0.5f);
		
		//front square

		glColor3f(1.0f, 0.0f, 0.0f);     // Red

		glVertex3f(0.5f, 0.5f, 0.5f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glVertex3f(0.5f, -0.5f, 0.5f);

		//back square
		glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      		glVertex3f( 0.5f, -0.5f, -0.5f);
      		glVertex3f(-0.5f, -0.5f, -0.5f);
      		glVertex3f(-0.5f,  0.5f, -0.5f);
      		glVertex3f( 0.5f,  0.5f, -0.5f);

		//left square
		glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      		glVertex3f(-0.5f,  0.5f,  0.5f);
      		glVertex3f(-0.5f,  0.5f, -0.5f);
      		glVertex3f(-0.5f, -0.5f, -0.5f);
      		glVertex3f(-0.5f, -0.5f,  0.5f);

		//right square
		//glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
		glColor3f(0.0f, 0.0f, 0.0f);//black
      		glVertex3f(0.5f,  0.5f, -0.5f);
      		glVertex3f(0.5f,  0.5f,  0.5f);
      		glVertex3f(0.5f, -0.5f,  0.5f);
      		glVertex3f(0.5f, -0.5f, -0.5f);


/*
		//top square
		glColor3f(0.0f, 1.0f, -1.0f); //Green
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);

		//bottom square
		glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      		glVertex3f( 1.0f, -1.0f,  1.0f);
      		glVertex3f(-1.0f, -1.0f,  1.0f);
      		glVertex3f(-1.0f, -1.0f, -1.0f);
      		glVertex3f( 1.0f, -1.0f, -1.0f);
		
		//front square

		glColor3f(1.0f, 0.0f, 0.0f);     // Red

		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		//back square
		glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      		glVertex3f( 1.0f, -1.0f, -1.0f);
      		glVertex3f(-1.0f, -1.0f, -1.0f);
      		glVertex3f(-1.0f,  1.0f, -1.0f);
      		glVertex3f( 1.0f,  1.0f, -1.0f);

		//left square
		glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      		glVertex3f(-1.0f,  1.0f,  1.0f);
      		glVertex3f(-1.0f,  1.0f, -1.0f);
      		glVertex3f(-1.0f, -1.0f, -1.0f);
      		glVertex3f(-1.0f, -1.0f,  1.0f);

		//right square
		//glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
		glColor3f(0.0f, 0.0f, 0.0f);//black
      		glVertex3f(1.0f,  1.0f, -1.0f);
      		glVertex3f(1.0f,  1.0f,  1.0f);
      		glVertex3f(1.0f, -1.0f,  1.0f);
      		glVertex3f(1.0f, -1.0f, -1.0f);
*/
	glEnd();
	glFlush();
}
//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>
void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
/*
	switch(theKey)
	{
		case 'Q':
		case 'q':
			exit(-1); //terminate the program
		default:
		break; // do nothing
	}
*/
	//switches to shape based on which key you press
	switch(theKey)
	{
		case 'T': //clean screen make triangle
		case 't':
			ngon(3);
			break;

		case 'H':	//hexagon
		case 'h':
			//glutDisplayFunc(ngon(6));
			ngon(6);
			break;


		case 'C':	//displays circle
		case 'c':
			ngon(30);
			break;

		case 'P':	//display point
		case 'p':
			drawPoint();
			break;
		
		case 'R':	//display line
		case 'r':
			drawLine();
			break;
			
		case 'S':	//display square
		case 's':
			ngon(4);
			break;
		

		
		case 'U':	//display cube
		case 'u':
			drawCube();
			break;
		
		case 'Q':
		case 'q':
			exit(-1);
		default:
		break;
	}
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int	 main(int argc, char** argv)
{
/*
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(800,600);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Big Deep - Type Q or q to quit") ; // open the screen window 
	glutDisplayFunc(myDisplay);     // register redraw function
        glutKeyboardFunc(myKeyboard); // register the keyboard action function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set display mode
	glutInitWindowSize(800, 600);			//set window size
	glutInitWindowPosition(100, 150);
	glutCreateWindow("(T)riangle, (C)ircle, (P)oint, (R)Line, c(U)be, (S)quare" );
	glutDisplayFunc(myDisplay);	 //register redraw function
	glutKeyboardFunc(myKeyboard);//register keyboard action function
	myInit();
	glutMainLoop();		//go into perpetual loop
}


