#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define CIRCLE_RADIUS  0.15f
#define PI 3.14159265358979323846

int flag = 1;

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glViewport(0, 0, 1000, 1000);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

void display2(void);
void display3(void);
void displayend(void);
void endtext(void);

void StartingText()
{
	char text[300];

	strcpy_s(text, "BALLOON POP GAME");
	glColor3f(0.86, 0.86, 0.86);
	glRasterPos2f(360, 800);

	int len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}

	strcpy_s(text, "INSTRUCTIONS FOR THE GAME");
	glColor3f(0, 0, 0);
	glRasterPos2f(365, 700);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
	}

	strcpy_s(text, "1. The player has to pop the balloons to gain score.");
	glColor3f(0, 0, 0);
	glRasterPos2f(60, 650);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}

	strcpy_s(text, "2. There are three levels in the game.");
	glColor3f(0, 0, 0);
	glRasterPos2f(60, 630);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}

	strcpy_s(text, "3. In the first level there will only be one color balloon and there is no negative score.");

	glColor3f(0, 0, 0);
	glRasterPos2f(60, 610);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}

	strcpy_s(text, "4. As the level increases, the number of balloons and their speeds also increase.");

	glColor3f(0, 0, 0);
	glRasterPos2f(60, 590);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}

	strcpy_s(text, "5. In level 2 and 3, you have to pop the specific color of balloon and on popping the wrong");
	glColor3f(0, 0, 0);
	glRasterPos2f(60, 570);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}

	strcpy_s(text, "balloon your score decreases.");
	glColor3f(0, 0, 0);
	glRasterPos2f(87, 550);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}

	strcpy_s(text, "6. A score of 5 will lead you to the next level.");
	glColor3f(0, 0, 0);
	glRasterPos2f(60, 530);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}

	strcpy_s(text, "7. On popping the wrong color balloon, 1 will be deducted from your score.");
	glColor3f(0, 0, 0);
	glRasterPos2f(60, 510);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}

	strcpy_s(text, "8. A score of 0 or score of 5 at level 3 will end the game.");
	glColor3f(0, 0, 0);
	glRasterPos2f(60, 490);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}


	strcpy_s(text, "PRESS THE S KEY TO START THE GAME");
	glColor3f(1, 0, 0);
	glRasterPos2f(355, 350);

	len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
	}
}


void pop(int x, int y)
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x+5, y+40);
	glVertex2f(x+25, y+50);
	glVertex2f(x+10, y+55);
	glVertex2f(x+3, y+100);
	glVertex2f(x-3, y+52);
	glVertex2f(x-20, y+46);
	glVertex2f(x-4, y+35);
	glVertex2f(x, y);
	glEnd();

}
void balloon()
{
	float theta;

	glLineWidth(0.5);
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(50 + 70 * cos(theta) / 2, 150 + 100 * sin(theta) / 2);
	}
	glEnd();

	glColor3f(1, 1, 0);
	glPointSize(2.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(50, 105);
	glVertex2f(30, 90);
	glVertex2f(70, 90);
	glEnd();

	glColor3f(1, 1, 0);
	glPointSize(2.0);
	glBegin(GL_LINES);
	glVertex2f(50, 90);
	glVertex2f(50, 20);
	glEnd();

	
}

void balloon2()
{
	float theta;

	glLineWidth(0.5);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(50 + 70 * cos(theta) / 2, 150 + 100 * sin(theta) / 2);
	}
	glEnd();

	glColor3f(1, 0, 0);
	glPointSize(2.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(50, 105);
	glVertex2f(30, 90);
	glVertex2f(70, 90);
	glEnd();

	glColor3f(1, 0, 0);
	glPointSize(2.0);
	glBegin(GL_LINES);
	glVertex2f(50, 90);
	glVertex2f(50, 20);
	glEnd();
}

void balloon3()
{
	float theta;

	glLineWidth(0.5);
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(50 + 70 * cos(theta) / 2, 150 + 100 * sin(theta) / 2);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glPointSize(2.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(50, 105);
	glVertex2f(30, 90);
	glVertex2f(70, 90);
	glEnd();

	glColor3f(0, 1, 0);
	glPointSize(2.0);
	glBegin(GL_LINES);
	glVertex2f(50, 90);
	glVertex2f(50, 20);
	glEnd();
}


void sun()
{

	float theta;

	glLineWidth(1.5);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(800 + 80 * cos(theta) / 2, 900 + 80 * sin(theta) / 2);
	}

	glEnd();
	
}

