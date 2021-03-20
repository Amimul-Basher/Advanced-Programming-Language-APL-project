# include "iGraphics.h"

int ballX[10];
int ballY[10];

int ballDX[10];
int ballDY[10];

int ballStates[10];

int score = 0;
char scoreText[100];

int gameOver = 0;
int maxSpeed = 1;

int onGamePage = 1;

void menuPage()
{
	iClear();
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, 600, 600);
	iSetColor(0, 0, 255);
	iText(100, 500, "Easy");
	iText(100, 400, "Medium");
	iText(100, 300, "Hard");
	iText(100, 200, "Exit");
}

void gamePage()
{
	iClear();
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, 600, 600);
	for (int i = 0; i<10; i++)
	{
		if (ballStates[i] == 0)
			iShowBMP(ballX[i], ballY[i], "ball.bmp");
		else if (ballStates[i] == 1)
			iShowBMP(ballX[i], ballY[i], "keeper.bmp");
	}
	iSetColor(255, 0, 0);
	iText(0, 590, "Score:");
	_itoa_s(score, scoreText, 10);
	iText(50, 590, scoreText);

	if (gameOver == 1)
		iText(50, 50, "The game is over! Click to start Again.");
}

void iDraw()
{
	if (onGamePage == 1)
		gamePage();
	else
		menuPage();
}

void animate()
{
	int ballsMoving = 0;
	for (int i = 0; i<10; i++)
	{
		ballX[i] += ballDX[i];
		ballY[i] += ballDY[i];
		if (ballX[i] <= 0 || ballX[i] >= 600 || ballY[i] <= 0 || ballY[i] >= 600)
			ballStates[i] = 2;
		if (ballStates[i] == 0)
			ballsMoving++;
	}
	if (ballsMoving == 0)
		gameOver = 1;
}

void iMouseMove(int mx, int my){
}
int isMouseOnTheBall(int mx, int my, int i)
{
	if (mx >= ballX[i] && mx <= ballX[i] + 64 && my >= ballY[i] && my <= ballY[i] + 64)
		return 1;
	else
		return 0;
}

void initializeGame(int speed)
{
	maxSpeed = speed;
	for (int i = 0; i<10; i++)
	{
		ballX[i] = rand() % (600 - 64);
		ballY[i] = rand() % (600 - 64);
		ballDX[i] = (rand() % maxSpeed + 1)*(rand() % 2 == 0 ? -1 : 1);
		ballDY[i] = (rand() % maxSpeed + 1)*(rand() % 2 == 0 ? -1 : 1);
		ballStates[i] = 0;
		score = 0;
	}
	gameOver = 0;
	onGamePage = 1;

}

void iMouse(int button, int state, int mx, int my)
{
	for (int i = 0; i<10; i++)
		if (ballStates[i] == 0 && state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && isMouseOnTheBall(mx, my, i))
		{
			score++;
			ballStates[i] = 1;
			ballDX[i] = 0;
			ballDY[i] = 0;
		}
	if (onGamePage == 1 && gameOver == 1 && state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && mx >= 50 && my >= 50 && mx <= 380 && my <= 60)
		onGamePage = 0;

	if (onGamePage == 0 && gameOver == 1 && state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && mx >= 100 && my >= 500 && mx <= 200 && my <= 510)
	{
		//  initialize the game and start it with maxSpeed = 1 (lowest == easy)
		initializeGame(1);
	}
	if (onGamePage == 0 && gameOver == 1 && state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && mx >= 100 && my >= 400 && mx <= 200 && my <= 410)
	{
		//  initialize the game and start it with maxSpeed = 1 (lowest == easy)
		initializeGame(3);
	}
	if (onGamePage == 0 && gameOver == 1 && state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && mx >= 100 && my >= 300 && mx <= 200 && my <= 310)
	{
		//  initialize the game and start it with maxSpeed = 1 (lowest == easy)
		initializeGame(5);
	}
	if (onGamePage == 0 && gameOver == 1 && state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && mx >= 100 && my >= 200 && mx <= 200 && my <= 210)
	{
		//  initialize the game and start it with maxSpeed = 1 (lowest == easy)
		exit(0);
	}
}
void iKeyboard(unsigned char key){
}
void iSpecialKeyboard(unsigned char key){
}
int main()
{
	//place your own initialization codes here.
	/*
	randomly set ball starting positions and dx,dy
	*/

	for (int i = 0; i<10; i++)
	{
		ballX[i] = rand() % (600 - 64);
		ballY[i] = rand() % (600 - 64);
		ballDX[i] = (rand() % maxSpeed + 1)*(rand() % 2 == 0 ? -1 : 1);
		ballDY[i] = (rand() % maxSpeed + 1)*(rand() % 2 == 0 ? -1 : 1);
	}

	iSetTimer(5, animate);
	iInitialize(600, 600, "Graphics Extended");
	return 0;
}