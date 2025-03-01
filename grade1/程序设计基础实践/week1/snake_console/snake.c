#include "snake.h"

Snake snake;
Food food,superfood;
OBST obst[MAX_OBSTACLES];
history user[1000] = {0};

char now_Dir = RIGHT;
char direction = RIGHT;
int  historynum = 1;
int cmp(const void* a, const void* b) {
	return ((history*)b)->socre - ((history*)a)->socre;
}
int Menu() {
	GotoXY(40, 12);
	printf("��ӭ����̰����С��Ϸ");
	GotoXY(43, 14);
	printf("1.��ʼ��Ϸ");
	GotoXY(43, 16);
	printf("2.����");
	GotoXY(43, 18);
	printf("3.����");
	GotoXY(43, 20);
	printf("4.���а�");
	GotoXY(43, 22);
	printf("����������˳���Ϸ");
	Hide();
	char ch;
	int result = 0;
	ch = _getch();
	switch (ch) {
	case '1':
		result = 1;
		break;
	case '2':
		result = 2;
		break;
	case '3':
		result = 3;
		break;
	case '4':
		result = 4;
		break;
	}
	system("cls");
	return result;
}
void GotoXY(int x, int y) {
	COORD cor;
	HANDLE hout;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);
}
void Hide() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cor_info = { 1, 0 };
	SetConsoleCursorInfo(hout, &cor_info);
}
void About(){
	GotoXY(43, 12);
	printf("���ݵ��ӿƼ���ѧ-�������ʵ������");
	GotoXY(43, 14);
	printf("̰����");
	GotoXY(43, 16);
	printf("����������ز˵�");
	Hide();
	char ch = _getch();
	system("cls");
}
void Help(){
	GotoXY(43, 12);
	printf("w ��");
	GotoXY(43, 14);
	printf("s ��");
	GotoXY(43, 16);
	printf("a ��");
	GotoXY(43, 18);
	printf("d ��");
	GotoXY(45, 20);
	printf("����ײ�������ǽ�ڻ� # ʱ��Ϸ����,��ײʱ̰�����ѿ�");
	GotoXY(45, 22);
	printf("�߳Ե� $ ��ʱ����,��ͬ�ַ����������ʲ�ͬ,������̽��");
	GotoXY(45, 24);
	printf("�������˳���Ϸ�����а���ֲ��ᱣ��");
	GotoXY(43, 26);
	printf("����������ز˵�");	
	Hide();
	char ch = _getch();
	system("cls");
}
void rink() {
    qsort(user, 10, sizeof(history), cmp);
	GotoXY(40, 2);
	printf("���а�");
	for (int i = 0; i < 1000; i++) {
		if (user[i].socre == 0) break;
		int t = 2 + 2 * (i + 1);
		GotoXY(40, t);
		printf("%d: %d��       �����¼��ң�%s", i + 1, user[i].socre, user[i].name);
	}
	GotoXY(50, 2);
	printf("����������ز˵�");
	Hide();
	char ch = _getch();
	system("cls");
}

void InitMap() {
	Hide();
	snake.snakeNode[0].x = MAP_WIDTH/2-1;
	snake.snakeNode[0].y = MAP_HEIGHT/2-1;

	GotoXY(snake.snakeNode[0].x, snake.snakeNode[0].y);
	printf("@");

	snake.length = 3;
	snake.speed = 250;
	now_Dir = RIGHT;

	for (int i = 1; i < snake.length; i++)
	{
		snake.snakeNode[i].y = snake.snakeNode[i - 1].y;
		snake.snakeNode[i].x = snake.snakeNode[i - 1].x - 1;
		GotoXY(snake.snakeNode[i].x, snake.snakeNode[i].y);
		printf("o");

	}

	for (int i = 1; i < MAP_HEIGHT-1; i++)
	{
		GotoXY(0, i);
		printf("|");
		GotoXY(MAP_WIDTH-1, i);
		printf("|");
	}

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		GotoXY(i, 0);
		printf("-");
		GotoXY(i, MAP_HEIGHT - 1);
		printf("-");
	}	
	PrintFood();
	PrintSuperFood();
	PrintOBST();
	GotoXY(50, 5);
	printf("��ǰ������0");
}


