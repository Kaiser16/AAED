#include <iostream>
#include <cstdlib>
#include <ctime>

int pseudoaleatorio (int min,int max)
{
    return (rand()%(max-min+1))+min;
}

int main()
{
    using namespace std;
    double vec[6];
    double n = 10000000;
    srand(time(0));
    for(double i = 0; i < n; i++)
    {
        switch (pseudoaleatorio(1,6))
        {
            case 1:vec[0]++;break;
            case 2:vec[1]++;break;
            case 3:vec[2]++;break;
            case 4:vec[3]++;break;
            case 5:vec[4]++;break;
            case 6:vec[5]++;break;
            default: cout<<"|FALLO|"<<endl;break;
        }
    }
    for(int i = 0;i < 6;i++){cout<<"Cara "<<i+1<<": "<<vec[i]/n<<endl;}
    return 0;
}