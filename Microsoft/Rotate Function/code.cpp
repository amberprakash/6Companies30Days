#include<bits/stdc++.h>

using namespace std;

int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        int original=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            original+=(i*nums[i]);
        }
        int ans=original;
        for(int i=n-1;i>=1;i--){
            int temp=original + sum -(n*nums[i]);
            ans=max(ans,temp);
            original=temp;
        }
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    cout<<maxRotateFunction(nums);
    return 0;
}