void TOH(int n, int from, int to, int aux,vector<vector<int>> &ans){
    if(n>0){
        TOH(n-1,from,aux,to,ans);
        ans.push_back({from,to});
        TOH(n-1,aux,to,from,ans);
    }
}


vector<vector<int>> towerOfHanoi(int n)
{
    //    Write your code here.
    vector<vector<int>>ans;
    TOH(n,1,2,3,ans);
    return ans;
}
