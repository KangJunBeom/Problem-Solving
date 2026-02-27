    /*
        백준 구간 합 구하기 5
        다이나믹프로그래밍/누적합
        체감 난이도 : 보통
    */

    // 주의해야 할 점 : x와 y의 값이 각각 행과 열을 의미합니다. 좌표와 개념을 혼동하지 마세요.
    #include <bits/stdc++.h>
    using namespace std;

    int arr[1025][1025];
    int n,m;

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> n >> m;
        
        //열 마다 누적합을 더해줌
        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=n; ++j){
                int tmp;
                cin >> tmp;
                arr[i][j] = tmp + arr[i][j-1];
            }
        }

        for(int i =0 ;i<m; ++i){
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int ans = 0;
            for(int i = x1; i<=x2; ++i){
                //더해야하는 영역의 가장 끝 열 값에서 더하지 않는 영역의 가장 끝 열의 값을 빼주면 빠르게 계산이 가능 
                ans += (arr[i][y2] - arr[i][y1-1]);
            }
            cout << ans << "\n";
        }
    }