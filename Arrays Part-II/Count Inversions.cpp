#include <bits/stdc++.h>
//Approach - 1
//Time Complexity: O(n^2)
//Space Complexity: O(1) 
long long getInversions(long long *arr, int n){
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

//Approach - 2
//Time Complexity: O(nlogn)
//Space Complexity: O(n) 
long long count1=0;

void merge(long long *arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;  

    while (left <= mid && right <= high) {
        if (arr[left] <=arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            count1=count1+(mid-left+1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
 
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(long long *arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  
    mergeSort(arr, mid + 1, high); 
    merge(arr, low, mid, high);  
}

long long getInversions(long long *arr, int n){
    mergeSort(arr, 0, n-1);
    return count1;
}