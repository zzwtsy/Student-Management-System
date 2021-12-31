#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//学生信息
struct info {
	int iStudent;//学生人数
	char chMiddleFileName[50];//fnSave函数保存期中文件名称
	char chFinalFileName[50];//fnSave函数保存期末文件名称
} Student;

//期中成绩
struct Middle {
	char chName[50];//姓名
	char chStudentId[50];//学号
	float fEnglish;//英语成绩
	float fChinese;//语文成绩
	float fMath;//数学成绩
	float fPhysical;//物理成绩
	float fGeography;//地理成绩
	float fAverage;//平均分
} Middle[100], Middletemp;

//期末成绩
struct Final {
	char chName[50];//姓名
	char chStudentId[50];//学号
	float fEnglish;//英语成绩
	float fChinese;//语文成绩
	float fMath;//数学成绩
	float fPhysical;//物理成绩
	float fGeography;//地理成绩
	float fAverage;//平均分
} Final[100], Finaltemp;

//定义函数
void fnSortMenu();//排序菜单
void fnSortMiddle();//期中排序
void fnSortFinal();//期末排序
void fnMenu();//主菜单
void fnSave();//保存信息
void fnInput();//信息输入
void fnOutput();//信息输出
void fnAverage();//求平均分
void fnFindInfo();//信息查找
void fnReadFile();//读取文件
void fnmodifyMenu();//修改数据菜单
void fnmodifyFinal();//修改期末数据
void fnmodifyMiddle();//修改期中数据

//期末成绩排序
void fnSortFinal() {
	float fsum[100];
	int iTemp;
	printf("**************************\n");
	printf("*--1.平均分由高到低排序--*\n");
	printf("*                        *\n");
	printf("*--2.平均分由低到高排序--*\n");
	printf("*                        *\n");
	printf("*------0.返回上级菜单----*\n");
	printf("**************************\n");
	printf("请输入数字:");
	scanf("%d", &iTemp);
	switch (iTemp) {
		case 1:
			//计算学生期中成绩平均分
			for (int j = 0; j < Student.iStudent; j++) {
				fsum[j] = Final[j].fEnglish + Final[j].fChinese + Final[j].fMath + Final[j].fPhysical + Final[j].fGeography;
				Final[j].fAverage = fsum[j] / 5;
			}
			//冒泡排序
			for (int j = 1; j < Student.iStudent; j++) {
				for (int i = 0; i < Student.iStudent - 1; i++) {
					if (Final[i].fAverage > Final[i + 1].fAverage) {
						Finaltemp = Final[i];
						Final[i] = Final[i + 1];
						Final[i + 1] = Finaltemp;
					}
				}
			}
			printf("姓名\t学号\t英语成绩\t语文成绩\t数学成绩\t物理成绩\t地理成绩\t平均分\n");
			for (int j = Student.iStudent - 1; j >= 0; j--) {
				printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Final[j].chName, Final[j].chStudentId, Final[j].fEnglish, Final[j].fChinese, Final[j].fMath, Final[j].fPhysical, Final[j].fGeography, Final[j].fAverage);
			}
			system("pause");
			system("cls");
			fnSortFinal();
			break;
		case 2:
			//计算学生期中成绩平均分
			for (int j = 0; j < Student.iStudent; j++) {
				fsum[j] = Final[j].fEnglish + Final[j].fChinese + Final[j].fMath + Final[j].fPhysical + Final[j].fGeography;
				Final[j].fAverage = fsum[j] / 5;
			}
			//冒泡排序
			for (int j = 1; j < Student.iStudent; j++) {
				for (int i = 0; i < Student.iStudent - 1; i++) {
					if (Final[i].fAverage > Final[i + 1].fAverage) {
						Finaltemp = Final[i];
						Final[i] = Final[i + 1];
						Final[i + 1] = Finaltemp;
					}
				}
			}
			printf("姓名\t学号\t英语成绩\t语文成绩\t数学成绩\t物理成绩\t地理成绩\t平均分\n");
			for (int j = 0; j < Student.iStudent; j++) {
				printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Final[j].chName, Final[j].chStudentId, Final[j].fEnglish, Final[j].fChinese, Final[j].fMath, Final[j].fPhysical, Final[j].fGeography, Final[j].fAverage);
			}
			system("pause");
			system("cls");
			fnSortFinal();
			break;
		//返回主菜单
		case 0:
			system("cls");
			fnMenu();
			break;
		default:
			printf("输入错误!!!");
			system("cls");
			fnSortFinal();
			break;
	}
}

