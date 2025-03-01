#pragma once
//头文件
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
//宏定义
#define MAP_HEIGHT 20
#define MAP_WIDTH 40
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define MAX_OBSTACLES 5
//结构体
typedef struct
{
	int x;
	int y;
}Food, Snakenode,OBST;

typedef struct
{
	Snakenode snakeNode[1000];
	int length;
	int speed;
}Snake;
typedef struct
{
	int socre;
	char name[14];
}history;

void GotoXY(int, int);
void Hide();
int Menu();
void Help();
void About();
void rink();
void InitMap();
void PrintFood();
void PrintSuperFood();
void PrintOBST();
int MoveSnake();
int IsCorrect();
void SpeedControl();
void savehistory();
void openhistory();
