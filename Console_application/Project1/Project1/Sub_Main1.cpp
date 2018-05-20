#include "Classprop.h"
#include "ComFunc.h"
#include "Dynamic_Allocation_example.h"
#include "Member.h"
#include "EHArray.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <assert.h>
#include <stdlib.h>




//define
#define MAX_NAME_LEN 50

//case 1
void TestGetSumInBoundary();
void TestIsPrime();
void TestFindBig();
//case 2 (array)
void TestArr();
void Test_strlen();
void Test_strcmp();
void Test_strcpy();
//case 3 (typedef)
void Test_struct();
void Test_union();
void Test_enum();
//case 4 (game test)
void Test_game();
//case 5 (memory)
void Test_memory();
void Test_malloc1();
void Test_malloc2();
void Test_realloc();
void Dynamic_Allocation_Example();
void Dynamic_Array_Example_Seq();
void Dynamic_Array_Example_Index();
//case 6 (input/output)
void File_inoutput();
int Control_member_list();
//void TestGetCountIsPrime();
//void TestGetSum();
//void TestSwap();
//void TestGetMaxPos();
//void TestSelectionSort();

//void TestGetSumInBoundary(void);

//int GetSumInBoundary(int start, int end);
//void TestGetSumInBoundary(void);
//void TestIsPrime(void);
//void TestGetCountIsPrime(void);

int main() {
	MakeChoice:
	int n;
	printf("\n ======================= \n\n");
	printf("1 : common function\n");
	printf("2 : array\n");
	printf("3 : typedef\n");
	printf("4 : game test1\n");
	printf("5 : memory\n");
	printf("6 : input/output\n");
	printf("7 : Control_member_list\n");
	printf("\n ======================= \n\n");
	printf("Input value : ");
	scanf_s("%d", &n);
	printf("\n ----------------------- \n\n");
	switch (n) {
	case 1: {
		TestGetSumInBoundary();
		TestIsPrime();
		TestFindBig();
		goto MakeChoice;
		break; }
	case 2: {
		printf("\n ======================= \n\n");
		printf("1 : Array\n");
		printf("2 : strlen\n");
		printf("3 : strcmp\n");
		printf("4 : strcpy\n");
		printf("\n ======================= \n\n");
		printf("Input value : ");
		scanf_s("%d", &n);
		printf("\n ----------------------- \n\n");
		switch (n) {
		case 1:
			TestArr();
			goto MakeChoice;
			break;
		case 2:
			Test_strlen();
			goto MakeChoice;
			break;
		case 3:
			Test_strcmp();
			goto MakeChoice;
			break;
		case 4:
			Test_strcpy();
			goto MakeChoice;
			break;
		default:
			printf("wrong input value.\n");
			goto MakeChoice;
			break;
		}
	}
	case 3: {
		printf("\n ======================= \n\n");
		printf("1 : Struct\n");
		printf("2 : union\n");
		printf("3 : enum\n");
		//printf("4 : strcpy\n");
		printf("\n ======================= \n\n");
		printf("Input value : ");
		scanf_s("%d", &n);
		printf("\n ----------------------- \n\n");
		switch (n) {
		case 1:
			Test_struct();
			goto MakeChoice;
			break;
		case 2:
			Test_union();
			goto MakeChoice;
			break;
		case 3:
			Test_enum();
			goto MakeChoice;
			break;
		default:
			printf("wrong input value.\n");
			goto MakeChoice;
			break;
		}

	}
	case 4: {
		Test_game();
		goto MakeChoice;
		break;
	}
	case 5: {
		printf("\n ======================= \n\n");
		printf("1 : memory\n");
		printf("2 : malloc\n");
		printf("3 : malloc+calloc\n");
		printf("4 : realloc\n");
		printf("5 : Dynamic Allocation example\n");
		printf("6 : Dynamic_Array_Example_Seq\n");
		printf("7 : Dynamic_Array_Example_index\n");
		printf("\n ======================= \n\n");
		printf("Input value : ");
		scanf_s("%d", &n);
		printf("\n ----------------------- \n\n");
		switch (n) {
		case 1:
			Test_memory();
			goto MakeChoice;
			break;
		case 2:
			Test_malloc1();
			goto MakeChoice;
			break;
		case 3:
			Test_malloc2();
			goto MakeChoice;
			break;
		case 4:
			Test_realloc();
			goto MakeChoice;
			break;
		case 5:
			Dynamic_Allocation_Example();
			goto MakeChoice;
			break;
		case 6:
			Dynamic_Array_Example_Seq();
			goto MakeChoice;
			break;
		case 7:
			Dynamic_Array_Example_Index();
			goto MakeChoice;
			break;
		default:
			printf("wrong input value.\n");
			goto MakeChoice;
			break;
		}
	}
	case 6:
		File_inoutput();
		goto MakeChoice;
		break;
	case 7:
		Control_member_list();
		goto MakeChoice;
		break;
	default:
		printf("wrong input value.\n");
		goto MakeChoice;
		break;
	}
	return 0;
}

