#include<cs50.h>
#include<stdio.h>
#include<helpers.h>

bool linear_search(int value, int values[], int n)
{
    int boolnum=0;

    if(n<1)
    {
        return false;
    }

    else
    {
        for(int i=0;i<n;i++)
        {
            if(values[i]== value)
            {
                boolnum=1;
                break;
            }
        }
    }

    if(boolnum==1)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool binary_search(int value, int values[],int n)
{
    int start_index = 0;
    int end_index = n-1;

    while(start_index <= end_index)
    {
        int mid_index = (start_index+end_index)/2;

        if(value == values[mid_index])
        {
            printf("found it !");
            return true;
        }
        else if(value < values[mid_index])
        {
            end_index = mid_index - 1;
        }
        else (value > values[mid_index])
        {
            start_index = mid_index - 1;
        }

        return true;
    }

    return false;
}

void sort(int values[], int n)
{
    for(int i =0;i<n;i++)
    {
        int min=i;
        for(int j = i; j<n;j++)
        {
            if(values[min]>values[j])
            {
                min = j;
            }
        }

        if(min != 1)
        {
            int temp = values[min];
            values[min] = values[i];
            values[i] = int temp;
        }
    }
}