#include<bits/stdc++.h>
void solve(vector<int>arr , int n , int target , vector<int>&ds , vector<vector<int>>&ans , int ind){
    if (target == 0) {
        ans.push_back(ds);
        return;
    }
    for(int i =ind ; i<arr.size() ;i++){
        if(ind!=i && arr[i]==arr[i-1])
            continue;
        if(arr[i]> target)
            break;
        //this without call is not required its only required when you are dealing with generous ans not unique 

        // solve(arr , n , target , ds , ans , i+1);
        ds.push_back(arr[i]);
        solve(arr, n, target - arr[i], ds, ans, i+1);
        ds.pop_back();

    }

}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){

    // Write your code here.
    sort(arr.begin() , arr.end());
    vector<vector<int>>ans;
    vector<int>ds;
    solve(arr , n , target , ds , ans , 0);
    return ans;

}
