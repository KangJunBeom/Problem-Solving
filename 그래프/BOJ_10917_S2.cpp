    /*
        백준 Your Life
        그래프/BFS
        체감 난이도 : 높음
    */

    #include <bits/stdc++.h>
    using namespace std;

    int target, way;
    vector<int> v[100001];
    vector<int> dist(100001,0); // 거리 값을 저장하기 위한 벡터
    // 메모리 관리를 신경써야 함. 데이터가 매우 큼

    void bfs(){
        int start = 1;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int next = q.front();
            if(next == target){
                cout << dist[next];
                exit(0);
            }
            q.pop();

            for(int s : v[next]){
                if(dist[s] != 0) continue; // 이미 방문한 곳이라고 판단할 수 있는 근거
                dist[s] = dist[next]+1;
                q.push(s);
            }
        }

        cout << "-1";
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> target >> way;
        
        for(int i = 0; i<way; ++i){
            int u, g;
            cin >> u >> g;
            v[u].push_back(g);
        }

        bfs();

    }