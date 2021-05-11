void hanoi(int n, int start, int end){
    if(n == 1){
        printf("%d -> %d\n", start, end);
        return;
    }
    int other = 6 - start - end;
    hanoi(n-1, start, other);
    printf("%d -> %d\n", start, end);
    hanoi(n-1, other, end);
}

int main(){
    hanoi(3, 1, 3);
}