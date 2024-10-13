Given an integer array of coins[ ] of size N representing different types of denominations and an integer sum, the task is to count all combinations of coins to make a given value sum.  

Note: Assume that you have an infinite supply of each type of coin. 

Examples: 

Input: sum = 4, coins[] = {1,2,3}
Output: 4
Explanation: there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2} and {1, 3}
#include <bits/stdc++.h>
using namespace std;

// Returns the count of ways we can
// sum coins[0...n-1] coins to get sum "sum"
int countWays(const vector<int>& coins, int n, int sum) {
  
    // If sum is 0 then there is 1 solution
    // (do not include any coin)
    if (sum == 0) return 1;

    // 0 ways in the following two cases
    if (sum < 0 || n == 0) return 0;

    // count is sum of solutions (i)
    // including coins[n-1] (ii) excluding coins[n-1]
    return countWays(coins, n, sum - coins[n - 1]) + 
            countWays(coins, n - 1, sum);
}

// Driver code
int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << countWays(coins, coins.size(), sum);
    return 0;
}
