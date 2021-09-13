#include <cstdio>
#include <algorithm>

#define N 10010

int L, M;
int tree[N];

int main(){
    std::fill(tree, tree+N, 1);
    scanf("%d %d", &L, &M);
    int b, e;
    for(int i=0;i<M;++i){
        scanf("%d %d", &b, &e);
        for(int j=b;j<=e;++j){
            tree[j] = 0;
        }
    }
    int count = 0;
    for(int i=0;i<=L;++i){
        count += tree[i];
    }
    printf("%d", count);
    return 0;
}