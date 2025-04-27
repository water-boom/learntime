#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <windows.h>

int a1[100];
int a2[1000];
int a3[10000];
int a4[100000];
int a5[1000000];
int aux[1000000];

void point(int option);
void point1();
void point2();
void point3();

void swap(int *a, int *b);
int check(int arry[], int len);

void BubbleSort(int arry[], int len);
void SelectSort(int arry[], int len);
void InsertSort(int arry[], int len);

void MergeSort(int arry[], int low, int high, int aux[], int flag);
void Merge(int arry[], int low, int mid, int high, int aux[]);

void QuickSort(int arry[], int low, int high, int flag);
static void _QuickSort(int arry[], int low, int high);
int QuickPass(int arry[], int low, int high);

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

double get_time_in_seconds() {
    LARGE_INTEGER frequency, count;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&count);
    return (double)count.QuadPart / (double)frequency.QuadPart;
}
void work(int option) {
    // BubbleSort
    printf("\n####BubbleSort####\n");
    point(option);  // 重新初始化数组
    BubbleSort(a1, 100);
    BubbleSort(a2, 1000);
    BubbleSort(a3, 10000);
    BubbleSort(a4, 100000);
    BubbleSort(a5, 1000000);
    
    // SelectSort
    printf("\n####SelectSort####\n");
    point(option);  // 重新初始化数组
    SelectSort(a1, 100);
    SelectSort(a2, 1000);
    SelectSort(a3, 10000);
    SelectSort(a4, 100000);
    SelectSort(a5, 1000000);
    
    // InsertSort
    printf("\n####InsertSort####\n");
    point(option);  // 重新初始化数组
    InsertSort(a1, 100);
    InsertSort(a2, 1000);
    InsertSort(a3, 10000);
    InsertSort(a4, 100000);
    InsertSort(a5, 1000000);
    
    // MergeSort
    printf("\n####MergeSort####\n");
    point(option);  // 重新初始化数组
    memset(aux, 0, sizeof(aux));
    MergeSort(a1, 0, 100-1, aux, 1);
    MergeSort(a2, 0, 1000-1, aux, 1);
    MergeSort(a3, 0, 10000-1, aux, 1);
    MergeSort(a4, 0, 100000-1, aux, 1);
    MergeSort(a5, 0, 1000000-1, aux, 1);
    
    // QuickSort
    printf("\n####QuickSort####\n");
    point(option);  // 重新初始化数组
    QuickSort(a1, 0, 100-1, 1);
    QuickSort(a2, 0, 1000-1, 1);
    QuickSort(a3, 0, 10000-1, 1);
    QuickSort(a4, 0, 100000-1, 1);
    QuickSort(a5, 0, 1000000-1, 1);
    
    // HeapSort
    printf("\n####HeapSort####\n");
    point(option);  // 重新初始化数组
    heapSort(a1, 100);
    heapSort(a2, 1000);
    heapSort(a3, 10000);
    heapSort(a4, 100000);
    heapSort(a5, 1000000);
}
int main() {
    int option;
    scanf("%d", &option);
    switch(option){
        case 1:
        printf("\n===============================Point1=======================================\n");
        break;
        case 2:
        printf("\n===============================Point2=======================================\n");
        break;
        case 3:
        printf("\n===============================Point3=======================================\n");
        srand(315); 
        break;
    }
	work(option);
    return 0;
}
void point(int option){
	switch(option){
		case 1:
		point1();
		break;
		case 2:
		point2();
		break;
		case 3:
		point3();
		break;
	}
}
void point1() {
    for (int i = 0; i < 100; i++) 
        a1[i] = i + 1;
    for (int i = 0; i < 1000; i++) 
        a2[i] = i + 1;
    for (int i = 0; i < 10000; i++) 
        a3[i] = i + 1;
    for (int i = 0; i < 100000; i++) 
        a4[i] = i + 1;
    for (int i = 0; i < 1000000; i++) 
        a5[i] = i + 1;
}

void point2() {
    for (int i = 0; i < 100; i++) 
        a1[i] = 100 - i; 
    for (int i = 0; i < 1000; i++) 
        a2[i] = 1000 - i; 
    for (int i = 0; i < 10000; i++) 
        a3[i] = 10000 - i; 
    for (int i = 0; i < 100000; i++) 
        a4[i] = 100000 - i; 
    for (int i = 0; i < 1000000; i++) 
        a5[i] = 1000000 - i; 
}

void point3() {
    for (int i = 0; i < 100; i++) 
        a1[i] = rand() % 1000;
    for (int i = 0; i < 1000; i++)
        a2[i] = rand() % 10000;
    for (int i = 0; i < 10000; i++)
        a3[i] = rand() % 100000;
    for (int i = 0; i < 100000; i++)
        a4[i] = rand() % 1000000;
    for (int i = 0; i < 1000000; i++)
        a5[i] = rand() % 10000000;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arry[], int len) {
    double start = get_time_in_seconds();
    int swapped = 0;
    for (int i = 0; i < len - 1; i++) {
        swapped = 0;
        for (int j = 0; j < len - i - 1; j++) {
            if (arry[j] > arry[j + 1]){
                swap(&arry[j], &arry[j + 1]);
                swapped = 1;
            }
        }
        if ((get_time_in_seconds() - start) > 120) { 
            printf("len = %d   Timeout occurred.\n", len);
            return; 
        }
        if (!swapped) break;
    }
    double end = get_time_in_seconds();
    if (check(arry, len) == 1) {
        double elapsed = (double)(end - start) ;
        printf("len = %d   ", len);
        printf("Time taken: %.15f seconds\n", elapsed);
    } else {
        printf("BubbleSort: Error\n");
    }
}

