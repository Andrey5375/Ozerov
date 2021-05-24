#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a,b,m, s ,l=0,max=0;
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        int i2 = i;
        s = 0;
        while (i2 != 0) {
        s = s + i2 % 2;
        i2 = i2 / 2;
        }
        if ((s == 5) && (i % 2 == 0) && (i % 10 != 0)) {
            l++;
            if (l == 1) {
                max = i;
            }
            if (i > max) {
                max = i;
            }
        }
    }
    cout << l << " " << max << endl;
}


