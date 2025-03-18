

account s[STU_NUM];
account t;
int check = 0;

void SetPosition(int x, int y) {
    HANDLE hOut;
    COORD pos;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(hOut, pos);
}

int Menu(void) {
    int option;
    int posy = 5;
    
    t.id = 24050228;      // 教师账号
    strcpy(t.password, "12345678");

    SetPosition(POS_X3, posy);
    printf("学生成绩管理系统\n");

    SetPosition(POS_X1, ++posy);
    printf("1.学生查询入口\n");
    SetPosition(POS_X4, posy);
    printf("2.教师管理员入口\n");


    SetPosition(POS_X1, posy += 1);
    printf("0.退出\n");

    SetPosition(POS_X1, ++posy);
    printf("请选择你想要进行的操作[0-2]:[   ]\b\b\b");
    scanf("%d", &option);
    while (getchar() != '\n');
    return option;
}

void StudentModel(int m,int n, Node* head,account s[]) {
    system("cls");
    int posy = 5;
    account tmp;
    int flag = 0;
    Node* temp;
    int j,i;

    // 登录循环，直到输入正确的学号和密码
    do{
        if (flag != 0) {
            system("cls");
            SetPosition(44, 10);
            printf("密码错误，请重新输入！\n");
            SetPosition(44, 12);
            system("pause");
            Sleep(540);
        }
		system("cls");
        SetPosition(42, 7);
        printf("请输入学生学号：");
        SetPosition(60, 7);
        scanf("%ld", &tmp.id);
        SetPosition(42, 9);
        printf("请输入学生密码：");
        SetPosition(60, 9);
        scanf("%s", tmp.password);
    for (i = 0; i < n; i++)
    {
		if (tmp.id == s[i].id && strcmp(tmp.password, s[i].password) == 0) {
			break;
		}
	}
    flag++;
	} while (tmp.id != s[i].id || (strcmp(tmp.password, s[i].password) != 0));
    

    system("cls");
    SetPosition(44, 10);
    printf("登录成功！");
    Sleep(540);

    system("cls");


    // 登录成功后，在链表中查找该学生的记录
    temp = head;
    while (temp != NULL) {
        if (temp->data.num == tmp.id) {
            // 找到记录，按照表格格式输出成绩信息
            printf("\n+--------------------------------------------------------+\n");
            printf("|                        查询结果                        |\n");
            printf("+--------------------------------------------------------+\n");
            // 输出表头
            printf("| %-10s | %-15s |", "学号", "姓名");
            for (j = 0; j < m; j++) {
                char header[16];
                sprintf(header, "课程%d", j + 1);
                printf(" %-10s |", header);
            }
            printf(" %-10s | %-10s |\n", "总分", "平均分");
            // 输出表头分隔线
            printf("+------------+-----------------+");
            for (j = 0; j < m; j++) {
                printf("------------+");
            }
            printf("------------+------------+\n");
            // 输出该学生记录
            printf("| %-10ld | %-15s |", temp->data.num, temp->data.name);
            for (j = 0; j < m; j++) {
                printf(" %-10.2f |", temp->data.score[j]);
            }
            printf(" %-10.2f | %-10.2f |\n", temp->data.sum, temp->data.aver);
            printf("+--------------------------------------------------------+\n");
			return;
        }
        temp = temp->next;
    }
    // 如果未在链表中找到对应记录
    printf("\n+--------------------------------------------------------+\n");
    printf("|           未找到该学号对应的学生记录                   |\n");
    printf("+--------------------------------------------------------+\n");
   
}

   
int ManagerModel() {
    system("cls");
    int option;

    account tmp;

    int flag = 1;
    if (check == 0) {
        do {
         
            if (flag != 1) {
                system("cls");
                SetPosition(44 ,10);
                printf("密码错误，请重新输入！\n");
                SetPosition(44 ,12);
                system("pause");
                Sleep(540);
            }
           
            system("cls");
            SetPosition(42, 5);
            printf("学生成绩管理系统――管理员权限\n");
            SetPosition(42, 7);
            printf("请输入管理员账号：");
            SetPosition(60, 7);
            scanf("%ld", &tmp.id);
            SetPosition(42, 9);
            printf("请输入管理员密码：");
            SetPosition(60, 9);
            scanf("%s", tmp.password);
            flag++;
        } while (tmp.id!=t.id|| strcmp(tmp.password, t.password) != 0);
        system("cls");
        SetPosition(44, 10);
        printf("登录成功！");
        Sleep(1000);
    }
    system("cls");
    check = 1;
    int posy = 5;
    SetPosition(POS_X1, ++posy);
    printf("1.管理信息\n");
    SetPosition(POS_X1, posy += 2);
    printf("2.查找信息\n");
    SetPosition(POS_X1, posy += 2);
    printf("3.磁盘信息\n");
    SetPosition(POS_X1, posy += 2);
    printf("0.退出\n");

    SetPosition(POS_X1, posy+=2);
    printf("请选择你想要进行的操作[0-3]:[   ]\b\b\b");
    scanf("%d", &option);
    while (getchar() != '\n');
    return option;
}

