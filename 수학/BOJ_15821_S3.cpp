/*
    백준 낚이고 낚아라
    수학/기하학
    체감 난이도 : 적당
*/

#include <bits/stdc++.h>
using namespace std;

int N, K;


int main(){

    cin >> N >> K;
    vector<double> area;
    for(int i = 0; i<N; ++i){
        int p; double max_len = 0.0, tmp =0.0;
        cin >> p;
        for(int j = 0; j<p; ++j){
            int x, y;
            cin >> x >> y;
            tmp = (double)x*x + (double)y*y;
            if(max_len < tmp){
                max_len = tmp;
            }
        }
        area.push_back(max_len);
    }

    sort(area.begin(), area.end());

    cout.precision(2);
    cout << fixed << area[K-1];

}