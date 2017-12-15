#include "global.h"
void output() {
	for (int i = 0; i < 100; i++) {
		printf("%-8s %-8s %-18s %-12s ", stuInfo[i].number, stuInfo[i].name, college[stuInfo[i].college].c_str(),sex[stuInfo[i].sex].c_str());
		int sum = 0;
		for (int o = 0; o < 10; o++) {
			printf("%-3d ", stuInfo[i].grade[o]);
			sum += stuInfo[i].grade[o];
		}
		printf("sum grade is %d", sum);
		printf("\n");
	}
}
void outputCollege(int number) {
	int flag = 0;
	for (int i = 0; i < 100; i++) {
		if (stuInfo[i].college == number) {
			flag++;
			printf("%-8s %-8s %-18s %-12s ", stuInfo[i].number, stuInfo[i].name, college[stuInfo[i].college].c_str(), sex[stuInfo[i].sex].c_str());
			int sum = 0;
			for (int o = 0; o < 10; o++) {
				printf("%-3d ", stuInfo[i].grade[o]);
				sum += stuInfo[i].grade[o];
			}
			printf("sum grade is %d", sum);
			printf("\n");
		}
	}
	if (flag == 0)printf("can't find any student in this college\n");
}
void outputName(std::string name) {
	int flag = 0;
	for (int i = 0; i < 100; i++) {
		if ((std::string)stuInfo[i].name == name) {
			flag++;
			printf("%-8s %-8s %-16s %-12s ", stuInfo[i].number, stuInfo[i].name, college[stuInfo[i].college].c_str(), sex[stuInfo[i].sex].c_str());
			int sum = 0;
			for (int o = 0; o < 10; o++) {
				printf("%-3d ", stuInfo[i].grade[o]);
				sum += stuInfo[i].grade[o];
			}
			printf("sum grade is %d", sum);
			printf("\n");
		}
	}
	if (flag == 0)printf("can't find any student in this name\n");
}