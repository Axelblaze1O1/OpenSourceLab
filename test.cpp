/*
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n][n];
    for(int i=1; i<n; i++){
        dp[i][i] = 0;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini = 1e9;
            for(int k=i;k<j;k++){
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                if(steps<mini){
                    mini = steps;
                }
            }
            dp[i][j]=mini;

        }
    }
    cout<<dp[1][n-1]<<endl;


return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int x = s1.length();
    int y = s2.length();
    int dp[y+1][x+1];

    for(int i=0;i<x+1;i++){
        dp[0][i]=0;
    }

    for(int i=0;i<y+1;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<y+1;i++){
        for(int j=1;j<x+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[y][x]<<endl;


}
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string src,dest;
    cin>>src>>dest;

    int dp[dest.length()+1][src.length()+1];
    for(int i=0;i<dest.length()+1;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<src.length()+1;i++){
        dp[0][i]=i;
    }

    for(int i=1;i<dest.length()+1;i++){
        for(int j=1;j<src.length()+1;j++){
            int u = 1;
            if(src[j-1]==dest[i-1]){
                u = 0;
            }
            dp[i][j] = min( u + dp[i-1][j-1] , min(1 + dp[i-1][j] ,1 + dp[i][j-1]));

        }

    }

    cout<<dp[dest.length()][src.length()];
/*
    for(int i=0;i<dest.length()+1;i++){
        for(int j=0;j<src.length()+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
*/

return 0;
}
