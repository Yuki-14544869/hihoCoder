/*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
*/
#include <bits/stdc++.h>
using namespace std;

const int  N = 1005;

int dp[N][N] = {0};

int min(const int a, const int b, const int c) {
    return min( a, min( b, c ) );
}

int main() {
    string input;
    cin >> input;
    int len = input.length();
    for (int i=len-1; i>=0; --i) {
        for (int j=i+1; j<len ; ++j) {
            if(input[i]==input[j])
                dp[i][j] = dp[i+1][j-1];
            else
                dp[i][j] = min( dp[i+1][j], dp[i][j-1], dp[i+1][j-1] ) + 1;
        }
    }
    cout << dp[0][len-1] << endl;
    return 0;
}