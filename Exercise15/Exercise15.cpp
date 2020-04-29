#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

bool substr( string a, int n, string s, int k, int p ) {
    for ( int i = 0 ; i <= k - 1 ; i++ ) {
        if ( !( ( p + i < n ) && ( a[p+i] == s[i] ) ) ) return false;
    }
    return true;
}

bool exist( string a, string s ) {
    for ( int r = 0 ; r < a.size( ) ; r++ ) {
        if ( substr( a, a.size( ), s, s.size( ), r ) ) return true;
    }
    return false ;
}

bool exist( string a, string s, int i ) {
    for ( int r = 0 ; r < i ; r++ ) {
        if ( substr( a, a.size( ), s, s.size( ), r ) ) return true;
    }
    return false ;
}

int main()
{
    string a = "PepaZdepa";
    string s = "Zde";
    int n = a.size();
    int k = s.size();
    bool found = false;
    for ( int i = 0 ; i <= n - k ; i++ ) {
        assert( found == exist( a, s, i ) ); 
        bool p = true;
        for ( int j = 0 ; j <= k - 1 ; j++ ) {
            assert( p == substr( a, n, s, j, i ) );
            if ( a[i+j] != s[j] ) p = false;
            assert( p == substr( a, n, s, j + 1, i ) );
        }
        if ( p ) found = true;
        assert( found == exist( a, s, i + 1 ) ); 
    }
    assert( ( found == exist( a, s ) ) || ( ( n == 0 ) && ( k == 0 ) ) );
    return 0;
}