void SelectSort(int arry[], int len) {
    double start = get_time_in_seconds();
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (arry[j] < arry[min])
                min = j;
        }
        swap(&arry[i], &arry[min]);
        if ((get_time_in_seconds() - start) > 120) { 
            printf("len = %d   Timeout occurred.\n", len);
            return; 
        }
    }
    double end = get_time_in_seconds();
    if (check(arry, len) == 1) {
        double elapsed = (double)(end - start);
        printf("len = %d   ", len);
        printf("Time taken: %.15f seconds\n", elapsed);
    } else {
        printf("SelectSort: Error\n");
    }
}

void InsertSort(int arry[], int len) {
    double start = get_time_in_seconds();
    for (int i = 1; i < len; i++) {
        int key = arry[i];
        int j = i - 1;
        while (j >= 0 && arry[j] > key) {
            arry[j + 1] = arry[j];
            j--;
        }
        arry[j + 1] = key;
        if ((get_time_in_seconds() - start) > 120) { 
            printf("len = %d   Timeout occurred.\n", len);
            return ; 
        }
    }
    double end = get_time_in_seconds();
    if (check(arry, len) == 1) {
        double elapsed = (double)(end - start);
        printf("len = %d   ", len);;
        printf("Time taken: %.15f seconds\n", elapsed);
    } else {
        printf("InsertSort: Error\n");
    }
}

void MergeSort(int arry[], int low, int high, int aux[], int flag) {
    double start = get_time_in_seconds();
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    MergeSort(arry, low, mid, aux, 0);
    MergeSort(arry, mid + 1, high, aux, 0);
    Merge(arry, low, mid, high, aux);
    for (int i = low; i <= high; i++) {
        arry[i] = aux[i];
    }
    if (flag == 1) {
        double end = get_time_in_seconds();
        if (check(arry, high+1) == 1) {
            double elapsed = (double)(end - start) ;
            printf("len = %d   ", high+1);
            printf("Time taken: %.15f seconds\n", elapsed);
        } else {
            printf("MergeSort: Error\n");
        }
    }
}

void Merge(int arry[], int low, int mid, int high, int aux[]) {

    int i = low;
    int j = mid + 1;
    int k = i;
    while (i <= mid && j <= high) {
        if (arry[i] < arry[j]) {
            aux[k++] = arry[i++];
        } else {
            aux[k++] = arry[j++];
        }
    }
    while (i <= mid) {
        aux[k++] = arry[i++];
    }
    while (j <= high) {
        aux[k++] = arry[j++];
    }
}

void QuickSort(int arry[], int low, int high, int flag) {
    if (flag == 1) {
        double start = get_time_in_seconds();// 只在顶层调用计时
        _QuickSort(arry, low, high);
        double end = get_time_in_seconds();
            if (check(arry,  high+1) == 1) {
                double elapsed = (double)(end - start);
                printf("len = %d   ", high+1);
                printf("Time taken: %.15f seconds\n", elapsed);
            } else {
                printf("QuickSort: Error\n");
            }
        
    } else {
        _QuickSort(arry, low, high);
    }
}

// 拆分实现函数
static void _QuickSort(int arry[], int low, int high) {
    if (low >= high) return;
    int pivot = QuickPass(arry, low, high);
    _QuickSort(arry, low, pivot-1);
    _QuickSort(arry, pivot+1, high);
}
int QuickPass(int arry[], int low, int high) {
    int pivotIdx = low + rand() % (high - low + 1);
    swap(&arry[low], &arry[pivotIdx]);
    int x = arry[low];
    while (low < high) {
        while (low < high && x <= arry[high])
            high--;
        if (low == high)
            break;
        arry[low++] = arry[high];
        while (low < high && x >= arry[low])
            low++;
        if (low == high)
            break;
        arry[high--] = arry[low];
    }
    arry[low] = x;
    return low;
}

void heapify(int arr[], int n, int i) {
    int largest = i;         // 当前节点
    int left = 2 * i + 1;    // 左子节点
    int right = 2 * i + 2;   // 右子节点

    // 找出最大值
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是当前节点，交换并递归调整
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// 主函数：堆排序
void heapSort(int arr[], int n) {
    double start = get_time_in_seconds();
    // 1. 建堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--){
    heapify(arr, n, i);
    if ((get_time_in_seconds() - start) > 120){
        printf("HeapSort: len = %d   Timeout occurred.\n", n);
        return;
    }
}
    // 2. 排序（交换堆顶与最后一个元素，然后继续调整）
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);      // 移动当前最大值到数组末尾
        heapify(arr, i, 0);  // 重新调整堆
        if ((get_time_in_seconds() - start) > 120) { 
            printf("HeapSort: len = %d   Timeout occurred.\n", n);
            return;
        }        
    }

    double end = get_time_in_seconds(); 
    if (check(arr, n) == 1) {
        double elapsed = (double)(end - start);
        printf("HeapSort: len = %d   Time taken: %.15f seconds\n", n, elapsed);
    } else {
        printf("HeapSort: Error\n");
    }
}
int check(int arry[], int len) {
    for (int i = 0; i < len - 1; i++) {
        if (arry[i] > arry[i + 1])
            return 0;
    }
    return 1;
}
