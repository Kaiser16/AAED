#include<iostream>
#include<algorithm>
#include<cstring>

void printvec(int *v,int *vf)
{
    int i = 0;
    while((v+i)!=vf) {std::cout<<*(v+i)<<" ";++i;}
    std::cout<<std::endl;
}

int main()
{
    int n=5;
    int v[n];
    int v_aux[n];
    for(int i = 0;i <= n;++i)
    {
        v[i] = i;
        memcpy(v_aux,v,sizeof(v));
        do
        {
            printvec(v_aux,v_aux+i);
        }
        while(std::next_permutation(v_aux,v_aux+i));
    }
    return 0;
}