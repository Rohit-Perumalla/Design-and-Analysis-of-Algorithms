
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int coins[] = {1, 2, 5};
    int n = 3;
    int amount = 11;
    for (int i=0;i<n;i++){
cout<<"coins: "<<coins[i]<<endl;}
cout<<"Amount:"<<amount<<endl;
    int dp[12];
    int used[12];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                    used[i] = coins[j];
                }
            }
        }
    }

    cout << "Minimum coins = " << dp[amount] << endl;

    cout << "Coins used: ";

    int x = amount;
    while (x > 0) {
        cout << used[x] << " ";
        x = x - used[x];
    }

    return 0;
}