//期中成绩排序
void fnSortMiddle() {
	float fsum[100];
	int iTemp;
	printf("**************************\n");
	printf("*--1.平均分由高到低排序--*\n");
	printf("*                        *\n");
	printf("*--2.平均分由低到高排序--*\n");
	printf("*                        *\n");
	printf("*------0.返回上级菜单----*\n");
	printf("**************************\n");
	printf("请输入数字:");
	scanf("%d", &iTemp);
	switch (iTemp) {
		case 1:
			//计算学生期中成绩平均分
			for (int j = 0; j < Student.iStudent; j++) {
				fsum[j] = Middle[j].fEnglish + Middle[j].fChinese + Middle[j].fMath + Middle[j].fPhysical + Middle[j].fGeography;
				Middle[j].fAverage = fsum[j] / 5;
			}
			//冒泡排序
			for (int j = 1; j < Student.iStudent; j++) {
				for (int i = 0; i < Student.iStudent - 1; i++) {
					if (Middle[i].fAverage > Middle[i + 1].fAverage) {
						Middletemp = Middle[i];
						Middle[i] = Middle[i + 1];
						Middle[i + 1] = Middletemp;
					}
				}
			}
			printf("姓名\t学号\t英语成绩\t语文成绩\t数学成绩\t物理成绩\t地理成绩\t平均分\n");
			for (int j = Student.iStudent - 1; j >= 0; j--) {
				printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Middle[j].chName, Middle[j].chStudentId, Middle[j].fEnglish, Middle[j].fChinese, Middle[j].fMath, Middle[j].fPhysical, Middle[j].fGeography, Middle[j].fAverage);
			}
			system("pause");
			system("cls");
			fnSortMiddle();
			break;
		case 2:
			//计算学生期中成绩平均分
			for (int j = 0; j < Student.iStudent; j++) {
				fsum[j] = Middle[j].fEnglish + Middle[j].fChinese + Middle[j].fMath + Middle[j].fPhysical + Middle[j].fGeography;
				Middle[j].fAverage = fsum[j] / 5;
			}
			//冒泡排序
			for (int j = 1; j < Student.iStudent; j++) {
				for (int i = 0; i < Student.iStudent - 1; i++) {
					if (Middle[i].fAverage > Middle[i + 1].fAverage) {
						Middletemp = Middle[i];
						Middle[i] = Middle[i + 1];
						Middle[i + 1] = Middletemp;
					}
				}
			}
			printf("姓名\t学号\t英语成绩\t语文成绩\t数学成绩\t物理成绩\t地理成绩\t平均分\n");
			for (int j = 0; j < Student.iStudent; j++) {
				printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Middle[j].chName, Middle[j].chStudentId, Middle[j].fEnglish, Middle[j].fChinese, Middle[j].fMath, Middle[j].fPhysical, Middle[j].fGeography, Middle[j].fAverage);
			}
			system("pause");
			system("cls");
			fnSortMiddle();
			break;
		case 0:
			system("cls");
			fnSortMenu();
			break;
		default:
			printf("输入错误!!!");
			system("cls");
			fnSortMiddle();
			break;
	}
}

//排序函数菜单
void fnSortMenu() {
	int iTemp;
	printf("********************\n");
	printf("*--1.期中成绩排序--*\n");
	printf("*                  *\n");
	printf("*--2.期末成绩排序--*\n");
	printf("*                  *\n");
	printf("*---0.返回主菜单---*\n");
	printf("********************\n");
	printf("请输入数字:");
	scanf("%d", &iTemp);
	switch (iTemp) {
		case 1:
			system("cls");
			fnSortMiddle();
			break;
		case 2:
			system("cls");
			fnSortFinal();
			break;
		//返回主菜单
		case 0:
			system("cls");
			fnMenu();
			break;
		default:
			printf("输入错误!!!\n");
			system("pause");
			system("cls");
			fnSortMenu();
			break;
	}
}

