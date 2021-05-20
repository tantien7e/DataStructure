#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int nbOfE;

int* createArr(){
    int *p = (int*)malloc(sizeof(int)*10000000);
    return p;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void generateArr(int* p, int n){
    srand((int) time(0));
    for(int i = 0; i< n; i++){
        p[i] = rand();
    }
}


void insertionSort(int *p, int n){
    clock_t tstart,tfinish;
    tstart= clock();
    time_t t1,t2; time(&t1);
    for(int i =1; i < n; i++){
        int value = p[i];
        while(i> 0 && value < p[i-1]){
            p[i] = p[i-1];
            i--;
        }
        p[i] = value; 
    }
    time(&t2);
    int durationinseconds = (int) (t2 - t1);
    tfinish= clock();
    float tcomp; 
    tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
    printf("Second: %d\n", durationinseconds);
    printf("Tick: %f\n", tcomp);
}

void selectionSort (int *p, int n){
    
    clock_t tstart,tfinish;
    tstart= clock();
    time_t t1,t2; time(&t1);

    for(int i = 0; i< n; i++){
        for(int j = i+ 1; j<n; j++){
            if(p[j]< p[i]){
                int tmp = p[j];
                p[j] = p[i];
                p[i] = tmp;
            }
        }
    }
    time(&t2);
    int durationinseconds = (int) (t2 - t1);
    tfinish= clock();
    float tcomp; 
    tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
    printf("Second: %d\n", durationinseconds);
    printf("Tick: %f\n", tcomp);

}

void heapify(int *p, int n, int i){
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;
    if(l<n && p[l] > p[largest]){
        largest = l;
    }
    if( r<n && p[r] > p[largest]){
        largest = r;
    }
    if(largest != i){
        swap(&p[largest], &p[i]);
        heapify(p,n,largest);
    }
}

void heapSort(int* p, int n){
    //Build heap from bottom up
    clock_t tstart,tfinish;
    tstart= clock();
    time_t t1,t2; time(&t1);
    for(int i = n/2-1; i>=0; i--){
        heapify(p, n, i);
    }
    //take out the biggest item, the heap -1 element
    for(int i = n-1; i> 0; i--){
        swap(&p[i], &p[0]);
        heapify(p, i, 0);
    }
    time(&t2);
    int durationinseconds = (int) (t2 - t1);
    tfinish= clock();
    float tcomp; 
    tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
    printf("Second: %d\n", durationinseconds);
    printf("Tick: %f\n", tcomp);

}

int partition(int *p, int start, int end){
    int pivot = p[end];
    int index = start;
    for(int i = start; i<=end; i++){
        if(p[i]<=pivot){
            swap(&p[i], &p[index]);
            index++;
        }
    }
    return index-1;
}

void quickSort(int* p, int start, int end){
    if(start < end){
        int k = partition(p, start, end);
        quickSort(p, start, k-1);
        quickSort(p, k+1, end);
    }
    else return;
}

void processQuickSort(int * p, int n){
    clock_t tstart,tfinish;
    tstart= clock();
    time_t t1,t2; time(&t1);

    int start = 0;
    int end = n -1;
    quickSort(p, start, end);
    time(&t2);
    int durationinseconds = (int) (t2 - t1);
    tfinish= clock();
    float tcomp; 
    tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
    printf("Second: %d\n", durationinseconds);
    printf("Tick: %f\n", tcomp);

}

int main(){

    int* p = createArr();
    int* k = createArr();
    printf("1. Generate data\n2.Insertion Sort\n3.Selection Sort\n4.Heap Sort\n5.Quick Sort\n6.Copy Array\n");
    int mode;
    do{
    printf("Choose mode: ");
    scanf("%d", &mode);
    switch (mode)
    {
    case 0:; return 0;
    case 1:; 
            printf("Enter the number of Element: ");
            scanf("%d", &nbOfE);
            generateArr(p, nbOfE);
        break;
    case 2:;
            insertionSort(k, nbOfE);
        break;
    case 3:;
            selectionSort(k, nbOfE);
        break;
    case 4:;
            heapSort(k, nbOfE);
        break;
    case 5:;
            processQuickSort(k, nbOfE);
        break;
    case 6:; 
            for(int i = 0; i< nbOfE; i++){
                k[i] = p[i];
            }
            break;
    default: printf("invalid!\n");
        break;
    }
    } while(mode !=0);
    return 0;
}
