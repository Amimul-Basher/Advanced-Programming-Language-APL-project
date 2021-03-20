# include "iGraphics.h"
#define Sp 5
#define JUMPHEIGHT 160


#define BEENUMBER  10

int point = 0;
int posx, posy; // to check the mouse position

void beeMovement();
void scoreRecord();

int bulletSp = Sp;
int EMOVEY = 1;
int EMOVEX = 1;


int level = 0;
int score = 0;
char scoretext[100];
char highscoretext[100];
int max = 0;


int mposx = 0, mposy = 0;
int i = 0;
int j = 0;
int screenwidth = 1200;
int screenheight = 600;
int stagepos_x = 300;
int stagepos_y = 200;
int homeScreen_state = 0;

//coins
char coin[2][40] = { "coin.bmp", "coin 2.bmp" };
int coinIndex = 0;
int coinState = 0;
bool coin1 = true;
bool coin2 = true;
bool coin3 = true;
bool coin4 = true;

// hero

int heropos_x = 50;
int heropos_y = 60;
char hero_movef[12][60] = { "move1.bmp", "move2.bmp", "move3.bmp", "move4.bmp", "move5.bmp", "move6.bmp", "move7.bmp", "move8.bmp", "move9.bmp", "move10.bmp", "move11.bmp", "move last.bmp" };
char hero_moveb[12][60] = { "move1b.bmp", "move2b.bmp", "move3b.bmp", "move4b.bmp", "move5b.bmp", "move6b.bmp", "move7b.bmp", "move8b.bmp", "move9b.bmp", "move10b.bmp", "move11b.bmp", "move lastb.bmp" };
char hero_standf[15] = { "stand.bmp" };
char hero_standb[15] = { "standb.bmp" };
char gun_shootf[15] = { "shootf.bmp" };
char gun_shootb[15] = { "shootb.bmp" };
char hero_shootf[15] = { "hshootf.bmp" };
char hero_shootb[15] = { "hshootb.bmp" };
char carnivorous_tree[30] = { "carnivorous tree.bmp" };
char gameOver[15] = { "Game over.bmp" };
char levelUp[15] = { "level up.bmp" };


char collision[2][20] = { "collisionf.bmp", "collisionb.bmp" };


char hero_dief[3][60] = { "hero dief 1.bmp", "hero dief 2.bmp", "hero dief 3.bmp" };
char hero_dieb[3][60] = { "hero dieb 1.bmp", "hero dieb 2.bmp", "hero dieb 3.bmp" };
int herodie_index = 0;
int herodie_state = 0;
// enemy bee

char bee_movef[2][20] = { "bee front 1.bmp", "bee front 2.bmp" };
char bee_moveb[2][20] = { "bee back 1.bmp", "bee back 2.bmp" };

struct rec{
	int beepos_x;
	int beepos_y;
	int beeIndex;
	bool beeExistence = true;
	bool beeMoveF = true;
	bool beeMoveB = true;
};
rec bee[BEENUMBER];
int beeState = 0;

char heroJumpf[2][15] = { "jumpupf.bmp", "jumpdownf.bmp" };
char heroJumpb[2][15] = { "jumpupb.bmp", "jumpdownb.bmp" };
int jumpIndex = 0;
int jumpstate = 0;
int jumppos_y = 0;
bool jump = false;
bool jumpup = false;
bool game_over = false;
bool game_start = false;
bool level_up = false;
bool high_score = false;

int heroIndex = 0;
int standstate = 0;


bool key_right = true;
bool key_left = true;
bool standingf = true;
bool standingb = true;
bool shootf = false;
bool shootb = false;
bool bullet_movef = false;
bool bullet_moveb = false;
int bulletMoveState = 0;
bool home_screen = true;
bool hero = true;
bool heroDie = false;

// bullet

int bulletposf_x;
int bulletposf_y;
int bulletposb_x;
int bulletposb_y;

// bomb
int bombpos_x = 0;
int bombpos_y = 0;
bool bomb = false;
int bombState = 0;
char bomb_blast[7][40] = { "bomb 1.bmp", "bomb 2.bmp", "bomb 3.bmp", "bomb 4.bmp", "bomb 5.bmp", "bomb 6.bmp", "bomb 7.bmp" };
int bombIndex = 0;



