void solve(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>ds){
if(ind==arr.size()){
    if(target==0){
        ans.push_back(ds);
    }
    return;
}
 //picking the element

if(arr[ind]<=target){
    ds.push_back(arr[ind]);
    solve( ind, target-arr[ind],  arr,  ans,  ds);
    ds.pop_back();
}
//not pick
solve( ind+1,target,arr,ans,ds);
}

vector<vector<int>> combSum(vector<int> &arr, int B)
{

    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>ds;
    solve(0,B,arr,ans,ds);
    return ans;

}
