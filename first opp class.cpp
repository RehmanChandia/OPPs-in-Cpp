#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string b;
    for(int i = 0; i<n; i++)
    {
        cin>>b;
        if(b.length() > 10)
        {
            cout<<b[0]<<b.length()-2<<b[b.length()-1]<<endl;
        }
        else
        {
            cout<<b<<endl;
        }
    }
    return 0;
}
