#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

inline int pseudoaleatorio (int min,int max){return (rand()%(max-min+1))+min;}

bool compararVec(int v1[],int v2[],int n)
{
    for(int i = 0; i < n;i++) if(v1[i] != v2[i]) return false;
    return true;
}

int main()
{
    int v1[] = {0,1,2,3,4,5};
    int v2[] = {0,1,2,3,4,5};
    int correctos = 0;
    const size_t n = sizeof v1 / sizeof *v1;
    srand(time(0));
    for(int i = 0;i < 10000000;i++)
    {
        random_shuffle(v1,v1+n);
        if(compararVec(v1,v2,n)) correctos++;
    }
    cout<<"Numero de permutaciones ordenadas: "<<correctos<<endl;
}