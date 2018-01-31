#include <iostream>
#include <functional>
#include <cmath>
#include <queue>
#include <vector>
#include <cstring>
#include <set> 
#include <algorithm>
using namespace std;

int main() {  
  
//    std::ios::sync_with_stdio(false);  
  
    long long dp[35];  
    dp[0] = 1;  
    dp[1] = 1;  
    for (int i = 2; i <= 30; i++) {  
        dp[i] = 0;  
        for (int j = 0; j < i; j++) {  
            dp[i] += dp[j] * dp[i-1-j];  
        }  
    }  
  
    while (1) {  
        int pos;  
        cin >> pos;  
        if (pos == 0) break;  
        cout << dp[pos] << endl;  
    }  
  
    return 0;  
} 
