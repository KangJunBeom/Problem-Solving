    /*
        토쟁이의 등굣길
        수학/다이나믹프로그래밍
        체감 난이도 : 보통
    */

    #include <bits/stdc++.h>
    using namespace std;

    //열과 행이 반대다.
    int dp[201][201];
    
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        int w, h;
        int toast_x, toast_y;

        cin >> w >> h;
        cin >> toast_x >> toast_y;

        // 확률과 통계 문제에서 경로 구하는 방법을 통해서 구할 수 있다.
        // 출발지점부터 토스트 가게 지점까지의 경로를 먼저 구해준다.
        for(int i = 1; i<=w; ++i){
            dp[1][i] = 1;
        }

        for(int j = 1; j<=h; ++j){
            dp[j][1] = 1;
        }

        //모듈러 연산을 통해서 값이 지나치게 커지지 않도록 한다.
        for(int i = 2; i<=toast_y; ++i){
            for(int j = 2; j<=toast_x; ++j){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000007;
            }
        }

        long long tmp = dp[toast_y][toast_x];

        // 이후, 토스트 가게에서부터 학교까지의 거리를 구해준다.
        for(int i = toast_x; i<=w; ++i){
            dp[toast_y][i] = 1;
        }

        for(int j = toast_y; j<=h; ++j){
            dp[j][toast_x] = 1;
        }

        // 역시 모듈러 연산을 활용한다.
        for(int i = toast_y+1; i<=h; ++i){
            for(int j = toast_x+1; j<=w; ++j){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000007;
            }
        }

        long long tmp2 = dp[h][w];

        //최종적으로 구한 두 결과 값의 곱에 모듈러를 적용해서 답을 얻어낸다.
        cout << (tmp * tmp2)%1000007 ;

        //DP 말고도 조합으로도 해결할 수 있다.

    }