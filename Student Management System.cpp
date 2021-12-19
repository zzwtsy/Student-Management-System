#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
	char chName[50];//生姓名
	char chStudentId[50];//学号
	char chStudentSex[10];//性别
	char chClass[30];//考试科目
	int iStudentAge;//年龄
	int iClassNumber;//考试科目数
	int iStudent;//学生人数
	int iTest_scores[30];//成绩
} student, student1[100];

//定义函数
void Menu();//主菜单
void fnInput();//信息输入
void fnDisplay();//信息输出
void fnFindInfo();//信息查找

//主菜单函数
void Menu() {
	int i;
	system("cls");
	printf("*******学生管理系统*******\n\n");
	printf("**************************\n");
	printf("*--1.录入学生信息及成绩--*\n");
	printf("*--2.输出学生信息及成绩--*\n");
	printf("*--3.查询学生信息及成绩--*\n");
	printf("*--0.     退出程序     --*\n");
	printf("**************************\n\n");
	printf("请输入数字:");
	scanf("%d", &i);
	system("cls");
	switch (i) {
		//跳转到到数据录入函数
		case 1:
			fnInput();//数据录入函数
			break;
		//跳转到数据输出函数
		case 2:
			fnDisplay();//学生信息输出函数
			break;
		//跳转到信息查找函数
		case 3:
			fnFindInfo();//信息查找函数
			break;
		//退出程序
		case 0:
			break;
		default:
			printf("请输入正确的数字!!!");
	}
}

//数据录入函数
void fnInput() {
	int tem;
	while (1) {
		printf("**************************\n");
		printf("*--1.录入学生信息及成绩--*\n");
		printf("*--0.    返回主菜单    --*\n");
		printf("**************************\n\n");
		printf("请选择子菜单编号:");
		scanf("%d", &tem);
		printf("\n");
		switch (tem) {
			//学生数据录入
			case 1:
				printf("学生人数:");
				scanf("%d", &student.iStudent);
				printf("学生考试科目数:");
				scanf("%d", &student.iClassNumber);
				for (int i = 0; i < student.iClassNumber; i++) {
					printf("科目%d名称:", i + 1);
					scanf("%s", student1[i].chClass);
				}
				//循环输入学生姓名、学号、年龄、性别、成绩
				for (int j = 0; j < student.iStudent; j++) {
					printf("第%d名学生\n", j + 1);
					printf("姓名:");
					scanf("%s", student1[j].chName);
					printf("性别:");
					scanf("%s", student1[j].chStudentSex);
					printf("学号:");
					scanf("%s", student1[j].chStudentId);
					printf("年龄:");
					scanf("%d", &student.iStudentAge);
					for (int k = 0; k < student.iClassNumber; k++) {
						printf("%s课的成绩:", student1[k].chClass);
						scanf("%d", &student1[k].iTest_scores[k]);
					}
					printf("\n");
				}
				system("cls");//清空屏幕
				break;
			//返回主菜单
			case 0:
				Menu();//主菜单函数
				break;
			default:
				printf("输入错误!!!");
		}
	}
}

//输出函数
void fnDisplay() {
	int tem;
	for (int j = 0; j < student.iStudent; j++) {
		printf("第%d名学生\n", j + 1);
		printf("学号:%s\n", student1[j].chStudentId);
		printf("姓名:%s\n", student1[j].chName);
		printf("性别:%s\n", student1[j].chStudentSex);
		printf("年龄:%d\n", student.iStudentAge);
		for (int k = 0; k < student.iClassNumber; k++) {
			printf("%s课的成绩:%d\n", student1[k].chClass, student1[k].iTest_scores[k]);
		}
		printf("\n");
	}
	printf("输入0返回主程序:");
	scanf("%d", &tem);
	printf("\n");
	switch (tem) {
		//返回主菜单
		case 0:
			Menu();//主菜单函数
			system("pause");//暂停程序,用户按任意键结束
			system("cls");//清空屏幕
			break;
	}
}

//信息查找
void fnFindInfo() {
	int iNumber, i, iTemp = 0;
	char chStudentnumber[30], chStudenName[30];
	while (1) {
		system("cls");
		printf("******************\n");
		printf("*--1.按学号查询--*\n");
		printf("*--2.按姓名查询--*\n");
		printf("*--0.返回主菜单--*\n");
		printf("******************\n");
		printf("请选择子菜单编号:");
		scanf("%d", &iNumber);
		switch (iNumber) {
			//按学号查询学生信息
			case 1:
				printf("请输入要查询的学生的学号:");
				scanf("%s", chStudentnumber);
				for (i = 0; i < student.iStudent; i++)
					if (strcmp(student1[i].chStudentId, chStudentnumber) == 0) {
						iTemp = 1;
						printf("学号:%s\n", student1[i].chStudentId);
						printf("姓名:%s\n", student1[i].chName);
						printf("性别:%s\n", student1[i].chStudentSex);
						printf("年龄:%d\n", student.iStudentAge);
						for (int k = 0; k < student.iClassNumber; k++) {
							printf("%s课的成绩:%d\n", student1[k].chClass, student1[k].iTest_scores[k]);
						}
						printf("\n");
					}
				if (iTemp == 0) {
					printf("该学号不存在！\n");
				}
				system("pause");//暂停程序,用户按任意键结束
				break;
			//按姓名查询学生信息
			case 2:
				printf("请输入要查询的学生的姓名:");
				scanf("%s", chStudenName);
				for (i = 0; i < student.iStudent; i++)
					if (strcmp(student1[i].chName, chStudenName) == 0) {
						iTemp = 1;
						printf("学号:%s\n", student1[i].chStudentId);
						printf("姓名:%s\n", student1[i].chName);
						printf("性别:%s\n", student1[i].chStudentSex);
						printf("年龄:%d\n", student.iStudentAge);
						for (int k = 0; k < student.iClassNumber; k++) {
							printf("%s课的成绩:%d\n", student1[k].chClass, student1[k].iTest_scores[k]);
						}
						printf("\n");
					}
				if (iTemp == 0) {
					printf("该姓名不存在！\n");
				}
				system("pause");//暂停程序,用户按任意键结束
				break;
			//返回主菜单
			case 0:
				Menu();//主菜单函数
				system("cls");//清屏
				break;
			default:
				printf("输入错误!!!\n");
		}
	}
}

//主函数
int main(void) {
	Menu();//主菜单函数
}
