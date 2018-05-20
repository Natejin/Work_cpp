#include "Dynamic_Allocation_example.h"
#include "Classprop.h"
#include "ComFunc.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <assert.h>
#include <stdlib.h>

void Student_Student(Student *stu, const char *name, int num);
Student *New_Student(const char *name, int num)//give name when create student
{
	Student *stu = 0;
	stu = (Student *)calloc(0, sizeof(Student));
	Student_Student(stu, name, num);
	return stu;
}
void Student_Student(Student *stu, const char *name, int num)
{
	strcpy_s(stu->name, MAX_NAME_LEN1, name);
	stu->num = num;
}
//void Student_TStudent(Student *stu);
void Delete_Student(Student *stu)//delete student
{
	/*tudent_TStudent(stu);*/
	free(stu);
}
void Student_Study(Student *stu)//student study
{
	printf("%d, %s student study\n", stu->num, stu->name);
}
void Student_View(Student *stu)//view student
{
	printf("number : %d, name : %s\n", stu->num, stu->name);
}