//case 1
void TestGetSumInBoundary() {
	int start, end;
	scanf_s("%d %d", &start, &end);
	printf("%d\n", GetSumInBoundary(start, end));
}
void TestIsPrime() {
	int val;
	scanf_s("%d", &val);
	printf("%d\n", IsPrime(val));
}
void TestFindBig() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d\n", FindBig(a, b));
}

//case 2 
void TestArr() {
	char name1[6] = "hello";
	char name2[6] = "hello";
	const char *str1 = "yahoo";
	const char *str2 = "yahoo";

	printf("name1: %p name2:%p\n", name1, name2);
	printf("str1: %p str2:%p\n", str1, str2);

	name1[0] = 'y';
	//str1[0] = 'k'; //값을 변경할 수 없음
	printf("name1: %s name2: %s\n", name1, name2);
	printf("str1: %s str2: %s\n", str1, str2);
}
void Test_strlen() {
	char c = 'a';
	wchar_t wc = L'홍';
	char name[10] = "홍길동";
	wchar_t wname[10] = L"홍길동";
	setlocale(LC_ALL, "Korean"); //로케일 설정(지역 설정)
	printf("c:%c wc:%lc\n", c, wc);
	printf("name:%s wname:%ls\n", name, wname);
	printf("name 길이:%zd wname 길이:%zd\n", strlen(name), wcslen(wname));
}
void Test_strcmp() {
	char name1[MAX_NAME_LEN + 1] = "hello";
	char name2[MAX_NAME_LEN + 1] = "hello world";
	if (strcmp(name1, name2) == 0)  // 앞쪽이 크면 양수 뒷쪽이 크면 음수
	{
		printf("%s 와 %s는 같다.\n", name1, name2);
	}
	else
	{
		printf("%s 와 %s는 다르다.\n", name1, name2);
	}
	if (strncmp(name1, name2, 5) == 0) // 앞쪽이 크면 양수 뒷쪽이 크면 음수
	{
		printf("%s 와 %s의 %d개의 문자는 같다.\n", name1, name2, 5);
	}
	else
	{
		printf("%s 와 %s의 %d개의 문자는 다르다.\n", name1, name2, 5);
	}
}

void Test_strcpy() {
	char name1[MAX_NAME_LEN + 1] = "hello";
	char name2[MAX_NAME_LEN + 1] = "";
	char name3[MAX_NAME_LEN + 1] = "";

	strcpy_s(name2, sizeof(name2), name1);
	printf("%s\n", name2);
	strncpy_s(name3, sizeof(name3), name1, 3);
	printf("%s\n", name3);
}

//case 3
	/*Struct*/
#define MAX_ID_LEN     20
#define MAX_ADDR_LEN   100
struct _Struct_Member
{

