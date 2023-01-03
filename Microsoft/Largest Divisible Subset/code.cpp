#include<bits/stdc++.h>
using namespace std;

vector<int>solve(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    vector<int>trace(n,-1);
    int ans=-1;
    int lastIndex=-1;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && dp[j]>=dp[i]){
                dp[i]=dp[j]+1;
                trace[i]=j;
            }
        }
        if(dp[i]>ans){
            ans=dp[i];
            lastIndex=i;
        }
    }
    vector<int>res;
    while(lastIndex!=-1){
        res.push_back(nums[lastIndex]);
        lastIndex=trace[lastIndex];
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    } 
    vector<int>res=solve(nums);
    for(auto x:res){
        cout<<x<<" ";
    }
    return 0;
}