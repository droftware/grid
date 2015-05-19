#include <iostream>
#include <algorithm>
#include "grid.h"

using namespace std;

main()
{
    cout<<"Hello World ,again"<<endl;
    grid<int> myGrid(5,5);
    myGrid.getAt(2,3) = 3;
    cout<<"Output "<<myGrid.getAt(2,3)<<endl;
    cout<<"bye Bye"<<endl;
    fill(myGrid.begin(),myGrid.end(),10);
    cout<<"Output "<<myGrid.getAt(2,3)<<endl;
    myGrid.getAt(0,0) = 10;
    myGrid.getAt(0,1) = 9;
    myGrid.getAt(0,2) = 8;
    myGrid.getAt(0,3) = 7;
    sort(myGrid.row_begin(0),myGrid.row_end(0));
    cout<<"Output "<<myGrid.getAt(0,0)<<" "<<myGrid.getAt(0,1)<<" ";
    cout<<myGrid.getAt(0,2)<<" "<<myGrid.getAt(0,3)<<endl;
    cout<<"Testing operator [] "<<endl;
    myGrid[4][3]=78;
    cout<<"Value at 4 , 3 is = "<<myGrid[4][3]<<endl;
    myGrid[4][3]=105;
    cout<<"Value at 4 , 3 is = "<<myGrid[4][3]<<endl;

    cout<<"Checking const version"<<endl;
    const grid<int> cg(10,10);
    //cg[5][7] = 45;
    cout<<"Value of cg at 5,7 is = "<<cg[5][7]<<endl;

    cout<<"Testing relational operators "<<endl;
    cout<<(cg < myGrid)<<endl;

    grid<char> a(7,8);
    grid<char> b(9,6);
    
    cout<<boolalpha;
    cout<<" a operator b"<<endl;
    cout<<" b is greater than a"<<endl;
    cout<<"<"<<(a<b)<<endl;
    cout<<">"<<(a>b)<<endl;
    cout<<"=="<<(a==b)<<endl;
    cout<<"<="<<(a<=b)<<endl;
    cout<<">="<<(a>=b)<<endl;
    cout<<"!="<<(a!=b)<<endl;
}