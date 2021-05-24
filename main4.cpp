#include <iostream>
#include <stdio.h>
#include <algorithm>


using namespace std;
int x[50];
void chislo_sum(int a,int b,int c){
    int i;
    if(!c){
        printf("%d",x[0]);
        for(i=1;i<a;i++){
            printf(" %d",x[i]);
        }
        printf("\n");
    }
    else{
        for(i=1;i<=min(b,c);i++){
            x[a]=i;
            chislo_sum(a+1,i,c-i);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    chislo_sum(0,n,n);
    return 0;

}
