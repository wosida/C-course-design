#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
#include <conio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)

#define   MAX_LEN  20                	              
#define   COURSE_NUM 2                  
#define   LEN sizeof(struct Student)	

typedef struct Student
{
	char num[MAX_LEN];
	char name[MAX_LEN];
	int score[COURSE_NUM];
	double sum;
	int rankNum;
	struct Student* next;
}STU;
;
char courseName[COURSE_NUM][MAX_LEN];

int  Menu(void);
STU* Creat(int n);
void Print(STU* head);
void SumofEveryStudent(STU* head, int n);
void Statistic(STU* head, int n);
STU* SortbyScore(STU* head);
STU* SortbyNumber(STU* head);
STU* SortbyName(STU* head);
void SearchbyNum(STU* head);
void SearchbyName(STU* head);
void SearchbyScore(STU* head, int n, int g, int f);
STU* deleteStu(STU* head, int* n);
void addStu(STU* head, int* stuNum);
void Modify(STU* head);

int main()
{
	system("color 3f");
	char c;
	int a, b, f, g;
	int h = 0;
	int n = 0;
	int i, j, flag = 0;
	STU* head = NULL;
	strcpy(courseName[0], "平时成绩");
	strcpy(courseName[1], "期末成绩");
	while (1)
	{
		system("cls");
		i = Menu();
		if (i == 1)
		{
			system("cls");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number:");
			scanf("%d", &n);
		}
		switch (i)
		{
		case 1:
			printf("\t\t\tInput student's ID, name and course score");
			printf("(");
			for (j = 0; j < 2; j++)
			{
				printf(" %s", courseName[j]);
			}
			printf(" )\n");
			head = Creat(n);
			SumofEveryStudent(head, n);
			flag = 1;
			head = SortbyScore(head);
			printf("录入数据成功!按任意键继续......");
			getche();
			system("cls");
			break;
		case 2:
			if (flag) {
				system("cls");
				printf("\n\n\n");
				printf("\t\t\t请选择您需要的排序方式：\n");
				printf("\t\t\t1.按成绩排序\n\t\t\t2.按学号排序\n\t\t\t3.按姓名排序\n\t\t\t");
				scanf("%d", &a);
				while (1) {
					if (a < 1 || a>3) {
						printf("\n\n\n");
						printf("\t\t\tinput error！please input again:");
						scanf("%d", &a);
					}
					if (a > 0 && a < 4) {
						break;
					}
				}
				if (a == 1) {
					system("cls");
					printf("\n\n\n");
					printf("\t\t\tSort in ascending order by sum score:\n");
					head = SortbyScore(head);
					Print(head);
				}
				if (a == 2) {
					system("cls");
					printf("\n\n\n");
					printf("\t\t\tSort from low to high in ascending order by number:\n");
					head = SortbyNumber(head);
					Print(head);
				}
				if (a == 3) {
					system("cls");
					printf("\n\n\n");
					printf("\t\t\tSort in dictionary order by name:\n");
					head = SortbyName(head);
					Print(head);
				}
				printf("数据计算完毕!按任意键继续......");
				getche();
				break;
			}
			else {
				system("cls");
				printf("\n\n\n请在此操作前先录入学生信息！按任意键继续......");
				getche();
				break;
			}
		case 3:
			system("cls");
			Statistic(head, n);
			printf("按任意键继续......");
			getche();
			break;
		case 4:
			if (flag) {
				system("cls");
				printf("\n\n\n");
				printf("\t\t\t请选择查询方式:\n");
				printf("\t\t\t1.按学号查询\n\t\t\t2.按姓名查询\n\t\t\t3.按总成绩是否在某个区间查询\n\t\t\t");
				scanf("%d", &b);
				while (1) {
					if (b < 1 || b>3) {
						system("cls");
						printf("\n\n\n");
						printf("\t\t\tinput error!please input again:");
						scanf("%d", &b);
					}
					if (b > 0 && b < 4) {
						break;
					}
				}
				if (b == 1) {
					system("cls");
					printf("\n\n\n");
					printf("\t\t\tInput the number you want to search:\n");
					SearchbyNum(head);
				}
				if (b == 2) {
					system("cls");
					printf("\n\n\n");
					printf("\t\t\tInput the name you want to search:\n");
					SearchbyName(head);
				}
				if (b == 3) {
					system("cls");
					printf("\n\n\n");
					printf("\t\t\tInput the sum score range you want to search:form__to__\n\t\t\t");
					scanf("%d %d", &g, &f);
					SearchbyScore(head, n, g, f);
				}
				printf("数据查询完毕!按任意键继续......");
				getche();
				break;
			}
			else {
				system("cls");
				printf("\n\n\n请在此操作前先录入学生信息！按任意键继续......");
				getche();
				break;
			}
		case 5:
			if (flag) {
				system("cls");
				printf("\n\n\n");
				Modify(head);
				SumofEveryStudent(head, n);
				head = SortbyScore(head);
				printf("按任意键继续......");
				getche();
				break;
			}
			else {
				system("cls");
				printf("\n\n\n请在此操作前先录入学生信息！按任意键继续......");
				getche();
				break;
			}
		case 6:
			if (flag) {
				system("cls");
				if (n == 1) {
					head = deleteStu(head, &n);
					flag = 0;
					break;
				}
				else {
					head = deleteStu(head, &n);
					head = SortbyScore(head);
					break;
				}
			}
			else {
				system("cls");
				printf("\n\n\n请在此操作前先录入学生信息！按任意键继续......");
				getche();
				break;
			}
		case 7:
			if (flag) {
				system("cls");
				printf("\n\n\n");
				addStu(head, &n);
				SumofEveryStudent(head, n);
				head = SortbyScore(head);
				printf("添加成功！按任意键继续......");
				getche();
				break;
			}
			else {
				system("cls");
				printf("\n\n\n请在此操作前先录入学生信息！按任意键继续......");
				getche();
				break;
			}
		case 0:
			system("cls");
			getchar();
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tSure to exit?(Y/y or N/n)\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\t");
			scanf("%c", &c);
			getchar();
			while (1) {
				if (c != 'y' && c != 'Y' && c != 'n' && c != 'N') {
					printf("\n\n\n\t\t\tinput error!please input again:");
					scanf("%c", &c);
					getchar();
				}
				if (c == 'y' || c == 'Y' || c == 'n' || c == 'N') {
					break;
				}
			}
			if (c == 'Y' || c == 'y') {
				system("cls");
				printf("\n\n\n\t\t\t******************************************************************************\n");
				printf("\t\t\tEnd of program!\n");
				printf("\t\t\t******************************************************************************\n");
			}
			if (c == 'N' || c == 'n') {
				break;
			}
			system("pause");
			return 0;
		default:
			system("cls");
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput error!\n");
			printf("\t\t\t******************************************************************************\n");
			system("pause");
			break;
		}
	}
	return 0;
}
/********************************
函数功能：显示菜单
参数：无
返回值：用户选择的菜单序号
*******************************/
int   Menu(void)
{
	int i;
	system("title 学生成绩管理系统V1.0");
	printf("\n\n");
	printf("\t\t\t                  学生成绩管理系统V1.0\n");
	printf("\t\t\t********************************************************\n");
	printf("\t\t\t*                  学生成绩管理系统                    *\n");
	printf("\t\t\t*                1.  录入学生信息功能                  *\n");
	printf("\t\t\t*                2.  学生信息排序功能                  *\n");
	printf("\t\t\t*                3.  统计学生成绩功能                  *\n");
	printf("\t\t\t*                4.  查询学生信息功能                  *\n");
	printf("\t\t\t*                5.  修改学生信息功能                  *\n");
	printf("\t\t\t*                6.  删除学生信息功能                  *\n");
	printf("\t\t\t*                7.  添加学生信息功能                  *\n");
	printf("\t\t\t*                0.  退出成绩管理系统                  *\n");
	printf("\t\t\t********************************************************\n");
	printf("\n\n\n\n");
	printf("\t\t\t*****************Please Input your choice:");
	scanf("%d", &i);
	return i;
}
/********************************
函数功能：创建链表
参数：学生人数
返回值：链表头结点
*******************************/
STU* Creat(int n) {
	STU* head = NULL;
	STU* p1, * p2=NULL, * p;
	int i, j, m;
	for (i = 1; i < n + 1; i++)
	{
		p1 = (STU*)malloc(LEN);
		printf("\t\t\t");
		if (p1 == NULL) {
			return 0;
		}
		scanf("%s", p1->num);

		scanf("%s", p1->name);

		for (j = 0; j < 2; j++)
		{
			scanf("%d", &p1->score[j]);
		}
		p1->rankNum = 0;
		p1->sum = 0;
		p1->next = NULL;
		if (i > 1) {
			p = head;
			for (m = 1; m < i; m++) {
				if (strcmp(p->num, p1->num) == 0) {
					printf("该学号与%s %s相同，请重新输入:\n\t\t\t", p->num, p->name);
					scanf("%s", p1->num);
					scanf("%s", p1->name);

					for (j = 0; j < 2; j++)
					{
						scanf("%d", &p1->score[j]);
					}
					
				}
				p = p->next;
			}
		}
		if (i == 1)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}

	}
	return(head);
}
/********************************
函数功能：计算每名学生总分
参数：链表头结点、学生人数
返回值：无
*******************************/
void  SumofEveryStudent(STU* head, int n)
{

	STU* p;
	int i;
	p = head;
	if (head != NULL)
	{
		printf("\n\n\n");
		for (i = 0; i < n; i++)
		{
			p->sum = (p->score[0]) * 0.4 + (p->score[1]) * 0.6;
			p = p->next;
		}
	}
}
/********************************
函数功能：打印链表（学生信息）
参数：链表头结点
返回值：无
*******************************/
void Print(STU* head)
{
	STU* p;
	int i;
	p = head;

	if (head != NULL)
	{
		printf("\t\t\t**************************************************************************************\n");
		printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名");
		for (i = 0; i < 2; i++)
		{
			printf("%-10s\t", courseName[i]);
		}
		printf("%-10s\t%-10s\n", "总分", "排名");
		do
		{
			printf("\t\t\t%-10s\t%-10s\t", p->num, p->name);
			for (i = 0; i < 2; i++)
			{
				printf("  %d\t\t", p->score[i]);
			}
			printf(" %-10d\t %-10d\n", (int)(p->sum + 0.5), p->rankNum);
			p = p->next;
		} while (p != NULL);
		printf("\t\t\t**************************************************************************************\n");
	}
}
/********************************
函数功能：统计课程信息
参数：链表头结点、学生人数
返回值：无
*******************************/
void  Statistic(STU* head, int n)
{
	STU* p;
	int i, j;
	int flag = 0;
	double sum;
	double course[2] = { 0 };
	int a[5], b[5] = { 0 };
	p = head;
	if (head != NULL)
	{
		flag = 1;
		for (i = 0; i < 2; i++)
		{
			p = head;
			sum = 0.0;
			do {
				sum += p->score[i];
				p = p->next;
			} while (p != NULL);
			course[i] = sum / n;
		}
	}
	else
	{
		printf("\n\n\n\t\t\tPlease input student information before doing this!!!\n");
	}
	if (flag) {
		printf("\n\t\t---------------------------------------------------------\n\t\t*\t\t\t\t\t\t\t*\n\t\t*\t\t\t\t\t\t\t*\n\t\t*");
		printf("%-5s\t%-7s\t%-7s\t%-7s\t%-7s\t%-7s %-7s*\n\t\t---------------------------------------------------------\n", "项目", "不及格", "[60,69]", "[70,79]", "[80,89]", "[90,100]", "平均分");

		for (i = 0; i < 2; i++)
		{
			p = head; 
			if (p == NULL) {
				return;
			}
			for (j = 0; j < 5; j++) 
			{
				a[j] = 0;
			}
			do {
				if (p->score[i] < 60)
				{
					a[0]++;
				}
				else if (p->score[i] < 70)
				{
					a[1]++;
				}
				else if (p->score[i] < 80)
				{
					a[2]++;
				}
				else if (p->score[i] < 90)
				{
					a[3]++;
				}
				else
				{
					a[4]++;
				}

				p = p->next;

			} while (p != NULL);

			printf("\t%-4s", courseName[i]);
			printf("*%-5s\t  %-5d\t  %-5d\t  %-5d\t  %-5d\t  %-5d\t  %-5.1f *\n", "人数", a[0], a[1], a[2], a[3], a[4], course[i]);
			printf("\t\t*%-5s\t%-5.2f%%\t%-5.2f%%\t%-5.2f%%\t%-5.2f%%\t%-5.2f%%\t        *\n", "比例", 100.0 * a[0] / n, 100.0 * a[1] / n, 100.0 * a[2] / n, 100.0 * a[3] / n, 100.0 * a[4] / n);
			printf("\t\t---------------------------------------------------------\n");
		}
		p = head;
		for (i = 0; i < n; i++) {
			if (p == NULL) {
				return;
			}
			if ((int)(p->sum + 0.5) < 60) {
				b[0]++;
			}
			else if ((int)(p->sum + 0.5) < 70) {
				b[1]++;
			}
			else if ((int)(p->sum + 0.5) < 80) {
				b[2]++;
			}
			else if ((int)(p->sum + 0.5) < 90) {
				b[3]++;
			}
			else {
				b[4]++;
			}
			p = p->next;
		}
		printf("\t    总评");
		printf("*%-5s\t  %-5d\t  %-5d\t  %-5d\t  %-5d\t  %-5d\t  %-5.1f *\n", "人数", b[0], b[1], b[2], b[3], b[4], (course[0] * 0.4 + course[1] * 0.6));
		printf("\t\t*%-5s\t%-5.2f%%\t%-5.2f%%\t%-5.2f%%\t%-5.2f%%\t%-5.2f%%\t        *", "比例", 100.0 * b[0] / n, 100.0 * b[1] / n, 100.0 * b[2] / n, 100.0 * b[3] / n, 100.0 * b[4] / n);
		printf("\n\t\t*\t\t\t\t\t\t\t*\n\t\t*\t\t\t\t\t\t\t*\n\t\t---------------------------------------------------------\n");
	}
}
/********************************
函数功能：按学生学号排序
参数：链表头结点
返回值：链表头结点
*******************************/
STU* SortbyNumber(STU* head)
{
	STU* endpt;
	STU* p;
	STU* p1, * p2;

	p1 = (STU*)malloc(LEN);
	if (p1 == NULL) {
		return 0;
	}
	p1->next = head;
	head = p1;

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->num, p1->next->next->num) > 0)
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;
	free(p1);
	p1 = NULL;
	return head;
}
/********************************
函数功能：按学生名字的字母顺序排序
参数：链表头结点
返回值：链表头结点
*******************************/
STU* SortbyName(STU* head)
{
	STU* endpt;
	STU* p;
	STU* p1, * p2;
	p1 = (STU*)malloc(LEN);
	if (p1 == NULL) {
		return 0;
	}
	p1->next = head;
	head = p1;

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->name, p1->next->next->name) > 0)
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;
	free(p1);
	p1 = NULL;
	return head;
}
/********************************
函数功能：按学生总分从高到低排名
参数：链表头结点
返回值：链表头结点
*******************************/
STU* SortbyScore(STU* head)
{
	STU* endpt;
	STU* p;
	STU* p1, * p2;
	int data = -1, ranknum = 0;

	p1 = (STU*)malloc(LEN);
	if (p1 == NULL) {
		return 0;
	}
	p1->next = head;
	head = p1;

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->sum < p1->next->next->sum)
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;
	head = head->next;
	free(p1);
	for (p = head; p; p = p->next)
	{
		if (p->sum  == data)
		{
			p->rankNum = ranknum;
		}
		else
		{
			ranknum++;
			p->rankNum = ranknum;
			data = p->sum ;
		}
	}

	return head;
}

