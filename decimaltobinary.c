#include<stdio.h>
int main()
{
	int n,rem=0,b[40],i=0,j;
	printf("enter any decimal number\n");
	scanf("%d",&n);
	if(n==0)
	{
		printf("binary number is 0\n");
	}
	while(n>0)
	{
		rem=n%2;
		b[i]=rem;
		n=n/2;
		i++;
	}
	j=i-1;
	printf("binary number\n");
	for(j;j>=0;j--)
	{
		printf("%d\t",b[j]);
	}
}
