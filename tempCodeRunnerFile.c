void merge(int* Left, int* Right, int* p, int l, int r){
    int i, j, k;
    i = j =k =0;
    while (i < l && j< r){
        if(Left[i]<=Right[j]){
            p[k] = Left[i];
            k++;
            i++;
        }
        else{
            p[k] = Right[j];
            j++;
            k++;
        }
    }
    while(i<l){
        p[k] = Left[i];
        i++;
        k++;
    }
    while(j<r){
        p[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int*p, int n){
    
    if(n<2) return;
    else{
        int mid = n/2;
        int Left[mid];
        int Right[n-mid];
        for(int i = 0; i< mid; i++){
            Left[i] = p[i];
        }
        for(int j = mid; j< n; j++){
            Right[j-mid] = p[j];
        }
        mergeSort(Left, mid);
        mergeSort(Right, n-mid);
        merge(Left, Right, p, mid, n-mid);
    }
}