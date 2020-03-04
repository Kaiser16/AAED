#include <iostream>

using namespace std;

void intercambioDirecto(int v[],int n)
{
    int aux;
    for(int i = 0; i < n; i++)
    {
        for(int j = n-1; j > i; j--)
        {
            if(v[j] < v[j-1])
            {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
}

void seleccionDirecta(int v[],int n)
{
    int p,m,aux;
    for(int i = 0;i < n;i++)
    {
        p = i;
        m = v[i];
        for(int j = i+1;j < n;j++)
        {
            if(v[j] < m)
            {
                p = j;
                m = v[j];
            }
        }
        v[p] = v[i];
        v[i] = m;
    }
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

int main()
{
    int v[] = {5,1,8,9,1,23,34,5};
    int n = 8;
    for(int aut:v) cout<<aut<<" ";
    cout<<endl;
    //intercambioDirecto(v,n);
    //seleccionDirecta(v,n);
    insercionDirecta(v,n);
    for(int aut:v) cout<<aut<<" ";
    cout<<endl;
    return 0;
}