void PrintFood() {
	int flag = 1;
	while (flag)
	{
		flag = 0;
		food.x = rand() % (MAP_WIDTH - 2) + 1;
		food.y = rand() % (MAP_HEIGHT - 2) + 1;
		for (int k = 0; k < snake.length - 1; k++)
		{
			if ((food.x == snake.snakeNode[k].x && food.y == snake.snakeNode[k].y) || (food.x == superfood.x && food.y == superfood.y))
			{
				flag = 1;
				break;
			}
		}
	}
	GotoXY(food.x, food.y);
	printf("$");
}

void PrintSuperFood() {
	int flag = 1;
	while (flag)
	{
		flag = 0;
		superfood.x = rand() % (MAP_WIDTH - 2) + 1;
		superfood.y = rand() % (MAP_HEIGHT - 2) + 1;
		for (int k = 0; k < snake.length - 1; k++)
		{
			if ((superfood.x == snake.snakeNode[k].x && superfood.y == snake.snakeNode[k].y) || (superfood.x == food.x && superfood.y == food.y))
			{
				flag = 1;
				break;
			}
		}
	}
	GotoXY(superfood.x, superfood.y);
	printf("��");
}


void PrintOBST() {
	int flag;
	for (int i = 0; i < MAX_OBSTACLES; i++) {
		flag = 1;
		while (flag) {
			flag = 0;
			obst[i].x = rand() % (MAP_WIDTH - 2) + 1;
			obst[i].y = rand() % (MAP_HEIGHT - 2) + 1;
			for (int k = 0; k < snake.length - 1; k++) {
				if ((obst[i].x == snake.snakeNode[k].x && obst[i].y == snake.snakeNode[k].y) ||
					(obst[i].x == food.x && obst[i].y == food.y) ||
					(obst[i].x == superfood.x && obst[i].y == superfood.y)) {
					flag = 1;
					break;
				}
			}
		}
		GotoXY(obst[i].x, obst[i].y);
		printf("#");
	}
}

