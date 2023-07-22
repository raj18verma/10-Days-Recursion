#include <bits/stdc++.h> 
long long Pow(int X, int N)
{
    // Write your code here. 
    if(N==0)
    return 1;
    else{
        return X*Pow(X,N-1);
    }
}