void display(){

	iShowBMP(0, 0, "Background.bmp");

	iShowBMP2(500, 190, "carnivorous tree.bmp", 0);
	iShowBMP2(0, 270, "stage small.bmp", 0);        // 350 * 50
	iShowBMP2(370, 120, "stage small.bmp", 0);     // 200 * 80
	iShowBMP2(590, 250, "stage mini.bmp", 0);     // 150 * 100
	iShowBMP2(900, 300, "stage big.bmp", 0);     // 300 * 50
	iShowBMP2(750, 120, "stage small.bmp", 0);
	iShowBMP2(10, 2, "beekilled.bmp", 0);
}



void coinpos(){
	if (coin1)
		iShowBMP2(90, 420, coin[coinIndex], 0);
	if (coin2)
		iShowBMP2(430, 270, coin[coinIndex], 0);
	if (coin3)
		iShowBMP2(650, 420, coin[coinIndex], 0);
	if (coin4)
		iShowBMP2(830, 270, coin[coinIndex], 0);
}



void iDraw()
{
	if (home_screen){
		iClear();
		iShowBMP2(0, 0, "home_final.bmp", 0);
	}
	else if (game_start)
	{
		iClear();
		display();
		iShowBMP2(1150, 5, "back to home.bmp", 0);
		iSetColor(255, 255, 255);
		_itoa(score, scoretext, 10);
		iText(70, 10, scoretext, GLUT_BITMAP_TIMES_ROMAN_24);
		
		
		coinpos();
		coinState++;
		if (coinState > 10)
			coinState = 0;
		if (coinState == 10)
			coinIndex++;
		if (coinIndex > 1)
			coinIndex = 0;
		
		if (90 > heropos_x + 10 && 90 < heropos_x + 50 && 420 > heropos_y + 5 && 420 < heropos_y + 70 && coin1)
		{
			coin1 = false;
			point += 5;
		}
		if (430 > heropos_x + 10 && 430 < heropos_x + 50 && 270 > heropos_y + 5 && 270 < heropos_y + 70 && coin2)
		{
			coin2 = false;
			point += 5;
		}
		if (650 > heropos_x + 10 && 650 < heropos_x + 50 && 420 > heropos_y + 5 && 420 < heropos_y + 70 && coin3)
		{
			coin3 = false;
			point += 5;
		}
		if (830 > heropos_x + 10 && 830 < heropos_x + 50 && 270 > heropos_y + 5 && 270 < heropos_y + 70 && coin4)
		{
			coin4 = false;
			point += 5;
		}

		// bomb blasting

		if (bomb && !hero)
		{
			bombState++;
			bombpos_x = heropos_x - 20;
			bombpos_y = heropos_y - 20;
			heroDie = true;
			if (bombState >= 150)
			{
				bombState = 0;
				game_start = false;
				game_over = true;
				bomb = false;
				home_screen = false;
				hero = false;
			}
			if (bombState == 8 || bombState == 16 || bombState == 24 || bombState == 32 || bombState == 40 || bombState == 48 || bombState == 56){
				bombIndex++;
				if (bombIndex > 6)
					bombIndex = 0;
			}
			iShowBMP2(bombpos_x, bombpos_y, bomb_blast[bombIndex], 0);
		}

		// bomb range

		if (hero){
		
//bullet
			if (bullet_movef){
				
				iShowBMP2(bulletposf_x, bulletposf_y, gun_shootf, 0);
				bulletposf_x += bulletSp;
				if (bulletposf_x > 1200){
					bullet_movef = false;
					shootf = false;
				}
			}
			else if (bullet_moveb)
			{
				iShowBMP2(bulletposb_x, bulletposb_y, gun_shootb, 0);
				bulletposb_x -= bulletSp;
				if (bulletposb_x < 0){
					bullet_moveb = false;
					shootb = false;
				}
			}

			if (jump)
			{
				if (jumpup && key_right){
					iShowBMP2(heropos_x, jumppos_y, heroJumpf[jumpIndex], 0);
				}
				else if (jumpup && key_left){
					iShowBMP2(heropos_x, jumppos_y, heroJumpb[jumpIndex], 0);
				}
				else if (!jumpup && key_right)
				{
					iShowBMP2(heropos_x, jumppos_y, heroJumpf[jumpIndex], 0);
				}
				else if (!jumpup && key_left)
				{
					iShowBMP2(heropos_x, jumppos_y, heroJumpb[jumpIndex], 0);
				}
			}
			// jump range 
			else
			{

				if (key_right && !standingf && !standingb && !shootf && !shootb && !heroDie){
					iShowBMP2(heropos_x, heropos_y, hero_movef[heroIndex], 0);
					standstate++;
					if (standstate >= 40)
					{
						standstate = 0;
						heroIndex = 0;
						standingf = true;
					}
				}

				else if (key_left && !standingf && !standingb && !shootf && !shootb && !heroDie){

					iShowBMP2(heropos_x, heropos_y, hero_moveb[heroIndex], 0);
					standstate++;
					if (standstate >= 40)
					{
						standstate = 0;
						heroIndex = 0;
						standingb = true;
					}
				}

				else if (standingf && !heroDie)
				{
					iShowBMP2(heropos_x, heropos_y, hero_standf, 0);
					if ((((heropos_x + 25 > 0 && heropos_x < 360 && jumppos_y == 190) || (heropos_x + 25 > 545 && heropos_x < 745 && jumppos_y == 190) || (heropos_x + 25 > 920 && heropos_x < 1200 && jumppos_y == 190) || (heropos_x + 25 > 200 && heropos_x < 590 && jumppos_y == 340) || (heropos_x + 25 > 740 && heropos_x < 900 && jumppos_y == 340)) && jumppos_y >55) || (heropos_x + 25 > 200 && heropos_x < 300 && jumppos_y <= 55))
					{	
						jump = true;
						jumpup = false;
						key_right = false;
					}

				}
				else if (standingb && !heroDie)
				{
					iShowBMP2(heropos_x, heropos_y, hero_standb, 0);
					if ((((heropos_x + 25 > 0 && heropos_x < 360 && jumppos_y == 190) || (heropos_x + 25 > 545 && heropos_x < 745 && jumppos_y == 190) || (heropos_x + 25 > 920 && heropos_x < 1200 && jumppos_y == 190) || (heropos_x + 25 > 200 && heropos_x < 590 && jumppos_y == 340) || (heropos_x + 25 > 740 && heropos_x < 900 && jumppos_y == 340)) && jumppos_y >55) || (heropos_x + 25 > 200 && heropos_x < 300 && jumppos_y <= 55))
					{
						jump = true;
						jumpup = false;
						key_left = false;

					}
				}

				else if (shootf && bullet_movef && !heroDie){                           
					
					iShowBMP2(heropos_x, heropos_y, hero_shootf, 0);
					
					standstate++;
					if (standstate >= 60)
					{                                                          
						standstate = 0;                                        
						heroIndex = 0;                                           
						standingf = true;
						shootf = false;
					}
				}


				else if (shootb && !heroDie){

					
					iShowBMP2(heropos_x, heropos_y, hero_shootb, 0);
					
					standstate++;
					if (standstate >= 60)
					{
						standstate = 0;
						heroIndex = 0;
						standingb = true;
						shootb = false;
					}
				}
			}
		}
		// hero range
		else if (heroDie){
			herodie_state++;
			if (herodie_state >= 150){
				herodie_state = 0;
				heroDie = false;
				game_start = false;
				game_over = true;
				jump = false;

			}
			if (standingf){

				iShowBMP2(heropos_x, heropos_y, hero_dieb[herodie_index], 0);
				if (herodie_state == 20 || herodie_state == 40){
					herodie_index++;
					heropos_x -= 10;
				}
			}
			if (standingb){

				iShowBMP2(heropos_x, heropos_y, hero_dief[herodie_index], 0);
				if (herodie_state == 20 || herodie_state == 40){
					herodie_index++;
					heropos_x += 5;
				}
			}
		}
		//herodie range


		// bee
		beeState++;
		if (beeState > 5)
			beeState = 0;

		for (i = 0; i < BEENUMBER; i++)

		{
			if (beeState == 5)
				bee[i].beeIndex++;
			if (bee[i].beeIndex > 1)
				bee[i].beeIndex = 0;
			//enemy move
			if (bee[i].beepos_x > heropos_x + 30 && bee[i].beepos_y > heropos_y + 35){
				bee[i].beepos_x -= EMOVEX;
				bee[i].beepos_y -= EMOVEY;
			}

			else if (bee[i].beepos_x > heropos_x + 30 && bee[i].beepos_y < heropos_y + 35){
				bee[i].beepos_x -= EMOVEX;
				bee[i].beepos_y += EMOVEY;
			}

			else if (bee[i].beepos_x < heropos_x + 30 && bee[i].beepos_y < heropos_y + 35){
				bee[i].beepos_x += EMOVEX;
				bee[i].beepos_y += EMOVEY;
			}

			else if (bee[i].beepos_x < heropos_x + 30 && bee[i].beepos_y > heropos_y + 35){
				bee[i].beepos_x += EMOVEX;
				bee[i].beepos_y -= EMOVEY;
			}

			else if (bee[i].beepos_x > heropos_x + 30 && bee[i].beepos_y == heropos_y + 35){
				bee[i].beepos_x -= EMOVEX;
			}
			else if (bee[i].beepos_x < heropos_x + 30 && bee[i].beepos_y == heropos_y + 35){
				bee[i].beepos_x += EMOVEX;
			}

			else if (bee[i].beepos_x == heropos_x + 30 && bee[i].beepos_y > heropos_y + 35){
				bee[i].beepos_y -= EMOVEY;
			}
			else if (bee[i].beepos_x == heropos_x + 30 && bee[i].beepos_y < heropos_y + 35){
				bee[i].beepos_y += EMOVEY;
			}

			else if (bee[i].beepos_x == heropos_x + 30 && bee[i].beepos_y == heropos_y + 35 && (bee[i].beeMoveB || bee[i].beeMoveF))
			{
				/*bee[i].beeMoveB = false;                      //unconcious realstic condition
				bee[i].beeMoveF = false;*/						//bomp and hero collision
				bomb = true;                                    //bee[i].beepos_x == heropos_x + 30 && bee[i].beepos_y == heropos_y + 35  to meke the game more easier
				hero = false;                                   // bee[i].beepos_x > heropos_x + 10 && bee[i].beepos_x < heropos_x + 50 && bee[i].beepos_y > heropos_y + 5 && bee[i].beepos_y < heropos_y + 70 && coin1 &&
				heroDie = true;
			}

			if (bulletposf_y + 10 > bee[i].beepos_y && bulletposf_y + 10 < bee[i].beepos_y + 50 && bulletposf_x > bee[i].beepos_x && bulletposf_x < bee[i].beepos_x +50){
				bee[i].beeExistence = false;
				bee[i].beepos_x = 50000;
				bullet_movef = false;
				standingf = true;
				bulletposf_x =1300;
				bulletposf_y = heropos_y + 28;
				score++;
			}

			if (bulletposb_y + 10 > bee[i].beepos_y && bulletposb_y + 10 < bee[i].beepos_y + 50 && bulletposb_x-10 > bee[i].beepos_x && bulletposb_x-10 < bee[i].beepos_x + 50){
				bee[i].beeExistence = false;
				bee[i].beepos_x = 50000;
				bullet_moveb = false;
				standingb = true;
				bulletposb_x = -100;
				bulletposb_y = heropos_y + 28;
				score++;
			}	
			if (score == 10){
				level_up = true;
				level++;

				game_start = false;
				game_over = false;
				bomb = false;
				home_screen = false;
				hero = false;
				EMOVEX ++;
				if (level == 3 || level == 6 || level == 9 || level == 12)
					EMOVEY++;
				bulletSp += 1;
				score = 0;
			}


			if (bee[i].beepos_x < heropos_x &&  bee[i].beeMoveF && bee[i].beeExistence)
				iShowBMP2(bee[i].beepos_x, bee[i].beepos_y, bee_movef[bee[i].beeIndex], 0);
			if (bee[i].beepos_x > heropos_x && bee[i].beeMoveB && bee[i].beeExistence)
				iShowBMP2(bee[i].beepos_x, bee[i].beepos_y, bee_moveb[bee[i].beeIndex], 0);
		}
		// bee range
	}
	// game start
	else if (game_over){
		iClear();
		display();
		iShowBMP2(400, 200, gameOver, 0);
	}
	// game over screen             iShowBMP2(400, 200, "Game over.bmp", 0);


	else if (level_up){
		iClear();
		display();
		iShowBMP2(400, 200, levelUp , 0);
		for (i = 0; i < BEENUMBER; i++){
			bee[i].beeExistence = true;
		}
	}
	
	else if (high_score){
		iClear();
		display();
		iShowBMP2(400, 200, "high score.bmp", 0);
		iSetColor(255, 255, 255);
		_itoa(max, highscoretext, 10);
		iText2(660, 250, highscoretext, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	printf("%d   %d   %d   %d    %d   %d    %d\n\n\n\n", posx, posy, heropos_x, heropos_y, jumppos_y, score, point);
}



void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT)
	{
		key_right = true;
		heropos_x += 5;
		heroIndex++;

		if (heroIndex >= 12)
			heroIndex = 0;
		if (heropos_x > 1200 - 50)
			heropos_x = 0;

		key_left = false;
		standingf = false;
		standingb = false;
		shootf = false;
		shootb = false;
	}

	if (key == GLUT_KEY_LEFT)
	{
		key_left = true;
		heroIndex++;
		heropos_x -= 5;
		if (heropos_x < 0){
			heropos_x = 1200 - 20;
		}
		if (heroIndex >= 12){
			heroIndex = 0;
		}

		key_right = false;
		standingf = false;
		standingb = false;
		shootf = false;
		shootb = false;
	}

	if (key == GLUT_KEY_UP)
	{
		if (!jump)
		{
			jump = true;
			jumpup = true;
			key_left = true;
			key_right = true;
			jumppos_y = heropos_y;
			heropos_y = jumppos_y;
		}
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 's'){
		
		if (standingf || key_right){
			if (!bullet_movef){
				shootf = true;
				shootb = false;
				bullet_movef = true;
				if (bullet_movef){
					bulletposf_x = heropos_x + 88;
					bulletposf_y = heropos_y + 28;
				}
				bullet_moveb = false;
			}
		}
	    else if(standingb || key_left){
			if (!bullet_moveb){
				shootb = true;
				shootf = false;
				bullet_movef = false;
				bullet_moveb = true;
				if (bullet_moveb){
					bulletposb_x = heropos_x;
					bulletposb_y = heropos_y + 28;
				}
			}
		}
		standingf = false;
		standingb = false;
		jump = false;
	}
}