//修改期末数据
void fnmodifyFinal() {
	int iStudentNumber, iTem, Temp = 0;
	char chName[50], chStudentId[50];
	float fEnglish, fChinese, fMath, fPhysical, fGeography;
	printf("输入要修改学生的学号:");
	scanf("%s", chStudentId);
	for (int i = 0; i < Student.iStudent; i++) {
		if (strcmp(Final[i].chStudentId, chStudentId) == 0) {
			Temp = 1;
			iStudentNumber = i;
a:
			system("cls");
			printf("1.修改姓名\n");
			printf("2.修改学号\n");
			printf("3.修改英语成绩\n");
			printf("4.修改语文成绩\n");
			printf("5.修改数学成绩\n");
			printf("6.修改物理成绩\n");
			printf("7.修改地理成绩\n");
			printf("0.返回上级菜单\n");
			printf("请选择编号:");
			scanf("%d", &iTem);
			switch (iTem) {
				case 1:
					printf("请输入新姓名:");
					scanf("%s", chName);
					strcpy(Final[iStudentNumber].chName, chName);
					goto a;
					break;
				case 2:
					printf("请输入新学号:");
					scanf("%s", chStudentId);
					strcpy(Final[iStudentNumber].chStudentId, chStudentId);
					goto a;
					break;
				case 3:
					printf("请输入英语成绩:");
					scanf("%f", &fEnglish);
					Final[iStudentNumber].fEnglish = fEnglish;
					goto a;
					break;
				case 4:
					printf("请输入语文成绩:");
					scanf("%f", &fChinese);
					Final[iStudentNumber].fChinese = fChinese;
					goto a;
					break;
				case 5:
					printf("请输入数学成绩:");
					scanf("%f", &fMath);
					Final[iStudentNumber].fMath = fMath;
					goto a;
					break;
				case 6:
					printf("请输入物理成绩:");
					scanf("%f", &fPhysical);
					Final[iStudentNumber].fPhysical = fPhysical;
					goto a;
					break;
				case 7:
					printf("请输入地理成绩:");
					scanf("%f", &fGeography);
					Final[iStudentNumber].fGeography = fGeography;
					goto a;
					break;
				case 0:
					system("cls");
					fnmodifyMenu();
					break;
				default:
					printf("输入错误!!!");
					goto a;
					system("cls");
					break;
			}
		}
	}
	if (Temp == 0) {
		printf("该学号不存在!!!\n");
		system("pause");
		system("cls");
		fnmodifyMenu();
	}
}

//修改期中数据函数
void fnmodifyMiddle() {
	int iStudentNumber, iTem, Temp = 0, i;
	char chName[50], chStudentId[50];
	float fEnglish, fChinese, fMath, fPhysical, fGeography;
//	while (1) {
	//修改期中学生信息
	printf("输入要修改学生的学号:");
	scanf("%s", chStudentId);
	for (i = 0; i < Student.iStudent; i++) {
		if (strcmp(Middle[i].chStudentId, chStudentId) == 0) {
			Temp = 1;
			iStudentNumber = i;
a:
			system("cls");
			printf("1.修改姓名\n");
			printf("2.修改学号\n");
			printf("3.修改英语成绩\n");
			printf("4.修改语文成绩\n");
			printf("5.修改数学成绩\n");
			printf("6.修改物理成绩\n");
			printf("7.修改地理成绩\n");
			printf("0.返回上级菜单\n");
			printf("请选择编号:");
			scanf("%d", &iTem);
			switch (iTem) {
				case 1:
					printf("请输入新姓名:");
					scanf("%s", chName);
					strcpy(Middle[iStudentNumber].chName, chName);
					goto a;
					break;
				case 2:
					printf("请输入新学号:");
					scanf("%s", chStudentId);
					strcpy(Middle[iStudentNumber].chStudentId, chStudentId);
					goto a;
					break;
				case 3:
					printf("请输入英语成绩:");
					scanf("%f", &fEnglish);
					Middle[iStudentNumber].fEnglish = fEnglish;
					goto a;
					break;
				case 4:
					printf("请输入语文成绩:");
					scanf("%f", &fChinese);
					Middle[iStudentNumber].fChinese = fChinese;
					goto a;
					break;
				case 5:
					printf("请输入数学成绩:");
					scanf("%f", &fMath);
					Middle[iStudentNumber].fMath = fMath;
					goto a;
					break;
				case 6:
					printf("请输入物理成绩:");
					scanf("%f", &fPhysical);
					Middle[iStudentNumber].fPhysical = fPhysical;
					goto a;
					break;
				case 7:
					printf("请输入地理成绩:");
					scanf("%f", &fGeography);
					Middle[iStudentNumber].fGeography = fGeography;
					goto a;
					break;
				case 0:
					system("cls");
					fnmodifyMenu();
					break;
				default:
					printf("输入错误!!!");
					goto a;
					system("cls");
					break;
			}
		}
	}
	if (Temp == 0) {
		printf("该学号不存在!!!\n");
		system("pause");
		system("cls");
		fnmodifyMenu();
	}
}

