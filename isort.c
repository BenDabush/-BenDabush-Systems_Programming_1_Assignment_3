#include <stdio.h>
#include "isort.h"

int main()
{
    char ch;
    int j = 0;
    int number = 0;
    int arr[ARRAY];

    FILE *fp = fopen("input.txt","r");
    if (fp == NULL)
    {
        return 0;
    }

    ch = fgetc(fp);
    while(ch!=EOF)
    {
        while((48 <= ch)&&(ch <=57))
        {
            number = number*10+(ch-48);
            ch = fgetc(fp);
        }
        *(arr+j) = number;
        number = 0;
        j++;
        ch = fgetc(fp);
    }

    insertion_sort(arr , ARRAY);
    for(int i = 0; i<ARRAY; i++)
    {
        if(i<ARRAY-1)
        {
            printf("%d,", *(arr+i));
        }
        else
        {
            printf("%d\n", *(arr+i));
        }
        
    }
    fclose(fp);
    return 0;
}

int shift_element(int* arr, int i)
{
    for(int j = i; j>0; j--)
    {
        *(arr+j+1) = *(arr+j);
    }
    return 0;
}

int insertion_sort(int* arr , int len)
{
    for(int i=1; i<len; i++)
    {
        int j=i-1;
        if(*(arr+j)>*(arr+i))
        {
            do{
                j--;
            }while ((j>=0) & (*(arr+j)>*(arr+i)));

            int alemnt_in_place_i = *(arr+i);
            shift_element(arr+j, (i-(j+1)));
            *(arr+j+1) = alemnt_in_place_i;
        }
    }
    return 0;
}