int ManageMessage(void) {
    system("cls");
    int option;
    int posy = 5;

    SetPosition(POS_X1, ++posy);
    printf("1.批量录入学生成绩信息\n");
    SetPosition(POS_X4, posy);
    printf("2.单个录入学生成绩信息\n");
    SetPosition(POS_X1, posy += 2);
    printf("3.删除学生成绩信息\n");
    SetPosition(POS_X4, posy);
    printf("4.修改学生成绩信息\n");
    SetPosition(POS_X1, posy += 2);
    printf("5.查看所有学生成绩信息\n");
    SetPosition(POS_X4, posy);
    printf("6.统计分析学生成绩信息\n");
    SetPosition(POS_X1, posy += 2);
    printf("0.返回上级菜单\n");

    SetPosition(POS_X1, posy+=2);
    printf("请选择你想要进行的操作[0-6]:[   ]\b\b\b");
    scanf("%d", &option);

    return option;
}

int SearchMessage(void) {
    system("cls");
    int option;
    int posy = 5;

    SetPosition(POS_X1, posy);
    printf("1.按学号查找记录\n");
    SetPosition(POS_X4, posy);
    printf("2.按姓名查找记录\n");
    SetPosition(POS_X1, posy += 2);
    printf("0.返回上级菜单\n");

    SetPosition(POS_X1, posy+=2);
    printf("请选择你想要进行的操作[0-2]:[   ]\b\b\b");
    scanf("%d", &option);

    return option;
}

int Other(void) {
    system("cls");
    int option;
    int posy = 5;

    SetPosition(POS_X1, posy += 2);
    printf("1.学生记录存入硬盘\n");
    SetPosition(POS_X4, posy);
    printf("2.从磁盘读取学生记录\n");
    SetPosition(POS_X1, posy += 2);
    printf("0.返回上级菜单\n");

    SetPosition(POS_X1, posy+=2);
    printf("请选择你想要进行的操作[0-2]:[   ]\b\b\b");
    scanf("%d", &option);

    return option;
}

