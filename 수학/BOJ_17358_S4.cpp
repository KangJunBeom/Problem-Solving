/*
    백준 복불복으로 지구 멸망
    수학/조합론
    체감 난이도 : 책정 난이도보다 쉬웠음
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    
    long long ans = 1;
    
    while(N-1>0){
        ans *= (N-1);
        ans %= 1000000007LL;
        N -= 2;
    }

    cout << ans;

}