void box()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(25, 200, 75, 230);
}

void shooter()
{
	glBegin(GL_LINES);
	glVertex2f(50, 230);
	glVertex2f(50, 300);
	glEnd();
}


void cloud1()
{
	float theta;

	//GLfloat angle;
	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(200 + 50 * cos(theta) / 2, 1000 + 50 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(230 + 50 * cos(theta) / 2, 990 + 50 * sin(theta) / 2);
	}
	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(240 + 50 * cos(theta) / 2, 1010 + 50 * sin(theta) / 2);
	}
	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(270 + 50 * cos(theta) / 2, 1000 + 50 * sin(theta) / 2);
	}

	glEnd();
	
}

void cloud2()
{
	float theta;
	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(820 + 45 * cos(theta) / 2, 880 + 45 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(855 + 45 * cos(theta) / 2, 890 + 45 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(855 + 45 * cos(theta) / 2, 870 + 45 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(890 + 45 * cos(theta) / 2, 880 + 45 * sin(theta) / 2);
	}

	glEnd();
	

}

void cloud3()
{
	float theta;
	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(60 + 45 * cos(theta) / 2, 850 + 45 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(95 + 45 * cos(theta) / 2, 860 + 45 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(95 + 45 * cos(theta) / 2, 840 + 45 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(130 + 45 * cos(theta) / 2, 850 + 45 * sin(theta) / 2);
	}

	glEnd();
	

}

void cloud4()
{
	float theta;
	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(500 + 50 * cos(theta) / 2, 920 + 50 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(535 + 50 * cos(theta) / 2, 930 + 50 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(535 + 50 * cos(theta) / 2, 910 + 50 * sin(theta) / 2);
	}

	glEnd();

	glLineWidth(1.5);
	glColor3f(0.86, 0.86, 0.86);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * PI * i / 180;
		glVertex2f(570 + 50 * cos(theta) / 2, 920 + 50 * sin(theta) / 2);
	}

	glEnd();
	

}

void backk(int i, int j)
{
	glColor3f(0, 0.14, 0.4);
	glBegin(GL_QUADS);
	glVertex2f(0.0 + i, 0.0 + j);
	glColor3f(0, 0.14, 0.4);
	glVertex2f(1000.0 + i, 0.0 + j);
	glColor3f(0.6, 0.8, 1);
	glVertex2f(1000.0 + i, -800 + j);
	//glColor3f(0.63, 0.79, 0.97);
	glColor3f(0.6, 0.8, 1);
	glVertex2f(0.0 + i, -800 + j);
	//glColor3f(0, 0.04, 0.2);
	glEnd();

}
void ground(int i, int j)
{
	glBegin(GL_QUADS);
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(0.0 + i, 0.0 + j);
	glVertex2f(1000.0 + i, 0.0 + j);
	glVertex2f(1000.0 + i, 0.0);
	glVertex2f(0.0 + i, 0.0);
	glEnd();

}

void scoredisplay(int x, int y, int space_c, int score)
{
	char text[300];

	strcpy_s(text, "SCORE:");
	glColor3f(0.86, 0.86, 0.86);
	glRasterPos2f(20, 30);

	int len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}

	strcpy_s(text, "LEVEL:");
	glColor3f(0.86, 0.86, 0.86);
	glRasterPos2f(780, 30);

	 len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}

	GLvoid* font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;

	glRasterPos2f(880, 30);
	glutBitmapCharacter(font_style1, 48 + flag);
	
	int j = 0, p, k;
	

	p = score;
	j = 0;
	k = 0;
	while (p > 9)
	{
		k = p % 10;
		glRasterPos2f((x - (j * space_c)), y);
		glutBitmapCharacter(font_style1, 48 + k);
		j++;
		p /= 10;
	}
	glRasterPos2f((x - (j * space_c)), y);
	glutBitmapCharacter(font_style1, 48 + p);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ground(0, 1000);
	backk(0, 1000);
	sun();
	cloud1();
	cloud2();
	cloud3();
	cloud4();
	StartingText();
	pop(20,30);


	glutSwapBuffers();
	glutPostRedisplay();
}

float balloonY = 830, balloonX = 150, bal2Y = 830, bal2X = 450, bal3Y = 830, bal3X = 800, bal4Y = 830, bal4X = 650, boxX = 0, boxY = 0, shooterX = 0, shooterY = 0;
float spin = 0;
int score1 = 0, miss1 = 0;
int score2 = 0, miss2 = 0;
int score3 = 0, miss3 = 0;

int rand(), r, c1, c2;
int x = 500;
int y = 1, z = 1;

void rectangle1()
{

	x++;
	glColor3f(y, z, 0);
	glRectf(25, 80, 75, 110);

	if (x > 500)
	{
		c1 = rand() % 2;
		if (c1 == 0)
		{
			y = 1;
			z = 1;
		}
		if (c1 == 1)
		{
			y = 1;
			z = 0;
		}

		x = 0;
	}
	
}

void rectangle2()
{

	x++;
	glColor3f(y, z, 0);
	glRectf(25, 80, 75, 110);

	if (x > 500)
	{
		c2 = rand() % 3;
		if (c2 == 0)
		{
			y = 1;
			z = 1;
		}
		if (c2 == 1)
		{
			y = 1;
			z = 0;

		}
		if (c2 == 2)
		{
			y = 0;
			z = 1;
		}

		x = 0;
	}
	
}

void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	balloonY -= 0.28;
	bal2Y -= 0.30;
	bal3Y -= 0.32;


	float sX1 = shooterX - 30;
	float sX2 = shooterX + 30;
	float sY1 = shooterY + 170;
	float sY2 = shooterY + 250;

	if (balloonY < 170)
	{
		balloonY = 830;
		r = rand() % 4;
		if (r == 0)
			balloonX = 195;
		if (r == 1)
			balloonX = 375;
		if (r == 2)
			balloonX = 555;
		if (r == 3)
			balloonX = 720;

		miss1++;
	}

	if ((balloonX >= sX1 && balloonX <= sX2 && balloonY >= sY1 && balloonY <= sY2))
	{
	
		pop(balloonX,balloonY);

		balloonY = 830;
		r = rand() % 4;
		if (r == 0)
			balloonX = 195;
		if (r == 1)
			balloonX = 375;
		if (r == 2)
			balloonX = 555;
		if (r == 3)
			balloonX = 720;

		score1++;
	}

	if (bal2Y < 170)
	{
		bal2Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal2X = 105;
		if (r == 1)
			bal2X = 240;
		if (r == 2)
			bal2X = 420;
		if (r == 3)
			bal2X = 600;

		miss1++;
	}

	if ((bal2X >= sX1 && bal2X <= sX2 && bal2Y >= sY1 && bal2Y <= sY2))
	{
		bal2Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal2X = 105;
		if (r == 1)
			bal2X = 240;
		if (r == 2)
			bal2X = 420;
		if (r == 3)
			bal2X = 600;

		score1++;
	}

	if (bal3Y < 170)
	{
		bal3Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal3X = 150;
		if (r == 1)
			bal3X = 300;
		if (r == 2)
			bal3X = 480;
		if (r == 3)
			bal3X = 840;

		miss1++;
	}

	if ((bal3X >= sX1 && bal3X <= sX2 && bal3Y >= sY1 && bal3Y <= sY2))
	{
		bal3Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal3X = 150;
		if (r == 1)
			bal3X = 300;
		if (r == 2)
			bal3X = 480;
		if (r == 3)
			bal3X = 840;

		score1++;
	}

		

	ground(0, 1000);
	backk(0, 1000);
	sun();
	cloud1();
	cloud2();
	cloud3();
	cloud4();

	glPushMatrix();
	scoredisplay(135, 30, 15, score1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(boxX, boxY, 0);
	box();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(shooterX, shooterY, 0);
	glRotatef(spin, 0, 0, 1);
	shooter();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(balloonX, balloonY, 0);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bal2X, bal2Y, 0);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bal3X, bal3Y, 0);
	balloon();
	glPopMatrix();


	glutSwapBuffers();
	//glutPostRedisplay();

	if (score1 == 5)
		glutDisplayFunc(display2);
	glutPostRedisplay();

	if(miss1==5)
		glutDisplayFunc(displayend);
	glutPostRedisplay();

}

