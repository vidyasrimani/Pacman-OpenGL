void init()
{
	glEnable(GL_NORMALIZE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.33, 0.005, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-1.5, 0, 40, -1.5, 0, 0, 0.0f, 1.0f, 0.0f);
}


The above function is the init() where the MatrixMode is selected,the perspective is chosen and the camera is set up. 
Here LoadIdentity is called before each change so that the initial matrix is always loaded and the MatrixMode is changed according to the original. gluLookAt() is used to set the camera.

bool Open(int a, int b)
{
	if (board_array[b][a] > 0)
	{
		return false;
	}
	return true;
}


The above function is used to check whether the Pac-Man is in a position whether the boundary of the grid is not present. 
board_array[31][28] is a double dimensional array that is used to show the grid of the Pac-Man game. 
Each value in the array corresponds to which direction the Pac-Man can move on encountering that position. In this case, 
if the board_araay[][]=0, then it means that the Pac-Man is in an open space (it has not encountered a boundary).
The Open() hence checks this value and then returns a Boolean true or false. This serves as a checker in the Move() 
where the next position of the Pac-Man is checked if feasible or not

a += speed1*cos(M_PI / 180 * angle1);
b += speed1*sin(M_PI / 180 * angle1);
if (animate&&ckey == GLUT_KEY_UP && (int)a-a> -0.1 && angle1!= 270)      {
 	if (Open(a, b - 1))
	{
		animate = true;
		angle1 = 270;
	}
}

Within the Move(), the above code is found. a and b are integer variables that 
find the absolute position of the Pac-Man with respect to the grid. Here the radian value of the direction (angle1) 
is multiplied with the current speed to give the required absolute position value.
In the if() statement, it is checked if the Pac-Man is moving (animate) and the keyboard key pressed is the UP key and if
the difference between the actual and absolute value of a is greater than -0.1 (there is movement) and the angle is along the North direction ie in 270. 
(Similarly angle1 is 0 for East, 90 for South and 180 for West).
Note that the same function is implemented by specialDown() as well. 
The difference between the two is that specialDown() works on a timer and it is called up only for a specific time

void Pac(void)
{
	glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslatef(a, -b, 0);
	glTranslatef(0.5, 0.6, 0);
	glTranslatef((float)BOARD_X / -2.0f, (float)BOARD_Y / 2.0f, 0.5);
	glutSolidSphere(0.5, 15, 10);
	glPopMatrix();
}


The above function Pac() creates the Pac-Man using the glutSolidSphere() 
function where the arguments are the size of the Pac-Man. The Translate() move the Pac-Man 
to its initial position on the grid created. 
glColor3f() obtains the yellow colour for the Pac-Man.

