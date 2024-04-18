//RECURSION+MEMO
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        int n=N;
        vector<vector<long long>> dp(n+1,vector<long long> (sum+1,0));
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                
                dp[i][j]+=dp[i-1][j];
                
                if(j-coins[i-1]>=0){
                    dp[i][j]+=dp[i][j-coins[i-1]];
                }
            }
        }
        
        return dp[n][sum];
        
    }
};

//TABULATION
class Solution {
  public:
    long long helper(int coins[],vector<vector<long long>> &t,int index,int sum){
        
        if(sum==0)return t[index][sum]=1;
        
        if(index==0 || sum<0)return 0;
        
        if(t[index][sum]!=-1)return t[index][sum];
        
        t[index][sum]=helper(coins,t,index-1,sum)+helper(coins,t,index,sum-coins[index-1]);
    }
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<long long>> t(N+1,vector<long long> (sum+1,-1));
        
        helper(coins,t,N,sum);
        
        return t[N][sum];

    }
};