/********************************
函数功能：输入学号搜索学生
参数：链表头结点
返回值：无
*******************************/
void  SearchbyNum(STU* head)
{
	char num[20] = { '\0' };
	int i;
	int flag = 1;
	STU* p;
	printf("\t\t\t");
	scanf("%s", num);
	printf("\n");
	printf("\t\t\t**************************************************************************************\n");
	p = head;
	if (head != NULL)
	{
		do {
			if (strcmp(num, p->num) == 0)
			{
				printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名");
				for (i = 0; i < 2; i++)
				{
					printf("%-10s\t", courseName[i]);
				}
				printf("%-10s\t%-10s\n", "总分", "排名");

				printf("\t\t\t");
				printf("%-10s\t%-10s\t", p->num, p->name);
				for (i = 0; i < 2; i++)
				{
					printf("  %-10d\t", p->score[i]);
				}
				printf(" %-10d\t %-10d\n", (int)(p->sum + 0.5), p->rankNum);
				flag = 0;
				break;
			}
			p = p->next;

		} while (p != NULL);
		if (flag)
		{
			printf("\t\t\t");
			printf("Not found!\n");
		}
	}
	printf("\t\t\t**************************************************************************************\n");

}
/********************************
函数功能：输入学生名字搜索学生
参数：链表头结点
返回值：无
*******************************/
void  SearchbyName(STU* head)
{
	char name[MAX_LEN] = { '\0' };
	int i;
	int flag = 1;
	STU* p;
	printf("\t\t\t");
	scanf("%s", name);
	printf("\n");
	printf("\t\t\t**************************************************************************************\n");
	printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名");
	for (i = 0; i < 2; i++)
	{
		printf("%-10s\t", courseName[i]);
	}
	printf("%-10s\t%-10s\n", "总分", "排名");
	p = head;
	if (head != NULL)
	{
		do {
			if (strcmp(name, p->name) == 0)
			{
				printf("\t\t\t");
				printf("%-10s\t%-10s\t", p->num, p->name);
				for (i = 0; i < 2; i++)
				{
					printf("  %-10d\t", p->score[i]);
				}
				printf(" %-10d\t %-10d\n", (int)(p->sum + 0.5), p->rankNum);
				flag = 0;
			}
			p = p->next;

		} while (p != NULL);
		if (flag)
		{
			printf("\t\t\t");
			printf("Not found!\n");
		}
	}
	printf("\t\t\t**************************************************************************************\n");

}
/********************************
函数功能：输入成绩寻找学生
参数：链表头结点、学生人数、分数起点，终点
返回值：无
******************************/
void SearchbyScore(STU* head, int n, int g, int f) {
	STU* p;
	p = head;
	int flag = 1;
	int i, j;
	printf("\n");
	printf("\t\t\t**************************************************************************************\n");
	printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名");
	for (i = 0; i < 2; i++)
	{
		printf("%-10s\t", courseName[i]);
	}
	printf("%-10s\t%-10s\n", "总分", "排名");
	for (i = 0; i < n; i++) {
		if ((int)(p->sum + 0.5) >= g && (int)(p->sum + 0.5) <= f) {
			printf("\t\t\t");
			printf("%-10s\t%-10s\t", p->num, p->name);
			for (j = 0; j < 2; j++)
			{
				printf("  %-10d\t", p->score[j]);
			}
			printf(" %-10d\t %-10d\n", (int)(p->sum + 0.5), p->rankNum);
			flag = 0;
		}
		p = p->next;
	}
	if (flag) {
		printf("\t\t\t");
		printf("Not found!\n");
	}
	printf("\t\t\t**************************************************************************************\n");
}
/********************************
函数功能：输入学号修改学生信息
参数：链表头节点
返回值：无
*******************************/
void Modify(STU* head)
{
	char num[20] = { '\0' };
	char temp[5] = { '\0' };
	int i;
	int flag = 1;
	int a=0, b=0;
	STU* p = head;

	printf("\t\t\tplease input number you want to modify\n");
	printf("\t\t\t");
	scanf("%s", num);
	if (head != NULL)
	{
		do {
			if (strcmp(num, p->num) == 0)
			{
				printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名");
				for (i = 0; i < 2; i++)
				{
					printf("%-10s\t", courseName[i]);
				}
				printf("%-10s\t%-10s\n", "总分", "排名");
				printf("\t\t\t");
				printf("%-10s\t%-10s\t", p->num, p->name);
				for (i = 0; i < 2; i++)
				{
					printf("  %-10d\t", p->score[i]);
				}
				printf(" %-10d\t %-10d\n\n", (int)(p->sum + 0.5), p->rankNum);
				printf("\t\t\tplease input the modified information:\n\t\t\t");
				printf("%-10s:", courseName[0]);
				scanf("%d", &a);
				printf("\t\t\t%-10s:", courseName[1]);
				scanf("%d", &b);
				flag = 0;
				printf("确定修改？(yes/no)");
				scanf("%s", temp);
				if (strcmp(temp, "yes") == 0) {
					p->score[0] = a;
					p->score[1] = b;
					printf("\t\t\t修改成功！");
				}
				if (strcmp(temp, "no") == 0) {
					break;
				}
			}
			p = p->next;
		} while (p);
		if (flag)
		{
			printf("Not find!\n");
		}
	}
}

