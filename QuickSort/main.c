#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "quickSortRandom.h"
#include "quickSortMedian.h"
#include "mergeSort.h"

// 배열을 순서대로 출력하는 함수
void printArr(int arr[]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d | ", arr[i]);
    }
    printf("\n");
}

//1~100난수 배열 생성함수
void randomNum(int list[], int num) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < num; i++) {
        list[i] = (rand()%100)+1;
    }
}

int main() {
    clock_t start, end; // 시간 측정을 위한 변수
    int arr[12] = {6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14}; // 임의의 배열
    // int arr[MAX] = { 0 }; // 60개의 입력 배열
    // randomNum(arr, MAX); // 60개의 랜덤 값 생성



    printArr(arr); // 정렬되지 않은 배열 출력

    start = clock(); // 시간 측정 시작

    // 더 정밀한 시간 측정을 위해 정렬을 만 번 반복한다.
    for(int i = 0; i < 100000; i++) {
        int testArr[MAX]; // 정렬된 배열을 저장할 배열
        memcpy(testArr, arr, sizeof(arr)); // 원본 배열을 복사

        //QuickSortRandomPivot(testArr, 0, MAX - 1); // random 방식으로 pivot을 선정하는 QuickSort
        QuickSortMedianPivot(testArr, 0, MAX - 1); // median 방식으로 pivot을 선정하는 QuickSort
        //mergeSort(testArr, 0, MAX - 1); // MergeSort

        memcpy(arr, testArr, sizeof(arr)); // 다시 원본 배열로 복사
    }

    end = clock(); // 시간 측정 종료

    printArr(arr); // 정렬된 배열 출력
    printf("Time: %f\n", (double)(end - start) / CLOCKS_PER_SEC); // 시간 출력

    return 0;
}