void iMouseMove(int mx, int my)
{
	//nothing to do
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		posx = mx;
		posy = my;
		if (home_screen){
			if (mx > 450 && mx < 750 && my >260 && my < 320)
			{
				game_start = true;
				home_screen = false;
				level_up = false;
				EMOVEX = 1;
				EMOVEY = 1;
				bulletSp = Sp;
				level = 0;
				point = 0;
				score = 0;
				coin1 = true;
				coin2 = true;
				coin3 = true;
				coin4 = true;

			}
			if (mx > 450 && mx < 750 && my >180 && my < 240){
				high_score = true;

				home_screen = false;
				//game_over = false;

				//game_start = false;
				//level_up = false;
			}

			if (mx > 450 && mx < 750 && my >90 && my < 150)
			{
				exit(1);
			}
		}

		if ((game_over || level_up || high_score) && !home_screen && !game_start || level_up)
		{
			if (mx>480 && mx < 570 && my >225 && my < 365){
				home_screen = true;
				game_start = false;
				game_over = false;
				level_up = false;
				heroDie = false;
				heropos_x = 50;
				heropos_y = 60;
				standingf = true;
				heroDie = false;
				hero = true;
				jumppos_y = 50;
				herodie_index = 0;
				bullet_movef = false;
				bullet_moveb = false;
				beeMovement();
				for (i = 0; i < BEENUMBER; i++){
					bee[i].beeExistence = true;
				}

			}
			if (mx>630 && mx < 720 && my >225 && my < 365){      // after game over to choose option 
				coin1 = true;
				coin2 = true;
				coin3 = true;
				coin4 = true;
				home_screen = false;
				game_start = true;
				game_over = false;
				level_up = false;
				heroDie = false;
				heropos_x = 50;
				heropos_y = 60;
				standingf = true;
				heroDie = false;
				hero = true;
				jumppos_y = 50;
				herodie_index = 0;
				bullet_movef = false;
				bullet_moveb = false;
				bulletposb_x = -100;
				bulletposf_x = 1300;
				beeMovement();
				for (i = 0; i < BEENUMBER; i++){
					bee[i].beeExistence = true;
				}
			}
		}
		if (game_start)
			if (mx>1145 && mx < 1185 && my >5 && my < 45){
				game_start = false;
				home_screen = true;
				game_over = false;
				level_up = false;
				beeMovement();	
			}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}


