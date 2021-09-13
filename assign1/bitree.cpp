#include <cstdio>
#include <cstring>

#define N 102
int left_child[N], right_child[N], parent[N];

int main(){
    int t; scanf("%d", &t);
    for(int tt=0;tt<t;++tt){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;++i){
            int idx, l, r;
            scanf("%d %d %d", &idx, &l, &r);
            left_child[idx] = l;
            parent[l] = idx;
            right_child[idx] = r;
            parent[r] = idx;
        }
        for(int i=0;i<m;++i){
            int type, x, y;
            scanf("%d", &type);
            if(type==1){
                scanf("%d %d", &x, &y);
                int px = parent[x];
                int py = parent[y];
                if(px==py){
                    int tmp = left_child[px];
                    left_child[px] = right_child[py];
                    right_child[py] = tmp;
                }
                else{
                    parent[x] = py;
                    parent[y] = px;
                    if(left_child[px]==x){
                        left_child[px] = y;
                        if(left_child[py]==y) left_child[py] = x;
                        else right_child[py] = x;
                    } 
                    else{
                        right_child[px] = y;
                        if(left_child[py]==y) left_child[py] = x;
                        else right_child[py] = x;
                    }
                }
            }
            else if(type==2){
                scanf("%d", &x);
                int c = x;
                while(left_child[c]!=-1){
                    c = left_child[c];
                }
                printf("%d\n", c);
            }
        }
    }
}