//修改数据菜单函数
void fnmodifyMenu() {
	int iTem;
	printf("************************\n");
	printf("*--1.修改期中学生信息--*\n");
	printf("*                      *\n");
	printf("*--2.修改期末学生信息--*\n");
	printf("*                      *\n");
	printf("*-----0.返回主菜单-----*\n");
	printf("************************\n");
	printf("请选择编号:");
	scanf("%d", &iTem);
	switch (iTem) {
		case 1:
			system("cls");
			fnmodifyMiddle();
			break;
		case 2:
			system("cls");
			fnmodifyFinal();
			break;
		//返回主菜单
		case 0:
			system("cls");
			fnMenu();
			break;
		default:
			printf("输入错误!!!");
			system("cls");
			fnmodifyMenu();
			break;
	}
}

//主菜单函数
void fnMenu() {
	int i;
	system("cls");
	printf("************学生成绩管理系统************\n\n");
	printf("****************************************\n");
	printf("*--1.录入学生信息--**--2.读取学生信息--*\n");
	printf("*                  **                  *\n");
	printf("*--3.保存学生信息--**--4.展示学生信息--*\n");
	printf("*                  **                  *\n");
	printf("*--5.查询学生信息--**--6.修改学生信息--*\n");
	printf("*                  **                  *\n");
	printf("*--7.求成绩平均分--**--8.排序学生信息--*\n");
	printf("*                  **                  *\n");
	printf("*----0.退出程序----**                  *\n");
	printf("*                  **                  *\n");
	printf("****************************************\n\n");
	printf("请输入数字:");
	scanf("%d", &i);
	system("cls");
	switch (i) {
		//跳转到数据录入函数
		case 1:
			fnInput();//数据录入函数
			break;
		//跳转到读取文件函数
		case 2:
			fnReadFile();//读取文件函数
			break;
		//跳转到保存信息函数
		case 3:
			fnSave();//保存信息函数
			break;
		//跳转到数据输出函数
		case 4:
			fnOutput();//学生信息输出函数
			break;
		//跳转到信息查找函数
		case 5:
			fnFindInfo();//信息查找函数
			break;
		//跳转到信息修改函数
		case 6:
			fnmodifyMenu();//信息修改函数
			break;
		//跳转到求平均分函数
		case 7:
			fnAverage();//求平均分函数
			break;
		//跳转到排序函数
		case 8:
			fnSortMenu();
			break;
		//退出程序
		case 0:
			break;
		default:
			printf("请输入正确的数字!!!");
			system("cls");
			fnMenu();
			break;
	}
}

