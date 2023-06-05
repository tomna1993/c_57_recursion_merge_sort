#include <stdio.h>

#define ARRAY_LENGTH 11

void print_array(int array[], int array_length);
void merge_sort(int array[], int array_length);
void sort_halves(int unsorted[], int sorted[], int start_index, int end_index);
void merge_halves(int unsorted[], int sorted[], int start_index, int mid_index, int end_index);
void copy_array(int from[], int to[], int start, int end);

int main(void)
{
    int unsorted_numbers[ARRAY_LENGTH] = {5, 7, 6, 3, 1, 9, 0, 2, 10, 4, 8}; 

    print_array(unsorted_numbers, ARRAY_LENGTH);

    // The sorted array will be placed back into unsorted array
    merge_sort(unsorted_numbers, ARRAY_LENGTH);

    print_array(unsorted_numbers, ARRAY_LENGTH);

    return 0;
}

void merge_sort(int array[], int array_length)
{  
    int unsorted[array_length];

    // The unsorted array (work array) must contain the same elements as
    // the array we want to sort
    copy_array(array, unsorted, 0, array_length);

    sort_halves(unsorted, array, 0, array_length - 1);

    return;
}


void sort_halves(int unsorted[], int sorted[], int start_index, int end_index)
{
    // Define base-case / exit condition
    // Consider list already sorted or list has just one number
    if (start_index >= end_index)
    {
        return;
    }

    int mid_index = (start_index + end_index) / 2;

    // Sort left source
    sort_halves(unsorted, sorted, start_index, mid_index);

    // Sort rigth source
    sort_halves(unsorted, sorted, mid_index + 1, end_index);

    // Merge left and right back into unsorted array
    merge_halves(unsorted, sorted, start_index, mid_index + 1, end_index);

    return;
}

void merge_halves(int unsorted[], int sorted[], int start_index, int mid_index, int end_index)
{
    int count = start_index;
    int start = start_index;

    int mid = mid_index;

    while (start < mid_index && mid <= end_index)
    {
        // Always check unsorted list, later we must copy the sorted array
        // back into the unsorted
        if (unsorted[start] <= unsorted[mid])
        {
            sorted[count] = unsorted[start];
            start++;
        }
        else
        {
            sorted[count] = unsorted[mid];
            mid++;
        }

        count++;
    }

    //
    while (start < mid_index) 
    {
        sorted[count++] = unsorted[start++];  
    }

    while (mid <= end_index)
    {
        sorted[count++] = unsorted[mid++];
    }

    // Copy the sorted part of the list back to unsorted
    copy_array(sorted, unsorted, 0, end_index + 1);

    return;
}

void copy_array(int from[], int to[], int start, int end)
{
    for (int i = start; i < end; i++)
    {
        to[i] = from[i]; 
    }

    return;
}

void print_array(int array[], int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        printf ("%i ", array[i]);
    }
    printf ("\n");

    return;
}
