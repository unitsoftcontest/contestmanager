#include <bits/stdc++.h>
using namespace std;
int arr[N];
void quick(int left, int right)
{
    if(left >= right) return;
    int l = left, r = right;
    int pivot = arr[(left + right) / 2];
    while(l <= r) {
        if(arr[l] < pivot) l++;
        if(arr[r] > pivot) r--;
    }
    while(l <= r) {
        while(arr[l] < pivot) l++;
        while(arr[r] > pivot) r--;
        if(l <= r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    quick(left, r);
    quick(l, right);
}