//求平均分
void fnAverage() {
	float fsum[100];
	int iNumber, fMax = 0;
	printf("**************************\n");
	printf("*--1.期中所有学生平均分--*\n");
	printf("*                        *\n");
	printf("*--2.期末所有学生平均分--*\n");
	printf("*                        *\n");
	printf("*--3.期中平均分最高学生--*\n");
	printf("*                        *\n");
	printf("*--4.期末平均分最高学生--*\n");
	printf("*                        *\n");
	printf("*-------0.返回主菜单-----*\n");
	printf("**************************\n");
	printf("请输入数字:");
	scanf("%d", &iNumber);
	switch (iNumber) {
		case 1:
			//计算学生期中成绩平均分
			for (int j = 0; j < Student.iStudent; j++) {
				fsum[j] = Middle[j].fEnglish + Middle[j].fChinese + Middle[j].fMath + Middle[j].fPhysical + Middle[j].fGeography;
				Middle[j].fAverage = fsum[j] / 5;
			}
			printf("姓名\t学号\t英语成绩\t语文成绩\t数学成绩\t物理成绩\t地理成绩\t平均分\n");
			for (int j = 0; j < Student.iStudent; j++) {
				printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Middle[j].chName, Middle[j].chStudentId, Middle[j].fEnglish, Middle[j].fChinese, Middle[j].fMath, Middle[j].fPhysical, Middle[j].fGeography, Middle[j].fAverage);
			}
			system("pause");
			system("cls");
			fnAverage();
			break;
		case 2:
			//计算学生期末成绩平均分
			for (int i = 0; i < Student.iStudent; i++) {
				for (int j = 0; j < 5; j++) {
					fsum[i] = Final[j].fEnglish + Final[j].fChinese + Final[j].fMath + Final[j].fPhysical + Final[j].fGeography;
					Final[i].fAverage = fsum[i] / 5;
				}
				for (int j = 0; j < Student.iStudent; j++) {
					printf("姓名\t学号\t英语成绩\t语文成绩\t数学成绩\t物理成绩\t地理成绩\n");
					printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Final[j].chName, Final[j].chStudentId, Final[j].fEnglish, Final[j].fChinese, Final[j].fMath, Final[j].fPhysical, Final[j].fGeography);
				}
			}
			system("pause");
			system("cls");
			fnAverage();
			break;
		//期中平均分最高学生
		case 3:
			//计算学生期中成绩平均分
			for (int j = 0; j < Student.iStudent; j++) {
				fsum[j] = Middle[j].fEnglish + Middle[j].fChinese + Middle[j].fMath + Middle[j].fPhysical + Middle[j].fGeography;
				Middle[j].fAverage = fsum[j] / 5;
			}
			//求最大平均分下标
			for (int j = 0; j < Student.iStudent; j++) {
				if (Middle[fMax].fAverage < Middle[j + 1].fAverage) {
					fMax = j;
				}
			}
			printf("姓名\t学号\t英语成绩\t语文成绩\t数学成绩\t物理成绩\t地理成绩\n");
			printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Middle[fMax].chName, Middle[fMax].chStudentId, Middle[fMax].fEnglish, Middle[fMax].fChinese, Middle[fMax].fMath, Middle[fMax].fPhysical, Middle[fMax].fGeography);
			system("pause");
			system("cls");
			fnAverage();
			break;
		//期末平均分最高学生
		case 4:
			//计算学生期末成绩平均分
			for (int j = 0; j < Student.iStudent; j++) {
				fsum[j] = Middle[j].fEnglish + Middle[j].fChinese + Middle[j].fMath + Middle[j].fPhysical + Middle[j].fGeography;
				Middle[j].fAverage = fsum[j] / 5;
			}
			//求最大平均分下标
			for (int j = 0; j < Student.iStudent; j++) {
				if (Middle[fMax].fAverage < Middle[j + 1].fAverage) {
					fMax = j;
				}
			}
			printf("姓名\t学号\t英语成绩\t语文成绩\t数学成绩\t物理成绩\t地理成绩\n");
			printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", Final[fMax].chName, Final[fMax].chStudentId, Final[fMax].fEnglish, Final[fMax].fChinese, Final[fMax].fMath, Final[fMax].fPhysical, Final[fMax].fGeography);
			system("pause");
			system("cls");
			fnAverage();
			break;
		//返回主菜单
		case 0:
			system("cls");
			fnMenu();
			break;
		default:
			printf("输入错误!!!");
			system("cls");
			fnAverage();
			break;
	}

}

//数据录入函数
void fnInput() {
	int j = 0, iNumber;
a:
	printf("******************\n");
	printf("*---1.期中成绩---*\n");
	printf("*                *\n");
	printf("*---2.期末成绩---*\n");
	printf("*                *\n");
	printf("*--0.返回主菜单--*\n");
	printf("******************\n");
	printf("请输入数字:");
	scanf("%d", &iNumber);
	switch (iNumber) {
		case 1:
			printf("学生人数:");
			scanf("%d", &Student.iStudent);
			//循环输入学生姓名、学号、成绩
			for (; j < Student.iStudent; j++) {
				printf("第%d名学生\n", j + 1);
				printf("姓名:");
				scanf("%s", Middle[j].chName);
				printf("学号:");
				scanf("%s", Middle[j].chStudentId);
				printf("英语课成绩:");
				scanf("%f", &Middle[j].fEnglish);
				printf("语文课成绩:");
				scanf("%f", &Middle[j].fChinese);
				printf("数学课成绩:");
				scanf("%f", &Middle[j].fMath);
				printf("物理课成绩:");
				scanf("%f", &Middle[j].fPhysical);
				printf("地理课成绩:");
				scanf("%f", &Middle[j].fGeography);
			}
			system("cls");
			goto a;
			break;
		case 2:
			printf("学生人数:");
			scanf("%d", &Student.iStudent);
			//循环输入学生姓名、学号、成绩
			for (; j < Student.iStudent; j++) {
				printf("第%d名学生\n", j + 1);
				printf("姓名:");
				scanf("%s", Final[j].chName);
				printf("学号:");
				scanf("%s", Final[j].chStudentId);
				printf("英语课成绩:");
				scanf("%f", &Final[j].fEnglish);
				printf("语文课成绩:");
				scanf("%f", &Final[j].fChinese);
				printf("数学课成绩:");
				scanf("%f", &Final[j].fMath);
				printf("物理课成绩:");
				scanf("%f", &Final[j].fPhysical);
				printf("地理课成绩:");
				scanf("%f", &Final[j].fGeography);
			}
			system("cls");
			goto a;
			break;
		case 0:
			fnMenu();
			break;
		default:
			printf("输入错误!!!\n");
			system("pause");
			system("cls");
			fnInput();
			break;
	}
}

