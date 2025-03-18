#include "sys.h"

int main() {
    int n = 0;
    int m = 0;
    int first = 1;
    Node* head = NULL;
    float sum[COURSE_NUM], aver[COURSE_NUM];
    account s[STU_NUM];
    account t;

    system("mode con cols=130 lines=60");
    system("color 0E");

    if (ReadfromFile(&n, &m, &head, &first, s) || first) {
        SetPosition(POS_X3, POS_Y);
        printf("尚未输入学生信息或文件打开失败，请先检查！\n");
        system("pause");
    }

    while (1) {
        system("cls");

        char ch;
        char mod = Menu();

        switch (mod) {

        case 0:
            system("cls");
            printf("退出系统！\n");
            exit(0);

        case 1:
                system("cls");
                StudentModel(m,n,head,s);
                system("pause");
            break;

        case 2:
            while (1) {
                system("cls");
                ch = ManagerModel();
                switch (ch) {
                case 0:
                    system("cls");
                    SetPosition(POS_X3, POS_Y);
                    printf("退出管理员登录！\n");
                    Sleep(2000);
                    break;
                case 1:
                    while (1) {
                        system("cls");
                        Caculate(n,m,head, sum,aver);
                        WritetoFile(n, m, head, s);
                        char m_char = ManageMessage();
                        switch (m_char) {
                        case 0:
                            system("cls");
                            SetPosition(POS_X3, POS_Y);
                            printf("返回上级菜单！\n");
                            Sleep(270);
                            break;
                        case 1:
                            system("cls");
                            InputRecord(&n, &m, &head,s);
                            first = 0;
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            if (first) {
                                SetPosition(POS_X3, POS_Y);
                                printf("系统中尚无学生成绩信息，请先输入！\n");
                                system("pause");
                                break;
                            }
                            AppendRecord(&n, &m, &head,s);

                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            if (first) {
                                SetPosition(POS_X3, POS_Y);
                                printf("系统中尚无学生成绩信息，请先输入！\n");
                                system("pause");
                                break;
                            }
                            DeleteRecord(&n, &m, &head);
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            if (first) {
                                SetPosition(POS_X3, POS_Y);
                                printf("系统中尚无学生成绩信息，请先输入！\n");
                                system("pause");
                                break;
                            }
                            ModifyRecord(n, m, head);
                            system("pause");
                            break;
                        case 5:
                            while (1) {
                                char r_char;
                                system("cls");
                                r_char = PrintRecord(n, m, head);
                                if (first) {
                                    SetPosition(POS_X3, POS_Y);
                                    printf("系统中尚无学生成绩信息，请先输入！\n");
                                    SetPosition(POS_X3, POS_Y+2);
                                    system("pause");
                                    break;
                                }
                                switch (r_char) {
                                case 0:
                                    system("cls");
                                    SetPosition(POS_X3, POS_Y);
                                    printf("返回上级菜单！\n");
                                    Sleep(270);
                                    break;
                                case 1:
                                    SortbyNum(n, m,head);
                                    break;
                                case 2:
                                    SortbyName(n, m, head);
                                    break;
                                case 3:
                                   SortbyScore(n, m, head, Ascending);
                                    break;
                                case 4: 
                                    SortbyScore(n, m, head, Descending);
                                    break;
                                }


                                    if (r_char == 0)
                                    break;
                            }    
                            SetPosition(POS_X3, POS_Y+2);
                            system("pause");
                            break;
                        case 6:
                            system("cls");
                            if (first) {
                                SetPosition(POS_X3, POS_Y);
                                printf("系统中尚无学生成绩信息，请先输入！\n");
                                system("pause");
                                break;
                            }
                            StatisticAnalysis(n, m, head);
                            system("pause");
                            break;
                        }
                        if (m_char == 0)
                            break;
                    }
                    break;

                case 2:
                    while (1) {
                        system("cls");
                        char s_char = SearchMessage();
                        switch (s_char) {
                        case 0:
                            system("cls");
                            SetPosition(POS_X3, POS_Y);
                            printf("返回上级菜单！\n");
                            Sleep(360);
                            break;
                        case 1:
                            system("cls");
                            if (first) {
                                SetPosition(POS_X3, POS_Y);
                                printf("系统中尚无学生成绩信息，请先输入！\n");
                                system("pause");
                                break;
                            }
                            SearchByNumber(n, m, head);
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            if (first) {
                                SetPosition(POS_X3, POS_Y);
                                printf("系统中尚无学生成绩信息，请先输入！\n");
                                system("pause");
                                break;
                            }
                            SearchByName(n, m, head);
                            system("pause");;
                            break;
                        }
                        if (s_char == 0)
                            break;
                    }
                    break;

                case 3:
                    while (1) {
                        system("cls");
                        char o_char = Other();
                        switch (o_char) {
                        case 0:
                            system("cls");
                            SetPosition(POS_X3, POS_Y);
                            printf("返回上级菜单！\n");
                            Sleep(270);
                            break;
                        case 1:
                            system("cls");
                            if (first) {
                                SetPosition(POS_X3, POS_Y);
                                printf("系统中尚无学生信息，请先输入！\n");
                                system("pause");
                                break;
                            }
                            WritetoFile(n, m, head,s);
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            if (ReadfromFile(&n, &m, &head, &first,s) || first) {
                                SetPosition(POS_X3, POS_Y);
                                printf("尚未输入学生信息或文件打开失败，请先检查！\n");
                                system("pause");
                                break;
                            }
                            system("pause");
                            break;
                        }
                        if (o_char == 0)
                            break;
                    }
                    break;
                }

                if (ch == 0)
                    break;
            }
            break;
        } 
    } 
    ClearNode(head);
    return 0;
}
