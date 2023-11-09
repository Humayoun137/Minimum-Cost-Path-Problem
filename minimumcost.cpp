#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 100;
int minCostPath(int cost[MAX_SIZE][MAX_SIZE], int m, int n)
{
    int dp[MAX_SIZE][MAX_SIZE];
    dp[0][0] = cost[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + cost[0][j];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = cost[i][j] + min(dp[i - 1][j - 1],

                                        min(dp[i - 1][j], dp[i][j - 1]));

        }
    }
    cout << "DP Table:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return dp[m - 1][n - 1];
}
int main()
{
    int cost[MAX_SIZE][MAX_SIZE];
    int m, n;

    cout << "Enter number of rows and columns (m, n): ";
    cin >> m >> n;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int minCost = minCostPath(cost, m, n);

    cout << "Minimum cost path = " << minCost << "\n";
    return 0;
}