void iPassiveMouseMove(int mx, int my)
{
	mposx = mx;
	mposy = my;
}

void beeMovement(){
	for (i = 0; i < BEENUMBER; i++){
		bee[i].beepos_x = 1250 - rand() % 100;
		bee[i].beepos_y = 100 + rand() % 600;
	}
}

void change_directio_jumping(){

	if (heropos_x + 25 > 485 && heropos_x + 25 < 580 && heropos_y + 20 > 190 && heropos_y + 20 < 220)   // tree trap condition
	{
		hero = false;
		heroDie = true;
		if (key_left)
			standingb = true;
		if (key_right)
			standingf = true;
	}
	if (jump){
		shootf = false;
		shootb = false;

		if (standingf){
			key_left = false;
			key_right = true;
		}
		else if (standingb){
			key_right = false;
			key_left = true;
		}

		if (jumpup){
			jumpIndex = 0;
			jumppos_y += 5;
			if (jumppos_y > heropos_y + JUMPHEIGHT){

				jumpup = false;
				jumpIndex++;
			}
		}
		else if (!jumpup && jumppos_y > 55 || (heropos_x + 25 > 200 && heropos_x < 300 && jumppos_y <= 55))   // hole condition
		{
			jumppos_y -= 5;
			heropos_y = jumppos_y;
			if (jumppos_y < -35)
				jumppos_y = 600;

			if (heropos_x + 25 > 200 && heropos_x < 300)
				jump = true;
			
			else if (jumppos_y < 60 || (heropos_x + 25 >= 370 && heropos_x < 540 && jumppos_y == 190) || (heropos_x + 25 > 0 && heropos_x < 220 && jumppos_y == 340) || (heropos_x + 25 > 590 && heropos_x < 710 && jumppos_y == 340) || (heropos_x + 25 > 750 && heropos_x < 920 && jumppos_y == 190) || (heropos_x + 25 > 900 && heropos_x < 1170 && jumppos_y == 340))
			{
				jump = false;
				heropos_y = jumppos_y;
				if (key_right)
					standingf = true;
				else
					standingb = true;
			}

		}
	}
}

void scoreRecord(){

	int highscore;
	FILE *scoreAdd;
	scoreAdd = fopen("High Score.txt", "r");
	fscanf(scoreAdd, "%d", &highscore);
	point > highscore ? highscore = point : highscore = highscore;
	max = highscore;
	fclose(scoreAdd);
 
	scoreAdd = fopen("High Score.txt", "w");
	fprintf(scoreAdd, "%d" , highscore);
	fclose(scoreAdd);
}

int main()
{
	srand(time(NULL));
	int rand();	
	iSetTimer(17, scoreRecord);
	iSetTimer(17, change_directio_jumping);
	beeMovement();
	scoreRecord();
	iInitialize(screenwidth, screenheight, "Metal slag");
	return 0;
}