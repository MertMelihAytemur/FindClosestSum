#include <stdio.h>
#include <math.h>

void swap(int *xp, int *yp);

void sort(int array[], int array_size);

int * findElements(int firstArray[], int secondArray[], int target, int array_size);

#define ARRAY_SIZE 6

int main() {
    int firstArray[] = {-1, 3, 8, 2, 9, 5};
    int secondArray[] = {4, -5, 2, 10, 5, 20};
    int target = 10;
    int *result;

    result =  findElements(firstArray,secondArray,target,ARRAY_SIZE);
    printf("[%d,%d]",result[0],result[1]);

    return 0;
}

int * findElements( int firstArray[],
                  int secondArray[],
                  int target,
                  int array_size
                  ) {
    sort(firstArray,array_size);
    sort(secondArray,array_size);


    int i = 0,j = array_size  -1;
    int smallestDiff = abs(firstArray[0] + secondArray[0] - target);
    int closestPair[] = {firstArray[0],secondArray[0]};

    while(i < array_size && j>=0){
        int v1 = firstArray[i];
        int v2 = secondArray[j];

        int currentDiff = (v1 + v2 - target);
        if(abs(currentDiff) < smallestDiff){
            smallestDiff = abs(currentDiff);
            closestPair[0] = v1;
            closestPair[1] = v2;
        }
        if (currentDiff == 0) {
            return closestPair;
        }
        else if (currentDiff < 0) {
            i += 1;
        }
        else {
            j -= 1;
        }
    }
    return closestPair;
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
