#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
    void solve(int k,int ind,int sumTill,int n,vector<int>&temp){
        if(sumTill==n && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if((sumTill>n && temp.size()<k) || (sumTill<n && temp.size()>k))return;

        for(int i=ind;i<=9;i++){
            temp.push_back(i);
            solve(k,i+1,sumTill+i,n,temp);
            temp.pop_back();
        }
        return;
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        ans={};
        vector<int>temp={};
        if(k>n)return ans;
        solve(k,1,0,n,temp);
        return ans;
    }
int main(){
    int k,n;
    cin>>k>>n;
    vector<vector<int>>temp=combinationSum3(k,n);
    for(auto x:temp){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}