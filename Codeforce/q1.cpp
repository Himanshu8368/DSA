// https://codeforces.com/problemset/problem/1921/A
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int area=0;
    while(t-- > 0){
        int a,b,c,d,e,f,g,h;
        cin>>a>>b>>c>>d>>e>>f>>g>>h;
        if((b-d!=0 && a-c)/(b-d)==0){
            area = (a-c)*(a-c)+(b-d)*(b-d);
        }
        if((c-e)/(d-f)==0){
            area = (c-e)*(c-e)+(d-f)*(d-f);
        }
        if((e-g)/(f-h)==0){
            area = (e-g)*(e-g)+(f-h)*(f-h);
        }
        area = (g-a)*(g-a)+(h-b)*(h-b);
    }
    return area;
}