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
	//printf("6: 포인터 함수 \n");
	//printf("1: 함수 기본 (원하는 값으로 변경) \n");
	//printf("1: 함수 기본 (원하는 값으로 변경) \n");
	//printf("1: 함수 기본 (원하는 값으로 변경) \n");
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
		printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
		main();
		break;
	}
}


#pragma region Singly_Linked_List

struct Node* Node_Insert(struct Node *current, int Node_data);
void Node_Delete(struct Node *destroy, struct Node* head);
struct Node* Node_Generate(int Node_data);
void Node_Display(struct Node *head);

// 노드 구조체
struct Node
{
	int Node_data; /* 데이터 */
	struct Node* Node_next; /* 다음 노드를 가리키는 부분 */
};
// 메인 함수
void Singly_Linked_List()
{
	//int Node_c;
	//struct Node *head = NULL;	//노드 초기화
	//printf("생성할 노드 개수 : ");
	//scanf_s("%d", &Node_c);

	struct Node* Node1 = Node_Generate(100);
	struct Node* Node2 = Node_Insert(Node1, 200);
	struct Node* Node3 = Node_Insert(Node2, 300);
	/* Node 2 뒤에 Node4 넣기 */
	struct Node* Node4 = Node_Insert(Node2, 400);

	Node_Display(Node1);

}

void Node_Display(struct Node *head) // 디스플레이 함수
{
	/* head 이 NULL 일 때 까지,
	즉 끝 부분에 도달할 때 까지 출력 */
	while (head)
	{
		printf("노드의 데이터 : %d \n", head->Node_data);
		head = head->Node_next;
	}
}
struct Node* Node_Generate(int data) //새 노드를 만드는 함수
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
/* current 라는 노드 뒤에 노드를 새로 만들어 넣는 함수 */
struct Node* Node_Insert(struct Node *current, int Node_data)
{
	/* current 노드가 가리키고 있던 다음 노드가 after 이다 */
	struct Node* after = current->Node_next;

	/* 새로운 노드를 생성한다 */
	struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));

	/* 새 노드에 값을 넣어준다. */
	newNode->Node_data = Node_data;
	newNode->Node_next = after;

	/* current 는 이제 newNode 를 가리키게 된다 */
	current->Node_next = newNode;

	return newNode;
}
/* 선택된 노드를 파괴하는 함수 */
void Node_Delete(struct Node *destroy, struct Node* head)
{
	/* 다음 노드를 가리킬 포인터*/
	struct Node *next = head;

	/* head 를 파괴하려 한다면 */
	if (destroy == head)
	{
		free(destroy);
		return;
	}

	/* 만일 next 가 NULL 이면 종료 */
	while (next)
	{
		/* 만일 next 다음 노드가 destroy 라면 next 가 destory 앞 노드*/
		if (next->Node_next == destroy)
		{
			/* 따라서 next 의 다음 노드는 destory 가 아니라 destroy 의 다음 노드가 된다. */
			next->Node_next = destroy->Node_next;
		}
		/* next 는 다음 노드를 가리킨다. */
		next = next->Node_next;

	}
	free(destroy);
}



#pragma endregion