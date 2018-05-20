#pragma once
typedef struct _Member Member;

#define MAX_NAME_LEN 20

struct _Member
{
	int mnum;
	char mname[MAX_NAME_LEN + 1];
};

Member *Member_New(int mnum, const char *mname);
void Member_Delete(Member *member);
int Member_GetNum(Member *member);
const char *Member_GetName(Member *member);
void Member_View(Member *member);
