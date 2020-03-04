#include <iostream>
#include <cstdlib>
#include <ctime>

double pseudoaleatoriodouble (double min,double max)
{
    int interv = (max - min + 1)*1000;
    double num = ((rand()%interv)/(double)1000+min);
    if(num > max) return max;
    else return num;
}

int main()
{
    using namespace std;
    srand(time(0));
    for(int i  = 0;i < 10000;i++){cout<<pseudoaleatoriodouble(0,10)<<endl;}
    return 0;
}