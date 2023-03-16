#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 50
#define ERROR -1

typedef struct Ratn_num{
	int numr; //分子
	int denm; //分母
}Qnum;

int gcd(int m,int n){
 	int r;
 	r=m%n;
 	while(r!=0)
 	{
 		m=n;
 		n=r;
 		r=m%n;
	 }
	 return n;
 }
 
int lcm(int m,int n){
 	return (m*n)/gcd(m,n);
}

//约分
void Reacf(Qnum *q){
	int temp = gcd(q->numr,q->denm);
	q->numr = q->numr/temp;
	q->denm = q->denm/temp;
}

//创建一个有理数
Qnum Create_Qnum(){
	int flag=-1; //flag为1表示输入是分数,为0表示输入是小数,为2表示整数输入,-1表示非法输入
	char str[MaxSize],num[MaxSize];
	Qnum qt={0,0};
	int i,flag_j=-1,j=0,count=0;
	while(flag==-1){
		count=0;
		flag = 2;
		flag_j=-1;
		j=0;
		gets(str);
		for(i=0;str[i]!='\0';i++){
			if(str[i]>'9'||str[i]<'0'&&str[i]!=' '&&str[i]!='-'&&str[i]!='/'&&str[i]!='.')
			{
				flag = -1;break;
			}
			if(str[i]=='-') count++;
			if(str[i]=='/'){
				flag = 1;
				if(str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>'0'&&str[i+1]<='9')
					flag_j = j-1;
				else{
					flag = -1;
					printf("抱歉请检查分母是否取零或数字和/之间是否有空格！\n");
				}
			}
			if(str[i]=='.'){
				flag = 0;
				if(str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>='0'&&str[i+1]<='9')
					flag_j = j-1;
				else{
					flag = -1;
					printf("抱歉你输入的小数格式有误！请确保数字和.之间没有空格！\n");
				}
			}
			if(str[i]>='0'&&str[i]<='9'){
				num[j++] = str[i];
			}
		}
		if(flag==-1){
			printf("请正确输入有理数！！!\n");
		}
	}
	
	//分数形式输入
	if(flag==1){ 
		for(i=0;i<=flag_j;i++){
			qt.numr += pow(10,flag_j-i)*(num[i]-'0');
		}
		for(i=flag_j+1;i<j;i++){
			qt.denm += pow(10,j-1-i)*(num[i]-'0');
		}
		Reacf(&qt);
		qt.numr = pow(-1,count)*qt.numr;
//		printf("%d/%d",qt.numr,qt.denm);
	}
	else if(!flag){ //小数形式输入
		for(i=0;i<j;i++){
			qt.numr += pow(10,j-1-i)*(num[i]-'0');
		}
		qt.denm = pow(10,(j-1-flag_j));
		Reacf(&qt);
		qt.numr = pow(-1,count)*qt.numr;
//		printf("%d/%d",qt.numr,qt.denm);
	}
	else{ //整数形式输入
		for(i=0;i<j;i++){
			qt.numr += pow(10,j-1-i)*(num[i]-'0');
		}
		qt.numr = pow(-1,count)*qt.numr;
		qt.denm = 1;
	}
	return qt;
}

//输出有理数
void Qnum_print(Qnum *q){
	Reacf(q);
	if(abs(q->numr)==abs(q->denm)) printf("%d\n",q->numr/q->denm);
	else if(abs(q->denm)==1) printf("%d\n",q->numr);
	else if((q->numr*q->denm)<0) printf("-%d/%d\n",abs(q->numr),abs(q->denm));
	else printf("%d/%d\n",q->numr,q->denm);
}

//有理数相加
Qnum Add_Qnum(Qnum q1,Qnum q2){
	Qnum q3;
	q3.denm = lcm(q1.denm,q2.denm);
	q3.numr = q1.numr*(q3.denm/q1.denm) + q2.numr*(q3.denm/q2.denm);
	return q3;
}

//有理数相减
Qnum Sub_Qnum(Qnum q1,Qnum q2){
	Qnum q3;
	q3.denm = lcm(q1.denm,q2.denm);
	q3.numr = q1.numr*(q3.denm/q1.denm) - q2.numr*(q3.denm/q2.denm);
	return q3;
}

//有理数相乘
Qnum Multi_Qnum(Qnum q1,Qnum q2){
	Qnum q3;
	q3.numr = q1.numr*q2.numr;
	q3.denm = q1.denm*q2.denm;
	return q3;
}

//有理数相除
Qnum Divi_Qnum(Qnum q1,Qnum q2){
	Qnum q3;
	if(q2.numr!=0){
		q3.numr = q1.numr*q2.denm;
		q3.denm = q1.denm*q2.numr;
		return q3;
	}
	else{
		printf("除法中除数不能为零！");
		exit(ERROR);
	}
}

int main(){
	Qnum q1,q2,q3;
	int k;
	printf("请分两行输入两个有理数: \n");
	q1=Create_Qnum();
	q2=Create_Qnum();
	while(1){
		int s_num;
		printf("输入要执行操作的序号:\n");
		printf("1.加法 2.减法 3.乘法 4.除法 5.退出\n");
		scanf("%d",&s_num);
		switch(s_num){
			case 1: q3=Add_Qnum(q1,q2);Qnum_print(&q3);break;
			case 2: q3=Sub_Qnum(q1,q2);Qnum_print(&q3);break;
			case 3: q3=Multi_Qnum(q1,q2);Qnum_print(&q3);break;
			case 4: q3=Divi_Qnum(q1,q2);Qnum_print(&q3);break;
		}
		if(s_num==5){
			break;
		}
	}
//	q3=Sub_Qnum(q1,q2);
//	Qnum_print(&q3);
	return 0;
}