#include <iostream>
#include <cstdlib>
#include <ctime>

int pseudoaleatorio (int min,int max)
{
    return (rand()%(max-min+1))+min;
}

bool comprobarVec (int v[],int a,int n)
{
    using namespace std;
    for(int i = 0;i < n;i++) 
    {
        //cout<<v[i]<<" =? "<<a<<endl;
        if(v[i] == a) return false;
    }
    return true;
}

void insercionDirecta(int v[],int n)
{
    int x,j;
    for(int i = 1;i < n ;i++)
    {
        x = v[i];
        j = i;
        while(j > 0 && x < v[j-1])
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = x;
    }
}


int main ()
{
    using namespace std;
    int min;
    int max;
    int *vec;
    int j = 0;
    cout<<"Introduce el minimo del rango: ";
    cin>>min;
    cout<<"Introduce el maximo del rango: ";
    cin>>max;
    max++;
    vec = new int[max-min];
    srand(time(0));
    for(int i = 0; i < 10000; i++)
    {
        int a = pseudoaleatorio(min,max-1);
        if(comprobarVec(vec,a,max-min))
        {
            vec[j] = a;
            j++;
        }
    }
    insercionDirecta(vec,max-min);
    cout<<endl;
    for(int i = 0;i < max-min;i++)cout<<vec[i]<<" ";
    return 0;
}