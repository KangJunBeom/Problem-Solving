    /*
        백준 스티커
        다이나믹프로그래밍
        체감 난이도 : 적당
    */

    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int tc, n;
        cin >> tc;
        while(tc--){
            cin >> n;
            vector<vector<int>> dp(3,vector<int>(n,0));
            vector<vector<int>> arr(2,vector<int>(n,0));

            for(int i = 0; i<2; ++i){
                for(int j =0; j<n; ++j){
                    cin >> arr[i][j];
                }
            }

            dp[0][0] = arr[0][0];
            dp[1][0] = arr[1][0];
            dp[2][0] = 0;

            // dp[0]는 앞 열에서 아래 선택하거나 미선택
            // dp[1]는 앞 열에서 위 선택하거나 미선택
            // dp[2]는 앞 열에서 큰 값 (이번 열에서 미선택);
            for(int j = 1; j<n; ++j){
                dp[0][j] = max(dp[1][j-1],dp[2][j-1])+arr[0][j];
                dp[1][j] = max(dp[0][j-1],dp[2][j-1])+arr[1][j];
                dp[2][j] = max(dp[0][j-1],dp[1][j-1]);
            }

            // max 함수는 기존 2개 중 큰 값을 비교하는 기능에서
            // C++ 11 이후 중괄호 안에 여러 원소를 넣어서 최댓값 확인할 수 있음
            cout <<  max({dp[0][n-1], dp[1][n-1], dp[2][n-1]}) << "\n";
        }
    }