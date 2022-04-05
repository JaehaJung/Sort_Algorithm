#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int* arr;		

void merge(int data[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int* tmp = (int*)malloc(sizeof(int) * r + 1);
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while (i <= q) tmp[k++] = data[i++];
    while (j <= r) tmp[k++] = data[j++];
    for (int a = p; a <= r; a++) data[a] = tmp[a];
}
void mergeSort(int data[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(data, p, q);
        mergeSort(data, q + 1, r);
        merge(data, p, q, r);
    }
}
void quickSort(int data[], int L, int R) {
    int left = L, right = R;
    int pivot = data[(L + R) / 2];    
    int temp;
    do
    {
        while (data[left] < pivot)    
            left++;
        while (data[right] > pivot)   
            right--;
        if (left <= right)    
        {
            temp = data[left];
            data[left] = data[right];
            data[right] = temp;
            
            left++;
            right--;
        }
    } while (left <= right);    

    if (L < right)
        quickSort(data, L, right);    

    if (left < R)
        quickSort(data, left, R);    
}
int sortThree(int L, int M, int R) {
    if (L >= M)
        if (M >= R)
            return M;
        else if (L <= R)
            return L;
        else
            return R;
    else if (L > R)
        return L;
    else if (M > R)
        return R;
    else
        return M;
}
void Re_quickSort(int data[], int L, int R) {
    int left = L, right = R;
    int pivot = data[(L + R) / 2];
     pivot = sortThree(left, pivot, right); // ó��, ������, �߰� ���� ���� �����Ͽ� �߰� ���� pivot ������ ���� 
    int temp;
    do
    {
        while (data[left] < pivot)
            left++;
        while (data[right] > pivot)
            right--;
        if (left <= right)
        {
            temp = data[left];
            data[left] = data[right];
            data[right] = temp;

            left++;
            right--;
        }
    } while (left <= right);

    if (L < right)
        quickSort(data, L, right);

    if (left < R)
        quickSort(data, left, R);
}
void bubbleSort(int data[], int L, int R) {
    int temp;
    for (int i = 0; i < R; i++) {

        for (int j = 0; j < R -1 - i; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int i, n, num;

    printf("�迭�� ũ�� : ");
    scanf_s("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);

    srand((int)time(NULL));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % (n * 10);
    }

    printf("\n���� ��\n\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    do {
    printf("\n 1. bubblesort\n 2. mergesort\n 3. quicksort\n 4. Re_quicksort(����)\n0. ����\n");
    scanf_s("%d", &num);

    /*��������*/
    if (num == 1) { 
        clock_t start, finish;
        double duration;
        start = clock();
        /*------�����ϱ�------*/
        bubbleSort(arr, 0, n);
        /*--------------------*/
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        printf("\n���� ��\n\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n%f��", duration);
    }

    /*��������*/
    if (num == 2) { 
        clock_t start, finish;
        double duration;
        start = clock();
        /*------�����ϱ�------*/
        mergeSort(arr, 0, n - 1); 
        /*--------------------*/
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        printf("\n���� ��\n\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n%f��", duration);
    }

    /*������*/
    if (num == 3) { 
        clock_t start, finish;
        double duration;
        start = clock();
        /*------�����ϱ�------*/
        quickSort(arr, 0, n - 1);
        /*--------------------*/
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        printf("\n���� ��\n\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n%f��", duration);
    }

    /*����������*/
    if (num == 4) {
        clock_t start, finish;
        double duration;
        start = clock();
        /*------�����ϱ�------*/
        Re_quickSort(arr, 0, n - 1);
        /*--------------------*/
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        printf("\n���� ��\n\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n%f��", duration);
    }
    } while (num == 1|| num == 2|| num == 3|| num ==4);
    return 0;
}

