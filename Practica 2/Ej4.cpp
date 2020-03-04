#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

double pseudoaleatoriodouble (double min,double max)
{
    int interv = (max - min)*1000;
    double num = ((rand()%interv)/(double)1000+min);
    if(num > max) return max;
    else return num;
}

int main()
{
    using namespace std;
    double num;
    double y = 0;
    srand(time(0));
    for(int i = 0; i < 10000000; i++)
    {
        num = pseudoaleatoriodouble(0,1);
        //cout << num <<" -> ";
        y += 4 * sqrt((1-pow(num,2)));
        //cout << y << endl;
    }
    cout <<"Media: "<<y/(double)10000000<<endl;
}