
#include <stdio.h>
int main()
{
    int array[100], pos, i, n;    
    printf("Enter number of elements in array:");
    scanf("%d", &n);    
    printf("Enter %d elements:", n);    
    for ( i = 0 ; i < n ; i++ )
	    scanf("%d", &array[i]);    
    printf("Enter the location to delete element:");
    scanf("%d", &pos);    
    if ( pos >= n+1 )    
    printf("Deletion not possible.\n");    
    else
    {    
        for ( i = pos - 1 ; i < n - 1 ; i++ )
		    array[i] = array[i+1];       
        printf("The new array is:\n");
        
        for( i = 0 ; i < n - 1 ; i++ )
		    printf("%d ", array[i]);        
    }    
    return 0;
}
