#include<bits/stdc++.h>
using namespace std;

void swa(int *a,int *b)
{
    int x = *a;
    *a = *b;
    *b =x;
}

class MaxHeap {
    int* harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of max heap
    int heap_size; // Current number of elements in max heap
public:
    MaxHeap(int a[], int s); // Constructor
    void maxHeapify(int i); // To maxHeapify subtree rooted with index i
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    //int extractMax(); // extracts root (maximum) element
    int getMax() { return harr[0]; } // Returns maximum
    void change_max(int);

};
void MaxHeap::change_max(int num)
{
    harr[0] = num;
    maxHeapify(0);
}
MaxHeap::MaxHeap(int a[], int s)
{
    heap_size = s;
    harr = a; // store address of array
    int i = (heap_size - 1) / 2;
    while (i >= 0) {
        maxHeapify(i);
        i--;
    }
}
void MaxHeap::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] > harr[i])
        largest = l;
    if (r < heap_size && harr[r] > harr[largest])
        largest = r;
    if (largest != i) {
        swa(&harr[i], &harr[largest]);
        maxHeapify(largest);
    }
}

int main()
{
    int n,k;
    long long int sum=0;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
          cin>>a[i];
          sum+=a[i];
    }
    MaxHeap h(a,n);
    for(int i=0;i<k;i++)
    {
        int num = h.getMax();
        int x = num/2;
        sum -= (num-x);
        h.change_max(x);
    }
    cout<<sum;
    return 0;
}
