/*
    백준 로마 카톨릭 미사
    시뮬레이션/구현
    체감 난이도 : 적당
*/

#include <bits/stdc++.h>
using namespace std;

int R, C;
char church[51][51];
// i = 3 까지 하면 악수할 때 중복 없이 횟수 계산 가능
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, 1, 0, -1};
int tary, tarx;
int ard_max = 0;
int ans = 0;

//상근이가 앉을 자리를 계산하기 위한 함수
int check(int sy, int sx){
    
    int check = 0;
    
    for(int i = 0; i<8; ++i){
        int goy = sy+dy[i];
        int gox = sx+dx[i];
        if(goy < 0 || gox < 0 || goy >= R || gox >= C) continue;
        if(church[goy][gox] == 'o') check++;
    }

    return check;
}

// 악수 횟수를 계산하기 위한 함수
void handshake(int sy, int sx){

    for(int i = 0; i<4; ++i){
        int goy = sy+dy[i];
        int gox = sx+dx[i];
        if(goy < 0 || goy>= R || gox < 0 || gox >= C) continue;
        if(church[goy][gox] == 'o') ans++;
    }

}

int main(){

    int sangx = -1, sangy = -1;
    cin >> R >> C;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j<C; ++j){
            cin >> church[i][j];
        }
    }

    // 상근이의 자리 선정
    for(int i = 0; i < R; ++i){
        for(int j = 0; j<C; ++j){
            if(church[i][j] == '.'){
                if(ard_max < check(i,j)){
                    ard_max = check(i,j);
                    sangx = j;
                    sangy = i;
                }
            }
        }
    }

    // 상근이가 앉을 수 있는 경우
    if(sangx != -1){
        church[sangy][sangx] = 'o';
    }

    // 악수 횟수 실제 계산
    for(int i = 0; i<R; ++i){
        for(int j = 0; j<C; ++j){
            if(church[i][j] == 'o'){
                handshake(i,j);
            }
        }
    }

    cout << ans;
    return 0;

}