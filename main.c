#include <stdio.h>
#include <math.h>

void swap(int *xp, int *yp);

void sort(int array[], int array_size);

int * find_elements(int first_array[], int second_array[], int target, int array_size);

#define ARRAY_SIZE 6

int main() {
    int first_array[] = {-1, 3, 8, 2, 9, 5};
    int second_array[] = {4, -5, 2, 10, 5, 20};
    int target = 10;
    int *result;

    result =  find_elements(first_array,second_array,target,ARRAY_SIZE);
    printf("[%d,%d]",result[0],result[1]);

    return 0;
}

int * find_elements( int first_array[],
                  int second_array[],
                  int target,
                  int array_size
                  ) {
    sort(first_array,array_size);
    sort(second_array,array_size);
    
    int i = 0,j = array_size  -1;
    int smallest_diff = abs(first_array[0] + second_array[0] - target);
    int closest_pair[] = {first_array[0],second_array[0]};

    while(i < array_size && j>=0){
        int first_pair = first_array[i];
        int second_pair = second_array[j];

        int current_diff = (first_pair + second_pair - target);
        if(abs(current_diff) < smallest_diff){
            smallest_diff = abs(current_diff);
            closest_pair[0] = first_pair;
            closest_pair[1] = second_pair;
        }
        if (current_diff == 0) {
            return closest_pair;
        }
        else if (current_diff < 0) {
            i += 1;
        }
        else {
            j -= 1;
        }
    }
    return closest_pair;
}

void sort( int array[], int array_size) {
    int min_idx;

    for (int i = 0; i < array_size - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < array_size; j++)
            if (array[j] < array[min_idx])
                min_idx = j;

        swap(&array[min_idx], &array[i]);
    }
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
