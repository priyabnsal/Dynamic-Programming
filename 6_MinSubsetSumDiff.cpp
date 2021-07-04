#include <bits/stdc++.h>
using namespace std;


int findMin(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	bool dp[n+1][sum+1];

	// for (int i = 0; i <= n; i++)
	// 	dp[i][0] = true;

	// for (int i = 1; i <= sum; i++)
	// 	dp[0][i] = false;

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0)
                dp[i][j] = 0;
            if(j==0)
                dp[i][j] = 1;
        }
        
    }

	for (int i=1; i<=n+1; i++)
	{
		for (int j=1; j<=sum+1; j++)
		{
			if (arr[i-1] <= j)
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
		}
	}

	int diff = INT_MAX;
	
	for (int j=sum/2; j>=0; j--)
	{
		// Find the
		if (dp[n][j] == true)
		{
			diff = sum-2*j;
			break;
		}
	}
	return diff;
}

int main()
{
	int arr[] = {10,18,52};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "The minimum difference between 2 sets is "
		<< findMin(arr, n);
	return 0;
}