void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	flag = 2;
	balloonY -= 0.32;
	bal2Y -= 0.34;
	bal3Y -= 0.36;
	bal4Y -= 0.33;


	float sX1 = shooterX - 30;
	float sX2 = shooterX + 30;
	float sY1 = shooterY + 170;
	float sY2 = shooterY + 250;

	if (balloonY < 170)
	{
		balloonY = 830;
		r = rand() % 4;
		if (r == 0)
			balloonX = 195;
		if (r == 1)
			balloonX = 375;
		if (r == 2)
			balloonX = 555;
		if (r == 3)
			balloonX = 720;

		miss2++;
	}

	if ((balloonX >= sX1 && balloonX <= sX2 && balloonY >= sY1 && balloonY <= sY2))
	{
		balloonY = 830;
		r = rand() % 4;
		if (r == 0)
			balloonX = 195;
		if (r == 1)
			balloonX = 375;
		if (r == 2)
			balloonX = 555;
		if (r == 3)
			balloonX = 720;

		if(y==1 && z==1)
			score2++;
		if (y == 1 && z == 0)
			score2--;
	}

	if (bal2Y < 170)
	{
		bal2Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal2X = 105;
		if (r == 1)
			bal2X = 240;
		if (r == 2)
			bal2X = 420;
		if (r == 3)
			bal2X = 600;

		miss2++;
	}

	if ((bal2X >= sX1 && bal2X <= sX2 && bal2Y >= sY1 && bal2Y <= sY2))
	{
		bal2Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal2X = 105;
		if (r == 1)
			bal2X = 240;
		if (r == 2)
			bal2X = 420;
		if (r == 3)
			bal2X = 600;

		if (y == 1 && z == 1)
			score2--;
		if (y == 1 && z == 0)
			score2++;
	}

	if (bal3Y < 170)
	{
		bal3Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal3X = 150;
		if (r == 1)
			bal3X = 300;
		if (r == 2)
			bal3X = 480;
		if (r == 3)
			bal3X = 840;

		miss2++;
	}

	if ((bal3X >= sX1 && bal3X <= sX2 && bal3Y >= sY1 && bal3Y <= sY2))
	{
		bal3Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal3X = 150;
		if (r == 1)
			bal3X = 300;
		if (r == 2)
			bal3X = 480;
		if (r == 3)
			bal3X = 840;

		if (y == 1 && z == 1)
			score2++;
		if (y == 1 && z == 0)
			score2--;
	}

	if (bal4Y < 170)
	{
		bal4Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal4X = 30;
		if (r == 1)
			bal4X = 180;
		if (r == 2)
			bal4X = 465;
		if (r == 3)
			bal4X = 630;

		miss2++;
	}

	if ((bal4X >= sX1 && bal4X <= sX2 && bal4Y >= sY1 && bal4Y <= sY2))
	{
		bal4Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal4X = 30;
		if (r == 1)
			bal4X = 180;
		if (r == 2)
			bal4X = 465;
		if (r == 3)
			bal4X = 630;

		if (y == 1 && z == 1)
			score2--;
		if (y == 1 && z == 0)
			score2++;
	}



	ground(0, 1000);
	backk(0, 1000);
	sun();
	cloud1();
	cloud2();
	cloud3();
	cloud4();

	glPushMatrix();
	scoredisplay(135, 30, 15, score2);
	glPopMatrix();

	glPushMatrix();
	rectangle1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(boxX, boxY, 0);
	box();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(shooterX, shooterY, 0);
	glRotatef(spin, 0, 0, 1);
	shooter();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(balloonX, balloonY, 0);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bal2X, bal2Y, 0);
	balloon2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bal3X, bal3Y, 0);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bal4X, bal4Y, 0);
	balloon2();
	glPopMatrix();


	glutSwapBuffers();
	//glutPostRedisplay();

	if (score2 == 5)
		glutDisplayFunc(display3);
	glutPostRedisplay();

	if (score2 == -1)
		glutDisplayFunc(displayend);
	glutPostRedisplay();

}