int MoveSnake() {
	Snakenode temp;
	int flag = 0;
	int flag1 = 0;
	temp= snake.snakeNode[snake.length - 1];
	for (int i = snake.length - 1; i > 0; i--)
	{
		snake.snakeNode[i] = snake.snakeNode[i - 1];
	}
	if (_kbhit())
	{
		direction = _getch();
		switch (direction)
		{
		case UP:
			if (now_Dir != DOWN)
				now_Dir = direction;
			break;
		case DOWN:
			if (now_Dir != UP)
				now_Dir = direction;
			break;
		case LEFT:
			if (now_Dir != RIGHT)
				now_Dir = direction;
			break;
		case RIGHT:
			if (now_Dir != LEFT)
				now_Dir = direction;
			break;
		}
	}
	switch(now_Dir)
	{
	case UP:
		snake.snakeNode[0].y--;
		break;
	case DOWN:
		snake.snakeNode[0].y++;
		break;
	case LEFT:
		snake.snakeNode[0].x--;
		break;
	case RIGHT:
		snake.snakeNode[0].x++;
		break;
	}
	GotoXY(snake.snakeNode[0].x, snake.snakeNode[0].y);
	printf("@");
	for (int i = 1; i < snake.length; i++) {
		GotoXY(snake.snakeNode[i].x, snake.snakeNode[i].y);
		printf("o");
	}
	if (snake.snakeNode[0].x == food.x && snake.snakeNode[0].y == food.y)
	{ 
		snake.length++;
		flag = 1;	
		snake.snakeNode[snake.length - 1] = temp;
	
	}
	if (snake.snakeNode[0].x == superfood.x && snake.snakeNode[0].y == superfood.y)
	{
		snake.length+=2;
		flag1 = 1;
		snake.snakeNode[snake.length - 1] = temp;
	
	}
	if (!flag)
	{
		GotoXY(temp.x, temp.y);
		printf(" ");
	}
	else
	{
		PrintFood();
		GotoXY(50, 5);
		printf("��ǰ������%d", snake.length - 3);
	}
	if (!flag1)
	{
		GotoXY(temp.x, temp.y);
		printf(" ");
	}
	else
	{
		PrintSuperFood();
		GotoXY(50, 5);
		printf("��ǰ������%d", snake.length - 3);
	}
	
	if (!IsCorrect())
	{
		system("cls");
		GotoXY(40, 14);
		printf("���յ÷֣�%d��", snake.length - 3);
		int tmp = snake.length - 3;
		historynum++;
		user[historynum].socre = tmp;
		if (historynum > 1000) {
			if (tmp > user[999].socre) {
				user[historynum].socre = tmp;
			}
		}
		GotoXY(40, 16);
		printf("������");
		GotoXY(40, 18);
		printf("����������ز˵�");
		GotoXY(40, 20);
		printf("�����뱾����Ϸ�����ǳƣ�(�ַ���С��14)\n");
		GotoXY(40, 24);
			for (int i = 0; i < 16; i++)
				printf("#");
		GotoXY(40, 25);
		printf("#");
		GotoXY(55, 25);
		printf("#");
		GotoXY(40, 26);
		for (int i = 0; i < 16; i++)
			printf("#");
		GotoXY(43, 25);
		while(1){
			
			if (historynum < 1000) {
				if (scanf("%14s", user[historynum].name) != EOF) {
					break;
				}
			}

		}
		GotoXY(43, 27);
		printf("�ǳ�������");
		char c = _getch();
		system("cls");
		return 0;
	}
	SpeedControl();
	Sleep(snake.speed);
	return 1;
}

int IsCorrect() {
	if (snake.snakeNode[0].x == 0 || snake.snakeNode[0].x == MAP_WIDTH -1 || snake.snakeNode[0].y == 0 || snake.snakeNode[0].y == MAP_HEIGHT - 1)
		return 0;
	for (int i = 0; i < MAX_OBSTACLES; i++) {
		if (snake.snakeNode[0].x == obst[i].x &&
			snake.snakeNode[0].y == obst[i].y)
			return 0;
	}
	for (int i = 1; i < snake.length; i++)
	{
		if (snake.snakeNode[0].x == snake.snakeNode[i].x && snake.snakeNode[0].y == snake.snakeNode[i].y) {
			snake.length = i;
			GotoXY(50, 5);
			printf("��ǰ������    ");

		}
	}
	return 1;
}

void SpeedControl() {
	switch (snake.length) {
	case 6:
		snake.speed = 200;
		break;
	case 9:
		snake.speed = 180;
		break;
	case 12:
		snake.speed = 160;
		break;
	case 15:
		snake.speed = 140;
		break;
	case 18:
		snake.speed = 120;
		break;
	case 21:
		snake.speed = 100;
		break;
	case 24:
		snake.speed = 80;
		break;
	case 27:
		snake.speed = 60;
		break;
	case 30:
		snake.speed = 40;
		break;
	default:
		break;
	}
}

void savehistory() {
	FILE* fp = fopen("history.txt", "w");
	if (fp == NULL) {
		printf("���а��¼����ʧ�ܣ�");
		return;
	}
	for (int i = 0; i < 1000 && user[i].socre != 0; i++) {
		fprintf(fp, "%d %s\n", user[i].socre, user[i].name);
	}
	fclose(fp);
}

void openhistory() {
	FILE* fp = fopen("history.txt", "r");
	if (fp == NULL) {
		printf("���а��¼��ʧ�ܻ��ļ������ڡ�\n");
		return;
	}
	for (int i = 0; i < 1000; i++) {
		if (fscanf(fp, "%d %s", &user[i].socre, user[i].name) == EOF)
			break;
	}
	fclose(fp);
}
