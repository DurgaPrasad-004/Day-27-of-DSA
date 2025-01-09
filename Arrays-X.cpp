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

// Buy stocks and sell them
int maxProfit(vector<int> &arr){
    int maxPro = 0;
    int n = arr.size();
    int miniPrice = INT_MAX;

    for(int i =0; i < n; i++){
        miniPrice = min(miniPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - miniPrice);
    }
    return maxPro;
}

// Time complexity = O(N);
int main(){

    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

// Rearrange array element s by sign
vector<int> rearrangebySign(vector<int> & arr, int n){
    // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array
    vector<int> pos;
    vector<int> neg;
    
    // Separate positive and negative elements of the array
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    // Positives on even indices, negatives on odd.
    for(int i = 0; i < n / 2; i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
    return arr;
}

// Optimal Approach
vector<int> rearrangebySignn(vector<int> &a){
    int n = a.size();
    vector<int> ans(n,0);

    // Separate positive and negative elements of the array
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    // IF the positives are lesser than the negatives
    if(pos.size() < neg.size()){
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number
        for(int i = 0; i < pos.size(); i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
        }
        // Then, fill the remaining elements with negatives
        int index = pos.size()*2;
        for(int i = pos.size(); i<neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
    else{
        for(int i = 0; i < pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i = neg.size(); i<pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
    return arr;
}
int main() {
    
  // Array Initialisation.
  int n = 6;
  vector<int> A {1,2,-4,-5,3,4};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

//Time Complexity: O(2*N)


// leaders of array
vector<int> LeadersOfarray(int arr[], int n){
    vector<int> ans;
    for(int i = 0; i < n; i++){
        bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
        for(int j = i+1; j <n; j++){
            if(arr[j] > arr[i]){

        // If any element found is greater than current leader
        // curr element is not the leader
                leader = false;
                break;
            }
        }
        if(leader == true)ans.push_back(arr[i]);
    }
    return ans;
}

//Time Complexity: O(N^2);

// Optimal Approach
vector<int> printLeaders(int arr[], int n){
    vector<int> ans;

    //  Last element of the array is the leader and push into arrays
    int max = arr[n-1];
    ans.push_back(arr[n-1]);

    // start checking from the end if a number is greater or not from the right
    for(int i = n-2; i>=0; i--){
        if(arr[i] > max){
            ans.push_back(arr[i]);
            max=arr[i];
        }
    }
    return ans;
}

int main(){
    int n = 6;
    int arr[6] = {10,22, 12, 3,0,6};
    vector<int> ans = printLeaders(arr,n);
    for(int i = ans.size() - 1; i>=0; i--){
        cout << arr[i] << "";
    }
    cout << endl;
    return 0;
}