//保存信息函数
void fnSave() {
	FILE *fp;
	int iNumber;
	printf("********************\n");
	printf("*--1.保存期中成绩--*\n");
	printf("*                  *\n");
	printf("*--2.保存期末成绩--*\n");
	printf("********************\n");
	printf("请输入数字:");
	scanf("%d", &iNumber);
	switch (iNumber) {
		//保存期中成绩
		case 1:
			printf("文件名称:");
			scanf("%s", Student.chMiddleFileName);
			fp = fopen(strcat(Student.chMiddleFileName, ".txt"), "w");
			for (int j = 0; j < Student.iStudent; j++) {
				fprintf(fp, "%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", Middle[j].chName, Middle[j].chStudentId, Middle[j].fEnglish, Middle[j].fChinese, Middle[j].fMath, Middle[j].fPhysical, Middle[j].fGeography);
			}
			printf("保存成功!!!\n");
			printf("文件保存在当前程序文件夹下\n");
			fclose(fp);//关闭文件
			break;
		//保存期末成绩
		case 2:
a:
			printf("文件名称:");
			scanf("%s", Student.chFinalFileName);
			//判断与期中成绩文件名称是否相同
			if (strcmp(Student.chMiddleFileName, strcat(Student.chFinalFileName, ".txt")) == 0) {
				printf("与期中成绩文件名称相同!请重新输入文件名!\n");
				system("pause");
				system("cls");
				goto a;
			}
			fp = fopen(strcat(Student.chFinalFileName, ".txt"), "w");
			for (int j = 0; j < Student.iStudent; j++) {
				fprintf(fp, "%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", Final[j].chName, Final[j].chStudentId, Final[j].fEnglish, Final[j].fChinese, Final[j].fMath, Final[j].fPhysical, Final[j].fGeography);
			}
			printf("保存成功!!!\n");
			printf("文件保存在当前程序文件夹下\n");
			fclose(fp);//关闭文件
			break;
		default:
			printf("输入错误!!!");
			break;
	}
	printf("\n");
	printf("输入0返回主菜单:");
	scanf("%d", &iNumber);
	switch (iNumber) {
		//返回主菜单
		case 0:
			fnMenu();//主菜单函数
			break;
		default:
			printf("输入错误!!!");
	}
}

//输出函数
void fnOutput() {
	//输出所有学生信息
	printf("***期中成绩***\n");
	for (int j = 0; j < Student.iStudent; j++) {
		printf("第%d名学生\n", j + 1);
		printf("姓名:%s\n", Middle[j].chName);
		printf("学号:%s\n", Middle[j].chStudentId);
		printf("英语课成绩:%.2f\n", Middle[j].fEnglish);
		printf("语文课成绩:%.2f\n", Middle[j].fChinese);
		printf("数学课成绩:%.2f\n", Middle[j].fMath);
		printf("物理课成绩:%.2f\n", Middle[j].fPhysical);
		printf("地理课成绩:%.2f\n", Middle[j].fGeography);
	}
	printf("\n");
	printf("***期末成绩***\n");
	for (int j = 0; j < Student.iStudent; j++) {
		printf("第%d名学生\n", j + 1);
		printf("姓名:%s\n", Final[j].chName);
		printf("学号:%s\n", Final[j].chStudentId);
		printf("英语课成绩:%.2f\n", Final[j].fEnglish);
		printf("语文课成绩:%.2f\n", Final[j].fChinese);
		printf("数学课成绩:%.2f\n", Final[j].fMath);
		printf("物理课成绩:%.2f\n", Final[j].fPhysical);
		printf("地理课成绩:%.2f\n", Final[j].fGeography);
	}
	printf("\n任意键返回主菜单\n");
	system("pause");
	system("cls");
	fnMenu();//主菜单函数
}

