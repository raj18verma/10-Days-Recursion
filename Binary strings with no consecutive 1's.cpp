vector<string> generateString(int N) {
    // Write your code here.
    if (N == 0) return {};

    if (N == 1){
        return {"0","1"};
    }
    
    vector<string> NMinus1Ans = generateString(N-1);
    vector<string> ans;
    for (auto x : NMinus1Ans){
        string temp0 = x + "0";
        ans.push_back(temp0);

        if (x.back() == '0'){
            string temp1 = x + "1";
            ans.push_back(temp1);
        }   
    }

    return ans;

}