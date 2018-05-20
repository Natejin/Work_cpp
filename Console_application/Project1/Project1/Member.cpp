#include "Member.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Member_Member(Member *member,int mnum,const char *mname);
Member *Member_New(int mnum, const char *mname)
{
	Member *member = 0;
	member = (Member *)malloc(sizeof(Member));
	Member_Member(member, mnum, mname);
	return member;
}
void Member_Member(Member *member, int mnum, const char *mname)
{
	member->mnum = mnum;
	memset(member->mname, 0, sizeof(member->mname));
	strncpy_s(member->mname, mname, MAX_NAME_LEN);
}
void Member_Delete(Member *member) 
{
	free(member);
}
int Member_GetNum(Member *member)
{
	return 0;
}
const char *Member_GetName(Member *member)
{
	return 0;
}
void Member_View(Member *member)
{
	printf("번호:%d 이름:%s\n", member->mnum, member->mname);
}