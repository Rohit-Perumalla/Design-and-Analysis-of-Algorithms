#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int W = 8;
    int value[] = {1, 2, 5, 10};
    int weight[] = {2, 3, 4, 5};
    int dp[5][9] = {0};

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value = " << dp[n][W] << endl; 

    int w = W;
    int totalW = 0;
    cout << "Selected Items:\n";
    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << "Item " << i << " -> Profit: " << value[i - 1] << ", Weight: " << weight[i - 1] << endl;
            totalW += weight[i - 1];
            w -= weight[i - 1];
        }
    }
    cout << "Total Weight = " << totalW << endl;
    return 0;
}
