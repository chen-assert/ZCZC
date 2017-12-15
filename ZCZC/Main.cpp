#include "global.h"
int interFaceFlag = 0;
void showInterface() {
	if (interFaceFlag == 0) {
		while (check() != 1) {}
		interFaceFlag = 1;
	}
	printf("******学生成绩系统菜单******\n");
	printf("1.原始文件读取(需前置执行)\n");
	printf("2.按姓名排序输出\n");
	printf("3.按平均成绩排序,输出\n");
	printf("4.输出给定学院学生\n");
	printf("5.修改给定学生成绩\n");
	printf("6.按姓名查询学生,输出\n");
	printf("7.修改系统密码\n");
	printf("0.返回上一级菜单\n");
}
int cmp_name(STU a, STU b) {
	int t = strcmp(a.name, b.name);
	if (t < 0)return 1;
	else return 0;
}
int cmp_grade(STU a, STU b) {
	int asum = 0, bsum = 0;
	for (int i = 0; i < 10; i++) {
		asum += a.grade[i];
		bsum += b.grade[i];
	}
	return asum > bsum;
}

void nameSort() {
	std::sort(stuInfo, stuInfo + 100, cmp_name);
	output();
}
void gradeSort() {
	std::sort(stuInfo, stuInfo + 100, cmp_grade);
	output();
}
int main() {
	while (1) {
		showInterface();
		int order;
		scanf("%d", &order);
		//system("cls");
		//abandon
		switch (order) {
		case 1:read(); break;
		case 2:nameSort(); break;
		case 3:gradeSort(); break;
		case 4: {
			printf("请输入要输出的学院编号:");
			int number;
			scanf("%d", &number);
			outputCollege(number);
			break;
		}
		case 5: {
			printf("请输入要修改的学生的学号:");
			char number[20];
			scanf("%s", number);
			int find = -1;
			for (int i = 0; i < 100; i++) {
				if (strcmp(stuInfo[i].number, number) == 0) {
					find = i;
					break;
				}
			}
			if (find == -1) {
				printf("can't find this student\n");
				break;
			}
			printf("请输入要修改的成绩序号(1-10):");
			int t, g;
			scanf("%d", &t);
			t--;
			printf("请输入要修改到的成绩:");
			scanf("%d", &g);
			stuInfo[find].grade[t] = g;
			write();
			break;
		}
		case 6: {
			printf("请输入要查询的学生名字:");
			std::string name;
			std::cin >> name;
			outputName(name);
			break;
		}
		case 7: {
			if (check() == -1) {
				break;
			}
			else {
				change();
			}
			break;
		}
		case 0: {
			interFaceFlag = 0;
			printf("有个屁上级菜单啊\n"); break;
		}
		default:
			printf("error! 请输入正确的命令\n");
		}
	}
}

