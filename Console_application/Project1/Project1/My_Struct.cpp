#include <stdio.h>
int main();

int Struct_Basic1();
int Struct_Basic2();
int Struct_Basic3();
int Struct_Pointer();
int Structs_Replace();
int Pass_Struct_Func();
int Struct_Example();

int My_Struct()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: ����ü �⺻1 \n");
	printf("2: ����ü �⺻2 \n");
	printf("3: ����ü �⺻3 \n");
	printf("4: Struct pointer \n");
	printf("5: Structs Replace \n");
	printf("6: Passing_Struct to a_Function \n");
	printf("7: Struct sample \n");
	//printf("5: �迭�� �Է¼� ��ŭ ���� \n");
	//printf("6: ������ �Լ� \n");
	//printf("1: �Լ� �⺻ (���ϴ� ������ ����) \n");
	//printf("1: �Լ� �⺻ (���ϴ� ������ ����) \n");
	//printf("1: �Լ� �⺻ (���ϴ� ������ ����) \n");
	printf("\n____________________________________________________________________________\n");
	printf("\nInput value : ");
	scanf_s("%d", &Index);
	printf("\n____________________________________________________________________________\n\n");
	switch (Index)
	{
	case(1):
		Struct_Basic1();
		goto Initiate_Program;
		break;
	case(2):
		Struct_Basic2();
		goto Initiate_Program;
		break;
	case(3):
		Struct_Basic3();
		goto Initiate_Program;
		break;
	case(4):
		Struct_Pointer();
		goto Initiate_Program;
		break;
	case(5):
		Structs_Replace();
		goto Initiate_Program;
		break;
	case(6):
		Pass_Struct_Func();
		goto Initiate_Program;
		break;
	case(7):
		Struct_Example();
		goto Initiate_Program;
		break;
		
	default:
		printf("���� ������� �� �˾� ��ھ�. �п� \n");
		main();
		break;
	}
	return 0;
}

#pragma region Struct_Basic1
struct Human
{
	int age; /* ���� */
	int height; /* Ű */
	int weight; /* ������ */
}; /* ; ���̴� �� �����ϼ��� */
int Struct_Basic1()
{
	struct Human Psi;

	Psi.age = 99;
	Psi.height = 185;
	Psi.weight = 80;

	printf("Psi �� ���� ���� \n");
	printf("����   : %d \n", Psi.age);
	printf("Ű     : %d \n", Psi.height);
	printf("������ : %d \n", Psi.weight);
	return 0;
}

#pragma endregion
#pragma region Struct_Basic2
char copy_str(char *dest, char *src);
struct Books
{
	/* å �̸� */
	char name[30];
	/* ���� �̸� */
	char auth[30];
	/* ���ǻ� �̸� */
	char publ[30];
	/* ���� ������? */
	int borrowed;
};
int Struct_Basic2()
{
	struct Books Harry_Potter;
	char name[50] = "Harry Potter";
	char auth[50] = "J.K. Rolling";
	char publ[50] = "Scholastic";


	copy_str(Harry_Potter.name, name);
	copy_str(Harry_Potter.auth, auth);
	copy_str(Harry_Potter.publ, publ);
	Harry_Potter.borrowed = 0;

	printf("å �̸� : %s \n", Harry_Potter.name);
	printf("���� �̸� : %s \n", Harry_Potter.auth);
	printf("���ǻ� �̸� : %s \n", Harry_Potter.publ);


	return 0;
}
char copy_str(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;
}
#pragma endregion
#pragma region Struct_Basic3
struct Books3
{
	/* å �̸� */
	char name[30];
	/* ���� �̸� */
	char auth[30];
	/* ���ǻ� �̸� */
	char publ[30];
	/* ���� ������? */
	int borrowed;
};
int Struct_Basic3()
{
	struct Books3 book_list[3];
	int i;

	for (i = 0; i<3; i++)
	{
		printf("å %d ���� �Է� : ", i);
		scanf_s("%s%s%s", book_list[i].name, sizeof(book_list[i].name), book_list[i].auth, sizeof(book_list[i].auth), book_list[i].publ, sizeof(book_list[i].publ));
		book_list[i].borrowed = 0;
	}

	for (i = 0; i<3; i++)
	{
		printf("------------------------------- \n");
		printf("å %s �� ����\n", book_list[i].name);
		printf("���� : %s \n", book_list[i].auth);
		printf("���ǻ� : %s \n", book_list[i].publ);

		if (book_list[i].borrowed == 0)
		{
			printf("�� ������\n");
		}
		else
		{
			printf("������ \n");
		}
	}
	return 0;
}
#pragma endregion
#pragma region Struct_Pointer_Test
int Struct_Pointer_test_Add_Func(int *a);
struct Struct_Pointer_test
{
	int a, b;
	int *pointer1;
	int *pointer2;
};
int Struct_Pointer()
{
	struct Struct_Pointer_test str;
	struct Struct_Pointer_test *pstr = &str;
	int i = 0;
	str.pointer1 = &i;
	*str.pointer1 = 3;
	printf("i : %d \n", i);
	*pstr->pointer1 = 4;
	printf("i : %d \n", i);

	(*pstr).a = 1;  //
	pstr->b = 2;
	printf("str �� a ��� : %d \n", str.a);
	printf("str �� b ��� : %d \n", str.b);

	pstr->a = 100;
	Struct_Pointer_test_Add_Func(&str.a);
	//Struct_Pointer_test_Add_Func(&str.b);
	printf("str.a : %d \n", str.a);
	//printf("*pstr.b : %d \n", pstr.b);

	return 0;
}
int Struct_Pointer_test_Add_Func(int *a)
{
	*a += 100;
	return 0;
}
#pragma endregion
#pragma region Structs_Replace
char Struct_Replace_arr_copy(char *dest, char *src);
struct Structs_Replace_str_1
{
	int i;
	char c;
	char arr1[20];
};
int Structs_Replace()
{
	struct Structs_Replace_str_1 str1, str2;

	str1.i = 1;
	str1.c = 'c';
	char src[] = "hello world";
	Struct_Replace_arr_copy(str1.arr1, src);

	str2 = str1;
	

	printf("str2.i : %d \n", str2.i);
	printf("str2.c : %c \n", str2.c);
	printf("str2.arr1 : %s \n", str2.arr1,sizeof(str2.arr1));

	return 0;
}
char Struct_Replace_arr_copy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;

}


