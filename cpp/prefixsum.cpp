#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 1e3+10;
int ar[N][N];
long long pf[N][N];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for(int j = 1; j<=n; j++){
            cin >> ar[i][j];
            pf[i][j]=a[i][j] + pf[i-1][j] + pf[i][j-1] -pf[i-1][j-1];
        }
    }

    for(int i=1; i <=p; i++){
        for(int j=1; j <=q; j++){
            
        }
    }


    int q;
    cin >> q;
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        long long sum = 0;
        for(int i=a; i<=c; i++){
            for(int j=b; j<=d; j++){
                sum = sum + ar[i][j];
            }
        }
        cout << sum << endl;
    }
    

    return 0;
}