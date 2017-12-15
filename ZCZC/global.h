#include<string>
#include<map>
#include<stdio.h>
#include <stdlib.h>
#include <algorithm>
#include<iostream>
#include<cstring>
struct STU
{
	char number[20];
	char name[20];
	int college;
	int sex;
	int grade[10];
};
extern STU stuInfo[100];
extern std::map<long long, std::string>sex;
extern std::map<long long, std::string>college;
void read();
void write();
void output();
void outputCollege(int number);
void outputName(std::string name);
int check();
int change();