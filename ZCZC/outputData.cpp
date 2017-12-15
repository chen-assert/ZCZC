#include "global.h"
void write() {
	FILE *fp;
	fp = fopen("..\\stuInfo.txt", "w+");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}
	for (int i = 0; i < 100; i++) {
		fprintf(fp, "%s ", stuInfo[i].number);
		fprintf(fp, "%s ", stuInfo[i].name);
		fprintf(fp, "%d ", stuInfo[i].college);
		fprintf(fp, "%d ", stuInfo[i].sex);
		for (int o = 0; o < 10; o++) {
			fprintf(fp, "%d ", stuInfo[i].grade[o]);
		}
		fprintf(fp, "\n");
	}
	printf("----修改文件完成----\n");
	fclose(fp);
}