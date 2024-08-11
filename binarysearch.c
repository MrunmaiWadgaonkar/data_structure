#include<stdio.h>
int main()
{
	int a[100],n,low,mid,high,i,item,found=0;
	printf("enter the dimension of array\n");
	scanf("%d",&n);
	printf("enter a sorted array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the element you want to search\n");
	scanf("%d",&item);
	low=0;
	high=n-1;
	mid=(low+high)/2;
	while(low<=high)
	{
		if(a[mid]==item)
		{
			found=1;
			printf("element found at %d position",mid+1);
			break;
		}
		else if(item>a[mid])
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
		mid=(low+high)/2;
	}
	return 0;
}
