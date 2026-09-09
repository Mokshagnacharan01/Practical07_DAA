#include <iostream>
using namespace std;

int main()
{
    int n, amount;

    // Number of coin types
    cout << "Enter number of coins: ";
    cin >> n;

    int coins[n];

    // Input coin values
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // Amount for which change is required
    cout << "Enter amount: ";
    cin >> amount;

    // dp[i] = minimum number of coins required to make amount i
    int dp[amount + 1];

    // Initialize
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = 999999999;
    }

    // Dynamic Programming
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                if (dp[i - coins[j]] != 999999999)
                {
                    dp[i] = min(dp[i],
                                dp[i - coins[j]] + 1);
                }
            }
        }
    }

    // Display result
    if (dp[amount] == 999999999)
    {
        cout << "Change cannot be made." << endl;
    }
    else
    {
        cout << "Minimum number of coins required = "
             << dp[amount] << endl;
    }

    return 0;
}