	char id[MAX_ID_LEN + 1];
	char name[MAX_NAME_LEN + 1];
	char addr[MAX_ADDR_LEN + 1];
	int gender;
	int age;

};
typedef struct _Struct_Member   StruMember;
void SetAge(StruMember *strumember, int age);
void Test_struct() {
	StruMember strumember[100] = { "" };

	//member 1
	strcpy_s(strumember[0].id, "jejutour");
	strcpy_s(strumember[0].name, "장언휴");
	strcpy_s(strumember[0].addr, "제주도 제주시 애월읍 고내리");
	strumember[0].age = 20;
	strumember[0].gender = 1;

	//member 2
	strumember[1] = { "natejin","natejin1","natejin2",1,40 };

	//print
	for (int index = 0; index <= 2; index++) {
		printf("아이디:%s 이름:%s \n", strumember[index].id, strumember[index].name);
		printf("주소:%s 나이:%d 성별:%d\n\n", strumember[index].addr, strumember[index].age, strumember[index].gender);
	}
	SetAge(&strumember[1], 25);
	printf("(OutFunc) 나이 : %d\n", strumember[1].age);
}
void SetAge(StruMember *strumember, int age)
{
	strumember->age = age;
	printf("(InFunc) 나이 : %d\n", strumember->age);
}
/*Union*/
void Test_union() {

	typedef union _Demo Demo;
	union _Demo
	{
		int i;
		short int s[2];
		char c[4];
		int t[8];
	};
	Demo data;
	data.i = 0x12345678;

	printf("i : 0x%x \ns[0] : 0x%x, s[1] : 0x%x \nc[0] : 0x%x, c[1] : 0x%x, c[2] : 0x%x, c[3] : 0x%x \n", data.i, data.s[0], data.s[1], data.c[0], data.c[1], data.c[2], data.c[3]);
	for (int m = 0; m <= 8; m++) {
		printf("t[%d]=%x\n", m, data.t[m]);
	}
	/*
	printf("i:=0x%x\n s[0]:=    \n", d.i, d.f, d.s, d.c);
	d.f = 1.0;
	printf("d.i: %10d d.f:%0.2f\n", d.i, d.f, d.a);
	d.i = 2;
	printf("d.i: %10d d.f:%0.2f\n", d.i, d.f, d.a);*/
}

/*Enum*/
namespace jop
{
	typedef enum _Enum enum1;
	enum _Enum
	{
		Class_First = 0,
		Weaponmaster = 0,
		Archer = 1,
		theft = 2,
		Class_Last = 2
	};
}

void Test_enum() {

	using namespace jop;
	int g = jop::enum1::Weaponmaster;
	if (g == jop::enum1::Weaponmaster)
	{
		printf("Weapnmaster %d\n", g );
	}
	else
	{
		printf("Archer %d\n", g);
	}
}

//case 4
	/*game test*/
void Test_game1(Class *CLASS, const char *name);
void Test_game()
{
	Class CLASS1;
	Class CLASS2;
	Test_game1(&CLASS1, "홍길동");
	Test_game1(&CLASS2, "강감찬");
}
void Test_game1(Class *CLASS, const char *name)
{
	printf("--------------%s 학생 테스트 시작--------------\n", name);
	Class_Class(CLASS, name);
	Class_View(CLASS);
	Class_Study(CLASS);
	Class_View(CLASS);
	Class_Study(CLASS);
	Class_View(CLASS);
	Class_ListenLecture(CLASS);
	Class_View(CLASS);
	Class_Study(CLASS);
	Class_View(CLASS);
	Class_Relax(CLASS);
	Class_View(CLASS);
	Class_Sleep(CLASS);
	Class_View(CLASS);
	Class_Drink(CLASS);
	Class_View(CLASS);
	Class_Sing(CLASS);
	Class_View(CLASS);
	printf("--------------%s 학생 테스트 종료--------------\n", name);
}

//case 4
	/*Memory*/
void Test_memory()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char name[10] = "Hello";
	void *vp = 0;
	vp = arr;
	
	printf("vp:%p arr:%p \n", vp, arr);
	vp = name;
	printf("vp:%p name:%p \n", vp, name);
} 
	//malloc1
void Test_malloc1()
{	
	int i = 3;
	int*ip = &i;

	*ip = 7;
	printf("i:%d\n", i);
	ip = (int *)malloc(sizeof(int));
	*ip = 9;
	printf("*ip:%d\n", *ip);
	free(ip);

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *base = arr;
	for (int i=0;i<10;i++)
	{
		printf("%d ", base[i]);
	}
	printf("\n");

	int n = 0;
	scanf_s("%d", &n);
	base = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i<n; i++)
	{
		base[i] = i + 1;
		printf("%d ", base[i]);
	}
	printf("\n");
	free(base);

}
	//malloc + calloc
void InputScores(int *base, int n);
void ViewScores(int *base, int n);
void Test_malloc2()
{
	int *base = 0;
	int max_stu = 0;
	printf("maximum student : ");
	scanf_s("%d", &max_stu);

	base = (int *)malloc(sizeof(int)*max_stu);
	ViewScores(base, max_stu);
	base = (int *)calloc(sizeof(int),max_stu);
	ViewScores(base, max_stu);
	base = (int *)malloc(sizeof(int)*max_stu);
	InputScores(base, max_stu);
	ViewScores(base, max_stu);
}
void InputScores(int *base, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("scores of %d number : ", i + 1);
		scanf_s("%d", base + i);
	}
}
void ViewScores(int *base, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("scores of %d number : %d\n", i + 1,base[i]);
	}
}
	//realloc
