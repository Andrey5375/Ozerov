#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int a, b,d,f=0,q;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if ((i % 2) == 0)
        {
            d = 1;
            for (int j = 2; j <=round(sqrtf(i)); j++)
            {
                if ((i % j) == 0)
                {
                    if ((j % 2) == 0)
                    {
                        d++;
                    }
                    int temp= i / j;
                    if (((temp % 2) == 0) && (j != temp))
                    {
                        d++;
                    }
                    if (d > 3) break;
                }
            }
            if (d == 3)
            {
                f = 1;
                cout << i << endl;
            }
        }
    }
    if (f == 0)
        cout << 0;
}






