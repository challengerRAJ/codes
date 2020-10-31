#include <iostream>
using namespace std;
int fun1(string X,string Y,int m,int n)
{
    if(n==0||m==0)
        return 0;
    if(X[m-1]==Y[n-1])
        return 1+fun(X,Y,m-1,n-1);
    else
        return max(fun(X,Y,m-1,n),fun(X,Y,m,n-1));
}

string printlcs(vector<vector<int> > dp,string X,string Y,int m,int n)
{
    string ans;
    int i = m, j = n,index = dp[m][n]; 
    while (i > 0 && j > 0) 
    { 
        if (X[i-1] == Y[j-1]) 
        { 
            ans += X[i-1];  
            i--; j--; index--; 
        } 
        else if (dp[i-1][j] > dp[i][j-1]) 
            i--; 
        else
            j--; 
    }
    return ans;
}


/* vector<vector<int>> mem(m+1,vector<int> (n+1,-1));*/
int fun2(string X,string Y,int m,int n,vector<vector<int> > &mem)
{
    if(n==0||m==0)
        return 0;
    if(mem[m][n]!=-1)
      return mem[m][n];
    if(X[m-1]==Y[n-1])
        return mem[m][n] = 1+fun(X,Y,m-1,n-1);
    else
        return mem[m][n] = max(fun(X,Y,m-1,n),fun(X,Y,m,n-1));
}
int fun3(string X,string Y,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(X[i-1]==Y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[m][n];
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>m>>n;
        string X,Y;
        cin>>X;
        cin>>Y;
        cout<<fun(X,Y,m,n)<<endl;
    }
	return 0;
}
