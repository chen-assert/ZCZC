#include "global.h"
void write() {
	FILE *fp;
	fp = fopen("..\\stuInfo.txt", "w+");
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
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
	printf("----�޸��ļ����----\n");
	fclose(fp);
}