int *base = 0;
int asize = 0;
int usage = 0;
void Input(int value);
void View();
void Resize();
void Test_realloc() 
{
	int Index;
	renumber:
	printf("\nInput number : ");
	scanf_s("%d", &Index);
	if (Index == 0)
		goto end;
	Input(Index);
	View();
	goto renumber;
	end:
	free(base);
}

void Input(int value)
{
	if (asize == usage)
	{
		Resize();
	}
	base[usage] = value;
	usage++;
}
void Resize()
{
	if (asize == 0)
	{
		asize = 1;
	}
	else
	{
		asize = asize * 2;
	}
	base = (int *)realloc(base, sizeof(int)*asize);
}
void View()
{
	int i = 0;
	printf("저장 용량:%d 사용량:%d\n", asize, usage);
	for (i = 0; i < usage; i++)
	{
		printf("%d\n", base[i]);
	}
	printf("\n");
	
}
	//Dynamic_Allocation_Example
void Dynamic_Allocation_Example()
{
	Student *stu = New_Student("홍길동", 33);
	Student_Study(stu);
	Student_View(stu);
	Delete_Student(stu);
}

	// Dynamic_Array_Example_Seq
Member *Member_Make(int mnum)
{
	char name[MAX_NAME_LEN + 1] = "";
	printf("%d 번 회원 이름 입력:", mnum);
	scanf_s("%s", name, MAX_NAME_LEN);
	return Member_New(mnum, name);
}
void Inputseq(EHArray *eharr);
void ViewSeq(EHArray *eharr);
void EndSeq(EHArray *eharr);
void Dynamic_Array_Example_Seq()
{
	EHArray *eharr = 0;
	eharr = EHArray_New(0, 0);
	int NumOfMember;
	int n;
	Makemeber:
	printf("\n ======================= \n\n");
	printf("1 : 회원 생성\n");
	printf("2 : 회원 목록 보기\n");
	printf("3 : 종료\n");
	//printf("4 : realloc\n");
	//printf("5 : Dynamic Allocation example\n");
	//printf("6 : Dynamic array example\n");
	printf("\n ======================= \n\n");
	printf("Input value : ");
	scanf_s("%d", &n);
	printf("\n ----------------------- \n\n");
	switch (n) {
	case 1:
		
		printf("생성할 회원수 : ");
		scanf_s("%d", &NumOfMember);
		for (int i = 0; i < NumOfMember; i++)
		{
			Inputseq(eharr);
		}
		goto Makemeber;
		break;
	case 2:
		ViewSeq(eharr);
		goto Makemeber;
		break;
	case 3:
		EndSeq(eharr);
		main();
		break;
	default:
		printf("wrong input value.\n");
		goto Makemeber;
		break;
	}
}
void Inputseq(EHArray *eharr)
{
	int mnum = 0;
	Member *member = 0;
	printf("생성할 회원 번호:");
	scanf_s("%d", &mnum);
	member = Member_Make(mnum);
	EHArray_PushBack(eharr, member);
}
void ViewSeq(EHArray *eharr)
{
	Iterator seek;
	Iterator end;
	Member *member = 0;
	seek = EHArray_Begin(eharr);
	end = EHArray_End(eharr);
	for (; seek != end; ++seek)
	{
		member = (Member *)(*seek);
		Member_View(member);
	}
}
void EndSeq(EHArray *eharr)
{
	Iterator seek;
	Iterator end;
	Member *member = 0;

	seek = EHArray_Begin(eharr);
	end = EHArray_End(eharr);

	for (; seek != end; ++seek)
	{
		member = (Member *)(*seek);
		Member_Delete(member);
	}
	EHArray_Delete(eharr);
}

EHArray *MakeArray(void);
void InputIndex(EHArray *eharr);
void ViewIndex(EHArray *eharr);
void EndIndex(EHArray *eharr);
void Dynamic_Array_Example_Index()
{
	EHArray *eharr = 0;
	eharr = MakeArray();
	InputIndex(eharr);
	ViewIndex(eharr);
	EndIndex(eharr);
}


