#include<bits/stdc++.h>
using namespace std;

bool Subset(int arr[],int sum, int n){
    bool t[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0;j<sum+1;j++)
        if(i==0){
         t[i][j]=false;
        }
        else if(j==0){
         t[i][j]=true;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
             t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else {
             t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){

    // memset(t, -1, sizeof(t));
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (Subset(arr, sum, n) == true)
        cout<< "Found a subset with given sum";
    else
        cout<<"No subset with given sum";
    return 0;
}