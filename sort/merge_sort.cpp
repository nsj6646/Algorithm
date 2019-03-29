/**
 * 
 * File: merge_sort.cpp
 * Updated: 2019.03.29
 * Author: nsj6646@naver.com
 * 
 **/
#include <cstdio>

#define MAX_N   100

static unsigned int seed = 54321;
static unsigned int pseudo_rand(int max) {
	seed = ((unsigned long long)seed * 1103515245 + 12345) & 0x7FFFFFFF;
	return seed % max;
}

struct Data
{
    int id,value;
};
Data a[MAX_N];
int n,m;
bool cmp(const Data &u, const Data &v){
    if(u.value==v.value){
        return u.id<v.id;
    }
    return u.value<v.value;
}

Data sorted[MAX_N];
void merge_sort(int start, int end){
    if(start==end) return;

    int mid=(start+end)>>1;
    merge_sort(start,mid);
    merge_sort(mid+1,end);
    
    ///////////////////////////////////////
    int i=start;
    int j=mid+1;
    int k=0;
    
    while(k<=end){
        if(i<=mid&&(j>end||cmp(a[i],a[j]))){
            sorted[k++]=a[i++];
        }
        else{
            sorted[k++]=a[j++];
        }
    }
    for(int i=start;i<=end;++i){
        a[i]=sorted[i-start];
    }
}


int main(){
    n=MAX_N;
    for(int i=0;i<n;++i){
        a[i].id=i;
        a[i].value=pseudo_rand(MAX_N);
    }
    //before
    for(int i=0;i<n;++i){
        printf("%d ",a[i].value);
    }
    printf("\n");

    merge_sort(0,n-1);
    
    //after
    for(int i=0;i<n;++i){
        printf("%d ",a[i].value);
    }
    printf("\n");
    
    //id  
    for(int i=0;i<n;++i){
        printf("%d ",a[i].id);
    }
    printf("\n");
}
