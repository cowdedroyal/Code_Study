#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ElementType int
#define MaxSize 100
#define SUCCESS 1
#define ERROR 0

ElementType trash;

typedef struct OrderList{
	ElementType data[MaxSize];
	int last;
}*OrdL,OrderList;

OrdL InitOrderList(){
	ElementType data;
	int count = 0;
	OrdL olt = (OrderList*) malloc(sizeof(OrderList));
	printf("请输入顺序表中的元素以回车加^z结束：\n");
	while(~scanf("%d",&data)){
		olt->data[count++] = data;
	}
	olt->last = count-1;
	return olt;
}

void display(OrdL ol){
	int i = 0;
	for (i = 0; i <= ol->last; i++)
	{
		printf("%d ", ol->data[i]);
	}
	printf("\n");
}

int insert(OrdL ol, int place, ElementType data){
	int i = 0;
	ElementType temp;
	if(place-1 > ol->last+1){
		printf("Sorry,your visit is beyond the scope of the Sequence List.\n");
		return ERROR;
	}
	for (i = ol->last;i >= place-1; i--){
		ol->data[i+1] = ol->data[i];
	}
	ol->data[place-1] = data;
	ol->last++;
	return SUCCESS;
}

int Delete(OrdL ol, int place){
	int i = 0;
	if(place-1 > ol->last){
		printf("Sorry,your visit is beyond the scope of the Sequence List.\n");
		return ERROR;
	}
	trash = ol->data[place-1];
	for (i = place; i <= ol->last; i++){
		ol->data[i - 1] = ol->data[i];
	}
	ol->last--;
	return SUCCESS;
}

int length(OrdL ol){
	return ol->last + 1;
}

int inverse(OrdL ol){
	int i, j;
	ElementType temp;
	for (i = 0,j = ol->last; i < j; i++,j--){
		temp = ol->data[i];
		ol->data[i] = ol->data[j];
		ol->data[j] = temp;
	}
	return SUCCESS;
}

int sort(OrdL ol){
	if(ol->last == -1){
		return ERROR;
	}
	//计数排序
	int max = ol->data[0];
	int min = ol->data[0];
	int i = 0;
	for (i = 0; i <= ol->last; i++){
		if(ol->data[i]>max)
			max = ol->data[i];
		if(ol->data[i]<min)
			min = ol->data[i];
	}
	int range = max - min + 1;
	int count[range];
	memset(count,0,sizeof(count));
	for (i = 0; i <= ol->last;i++){
		count[ol->data[i]-min]++;
	}
	int j = 0;
	for (i = 0; i < range; i++){
		while(count[i]--){
			ol->data[j++] = i + min;
		}
	}
	return SUCCESS;
}

int combine_OrderList(OrdL ol1,OrdL ol2){
	int i = 0,j = 0,k = 0;
	sort(ol1);
	sort(ol2);
	int len = ol1->last + 1 + ol2->last + 1;
	int data[len];
	while(i<=ol1->last&&k<=ol2->last){
		if(ol1->data[i]<ol2->data[k]){
			data[j++] = ol1->data[i];
			i++;
		}
		else{
			data[j++] = ol2->data[k];
			k++;
		}
	}
	if(i<=ol1->last){
		for (;i<=ol1->last;i++){
			data[j++] = ol1->data[i];
		}
	}
	else{
		for (; k <= ol2->last; k++){
			data[j++] = ol2->data[k];
		}
	}
	memcpy(ol1->data, data, sizeof(data));
	ol1->last = j - 1;
	return SUCCESS;
}

int main(){
	OrdL ol1 = InitOrderList();
	OrdL ol2;
	while (1){
		int c, place = 0, elem = 0;
		printf("请输入需要进行的操作的序号:\n");
		printf("1.插入 2.删除 3.显示刚才删除的数据 4.逆置 5.排序 6.合并 7.输出 8.顺序表的长度 9.退出\n");
		scanf("%d", &c);
		switch (c){
		case 1:
			printf("你要插入的位置和元素: ");
			scanf("%d %d", &place, &elem);
			insert(ol1, place, elem);
			break;
		case 2:
			printf("请输入你要删除元素的位置: ");
			scanf("%d", &place);
			Delete(ol1, place);
			break;
		case 3:
			printf("最近一次删除的数: %d\n", trash);
			break;
		case 4:
			inverse(ol1);
			break;
		case 5:
			sort(ol1);
			break;
		case 6:
			ol2 = InitOrderList();
			combine_OrderList(ol1, ol2);
			break;
		case 7:
			display(ol1);
			break;
		case 8:
			printf("顺序表的长度为: %d\n", length(ol1));
			break;
		}
		if (c == 9)
		{
			break;
		}
	}
	return 0;
}