//信息查找
void fnFindInfo() {
	int iNumber, j, iTemp = 0;
	char chMiddleStudentId[30], chMiddleStudenName[30];
	char chFinalStudentId[30], chFinalStudenName[30];
	printf("********************\n");
	printf("*--1.查找期中成绩--*\n");
	printf("*                  *\n");
	printf("*--2.查找期末成绩--*\n");
	printf("*                  *\n");
	printf("*---0.返回主菜单---*\n");
	printf("********************\n");
	printf("请输入数字:");
	scanf("%d", &iNumber);
	switch (iNumber) {
		//查找期中成绩
		case 1:
			while (1) {
				system("cls");
				printf("********************\n");
				printf("*---1.按学号查询---*\n");
				printf("*                  *\n");
				printf("*---2.按姓名查询---*\n");
				printf("*                  *\n");
				printf("*--0.返回上级菜单--*\n");
				printf("********************\n");
				printf("请选择子菜单编号:");
				scanf("%d", &iNumber);
				switch (iNumber) {
					//按学号查询学生信息
					case 1:
						printf("请输入要查询的学生的学号:");
						scanf("%s", chMiddleStudentId);
						//输出学生信息
						for (j = 0; j < Student.iStudent; j++)
							if (strcmp(Middle[j].chStudentId, chMiddleStudentId) == 0) {
								iTemp = 1;
								printf("姓名:%s\n", Middle[j].chName);
								printf("学号:%s\n", Middle[j].chStudentId);
								printf("英语课成绩:%.2f\n", Middle[j].fEnglish);
								printf("语文课成绩:%.2f\n", Middle[j].fChinese);
								printf("数学课成绩:%.2f\n", Middle[j].fMath);
								printf("物理课成绩:%.2f\n", Middle[j].fPhysical);
								printf("地理课成绩:%.2f\n", Middle[j].fGeography);
							}
						if (iTemp == 0) {
							printf("该学号不存在!!!\n");
						}
						system("pause");//暂停程序,用户按任意键结束
						break;
					//按姓名查询学生信息
					case 2:
						printf("请输入要查询的学生的姓名:");
						scanf("%s", chMiddleStudenName);
						//输出学生信息
						for (j = 0; j < Student.iStudent; j++)
							if (strcmp(Middle[j].chName, chMiddleStudenName) == 0) {
								iTemp = 1;
								printf("第%d名学生\n", j + 1);
								printf("姓名:%s\n", Middle[j].chName);
								printf("学号:%s\n", Middle[j].chStudentId);
								printf("英语课成绩:%.2f\n", Middle[j].fEnglish);
								printf("语文课成绩:%.2f\n", Middle[j].fChinese);
								printf("数学课成绩:%.2f\n", Middle[j].fMath);
								printf("物理课成绩:%.2f\n", Middle[j].fPhysical);
								printf("地理课成绩:%.2f\n", Middle[j].fGeography);
							}
						if (iTemp == 0) {
							printf("该姓名不存在!!!\n");
						}
						system("pause");//暂停程序,用户按任意键结束
						break;
					//返回上级菜单
					case 0:
						system("cls");//清屏
						fnFindInfo();//查找信息函数
						break;
					default:
						printf("输入错误!!!\n");
				}
			}
			break;
		//查找期末成绩
		case 2:
			while (1) {
				system("cls");
				printf("********************\n");
				printf("*---1.按学号查询---*\n");
				printf("*                  *\n");
				printf("*---2.按姓名查询---*\n");
				printf("*                  *\n");
				printf("*--0.返回上级菜单--*\n");
				printf("********************\n");
				printf("请选择子菜单编号:");
				scanf("%d", &iNumber);
				switch (iNumber) {
					//按学号查询学生信息
					case 1:
						printf("请输入要查询的学生的学号:");
						scanf("%s", chFinalStudenName);
						//输出学生信息
						for (j = 0; j < Student.iStudent; j++)
							if (strcmp(Final[j].chStudentId, chFinalStudentId) == 0) {
								iTemp = 1;
								printf("姓名:%s", Final[j].chName);
								printf("学号:%s", Final[j].chStudentId);
								printf("英语课成绩:%.2f", Final[j].fEnglish);
								printf("语文课成绩:%.2f", Final[j].fChinese);
								printf("数学课成绩:%.2f", Final[j].fMath);
								printf("物理课成绩:%.2f", Final[j].fPhysical);
								printf("地理课成绩:%.2f", Final[j].fGeography);
							}
						if (iTemp == 0) {
							printf("该学号不存在!!!\n");
						}
						system("pause");//暂停程序,用户按任意键结束
						break;
					//按姓名查询学生信息
					case 2:
						printf("请输入要查询的学生的姓名:");
						scanf("%s", chFinalStudenName);
						//输出学生信息
						for (j = 0; j < Student.iStudent; j++)
							if (strcmp(Final[j].chName, chFinalStudenName) == 0) {
								iTemp = 1;
								printf("第%d名学生\n", j + 1);
								printf("姓名:%s", Final[j].chName);
								printf("学号:%s", Final[j].chStudentId);
								printf("英语课成绩:%.2f", Final[j].fEnglish);
								printf("语文课成绩:%.2f", Final[j].fChinese);
								printf("数学课成绩:%.2f", Final[j].fMath);
								printf("物理课成绩:%.2f", Final[j].fPhysical);
								printf("地理课成绩:%.2f", Final[j].fGeography);
							}
						if (iTemp == 0) {
							printf("该姓名不存在!!!\n");
						}
						system("pause");//暂停程序,用户按任意键结束
						break;
					//返回上级菜单
					case 0:
						system("cls");//清屏
						fnFindInfo();//查找信息单函数
						break;
					default:
						printf("输入错误!!!\n");
				}
			}
			break;
		case 0:
			fnMenu();
			break;
		default:
			printf("输入错误!!!");
			break;
	}
}

