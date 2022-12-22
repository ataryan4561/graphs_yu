#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;
int binarySearch(vector<int> arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
  
        if (arr[mid] == x) 
            return mid; 
  
        
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {}
    int n;
    cin>>n;
    vector<int> arr(n,0);
    vector<int> arr2(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        arr2[i]=arr[i];
    }
    sort(arr2.begin(),arr2.end(),greater<int>());
    vector<int> ans(n,0);
    for(int i=0; i<n; i++)
    {
        int index=binarySearch(arr2, 0, n - 1, arr[i])
            {
                ans[i]=index+1;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
