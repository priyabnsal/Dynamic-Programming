// Rod Cutting Problem

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int length[], int price[], int n, int L) {
	int dp[n + 1][L + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= L; j++)
			if (j == 0 || i == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= L; j++) {
			if (length[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j],
				               price[i - 1] + dp[i][j - length[i - 1]]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][L];
}

signed main() {
	// int n; cin >> n;
	// int length[n], price[n];
	// for (int i = 0; i < n; i++)
	// 	cin >> length[i];
	// for (int i = 0; i < n; i++)
	// 	cin >> price[i];
	// int L; cin >> L;

	int len[] = { 1,2,3,4,5,6 };
    int price[] = { 1,5,8,9,10,17};
    int n = 9;
	int L = sizeof(len) / sizeof(len[0]);
	cout << getMaxProfit(len, price, n, L) << endl;
	return 0;
}