void InputRecord(int* n, int* m, Node** head,account s[]) {
    int i=0, j;
    Node* tail = NULL;
    *head = NULL;

    // 打印标题边框和系统提示
    printf("+--------------------------------------------------------+\n");
    printf("|                   学生信息录入系统                     |\n");
    printf("+--------------------------------------------------------+\n");

    // 录入学生人数和课程数（直接在表格中提示）
    printf("| 请输入学生人数 (n<%d): ", STU_NUM);
    scanf("%d", n);
    printf("| 请输入课程门数  (m<%d): ", COURSE_NUM);
    scanf("%d", m);
    printf("+--------------------------------------------------------+\n");


    // 针对每个学生录入信息
    for (i = 0; i < *n; i++) {
        Node* temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("内存分配失败\n");
            exit(0);
        }
        printf("\n+--------------------------------------------------------+\n");
        printf("|                   录入第 %d 个学生信息                   |\n", i + 1);
        printf("+--------------------------------------------------------+\n");

        // 输出表头：学号、姓名和各课程（成绩）列
        printf("| %-10s | %-15s |", "学号", "姓名");
        for (j = 0; j < *m; j++) {
            // 这里统一显示为“成绩”
            printf(" %-8s |", "成绩");
        }
        printf("\n");

        // 分隔线
        printf("+------------+-----------------+");
        for (j = 0; j < *m; j++) {
            printf("----------+");
        }
        printf("\n");

        // 分步录入数据时，先提示再输入
        printf("请输入学号: ");
        scanf("%8ld", &temp->data.num);
        s[i].id = temp->data.num;
        strcpy(s[i].password, "12345678");
		
        printf("请输入姓名: ");
        scanf("%s", temp->data.name);
        for (j = 0; j < *m; j++) {
            printf("请输入第%d门成绩: ", j + 1);
            scanf("%f", &temp->data.score[j]);
        }

        // 打印录入后生成的表格行（数据行）
        printf("+--------------------------------------------------------+\n");
        printf("| %10ld | %-15s |", temp->data.num, temp->data.name);
        for (j = 0; j < *m; j++) {
            printf(" %8.2f |", temp->data.score[j]);
        }
        printf("\n+--------------------------------------------------------+\n");

        temp->next = NULL;
        if (*head == NULL) {
            *head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    printf("\n\n录入成功！\n");
}

void AppendRecord(int* n, int* m, Node** head,account s[]) {
    int i, j;
    int num_record;

    // 输出添加记录的标题及提示边框
    printf("+--------------------------------------------------------+\n");
    printf("|                  添加学生记录                          |\n");
    printf("+--------------------------------------------------------+\n");
    printf("| 请输入需要增加的学生记录条数：");
    scanf("%d", &num_record);
    printf("+--------------------------------------------------------+\n");

    // 检查添加后总记录是否超过上限
    while (*n + num_record > STU_NUM) {
        system("cls");
        printf("+--------------------------------------------------------+\n");
        printf("|                  添加学生记录                          |\n");
        printf("+--------------------------------------------------------+\n");
        printf("| 要增加的记录条数太多，请重新输入：");
        scanf("%d", &num_record);
        printf("+--------------------------------------------------------+\n");
    }

    // 循环录入每个新增的学生信息
    for (i = 0; i < num_record; i++) {
        Node* temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("内存分配失败\n");
            exit(0);
        }

        // 显示当前录入记录的表格标题
        printf("\n+--------------------------------------------------------+\n");
        printf("|                   录入第 %d 个学生信息                   |\n", *n + i + 1);
        printf("+--------------------------------------------------------+\n");

        // 输出表头：学号、姓名及各门成绩
        printf("| %-10s | %-15s |", "学号", "姓名");
        for (j = 0; j < *m; j++) {
            printf(" %-8s |", "成绩");
        }
        printf("\n");

        // 打印分隔线
        printf("+------------+-----------------+");
        for (j = 0; j < *m; j++) {
            printf("----------+");
        }
        printf("\n");

        // 依次录入数据
        printf("请输入学号: ");
        scanf("%8ld", &temp->data.num);
		s[*n + i].id = temp->data.num;
		strcpy(s[*n + i].password, "12345678");
        printf("请输入姓名: ");
        scanf("%s", temp->data.name);
        for (j = 0; j < *m; j++) {
            printf("请输入第%d门成绩: ", j + 1);
            scanf("%f", &temp->data.score[j]);
        }

        // 显示录入完成后的数据行
        printf("+--------------------------------------------------------+\n");
        printf("| %10ld | %-15s |", temp->data.num, temp->data.name);
        for (j = 0; j < *m; j++) {
            printf(" %8.2f |", temp->data.score[j]);
        }
        printf("\n+--------------------------------------------------------+\n");

        // 将新记录插入链表头部
        temp->next = *head;
        *head = temp;
    }
    *n = *n + num_record;

    // 输出添加成功的提示信息
    printf("\n+--------------------------------------------------------+\n");
    printf("|                      添加成功！                        |\n");
    printf("+--------------------------------------------------------+\n");
}

