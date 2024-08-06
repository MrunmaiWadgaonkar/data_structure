#include<stdio.h>
void main()
{
	int a[10],n,i,found=0;
	printf("enter array elements\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the number you want to search\n");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if(n==a[i])
		{
			found=1;
			printf("element found at %d position\n",i+1);
		}
	}
	if(found==0)
	{
		printf("element not found\n");
	}
}
