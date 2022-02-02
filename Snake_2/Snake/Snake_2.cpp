#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

const int u_l_c = 201;//������� ����� ����
const int l_l_c = 200;//������ ����� ����
const int u_r_c = 187;//������ ������� ����
const int l_r_c = 188;//������ ������ ����
const int h_border = 205;//�������������� �������
const int v_border = 186;//������������ �������
const int width = 30;//������ ����
const int height = 20;//������ ����
const char snake = 'S';//������
const int diamond = 4;//��������
const int winner_score = 6;//����������� ���������� ����� ��� ������

//���������� ������
int x_snake;
int y_snake;

//���������� ���������
int x_diamond;
int y_diamond;

bool game_over = false;//������� ������ �� ����
char drive = 'x';//������������� �����������
int timer = 600;//������
int score = 0;//������������ ����

void rulesGame()
{
	using namespace std;
	cout << "w - up, s - down, a - left, d - reight, q - exit.\n";
	cout << "Time game.\n";
	cout << "You win if you collect 6 crystals.\n\n";
}

void setupSnake()
{
	x_snake = width / 2;
	y_snake = height / 2;
}

void setupDiamond()
{
	x_diamond = 1 + rand() % (width - 2);
	y_diamond = 1 + rand() % (height - 2);
}

void printField()
{
	using namespace std;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << static_cast<char>(u_l_c);
			}
			else if (i == height - 1 && j == 0)
			{
				cout << static_cast<char>(l_l_c);
			}
			else if (i == 0 && j == width - 1)
			{
				cout << static_cast<char>(u_r_c);
			}
			else if (i == height - 1 && j == width - 1)
			{
				cout << static_cast<char>(l_r_c);
			}
			else if (i == 0 || i == height - 1)
			{
				cout << static_cast<char>(h_border);
			}
			else if (j == 0 || j == width - 1)
			{
				cout << static_cast<char>(v_border);
			}
			else if (i == y_snake && j == x_snake)
			{
				cout << snake;
			}
			else if (i == y_diamond && j == x_diamond)
			{
				cout << static_cast<char>(diamond);
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
	cout << "SCORE: " << score << endl; 
	cout << "TIME: ";
	--timer;
	if (timer % 10 == 0)
	{
		cout << timer / 10 << endl;
	}
	cout << endl;
}

void snakeDrive()
{
	char button;
	if (x_snake > 0 && x_snake < width - 1 && y_snake > 0 && y_snake < height - 1)
	{
		if (_kbhit())
		{
			button = _getch();
			switch (button)
			{
			case 'w':
			case 'W':
				drive = 'u';
				break;
			case 's':
			case 'S':
				drive = 'd';
				break;
			case 'a':
			case 'A':
				drive = 'l';
				break;
			case 'd':
			case 'D':
				drive = 'r';
				break;
			case 'q':
			case 'Q':
				game_over = true;
				break;
			}
		}
	}
}

void resultGame()
{
	if (x_snake == x_diamond && y_snake == y_diamond)
	{
		++score;
		x_diamond = 1 + rand() % (width - 2);
		y_diamond = 1 + rand() % (height - 2);
	}
}

bool gameOver(int score)
{
	if (timer == 0)
	{
		game_over = true;
		return game_over;
	}
	if (score == winner_score)
	{
		game_over = true;
		return game_over;
	}
}

void winner()
{
	if (score == winner_score)
	{
		std::cout << "You WIN!!!\n";
	}
	else
	{
		std::cout << "You LOSE!!!\n";
	}
}

void xSnakePlus()
{
	x_snake++;
}

void xSnakeMinus()
{
	x_snake--;
}

void ySnakePlus()
{
	y_snake++;
}

void ySnakeMinus()
{
	y_snake--;
}

void border()
{
	if (y_snake == 0)
	{
		y_snake = height - 1;
	}
	else if (y_snake == height-1)
	{
		y_snake = 0;
	}
	else if (x_snake == 0)
	{
		x_snake = width - 1;
	}
	else if (x_snake == width - 1)
	{
		x_snake = 0;
	}
}

int main()
{
	srand(time(NULL));
	setupSnake();
	setupDiamond();
	while (!game_over)
	{
		system("cls");
		rulesGame();
		printField();
		snakeDrive();
		if (drive == 'u')
		{
			ySnakeMinus();
		}
		else if (drive == 'd')
		{
			ySnakePlus();
		}
		else if (drive == 'l')
		{
			xSnakeMinus();
		}
		else if (drive == 'r')
		{
			xSnakePlus();
		}
		border();
		gameOver(score);
		resultGame();
		Sleep(20);
	}
	winner();
	system("pause");

	return 0;
}