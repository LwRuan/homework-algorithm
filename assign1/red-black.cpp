#include <cstdio>
#include <cstring>

#define N 22
int W, H, sm, sn;
int board[N][N], vis[N][N];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void search(int m, int n){
    for(int d=0;d<4;++d){
        int tm = m + dir[d][0];
        int tn = n + dir[d][1];
        if(tm < 0 || tm >= H) continue;
        if(tn < 0 || tn >= W) continue;
        if(board[tm][tn] || vis[tm][tn]) continue;
        vis[tm][tn] = 1;
        search(tm, tn); 
    }
}

int main(){
    while(scanf("%d %d", &W, &H)!=EOF){
        if(W==0) break;
        getchar();
        memset(board, 0, sizeof(board));
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                char c = getchar();
                if(c=='#') board[i][j] = 1;
                else if(c=='@'){sm=i;sn=j;vis[i][j]=1;}
            }
            getchar();
        }
        search(sm, sn);
        int cnt = 0;
        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                cnt += vis[i][j];
            }
        }
        printf("%d\n", cnt);
    }
}