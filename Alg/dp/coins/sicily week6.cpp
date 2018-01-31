#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std ;

int main()
{
    int wt[]={0,3,5,2,6,11,8} ;
    double v[]={0,0.01,0.05,0.1,0.25,0.5,1} ;
    
    int W,A[7];
    double M[7][10005] ;
    while ( cin >> W ){
        for ( int i=1 ; i<=6 ; i++ )
            cin >> A[i] ;
        memset(M, 0, sizeof(M));
        for ( int i=1 ; i<=6 ; i++ )
            for ( int w=1 ; w<=W ; w++ ){
                M[i][w] = 0 ; 
                int n=min(A[i],w/wt[i]) ; // ����i��Ʒ������ȡ���ٸ� 
                for ( int k=0 ; k<=n ; k++ )
                    M[i][w]=max(M[i][w],k*v[i]+M[i-1][w-k*wt[i]]) ; // ȡk��i��Ʒ���루k-1����i��Ʒ�ıȽ� 
            }
        cout << "$" << fixed << setprecision(2) << M[6][W] << endl ;
    }
    
    return 0 ;
}                                 
