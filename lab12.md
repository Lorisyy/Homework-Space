# lab12 Sorting
## Bubble sort


冒泡排序（英语：Bubble Sort）是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序（如从大到小、首字母从A到Z）错误就把他们交换过来。 
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
(```)  

#include <stdio.h>
void bubble_sort(int arr[], int len) {  
    int i, j, temp;  
    for (i = 0; i < len - 1; i++)  
        for (j = 0; j < len - 1 - i; j++)  
            if (arr[j] > arr[j + 1]) {  
                temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp;  
            }  
}
int main() {  
    int arr[] = { 22, 34, 3, 32, 82,55, 89, 50, 37, 5, 64, 35, 9, 70 };  
    int len = (int) sizeof(arr) / sizeof(*arr);  
    bubble_sort(arr, len);  
    int i;  
    for (i = 0; i < len; i++)  
        printf("%d ", arr[i]);  
    return 0;  
}  

(```)

如图所示：

![Bubble Sort](images/Bubble_sort_.gif)  

## Selection sort
选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理如下。首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。

(```)

void swap(int *a,int *b)  
{   
    int temp = *a;  
    *a = *b;   
    *b = temp;  
}  
void selection_sort(int arr[], int len)   
{  
    int i,j;  
 
    for (i = 0 ; i < len - 1 ; i++) 
    {  
        int min = i;  
        for (j = i + 1; j < len; j++)       //遍历

            if (arr[j] < arr[min])    //找到目前最小值

                min = j;    //记录最小值  

           swap(&arr[min], &arr[i]);    //交换swap  
    }  
}  

(```)  

The ![Pictures](images/Selection-Sort.gif)  

![Selection](images/Selection_sort.gif)  