#pragma endregion
#pragma region Pass_Struct_Func

struct Pass_Struct_Func_str_1
{
	int age;
	int gender;
	char name[20];
};
struct Pass_Struct_Func_str_2
{
	struct Pass_Struct_Func_str_1 data;
	char elements[20];
};
int Pass_Struct_Func_set(struct Pass_Struct_Func_str_1 *met, int age, int gender, char *name, struct Pass_Struct_Func_str_2 *et, char *elements);
char Pass_Struct_Func_copy_str(char *dest, char *src);
int Pass_Struct_Func_copy_ele(struct Pass_Struct_Func_str_2 *dest, char *ele);

int Pass_Struct_Func()
{
	struct Pass_Struct_Func_str_2 Human;
	char src1[] = "Lee";
	char src2[] = "Fire";
	char src3[] = "Ice";

	Pass_Struct_Func_set(&Human.data, 10, 1, src1, &Human, src2);

	printf("AGE : %d // Gender : %d // Name : %s //elements : %s \n", Human.data.age, Human.data.gender, Human.data.name, Human.elements);
	Pass_Struct_Func_copy_ele(&Human, src3);
	printf("AGE : %d // Gender : %d // Name : %s //elements : %s \n", Human.data.age, Human.data.gender, Human.data.name, Human.elements);
	return 0;
}
int Pass_Struct_Func_set(struct Pass_Struct_Func_str_1 *met, int age, int gender, char *name, struct Pass_Struct_Func_str_2 *et, char *elements)
{
	met->age = age;
	met->gender = gender;
	copy_str(met->name, name);
	copy_str(et->elements, elements);

	return 0;
}
char Pass_Struct_Func_copy_str(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;
}
int Pass_Struct_Func_copy_ele(struct Pass_Struct_Func_str_2 *dest, char *ele)
{
	copy_str(dest->elements, ele);
	return 0;
}



#pragma endregion
#pragma region Zombie
int Struct_Example_prt_stat(struct HUMAN name);
struct HUMAN
{
	int age;
	int height;
	int weight;
	int gender;
};
int Struct_Example()
{
	struct HUMAN Adam = { 31, 182, 75, 0 };
	struct HUMAN Eve = { 27, 166, 48, 1 };

	Struct_Example_prt_stat(Adam);
	Struct_Example_prt_stat(Eve);
	return 0;
}
int Struct_Example_prt_stat(struct HUMAN name)
{


	printf("AGE : %d / Height : %d / Weight : %d gender : ", name.age, name.height, name.weight);

	if (name.gender == 0)
	{
		printf("MALE \n");
	}
	else
	{
		printf("FEMALE \n");
	}

	if (name.gender == 0 && name.height >= 180)
	{
		printf("HE IS A WINNER!! \n");
	}
	else if (name.gender == 0 && name.height < 180)
	{
		printf("HE IS A LOSER!! \n");
	}

	printf("------------------------------------------- \n");

	return 0;

	enum { RED, BLUE, WHITE, BLACK };
	int Enum_Basic();
	{
		int palette = RED;

		switch (palette)
		{
		case RED:
			printf("palette : RED \n");
			break;

		case BLUE:
			printf("palette : BLUE \n");
			break;
		case WHITE:
			printf("palette : WHITE \n");
			break;
		case BLACK:
			printf("palette : BLACK \n");
			break;
		}
	}
}
#pragma endregion