EHArray *MakeArray(void)
{
	int max = 0;
	printf("최대 관리할 회원 수를 입력하세요.\n");
	scanf_s("%d", &max);
	return EHArray_New(max, 0);
}
void InputIndex(EHArray *eharr)
{
	int i = 0;
	Member *member = 0;
	int max = EHArray_GetCapacity(eharr);
	for (i = 0; i<max; i++)
	{
		member = Member_Make(i + 1);
		EHArray_SetAt(eharr, i, member);
	}
}

void ViewIndex(EHArray *eharr)
{
	int max = 0;
	int i = 0;
	Member *member = 0;
	max = EHArray_GetCapacity(eharr);
	for (i = 0; i<max; i++)
	{
		member = (Member *)EHArray_GetAt(eharr, i);
		Member_View(member);
	}
}
void EndIndex(EHArray *eharr)
{
	int max = 0;
	int i = 0;
	Member *member = 0;

	max = EHArray_GetCapacity(eharr);

	for (i = 0; i<max; i++)
	{
		member = (Member *)EHArray_GetAt(eharr, i);
		Member_Delete(member);
	}
	EHArray_Delete(eharr);
}

void File_inoutput()
{
//#define FNAME "Demo.txt"
//#define MAX_BUFSIZE 20
//	FILE *fp = 0;
//	fopen_s(&fp, FNAME, "w");
//	if (fp == 0)
//	{
//		printf("파일 열기 실패\n");
//	}
//	fprintf(fp, "hello %s %d\n", "yahoo", 27);
//	fprintf(fp, "fprintf 함수 테스트\n");
//
//	char name[256] = "";
//	int a = 0, b = 0, c = 0, d = 0;
//	printf("이름:");
//	fscanf_s(stdin, "%s", name, sizeof(name));
//	printf("입력한 이름:%s\n", name);
//	printf("다음과 같은 포멧으로 입력(정수.정수.정수.정수):");
//	fscanf_s(stdin, "%d.%d.%d.%d", &a, &b, &c, &d);
//	printf("입력한 내용은 %d.%d.%d.%d\n", a, b, c, d);
//
//	char name[256] = "";
//	int a = 0, b = 0, c = 0, d = 0;
//	FILE *fp = 0;
//	fopen_s(&fp, FNAME, "r");
//	if (fp == 0)
//	{
//		printf("파일 열기 실패\n");
//		return;
//	}
//	fscanf_s(fp, "%s", name, sizeof(name));
//	printf("이름:%s\n", name);
//	fscanf_s(fp, "%d.%d.%d.%d", &a, &b, &c, &d);
//	printf("IP 주소:%d.%d.%d.%d\n", a, b, c, d);
//	fclose(fp);
//	return;
//
//	char buf[MAX_BUFSIZE];
//	int no = 0;
//	while (1) //파일의 끝을 만나지 않을 동안
//	{
//		fgets(buf, MAX_BUFSIZE, fp);
//		if (feof(fp))
//		{
//			return;
//		}
//		no++;
//		printf("[%d] %s", no, buf); //한 라인을 얻어와서 콘솔 화면에 출력
//	}
}


#define FNAME   "data.txt"
#define MAX_MEMBER    4
#define MAX_NAME_LEN 20
typedef struct _List_Member LMember;
struct _List_Member
{
	char name[MAX_NAME_LEN + 1];
	int num;
};

LMember src[MAX_MEMBER] =
{
	{ "홍길동",1 },{ "강감찬",4 },{ "을지문덕",2 },{ "김구",3 }
};

LMember dest[MAX_MEMBER];
void Save();//src의 회원 정보 파일에 쓰기
void Load();//파일에 회원 정보를 dest로 읽기
void List();//dest 내용 출력
int Control_member_list()
{
	Save();
	Load();
	List();
	return 0;
}

void Save()
{
	FILE *fp = 0;
	fopen_s(&fp, FNAME, "w");

	if (fp)
	{
		fwrite(src, sizeof(LMember), MAX_MEMBER, fp);
		fclose(fp);
	}
	else
	{
		printf("데이터 저장 실패\n");
	}
}

void Load()
{
	FILE *fp = 0;
	fopen_s(&fp, FNAME, "r");
	if (fp)
	{
		fread(dest, sizeof(LMember), MAX_MEMBER, fp);
		fclose(fp);
	}
	else
	{
		printf("처음으로 회원 관리 프로그램을 사용을 환영합니다.\n");
	}
}


void List()
{
	int i = 0;
	for (i = 0; i<MAX_MEMBER; i++)
	{
		printf("이름:%s 번호:%d\n", dest[i].name, dest[i].num);
	}
}