void DeleteRecord(int* n, int* m, Node** head) {
    int j;
    long id;
    char ch;

    // 打印删除操作标题及提示
    printf("+--------------------------------------------------------+\n");
    printf("|                     删除学生记录                       |\n");
    printf("+--------------------------------------------------------+\n");
    printf("| 请输入要删除学生信息对应的学号： ");
    scanf("%ld", &id);
    printf("+--------------------------------------------------------+\n");

    Node* temp = *head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data.num == id) {
            // 找到记录后，显示详细信息
            printf("+--------------------------------------------------------+\n");
            printf("|                      学生详细信息                      |\n");
            printf("+--------------------------------------------------------+\n");
            printf("| %-10s | %-15s |", "学号", "姓名");
            for (j = 0; j < *m; j++) {
                printf(" %-8s |", "成绩");
            }
            printf(" %-8s | %-8s |\n", "总分", "平均");

            // 打印分隔线
            printf("+------------+-----------------+");
            for (j = 0; j < *m; j++) {
                printf("----------+");
            }
            printf("----------+----------+\n");

            // 显示该生记录
            printf("| %10ld | %-15s |", temp->data.num, temp->data.name);
            for (j = 0; j < *m; j++) {
                printf(" %8.2f |", temp->data.score[j]);
            }
            printf(" %8.2f | %8.2f |\n", temp->data.sum, temp->data.aver);
            printf("+--------------------------------------------------------+\n");

            // 提示确认是否删除
            printf("| 确认删除该记录？（Y/y 删除，N/n 取消）：");
            getchar(); // 吃掉可能残留的换行符
            scanf("%c", &ch);
            printf("+--------------------------------------------------------+\n");

            if (ch == 'Y' || ch == 'y') {
                if (prev == NULL) {
                    *head = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                free(temp);
                *n = *n - 1;
                printf("| 删除成功！                                           |\n");
                printf("+--------------------------------------------------------+\n");
                return;
            }
            else if (ch == 'N' || ch == 'n') {
                printf("| 已取消删除。                                         |\n");
                printf("+--------------------------------------------------------+\n");
                return;
            }
            else {
                printf("| 输入错误，操作终止。                                 |\n");
                printf("+--------------------------------------------------------+\n");
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    printf("| 未找到该学生记录！                                   |\n");
    printf("+--------------------------------------------------------+\n");
}

void ModifyRecord(int n, int m, Node* head) {
    int j;
    long id;
    char ch;
    Node* temp = head;

    // 打印修改操作的标题及提示
    printf("+--------------------------------------------------------+\n");
    printf("|                   修改学生记录                         |\n");
    printf("+--------------------------------------------------------+\n");
    printf("| 请输入需要修改信息对应的学号：");
    scanf("%ld", &id);
    printf("+--------------------------------------------------------+\n");

    // 遍历链表查找对应学号的记录
    while (temp != NULL) {
        if (temp->data.num == id) {
            // 找到记录，打印该学生详细信息
            printf("+--------------------------------------------------------+\n");
            printf("|                      学生详细信息                      |\n");
            printf("+--------------------------------------------------------+\n");
            printf("| %-10s | %-15s |", "学号", "姓名");
            for (j = 0; j < m; j++) {
                printf(" %-8s |", "成绩");
            }
            printf(" %-8s | %-8s |\n", "总分", "平均");
            // 分隔线
            printf("+------------+-----------------+");
            for (j = 0; j < m; j++) {
                printf("----------+");
            }
            printf("----------+----------+\n");
            // 输出该生数据
            printf("| %10ld | %-15s |", temp->data.num, temp->data.name);
            for (j = 0; j < m; j++) {
                printf(" %8.2f |", temp->data.score[j]);
            }
            printf(" %8.2f | %8.2f |\n", temp->data.sum, temp->data.aver);
            printf("+--------------------------------------------------------+\n");

            // 提示确认是否修改
            printf("| 确认是否需要修改该记录？（Y/y 修改，N/n 取消）：   ");
            getchar(); // 清除残留换行符
            scanf("%c", &ch);
            printf("+--------------------------------------------------------+\n");

            if (ch == 'Y' || ch == 'y') {
                // 以表格形式提示重新输入修改后的信息
                printf("|              请输入修改后的学生信息                  |\n");
                printf("+--------------------------------------------------------+\n");
                printf("| 请输入学号：  ");
                scanf("%ld", &temp->data.num);
                printf("+--------------------------------------------------------+\n");
                printf("| 请输入姓名：  ");
                scanf("%s", temp->data.name);
                printf("+--------------------------------------------------------+\n");
                for (j = 0; j < m; j++) {
                    printf("| 请输入第%d门成绩： ", j + 1);
                    scanf("%f", &temp->data.score[j]);
                    printf("+--------------------------------------------------------+\n");
                }
                // 重新计算总分与平均值
                {
                    float sum = 0;
                    for (j = 0; j < m; j++) {
                        sum += temp->data.score[j];
                    }
                    temp->data.sum = sum;
                    temp->data.aver = (m > 0) ? sum / m : 0;
                }
                printf("| 修改成功！                                           |\n");
                printf("+--------------------------------------------------------+\n");
                return;
            }
            else if (ch == 'N' || ch == 'n') {
                printf("| 已取消修改。                                         |\n");
                printf("+--------------------------------------------------------+\n");
                return;
            }
            else {
                printf("| 输入错误，操作终止。                                 |\n");
                printf("+--------------------------------------------------------+\n");
                return;
            }
        }
        temp = temp->next;
    }
    // 未找到记录的提示
    printf("| 未找到该学生记录！                                   |\n");
    printf("+--------------------------------------------------------+\n");
}

int PrintRecord(int n, int m, Node* head) {
    int j, k;

    int total_width = 70 + m * 12;


    printf("\n+");
    for (k = 0; k < total_width - 2; k++) {
        printf("-");
    }
    printf("+\n");

    printf("| %-12s | %-16s |", "学号", "姓名");
    for (j = 0; j < m; j++) {
        char header[20];
        sprintf(header, "课程%d", j + 1);
        printf(" %-12s |", header);
    }
    printf(" %-12s | %-12s |\n", "总分", "平均分");


    printf("+");
    for (k = 0; k < total_width - 2; k++) {
        printf("-");
    }
    printf("+\n");


    Node* temp = head;
    while (temp != NULL) {
        printf("| %-12ld | %-16s |", temp->data.num, temp->data.name);
        for (j = 0; j < m; j++) {
            printf(" %-12.2f |", temp->data.score[j]);
        }
        printf(" %-12.2f | %-12.2f |\n", temp->data.sum, temp->data.aver);
        temp = temp->next;
    }


    printf("+");
    for (k = 0; k < total_width - 2; k++) {
        printf("-");
    }
    printf("+\n");

    // 预留排序菜单的区域
    printf("\n");
    printf("+");
    for (k = 0; k < total_width - 2; k++) {
        printf("-");
    }
    printf("+\n");
    printf("| 排序功能: [1] 按学号排序  [2] 按姓名排序  [3] 总分升序  [4] 总分降序  [0]返回  |\n");
    printf("+");
    for (k = 0; k < total_width - 2; k++) {
        printf("-");
    }
    printf("+\n");
    //选择
    int option;

    printf("\n");
    printf("+");
    for (int k = 0; k < total_width - 2; k++) {
        printf("-");
    }
    printf("+\n");

    printf("| 请选择你想要进行的操作 [0-4]: [   ]");
    for (int k = 0; k < total_width - 38; k++) {
        printf(" ");
    }
    printf("|\n");

    printf("+");
    for (int k = 0; k < total_width - 2; k++) {
        printf("-");
    }
    printf("+\n");

    printf("\033[A");
    printf("\033[A");

    for (int k = 0; k < total_width - 48; k++) {
        printf("\033[C");
    } 


    scanf("%d", &option);
    while (getchar() != '\n'); 
    return option;
 
}

void StatisticAnalysis(int n, int m, Node* head) {
    int i, j, t[6];
    // 定义分数段字符串
    char* range[6] = { "<60", "60-69", "70-79", "80-89", "90-99", "100" };
    Node* p;

    // 针对每门课程输出统计结果
    for (j = 0; j < m; j++) {
        printf("\n+--------------------------------------------------------+\n");
        printf("|             课程%d成绩统计结果                         |\n", j + 1);
        printf("+----------------+--------------+------------------------+\n");
        printf("|   分数段       |    人数      |         占比           |\n");
        printf("+----------------+--------------+------------------------+\n");

        memset(t, 0, sizeof(t));
        p = head;
        while (p != NULL) {
            float score = p->data.score[j];
            if (score < 60)
                t[0]++;
            else if (score < 70)
                t[1]++;
            else if (score < 80)
                t[2]++;
            else if (score < 90)
                t[3]++;
            else if (score < 100)
                t[4]++;
            else if (score == 100)
                t[5]++;
            p = p->next;
        }
        for (i = 0; i < 6; i++) {
            printf("| %-14s | %-12d | %-21.2f%% |\n", range[i], t[i], (float)t[i] / n * 100);
        }
        printf("+----------------+--------------+------------------------+\n");
    }

    // 学生成绩平均分统计
    printf("\n+--------------------------------------------------------+\n");
    printf("|           学生成绩平均分统计结果                         |\n");
    printf("+----------------+--------------+------------------------+\n");
    printf("|   分数段       |    人数      |         占比           |\n");
    printf("+----------------+--------------+------------------------+\n");

    memset(t, 0, sizeof(t));
    p = head;
    while (p != NULL) {
        float aver = p->data.aver;
        if (aver < 60)
            t[0]++;
        else if (aver < 70)
            t[1]++;
        else if (aver < 80)
            t[2]++;
        else if (aver < 90)
            t[3]++;
        else if (aver < 100)
            t[4]++;
        else if (aver == 100)
            t[5]++;
        p = p->next;
    }
    for (i = 0; i < 6; i++) {
        printf("| %-14s | %-12d | %-21.2f%% |\n", range[i], t[i], (float)t[i] / n * 100);
    }
    printf("+----------------+--------------+------------------------+\n");

    // 留出空行，为后续功能（如排序菜单）预留空间
    printf("\n\n");
}

void SearchByNumber(int n, int m, Node* head) {
    long id;
    int j;
    Node* temp = head;

    // 输出查询操作标题及提示
    printf("\n+--------------------------------------------------------+\n");
    printf("|                   学生记录查询                         |\n");
    printf("+--------------------------------------------------------+\n");
    printf("| 请输入要查找的学生的学号： ");
    scanf("%ld", &id);
    printf("+--------------------------------------------------------+\n");

    // 遍历链表查找对应的学号记录
    while (temp != NULL) {
        if (temp->data.num == id) {
            // 找到记录后，以表格形式输出详细信息
            printf("\n+--------------------------------------------------------+\n");
            printf("|                        查询结果                        |\n");
            printf("+--------------------------------------------------------+\n");
            // 输出表头
            printf("| %-10s | %-15s |", "学号", "姓名");
            for (j = 0; j < m; j++) {
                char header[16];
                sprintf(header, "课程%d", j + 1);
                printf(" %-10s |", header);
            }
            printf(" %-10s | %-10s |\n", "总分", "平均分");
            // 输出表头分隔线
            printf("+------------+-----------------+");
            for (j = 0; j < m; j++) {
                printf("------------+");
            }
            printf("------------+------------+\n");
            // 输出该生记录
            printf("| %-10ld | %-15s |", temp->data.num, temp->data.name);
            for (j = 0; j < m; j++) {
                printf(" %-10.2f |", temp->data.score[j]);
            }
            printf(" %-10.2f | %-10.2f |\n", temp->data.sum, temp->data.aver);
            printf("+--------------------------------------------------------+\n");
            return;
        }
        temp = temp->next;
    }
    // 未找到记录时，以表格形式提示
    printf("\n+--------------------------------------------------------+\n");
    printf("|           未找到该学号对应的学生记录                   |\n");
    printf("+--------------------------------------------------------+\n");
}

void SearchByName(int n, int m, Node* head) {
    int flag = 1;
    int j;
    Node* temp = head;
    char name[NAME_LEN];

    // 输出查询操作标题及提示
    printf("\n+--------------------------------------------------------+\n");
    printf("|                   学生姓名查询                         |\n");
    printf("+--------------------------------------------------------+\n");
    printf("| 请输入要查找的学生的姓名： ");
    scanf("%s", name);
    printf("+--------------------------------------------------------+\n");

    // 遍历链表查找对应的姓名记录
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            if (flag) {
                // 仅在找到第一个匹配项时打印表头
                printf("\n+--------------------------------------------------------+\n");
                printf("|                        查询结果                        |\n");
                printf("+--------------------------------------------------------+\n");
                printf("| %-10s | %-15s |", "学号", "姓名");
                for (j = 0; j < m; j++) {
                    char header[16];
                    sprintf(header, "课程%d", j + 1);
                    printf(" %-10s |", header);
                }
                printf(" %-10s | %-10s |\n", "总分", "平均分");
                printf("+------------+-----------------+");
                for (j = 0; j < m; j++) {
                    printf("------------+");
                }
                printf("------------+------------+\n");
                flag = 0; // 取消未找到的标记
            }
            // 输出该生记录
            printf("| %-10ld | %-15s |", temp->data.num, temp->data.name);
            for (j = 0; j < m; j++) {
                printf(" %-10.2f |", temp->data.score[j]);
            }
            printf(" %-10.2f | %-10.2f |\n", temp->data.sum, temp->data.aver);
        }
        temp = temp->next;
    }

    // 如果未找到记录，输出未找到信息
    if (flag) {
        printf("\n+--------------------------------------------------------+\n");
        printf("|           未找到该姓名对应的学生记录                   |\n");
        printf("+--------------------------------------------------------+\n");
    }
    else {
        printf("+--------------------------------------------------------+\n");
        return;
    }
}

