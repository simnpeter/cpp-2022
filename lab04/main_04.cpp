#include <iostream>
#include <iomanip>

#include "PointSet.h"

using namespace std;
int main() {/*
    //Definíció - üres dinamikus tömb
    vector<int> v;
//Feltöltés: új elem hozzáadása: push_back VAGY emplace_back
    for( int i=0; i<10; ++i ){
        v.push_back( i * 10 );
    }
//Kiíratás
    for(int i=0; i<v.size(); ++i ){
        cout<<v[ i ]<<" ";
    }
    cout<<endl;*/
    int n = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        n = n << 1;
    }

    PointSet pset1(10);
    cout<<"#points: " <<Point::getCounter()<<endl;
    PointSet pset2(20);
    cout<<"#points: " <<Point::getCounter()<<endl;
    return 0;
}