#include "global.h"
void read() {
	FILE *fp, *fp2, *fp3, *fp4;
	fp = fopen("..\\stuInfo.txt", "r");
	fp2 = fopen("..\\collegeCode.txt", "r");
	fp3 = fopen("..\\sexCode.txt", "r");
	fp4 = fopen("..\\password.txt", "r");
	if (fp == NULL || fp2 == NULL || fp3 == NULL|| fp4==NULL) {
		printf("打开文件失败\n");
		return;
	}
	for (int i = 0; i < 100; i++) {
		fscanf(fp, "%s", stuInfo[i].number);
		fscanf(fp, "%s", stuInfo[i].name);
		fscanf(fp, "%d", &stuInfo[i].college);
		fscanf(fp, "%d", &stuInfo[i].sex);
		for (int o = 0; o < 10; o++) {
			fscanf(fp, "%d", &stuInfo[i].grade[o]);
		}
	}
	int ti;
	char tc[50];
	while (fscanf(fp2, "%d %s", &ti, tc) != EOF) {
		college[ti] = (std::string)tc;
	}
	while (fscanf(fp3, "%d %s", &ti, tc) != EOF) {
		sex[ti] = (std::string)tc;
	}
	//using std::map to save college and sex information
	//crap
	printf("----读取文件完成----\n");
	fclose(fp);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
}