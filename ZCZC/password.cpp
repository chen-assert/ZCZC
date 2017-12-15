#include"global.h"
#define DEBUG 1
int check() {
	FILE *fp4;
	printf("please entry now password:");
#ifdef DEBUG
	fp4 = fopen("..\\password.txt", "r");
	printf("(debug:now password is ");
	char c;
	while (fscanf(fp4, "%c", &c) != EOF) {
		printf("%c", c ^ 0x25);
	}
	printf(")");
	fclose(fp4);
#endif // DEBUG
	fp4 = fopen("..\\password.txt", "r");
	char secret[50];
	scanf("%s", secret);
	int i = 0;
	while (fscanf(fp4, "%c", &c) != EOF) {
		if (secret[i] != (c ^ 0x25)) {
			printf("password error!\n");
			return -1;
		}
		i++;
	}
	if (strlen(secret) != i) {
		printf("password error!\n");
		return -1;
	}
	return 1;
}
int change() {
	FILE *fp4;
	printf("please entry new password:");
	char secret[50];
	scanf("%s", secret);
	fp4 = fopen("..\\password.txt", "w+");
	for (int i = 0; i < strlen(secret); i++) {
		fprintf(fp4, "%c", secret[i] ^ 0x25);
		//using XOR to save password
	}
	fclose(fp4);
	return 0;
}