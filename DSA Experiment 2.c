
#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[100], n, key, i, result;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Function call
    result = linearSearch(arr, n, key);

    // Display result
    if(result == -1)
    {
        printf("Element not found.\n");
    }
    else
    {
        printf("Element found at position %d.\n", result);
    }

    return 0;
}