void Caculate(int n, int m, Node* head, float sum[], float aver[]) {
    CalculateScoreOfCourse(n,m, head, sum, aver);
    CalculateScoreOfStudent(n, m, head);
}

void CalculateScoreOfCourse(int n, int m, Node* head, float sum[], float aver[]) {
    int i, j;
    for (j = 0; j < m; j++) {
        sum[j] = 0;
        Node* temp = head; // 每门课程重新遍历链表
        for (i = 0; i < n; i++) {
            if (temp == NULL)
                break;
            sum[j] += temp->data.score[j];
            temp = temp->next;
        }
        aver[j] = sum[j] / n;
    }
}

void CalculateScoreOfStudent(int n, int m, Node* head) {
    Node* temp = head;
    int i, j;
    for (i = 0; i < n; i++) {
        temp->data.sum = 0;
        for (j = 0; j < m; j++) {
            temp->data.sum += temp->data.score[j];
        }
        temp->data.aver = temp->data.sum / m;
        temp = temp->next;
    }
}

void WritetoFile(int n, int m, Node* head,account s[]) {
    int j;
    FILE* fp,*fp2;
    if ((fp = fopen("student.txt", "w")) == NULL) {
        SetPosition(POS_X3, POS_Y);
        printf("文件student.txt无法正常打开！");
        exit(0);
    }

    if ((fp2 = fopen("account.txt", "w")) == NULL) {
        SetPosition(POS_X3, POS_Y);
        printf("文件sccount.txt无法正常打开！");
        exit(0);
    }
    for (int i = 0; i < n; i++) 
		fprintf(fp2, "%ld %s\n", s[i].id, s[i].password);
    fprintf(fp, "%d %d\n", n, m);
    Node* temp = head;
	
    while (temp != NULL) {
        fprintf(fp, "%ld %s\n", temp->data.num, temp->data.name);
        for (j = 0; j < m; j++) {
            fprintf(fp, "%.2f ", temp->data.score[j]);
        }
        fprintf(fp, "%.2f %.2f\n", temp->data.sum, temp->data.aver);
        temp = temp->next;
    }
    fclose(fp);
    fclose(fp2);
    SetPosition(POS_X3, POS_Y);
    printf("存盘完毕！");
}