//读取文件信息
void fnReadFile() {
	FILE *fp;
	int j = 0, iTemp;
	char chFileName[50];
	printf("************************\n");
	printf("*--1.读取期中文件信息--*\n");
	printf("*                      *\n");
	printf("*--2.读取期末文件信息--*\n");
	printf("*                      *\n");
	printf("*------0.返回主函数----*\n");
	printf("************************\n");
	printf("请输入数字:");
	scanf("%d", &iTemp);
	switch (iTemp) {
		case 1:
			printf("文件需要与程序在同一文件夹！！！\n\n");
			printf("请输入文件名称:");
			scanf("%s", chFileName);
			if ((fp = fopen(strcat(chFileName, ".txt"), "r")) == NULL) {
				printf("打开文件%s错误\n", chFileName);
				system("pause");
				system("cls");
				fnReadFile();
			} else {
				while ( !feof(fp)) {
					fscanf(fp, "%s%s%f%f%f%f%f", Middle[j].chName, Middle[j].chStudentId, &Middle[j].fEnglish, &Middle[j].fChinese, &Middle[j].fMath, &Middle[j].fPhysical, &Middle[j].fGeography);
					j++;
				}
				Student.iStudent=j-1;
				if (j == 0) {
					printf("文件中无信息!!!\n\n");
					system("pause");
					fnMenu();
				} else if (j != 0) {
					{
						printf("信息读取成功!!!\n\n");
					}
					fclose(fp);//关闭文件
					printf("\n任意键返回上级菜单\n");
					system("pause");
					system("cls");
					fnReadFile();//主菜单函数
				}
			}
			break;
		case 2:
			printf("文件需要与程序在同一文件夹！！！\n\n");
			printf("请输入文件名称:");
			scanf("%s", chFileName);
			if ((fp = fopen(strcat(chFileName, ".txt"), "r")) == NULL) {
				printf("打开文件%s错误\n", chFileName);
				system("pause");
				system("cls");
				fnReadFile();
			} else {
				while ( !feof(fp)) {
					fscanf(fp, "%s%s%f%f%f%f%f", Final[j].chName, Final[j].chStudentId, &Final[j].fEnglish, &Final[j].fChinese, &Final[j].fMath, &Final[j].fPhysical, &Final[j].fGeography);
					j++;
				}
				Student.iStudent=j-1;
				if (j == 0) {
					printf("文件中无信息!!!\n\n");
					system("pause");
					fnMenu();
				} else if (j != 0) {
					{
						printf("信息读取成功!!!\n\n");
					}
					fclose(fp);//关闭文件
					printf("\n任意键返回上级菜单\n");
					system("pause");
					system("cls");
					fnReadFile();//主菜单函数
				}
			}
			break;
		case 0:
			system("cls");
			fnMenu();
			break;
		default:
			printf("输入错误!!!\n");
			system("pause");
			system("cls");
			fnReadFile();
			break;
	}

}

//主函数
int main(void) {
	fnMenu();//菜单函数
}
