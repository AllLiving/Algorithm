#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std ;
#define INF 9999999

double C[1<<18][21] ;
int main()
{
    int T ; cin >> T ;
    int n ; 
    double data[21][2],dis[21][21] ;
    while ( T-- ){
        cin >> n ;
        for ( int i=0 ; i<n ; i++ )
            cin >> data[i][0] >> data[i][1] ;
        for ( int i=0; i<n ; i++ )
            for ( int j=0 ; j<n ; j++ )
                dis[i][j]=sqrt(pow(data[i][0]-data[j][0],2)
                              +pow(data[i][1]-data[j][1],2));
        
        int Cnt=1<<(n-2) ; // remove start and end
        
        for ( int i=0 ; i<Cnt ; i++ )
            for ( int j=0 ; j<n ; j++ )
                C[i][j]=INF ;
        for ( int i=0 ; i<n ; i++ )
            C[0][i]=dis[i][0] ;
        
        for ( int i=1 ; i<Cnt ; i++ )
            for ( int j=1 ; j<n-1 ; j++ )
                for ( int k=1 ; k<n-1 ; k++ )
                    if ( (1<<(k-1))&i ) // k is in the set   
                    {
						C[i][j]=min(C[i][j],dis[j][k]+C[i-(1<<(k-1))][k]) ;
						printf("C[%d][%d]=%lf\n",i,j,C[i][j]);
                    }    
        
        double ans=INF ;
        for ( int i=1 ; i<n ; i++ ) // 以i为倒数第二个点，最后走到第N个城市 
            ans=min(ans,C[Cnt-1][i]+dis[i][n-1]) ;
        
        cout << fixed << setprecision(2) << ans << endl ;
        
        
    }
    
    
    return 0 ;
}                                 
