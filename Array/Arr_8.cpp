#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        int curr_sum=arr[0], mx= INT_MIN;
    
        for(int i=1;i<n;i++){
            
            curr_sum = max(arr[i], curr_sum+arr[i]);
            mx = max(curr_sum, mx);
        }
        return mx;
        
    }
};