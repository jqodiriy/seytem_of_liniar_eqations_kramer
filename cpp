#include <iostream>
using namespace std;

double a[100][101];
int n;
double dt(int x){
    double b[n][n];
    for(int i=0; i < n; i ++){
        for(int j=0; j < n; j ++){
            if(x == j)
                b[i][j] = a[i][n];
            else
                b[i][j] = a[i][j];
        }
    }
    double s = 1;
    for(int k=0; k < n; k ++){
        if(b[k][k] == 0){
            bool ok = 0;
            for(int i = k+1; i < n; i ++){
                if(b[i][k]!=0){
                    ok = 1;
                    s = -s;
                    for(int j = k; j < n; j ++){
                        swap(b[i][j] , b[k][j]);
                    }
                    break;
                }
            }
            if(ok == 0) return 0;
        }
        for(  int i = k + 1; i < n; i ++){
            for(int j = k + 1; j < n; j ++){
                b[i][j] -= b[k][j] * b[i][k] / b[k][k];
            }
        }
    }
    for(int i=0; i < n; i ++){
        s *= b[i][i];
    }
    return s;
}

int main(){

    cin >> n;
    for(int i=0; i < n; i ++){
        for(int j=0; j <= n; j ++){
            cin >> a[i][j];
        }
    }
    double x[n] , d[n+1];
    for(int i=0; i <= n; i ++){
        d[i] = dt(i);
    }
    if(d[n] == 0){
        bool ok = 1;
        for(int i=0 ;i < n; i ++){
            if(d[i]!=0) ok = 0;
        }
        if(ok == 0)
            cout << "tenglamalar sistemasi yechimga ega emas !!!";
        else
            cout << "tenglamalar sistemasi cheksiz ko`p yechimga ega !!!";
        return 0;
    }
    for(int i=0; i < n; i ++){
        x[i] = d[i] / d[n];
    }
    cout << "\n\n";
    for(int i=0; i < n; i ++){
        cout << "x" << i+1 << " = " << x[i] << endl;
    }
    cout << "\n\n";
    cout <<" --------- Tekshirish ---------\n";
    for(int i=0; i < n; i ++){
        for(int j=0; j < n; j ++){
            
            if(a[i][j] >= 0 && j > 0)
                cout << " + " << a[i][j];
            else if(j > 0)
                cout << " - " << -a[i][j];
            else
                cout << a[i][j];
            
            cout  << " * ";
            
            
            if(x[j] < 0){
                cout << '(' << x[j] << ')';
            }
            else
                cout << x[j];
        }
        cout << " = " << a[i][n] << endl;
    }
    cout << " -----------------------------\n\n\n";
}
/*
just for chek
4
1 3 5 -9 -29
2 7 0 -2 -15
3 1 4 8 39
11 0 9 5 38
 */
