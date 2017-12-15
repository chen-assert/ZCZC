#include "global.h"
int interFaceFlag = 0;
void showInterface() {
	if (interFaceFlag == 0) {
		while (check() != 1) {}
		interFaceFlag = 1;
	}
	printf("******ѧ���ɼ�ϵͳ�˵�******\n");
	printf("1.ԭʼ�ļ���ȡ(��ǰ��ִ��)\n");
	printf("2.�������������\n");
	printf("3.��ƽ���ɼ�����,���\n");
	printf("4.�������ѧԺѧ��\n");
	printf("5.�޸ĸ���ѧ���ɼ�\n");
	printf("6.��������ѯѧ��,���\n");
	printf("7.�޸�ϵͳ����\n");
	printf("0.������һ���˵�\n");
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
			printf("������Ҫ�����ѧԺ���:");
			int number;
			scanf("%d", &number);
			outputCollege(number);
			break;
		}
		case 5: {
			printf("������Ҫ�޸ĵ�ѧ����ѧ��:");
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
			printf("������Ҫ�޸ĵĳɼ����(1-10):");
			int t, g;
			scanf("%d", &t);
			t--;
			printf("������Ҫ�޸ĵ��ĳɼ�:");
			scanf("%d", &g);
			stuInfo[find].grade[t] = g;
			write();
			break;
		}
		case 6: {
			printf("������Ҫ��ѯ��ѧ������:");
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
			printf("�и�ƨ�ϼ��˵���\n"); break;
		}
		default:
			printf("error! ��������ȷ������\n");
		}
	}
}

