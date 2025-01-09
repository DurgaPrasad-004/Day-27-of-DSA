#include<bits/stdc++.h>
using namespace std;

// Kaden's algorithm
// Brute force

void MaxSubarray(vector<int> & a, int n){
    int maxi = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int k = i; k < n; k++){
                sum += a[k];
                maxi = max(sum, maxi);
            }
        }
    }
}
// Time complexity = 0(Ncube);

// Better appraach
void MaxSubarray(vector<int> & a, int n){
    int maxi = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int k = i; k < n; k++){
                sum += a[j];
            }
        }
    }
}
// Time complexity = 0(Nsquare);

// Optimal Approach
long long maxSubarray(int arr[], int n){
    long long maxi = LONG_MIN;
    long long sum = 0;

    int start = 0;
    int ansStart = -1, andEnd = -1;
    for(int i = 0; i < n; i++){

        if (sum == 0) start = i; // starting index

        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if ( sum < 0){
            sum = 0;
        }
    }
     //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";
    
}
int main(){
    
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}