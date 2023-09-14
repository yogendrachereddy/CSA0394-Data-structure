#include<stdio.h>
 int main()
{
    int n,i,j;
	int arr[n];
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}
    for(i=0;i<n;i++)
    {
        for(j=i;j<n-1;j++)
        {
            if(arr[i]==arr[j+1])
            {
                printf("Number %d has duplicate values\n",arr[i]);
            }
        }
    }
    return 0;
}
