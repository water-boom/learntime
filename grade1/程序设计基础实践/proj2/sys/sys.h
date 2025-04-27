
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define STU_NUM 50
#define COURSE_NUM 10
#define NAME_LEN 10
#define POS_X1 35
#define POS_X2 40
#define POS_X3 50
#define POS_X4 65
#define POS_Y 3

typedef struct student {
    long num;
    char name[NAME_LEN];
    float score[COURSE_NUM];
    float sum;
    float aver;
} STU;

typedef struct Node {
    STU data;
    struct Node* next;
} Node;

typedef struct account {
    long id;
    char password[9];
} account;

void SetPosition(int x, int y);
void ClearNode(Node* head);

int Menu(void);
void StudentModel(int m, int n,Node* head,account s[]);
int ManagerModel(void);
int ManageMessage(void);
int SearchMessage(void);
int Other(void);

void InputRecord(int* n, int* m, Node** head,account s[]);   // 输入学生成绩信息，使用链表保存
void AppendRecord(int* n, int* m, Node** head,account s[]);    // 添加学生成绩信息
void DeleteRecord(int* n, int* m, Node** head);      // 删除学生成绩信息 
void SearchByNumber(int n, int m, Node* head);       // 按学号查找学生成绩信息
void SearchByName(int n, int m, Node* head);         // 按姓名查找学生成绩信息
void ModifyRecord(int n, int m, Node* head);         // 修改学生成绩信息


void CalculateScoreOfStudent(int n, int m, Node* head);   // 计算学生的总分和平均分
void CalculateScoreOfCourse(int n, int m, Node* head, float sum[], float aver[]); // 计算各课程总分与平均分
void Caculate(int n, int m, Node* head, float sum[], float aver[]);

void SortbyNum(int n, int m, Node* head);            // 按学号排序
void SortbyName(int n, int m, Node* head);           // 按姓名排序
void SortbyScore(int n, int m, Node* head, int(*cmp)(float a, float b)); // 按成绩排序
int Ascending(float a, float b);                   // 升序比较函数
int Descending(float a, float b);                  // 降序比较函数
void StatisticAnalysis(int n, int m, Node* head);    // 统计分析
int PrintRecord(int n, int m, Node* head);          // 输出学生成绩信息
void WritetoFile(int n, int m, Node* head,account s[]);          // 将学生成绩信息写入文件
int ReadfromFile(int* n, int* m, Node** head, int* first,account s[]); // 从文件中读取学生成绩信息
