

class Solution{
public:
    int t[1001][1001];
    int solve(int arr[], int i, int j) {
       if(i>=j) return 0;
       int mn = INT_MAX;
       if(t[i][j] != -1) return t[i][j];
       for(int k = i;k<j;k++) {
           int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
           mn = min(mn,temp);
       }
       return t[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(t,-1,sizeof(t));
        return solve(arr,1,N-1);
    }
};
