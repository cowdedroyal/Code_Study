#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElemType int
#define ERROR 0
#define SUCCESS 1

ElemType trash;

typedef struct Node{
	ElemType data;
	struct Node *next;
}*LinkList,Node;
/*
* @brief 初始化线性链表
* @param head 线性链表的头指针(指向头结点)
*/
void InitLinkList(LinkList *head){
	ElemType data_t;
	Node *NewNode;
	Node *p;
	printf("请输入线性链表中的元素以回车^Z结束:\n");
	(*head) = (LinkList)malloc(sizeof(struct Node));
	(*head)->next = NULL;
	while(~scanf("%d", &data_t)){
		NewNode = (LinkList)malloc(sizeof(struct Node));
		NewNode->data = data_t;
		NewNode->next = NULL;
		if (!((*head)->next))
		{
			(*head)->next = NewNode;
			p = NewNode;
		}
		else{
			p->next = NewNode;
			p = NewNode;
		}
	}
}

void display(LinkList head){
	Node *p = head->next;
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int length(LinkList head){
	Node *p = head->next;
	int count = 0;
	while(p){
		count++;
		p=p->next;
	}
	return count;
}

// 第place号元素后面插入
int insert(LinkList head,int place,ElemType data){
	Node *p = head;
	Node *NewNode = (Node *)malloc(sizeof(struct Node));
	int count = 0;
	while (count < place){
		p = p->next;
		if (p == NULL)
		{
			printf("Sorry,your visit is beyond the scope of the sequence list.\n");
			return ERROR;
		}
		count++;
	}
	NewNode->data = data;
	NewNode->next = p->next;
	p->next = NewNode;
	return SUCCESS;
}

// 删除第place号元素
int Delete(LinkList head, int place){
	Node *p = head;
	Node *pre;
	int count = 0;
	while (count < place-1)
	{
		p = p->next;
		if (p == NULL)
		{
			printf("Sorry, your visit is beyond the scope of the link list.\n");
			return ERROR;
		}
		count++;
	}
	pre = p;
	p = p->next;
	if(p){
		trash = p->data;
		pre->next = p->next;
		free(p);
	}
	else{
		printf("Warning there isn't a element on the place of the link list.\n");
	}
	return SUCCESS;
}

int inverse(LinkList L){
	LinkList p = L->next; // p is the first element
	Node *t;
	L->next = NULL;
	while(p){
		// 头插法
		t = p;		   // 存取当前元素
		p = p->next;   // 位移
		t->next = L->next; // 尾部
		L->next = t; //头节点指向当前节点
	}
	return SUCCESS;
}

//按照值的从小到大排序
int sort(LinkList head){
	if (!(head->next))
		return ERROR; //空链表不排序
	//计数排序，时间复杂度O(n+range),空间复杂度O(n+range)
	Node *p = head->next; //the first element
	int i;
	int min = head->next->data;
	int max = head->next->data;
	while(p){
		if(p->data>max) max = p->data;
		if(p->data<min) min = p->data;
		p = p->next;
	}
	int range = max - min + 1;
	int count[range];
	memset(count, 0, sizeof(count)); //不需要free
	//int *count = (int *)malloc(range * sizeof(int));
	//memset(count, 0, range * sizeof(int)); //这里不能用sizeof(count),同时需要free
	p = head->next;
	while(p){
		count[(p->data)-min]++;
		p = p->next;
	}
	p = head->next;
	for (i = 0; i < range;i++){
		while(count[i]--){
			p->data = i + min;
			p = p->next;
		}
	}
	//free(count);
	return SUCCESS;
}

//可以合并任意的两个线性链表,结果按值从小到大排列
int combine_LinkList(LinkList h1, LinkList h2){
	//合并排序
	Node *p=h1->next, *q=h2->next; //the first element
	sort(h1);
	sort(h2);
	Node *t = h1;
	//h1->next = NULL;
	while(p&&q){
		if(p->data <= q->data){
			t->next = p;
			t = t->next;
			p = p->next;
		}
		else{
			t->next = q;
			t = t->next;
			q = q->next;
		}
	}
	if(p){
		t->next = p;
	}
	else{
		t->next = q;
	}
	return SUCCESS;
}

int main(){
	LinkList h1;
	LinkList h2;
	InitLinkList(&h1);
	while(1){
		int c,place=0,elem=0;
		printf("请输入需要进行的操作的序号:\n");
		printf("1.插入 2.删除 3.显示刚才删除的数据 4.逆置 5.排序 6.合并 7.输出 8.线性链表的长度 9.退出\n");
		scanf("%d", &c);
		switch(c){
			case 1:
			printf("你要插入的位置和元素: ");
			scanf("%d %d", &place, &elem);
			insert(h1, place, elem);
			break;
			case 2:
			printf("请输入你要删除元素的位置: ");
			scanf("%d", &place);
			Delete(h1, place);
			break;
			case 3:
			printf("最近一次删除的数: %d\n", trash);
			break;
			case 4:
			inverse(h1);
			break;
			case 5:
			sort(h1);
			break;
			case 6:
			InitLinkList(&h2);
			combine_LinkList(h1, h2);
			break;
			case 7:
			display(h1);
			break;
			case 8:
			printf("线性链表的长度为: %d\n",length(h1));
			break;
		}
		if(c==9){
			break;
		}
	}
	return 0;
}