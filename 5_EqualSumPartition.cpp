#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
        }
        int n=nums.size();
        int w= sum/2;
        bool t[n+1][w+1];
        if(sum%2!=0)
            return false;
        if(sum%2==0)
           for(int i=0;i<n+1;i++){
                for(int j=0;j<w+1;j++){
                    if(i==0 )
                        t[i][j]=false;
                    if(j==0)
                        t[i][j]=true;
            }
           }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<w+1;j++){
                    if(nums[i-1]<=j){
                        t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                    }
                    else
                         t[i][j]=t[i-1][j];
                }
            }
            return t[n][w];
    }
// Driver Code
int main()
{
	vector<int> arr= {1,6,11,5 };
	
	// Function call
	if (canPartition(arr) == true)
		cout << "Can be divided into two subsets of equal "
				"sum";
	else
		cout << "Can not be divided into"
			<< " two subsets of equal sum";
	return 0;
}