/********************************
函数功能：输入学号删除学生
参数：链表头结点、学生人数
返回值：新的链表头结点
*******************************/
STU* deleteStu(STU* head, int* n)
{
	char num[20] = { '\0' };
	int i;
	int flag = 1;
	char temp[5] = { '\0' };
	STU* p, * q=NULL;
	printf("\t\t\tplease input number you want to delete\n");
	printf("\t\t\t");
	scanf("%s", num);
	p = head;
	printf("\t\t\t**************************************************************************************\n");
	if (head != NULL)
	{
		do {
			if (strcmp(num, p->num) == 0)
			{
				printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名");
				for (i = 0; i < 2; i++)
				{
					printf("%-10s\t", courseName[i]);
				}
				printf("%-10s\t%-10s\n", "总分", "排名");

				printf("\t\t\t");
				printf("%-10s\t%-10s\t", p->num, p->name);
				for (i = 0; i < 2; i++)
				{
					printf("  %-10d\t", p->score[i]);
				}
				printf(" %-10d\t %-10d\n", (int)(p->sum + 0.5), p->rankNum);
				printf("\t\t\t**************************************************************************************\n");
				flag = 0;
				printf("\t\t\tAre you sure to delete?(yes/no):");
				scanf("%s", temp);
				if (strcmp(temp, "yes") == 0)
				{
					if (p == head)
					{
						head = p->next;
					}
					else
					{
						q->next = p->next;
					}
					free(p);
					*n = *n - 1;
					printf("删除成功！按任意键继续......\n");
					getche();
					break;
				}
				 if (strcmp(temp, "no") == 0) {
					printf("按任意键继续.....\n");
					getche();
					break;
				 }
			
			}
			q = p;
			p = p->next;

		} while (p != NULL);
		if (flag)
		{
			printf("\t\t\t");
			printf("Not found!\n");
		}
	}
	
	return head;
}
/********************************
函数功能：输入学号添加学生
参数：链表头结点、学生人数
返回值：无
*******************************/
void addStu(STU* head, int*k)
{
	STU* Nhead = NULL;
	STU* p1, * p2=NULL,*p;
	int i, j, n,m;

	printf("please input student number you want to add:");
	scanf("%d", &n);
	*k += n;
	printf("\t\t\tInput student's ID, name and course score");
	printf("(");
	for (j = 0; j < 2; j++)
	{
		printf(" %s", courseName[j]);
	}
	printf(" )\n");
	for (i = 1; i < n + 1; i++)
	{
		p1 = (STU*)malloc(LEN);
		printf("\t\t\t");
		if (p1 == NULL) {
			return;
		}
		scanf("%s %s", p1->num, p1->name);
		for (j = 0; j < 2; j++)
		{
			scanf("%d", &p1->score[j]);
		}

		p1->rankNum = 0;
		p1->sum = 0;
		p1->next = NULL;
		
		p = head;
		for (m = 0; m < i; m++) {
			if (strcmp(p->num, p1->num) == 0) {
			printf("该学号与%s %s相同，请重新输入:\n\t\t\t", p->num, p->name);
			scanf("%s", p1->num);
			scanf("%s", p1->name);

			  for (j = 0; j < 2; j++)
			  {
				scanf("%d", &p1->score[j]);
			  }

			}
				p = p->next;
			}
		if (i == 1)
		{
			Nhead = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	p2 = head;
	while (p2->next)
	{
		p2 = p2->next;
	}
	p2->next = Nhead;
}
