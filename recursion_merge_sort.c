#include <stdio.h>

#define ARRAY_LENGTH 11

void print_array(int array[], int start, int end);
void merge_sort(int unsorted[], int sorted[], int start_index, int end_index);
void merge_left_right(int unsorted[], int sorted[], int start_index, int mid_index, int end_index);
void copy_array(int from[], int to[], int start, int end);

int main(void)
{
    int unsorted_numbers[ARRAY_LENGTH] = {5, 7, 6, 3, 1, 9, 0, 2, 10, 4, 8}; 

    int sorted_numbers[ARRAY_LENGTH];

    copy_array(unsorted_numbers, sorted_numbers, 0, ARRAY_LENGTH - 1);

    print_array(unsorted_numbers, 0, ARRAY_LENGTH - 1);

    merge_sort(unsorted_numbers, sorted_numbers, 0, ARRAY_LENGTH - 1);

    print_array(sorted_numbers, 0, ARRAY_LENGTH - 1);

    return 0;
}

void merge_sort(int unsorted[], int sorted[], int start_index, int end_index)
{
    // Define base-case / exit condition
    // Consider list already sorted
    if (end_index - start_index < 1)
    {
        return;
    }

    int mid = (start_index + end_index) / 2;

    // Sort left
    // print_array(unsorted, start_index, mid);
    merge_sort(unsorted, sorted, start_index, mid);

    // Sort rigth
    // print_array(unsorted, mid + 1, end_index);
    merge_sort(unsorted, sorted, mid + 1, end_index);

    // Merge left and right
    merge_left_right(unsorted, sorted, start_index, mid + 1, end_index);

    return;
}

// Merge sorted halves
void merge_left_right(int unsorted[], int sorted[], int start_index, int mid_index, int end_index)
{
    int mid = mid_index;
    int start = start_index;

    for (int i = start_index; i <= end_index; i++)
    {
        if (mid > end_index)
        {
            mid = start;
        }

        if (start >= mid_index)
        {
            start = mid; 
        }

        if (unsorted[start] < unsorted[mid])
        {
            sorted[i] = unsorted[start];
            start++;
        }
        else
        {
            sorted[i] = unsorted[mid];
            mid++;
        }
    }

    // Need to copy the sorted values from the sorted array to the unsorted
    // It is important to do this step because in merging the unsorted array is used
    copy_array(sorted, unsorted, start_index, end_index);

    // printf ("Sorted:\n");
    // print_array(sorted, start_index, end_index);

    // printf ("Unsorted:\n");
    // print_array(unsorted, start_index, end_index);

    return;
}

void copy_array(int from[], int to[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        to[i] = from[i]; 
    }

    return;
}

void print_array(int array[], int start, int end)
{
    printf ("[");

    for (int i = start; i <= end; i++)
    {
        printf ("%i ", array[i]);
    }
    printf ("]\n");

    return;
}