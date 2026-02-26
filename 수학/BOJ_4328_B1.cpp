/*
    BOJ 4328 기초 나머지 계산
    수학/큰 수 연산
    체감 난이도 : B1 이상
*/

#include <bits/stdc++.h>
using namespace std;

// 문자열로 이뤄진 b진수를 10진수로 변환하는 함수
long long bto10(int b, string m){
    
    reverse(m.begin(), m.end());
    int gop = 1;
    long long num = 0;
    for(char c : m){
        int tmp = c - '0';
        num += tmp*gop;
        gop *= b;
    }

    return num;
}

// 10진수를 b진수 문자열로 변환하는 함수
string _10tos(int b, long long p){

    if(p==0) return "0";

    string s = "";
    long long tmp = p;
    while(tmp>0){
        s += tmp%b + '0';
        tmp /= b;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){

    int b;
    string p, m;
    
    while(cin >> b && b!=0){
        cin >> p >> m;
        long long m_val = bto10(b,m);
        long long remainder = 0;
        // b진수의 숫자를 나누기 할 수 있는 범위 안으로 조절하기 위한 방식
        for (char c : p) {
            int digit = c - '0';
            remainder = (remainder * b + digit) % m_val;
        }

        cout << _10tos(b, remainder) << "\n";
    }

}