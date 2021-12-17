#include<stdio.h>
#include<stdlib.h>

struct student {
	char chName[50];	  //学生姓名
	char chStuId[50];	  //学生学号
	int chClass;	  	  //学生考试科目
	int iStudent;	  	  //学生人数
	int iTest_scores[30]; //学生成绩
} student, student1[200];

//定义函数
void Menu();
void fnInput();
void fnDisplay();

//主菜单函数
void Menu() {
	int i;
	system("cls");
	printf("***学生管理系统***\n\n");
	printf(" --------------------\n");
	printf("|1.录入学生信息及成绩|\n");
	printf("|2.显示学生信息及成绩|\n");
	printf("|0.退出程序          |\n");
	printf(" --------------------\n\n");
	printf("请输入数字:");
	scanf("%d", &i);
	system("cls");
	while (1) {
		switch (i) {
			//输入1进入到数据录入二级菜单
		case 1:
			fnInput();//数据录入函数
			break;
			//输入2进入到数据输出函数
		case 2:
			fnDisplay();//学生信息输出函数
			break;
			//输入0退出程序
		case 0:
			return;
			default:
				printf("请输入正确的数字!!!");
		}
	}
}

//数据录入函数
void fnInput() {
	int tem;
	while (1) {
		printf(" ----------------\n");
		printf("|1.学生信息及成绩|\n");
		printf("|0.返回主菜单    |\n");
		printf(" ----------------\n\n");
		printf("请选择子菜单编号:");
		scanf("%d", &tem);
		printf("\n");
		switch (tem) {
			//输入1进行学生数据录入
		case 1:
			printf("学生人数:");
			scanf("%d", &student.iStudent);
			printf("学生考试科目数:");
			scanf("%d", &student.chClass);
			//循环输入学生姓名、学号、成绩
			for (int j = 0; j < student.iStudent; j++) {
				printf("输入第%d名学生姓名:", j + 1);
				scanf("%s", student1[j].chName);
				printf("输入第%d名学生学号:", j + 1);
				scanf("%s", student1[j].chStuId);
				for (int k = 0; k < student.chClass; k++) {
					printf("输入第%d名学生第%d门课的成绩:", j + 1, k + 1);
					scanf("%d", &student1[k].iTest_scores[k]);
				}
				printf("\n");
			}
			//清空屏幕
			system("cls");
			break;
			//输入0返回主菜单
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
	while (1) {
		printf(" ------------------\n");
		printf("|1.显示所有学生信息|\n");
		printf("|0.返回主菜单      |\n");
		printf(" ------------------\n\n");
		printf("请选择子菜单编号:");
		scanf("%d", &tem);
		printf("\n");
		switch (tem) {
			//输入1将所有学生信息输出到屏幕
		case 1:
			//循环输出学生姓名、学号、成绩
			for (int j = 0; j < student.iStudent; j++) {
				printf("第%d名学生姓名:%s\n", j + 1, student1[j].chName);
				printf("第%d名学生学号:%s\n", j + 1, student1[j].chStuId);
				for (int k = 0; k < student.chClass; k++) {
					printf("第%d名学生第%d门课的成绩:%d\n", j + 1, k + 1, student1[k].iTest_scores[k]);
				}
				printf("\n");
			}
			//暂停程序,用户按任意键结束
			system("pause");
			break;
			//输入0返回主菜单
		case 0:
			Menu();//主菜单函数
			//暂停程序,用户按任意键结束
			system("pause");
			//清空屏幕
			system("cls");
			break;
		}
	}
}

//主函数
int main(void) {
	Menu();//主菜单函数
}
