#include <iostream>
using namespace std;
int fun(int a,int b,int x,int y)
{
    if(a==x && b==y)
        return 1;
    if(a>x||b>y)
        return 0;
    return fun(a+b,b,x,y) | fun(a,a+b,x,y);
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        cout<<fun(a,b,x,y)<<endl;
    }
    return 0;
}
