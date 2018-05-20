#pragma once

typedef struct _Student Student;
#define MAX_NAME_LEN1 20

struct _Student //student
{
	char name[MAX_NAME_LEN1]; //student name
	int num;				 //student num.
};

Student *New_Student(const char *name,int num);//give name when create student
void Delete_Student(Student *stu);//delete student
void Student_Study(Student *stu);//student study
void Student_View(Student *stu);//view student
