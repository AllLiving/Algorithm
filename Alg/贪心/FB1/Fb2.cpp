#include <iostream>

using namespace std;

#define M 1000000007

struct Matrix{
    long long v[2][2];
};

Matrix matrixMul(Matrix a, Matrix b) {
    Matrix temp;
    for (int i = 0; i != 2; i++) {
        for (int j = 0; j != 2; j++) {
            temp.v[i][j] = 0;
            for (int k = 0; k != 2; k++) {
                temp.v[i][j] += a.v[i][k] * b.v[k][j];
                temp.v[i][j] %= M;
            }
        }
    }
    return temp;
}

Matrix power(Matrix a, Matrix b, long long n) {
    while (n) {
        if (n & 1) {
            b = matrixMul(b, a);
        }
        n >>= 1;
        a = matrixMul(a, a);
    }
    return b;
}

int main(int argc, char* argv[]) 
{
    Matrix a = {1, 1, 1, 0}, b = {1, 0, 0, 1};
    long long n;
    while (cin >> n) {
        if (n == 0)
            cout << 0 << endl;
        else {
            Matrix result = power(a, b, n - 1);
            cout << result.v[0][0] << endl;
        }
    }

    return 0;
}
