#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

char c,A[5],B[5];
int temp[20];

void tobinary(int a)
{
	int flag = 0;
	if(a<0)
	{
		a=-a;
		flag=1;
	}
	for (int i=0;i<=12;++ i)
		temp[i]=0;
	int count=0;
	while(a)
	{
		temp[count++]=a%2;
		a/=2;
	}
	if (flag){
		for(int i=0;i<=12;++i)
			temp[i]=!temp[i];
		temp[0]++;
		for(int i=0;i<=12;++i)
			if (temp[i]==2)
			{
				temp[i]=0;
				temp[i+1]++;
			}
	}
	count=12;
	while(count>= 0)
		printf("%d",temp[count--]);
	return;
}

int ctoi(char a)
{
	if (a>='0'&&a<='9')
		return a-'0';
	if (a>='A'&&a<='Z')
		return a-'A'+10;
	if (a>='a'&&a<='z')
		return a-'a'+10; 
}

int todemical(char *A)
{
	int i=0,flag=1,number=0;
	if(A[0]=='-')
	{
		flag=-1;
		i=1;
	}
	for(;A[i];++ i)
	{
		number*=16;
		number+=ctoi(A[i]);
	}
	return flag*number;
}

main()
{
	int n,a,b;
	while(cin>>n)
	while(n--)
	{
		cin>>A>>c>>B;
		a=todemical(A);
		tobinary(a);
		printf("%c",c);
		b=todemical(B);
		tobinary(b);
		if (c=='+')
			printf("=%d\n",a+b);
		else printf("=%d\n",a-b);
	}
}
