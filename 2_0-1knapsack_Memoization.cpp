#include<bits/stdc++.h>
using namespace std;

int static t[100][1002];

int knapsack(int wt[],int val[], int w, int n){
    if(n==0||w==0){
        return 0;
    }
    if(t[n][w]!=-1){
        return t[n][w];
    }
    if(wt[n-1]<=w){
        return t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
    }
    // if(wt[n-1]>w) 
    else {
        return t[n][w]=knapsack(wt,val,w,n-1);
    }
    
}

int main(){

    memset(t, -1, sizeof(t));
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int w = 50; 
    int n = sizeof(wt) / sizeof(wt[0]);
    cout<<knapsack(wt,val,w,n);
    return 0;
}