int ReadfromFile(int* n, int* m, Node** head, int* first,account s[]) {
    FILE* fp,*fp2;
    int i, j;
    if ((fp = fopen("student.txt", "r")) == NULL) {
        SetPosition(POS_X3, POS_Y);
        printf("磁盘文件student.txt无法打开");
        return 1;
    }
    fscanf(fp, "%d %d", n, m);

    if ((fp2 = fopen("account.txt", "r")) == NULL) {
        SetPosition(POS_X3, POS_Y+2);
        printf("磁盘文件account.txt无法打开");
        return 1;
    }
	for (int i = 0; i < *n; i++)
		fscanf(fp2, "%ld %s", &s[i].id, s[i].password);

    *head = NULL;
    
    Node* tail = NULL;
    for (i = 0; i < *n; i++) {
        Node* temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("内存分配失败\n");
            exit(0);
        }
        fscanf(fp, "%ld %s", &temp->data.num, temp->data.name);
        for (j = 0; j < *m; j++) {
            fscanf(fp, "%f", &temp->data.score[j]);
        }
        fscanf(fp, "%f %f", &temp->data.sum, &temp->data.aver);
        temp->next = NULL;
        if (*head == NULL) {
            *head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    *first = 0;
    fclose(fp);
    fclose(fp2);
    SetPosition(POS_X3, POS_Y);
    printf("数据从磁盘读取完毕！");
    return 0;
}


void SortbyName(int n, int m, Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* p = temp;
        while (p != NULL) {
            if (strcmp(temp->data.name, p->data.name) > 0) {
                STU t = temp->data;
                temp->data = p->data;
                p->data = t;
            }
            p = p->next;
        }
        temp = temp->next;
    }
    SetPosition(POS_X3, POS_Y);
    printf("按姓名字典对学生记录排序完毕");
}

void SortbyNum(int n, int m, Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* p = temp;
        while (p != NULL) {
            if (temp->data.num > p->data.num) {
                STU t = temp->data;
                temp->data = p->data;
                p->data = t;
            }
            p = p->next;
        }
        temp = temp->next;
    }
    SetPosition(POS_X3, POS_Y);
    printf("按学号从小到大对学生记录排序完毕");
}

void SortbyScore(int n, int m, Node* head, int(*cmp)(float a, float b)) {
    Node* temp = head;
    while (temp != NULL) {
        Node* p = temp;
        while (p != NULL) {
            if (cmp(temp->data.aver, p->data.aver)) {
                STU t = temp->data;
                temp->data = p->data;
                p->data = t;
            }
            p = p->next;
        }
        temp = temp->next;
    }
    SetPosition(POS_X3, POS_Y);
    printf("按学生成绩总分排序完毕");
}


void ClearNode(Node* head) {
    Node* temp = head;
    Node* wait_free = NULL;
    while (temp != NULL) {
        wait_free = temp;
        temp = temp->next;
        free(wait_free);
    }
}



int Ascending(float a, float b) {
    return a > b;
}

int Descending(float a, float b) {
    return a < b;
}