void display3(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	flag = 3;

	balloonY -= 0.34;
	bal2Y -= 0.36;
	bal3Y -= 0.38;
	bal4Y -= 0.37;


	float sX1 = shooterX - 30;
	float sX2 = shooterX + 30;
	float sY1 = shooterY + 170;
	float sY2 = shooterY + 250;

	if (balloonY < 170)
	{
		balloonY = 830;
		r = rand() % 4;
		if (r == 0)
			balloonX = 195;
		if (r == 1)
			balloonX = 375;
		if (r == 2)
			balloonX = 555;
		if (r == 3)
			balloonX = 720;

		miss3++;
	}

	if ((balloonX >= sX1 && balloonX <= sX2 && balloonY >= sY1 && balloonY <= sY2))
	{
		balloonY = 830;
		r = rand() % 4;
		if (r == 0)
			balloonX = 195;
		if (r == 1)
			balloonX = 375;
		if (r == 2)
			balloonX = 555;
		if (r == 3)
			balloonX = 720;

		if (y == 1 && z == 1)
			score3++;
		if ((y == 1 && z == 0) || (y==0&&z==1))
			score3--;
	}

	if (bal2Y < 170)
	{
		bal2Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal2X = 105;
		if (r == 1)
			bal2X = 240;
		if (r == 2)
			bal2X = 420;
		if (r == 3)
			bal2X = 600;

		miss3++;
	}

	if ((bal2X >= sX1 && bal2X <= sX2 && bal2Y >= sY1 && bal2Y <= sY2))
	{
		bal2Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal2X = 105;
		if (r == 1)
			bal2X = 240;
		if (r == 2)
			bal2X = 420;
		if (r == 3)
			bal2X = 600;

		if (y == 0 && z == 1)
			score3++;
		if ((y == 1 && z == 0) || (y == 1 && z == 1))
			score3--;
	}

	if (bal3Y < 170)
	{
		bal3Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal3X = 150;
		if (r == 1)
			bal3X = 300;
		if (r == 2)
			bal3X = 480;
		if (r == 3)
			bal3X = 840;

		miss3++;
	}

	if ((bal3X >= sX1 && bal3X <= sX2 && bal3Y >= sY1 && bal3Y <= sY2))
	{
		bal3Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal3X = 150;
		if (r == 1)
			bal3X = 300;
		if (r == 2)
			bal3X = 480;
		if (r == 3)
			bal3X = 840;

		if (y == 1 && z == 0)
			score3++;
		if ((y == 1 && z == 1) || (y == 0 && z == 1))
			score3--;
	}

	if (bal4Y < 170)
	{
		bal4Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal4X = 30;
		if (r == 1)
			bal4X = 180;
		if (r == 2)
			bal4X = 465;
		if (r == 3)
			bal4X = 630;

		miss3++;
	}

	if ((bal4X >= sX1 && bal4X <= sX2 && bal4Y >= sY1 && bal4Y <= sY2))
	{
		bal4Y = 830;
		r = rand() % 4;
		if (r == 0)
			bal4X = 30;
		if (r == 1)
			bal4X = 180;
		if (r == 2)
			bal4X = 465;
		if (r == 3)
			bal4X = 630;

		if (y == 0 && z == 1)
			score3++;
		if ((y == 1 && z == 0) || (y == 1 && z == 1))
			score3--;
	}



	ground(0, 1000);
	backk(0, 1000);
	sun();
	cloud1();
	cloud2();
	cloud3();
	cloud4();

	glPushMatrix();
	scoredisplay(135, 30, 15, score3);
	glPopMatrix();

	glPushMatrix();
	rectangle2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(boxX, boxY, 0);
	box();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(shooterX, shooterY, 0);
	glRotatef(spin, 0, 0, 1);
	shooter();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(balloonX, balloonY, 0);
	balloon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bal2X, bal2Y, 0);
	balloon3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bal3X, bal3Y, 0);
	balloon2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bal4X, bal4Y, 0);
	balloon3();
	glPopMatrix();


	glutSwapBuffers();
	//glutPostRedisplay();

	if (score3 == 5)
		glutDisplayFunc(displayend);
	glutPostRedisplay();


	if (score3 == -1)
		glutDisplayFunc(displayend);
	glutPostRedisplay();


}

void endtext(void)
{
	char text[300];

	strcpy_s(text, "GAME OVER");
	glColor3f(1, 0, 0);
	glRasterPos2f(400, 500);

	int len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}
}

void displayend(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ground(0, 1000);
	backk(0, 1000);
	sun();
	cloud1();
	cloud2();
	cloud3();
	cloud4();
	endtext();

	glutSwapBuffers();
	glutPostRedisplay();
}

void skeys(int key, int x, int y) 
{
	if (key == GLUT_KEY_LEFT)
	{
		boxX -= 24;
		shooterX -= 24;
	}
	

	if (key == GLUT_KEY_RIGHT)
	{
		boxX += 24;
		shooterX += 24;
	}
	
}

void keys(unsigned char key, int x, int y)
{
	if (key == 's' || key=='S')
	{
		glutDisplayFunc(display1);
	}
	
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 770);
	glutCreateWindow("BALLOON POP");
	glutDisplayFunc(display);
	glutSpecialFunc(skeys);
	glutKeyboardFunc(keys);
	myinit();
	glutInitWindowPosition(100, 100);
	glutMainLoop();
}