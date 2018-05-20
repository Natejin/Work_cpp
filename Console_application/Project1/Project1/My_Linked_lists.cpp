#include <stdio.h>
#include <stdlib.h>
#include "My_Linked_lists.h"

void My_Linked_lists()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: Singly Linked List \n");
	//printf("2: Dynamic Memory alloication (1st Array) \n");
	//printf("3: Dynamic Memory alloication (2st Array) \n");
	//printf("4: Dynamic Memory alloication (Struct) \n");
	//printf("5: Linker List \n");
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
		Singly_Linked_List();
		goto Initiate_Program;
		break;
	//case(2):
	//	DMA_1arr_exam();
	//	goto Initiate_Program;
	//	break;
	//case(3):
	//	DMA_2arr_exam();
	//	goto Initiate_Program;
	//	break;
	//case(4):
	//	DMA_struct();
	//	goto Initiate_Program;
	//	break;
	//case(5):
	//	Linker_List();
	//	goto Initiate_Program;
	//	break;
	//case(6):
	//	Linker_List();
	//	goto Initiate_Program;
	//	break;
	default:
		printf("���� ������� �� �˾� ��ھ�. �п� \n");
		main();
		break;
	}
}


#pragma region Singly_Linked_List

struct Node* Node_Insert(struct Node *current, int Node_data);
void Node_Delete(struct Node *destroy, struct Node* head);
struct Node* Node_Generate(int Node_data);
void Node_Display(struct Node *head);

// ��� ����ü
struct Node
{
	int Node_data; /* ������ */
	struct Node* Node_next; /* ���� ��带 ����Ű�� �κ� */
};
// ���� �Լ�
void Singly_Linked_List()
{
	//int Node_c;
	//struct Node *head = NULL;	//��� �ʱ�ȭ
	//printf("������ ��� ���� : ");
	//scanf_s("%d", &Node_c);

	struct Node* Node1 = Node_Generate(100);
	struct Node* Node2 = Node_Insert(Node1, 200);
	struct Node* Node3 = Node_Insert(Node2, 300);
	/* Node 2 �ڿ� Node4 �ֱ� */
	struct Node* Node4 = Node_Insert(Node2, 400);

	Node_Display(Node1);

}

void Node_Display(struct Node *head) // ���÷��� �Լ�
{
	/* head �� NULL �� �� ����,
	�� �� �κп� ������ �� ���� ��� */
	while (head)
	{
		printf("����� ������ : %d \n", head->Node_data);
		head = head->Node_next;
	}
}
struct Node* Node_Generate(int data) //�� ��带 ����� �Լ�
{
	/*int i;
	struct Node *Node_temp;

	for (i = 0; i < Node_c; i++)
	{
	Node_temp = (struct Node *)malloc(sizeof(struct Node));
	Node_temp->Node_data = i;
	if (*head == NULL)
	{
	*head = Node_temp;
	(*head)->Node_data = NULL;
	}
	else
	{
	Node_temp->Node_next = *head;
	*head = Node_temp;
	}
	}*/
	struct Node* Node_new = (struct Node *)malloc(sizeof(struct Node));

	Node_new->Node_data = data;
	Node_new->Node_next = NULL;

	return Node_new;
}
/* current ��� ��� �ڿ� ��带 ���� ����� �ִ� �Լ� */
struct Node* Node_Insert(struct Node *current, int Node_data)
{
	/* current ��尡 ����Ű�� �ִ� ���� ��尡 after �̴� */
	struct Node* after = current->Node_next;

	/* ���ο� ��带 �����Ѵ� */
	struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));

	/* �� ��忡 ���� �־��ش�. */
	newNode->Node_data = Node_data;
	newNode->Node_next = after;

	/* current �� ���� newNode �� ����Ű�� �ȴ� */
	current->Node_next = newNode;

	return newNode;
}
/* ���õ� ��带 �ı��ϴ� �Լ� */
void Node_Delete(struct Node *destroy, struct Node* head)
{
	/* ���� ��带 ����ų ������*/
	struct Node *next = head;

	/* head �� �ı��Ϸ� �Ѵٸ� */
	if (destroy == head)
	{
		free(destroy);
		return;
	}

	/* ���� next �� NULL �̸� ���� */
	while (next)
	{
		/* ���� next ���� ��尡 destroy ��� next �� destory �� ���*/
		if (next->Node_next == destroy)
		{
			/* ���� next �� ���� ���� destory �� �ƴ϶� destroy �� ���� ��尡 �ȴ�. */
			next->Node_next = destroy->Node_next;
		}
		/* next �� ���� ��带 ����Ų��. */
		next = next->Node_next;

	}
	free(destroy);
}



#pragma endregion