#include <cstdio>
#include <cstring>

int count = 0;
unsigned char left = 0, right = 0, mid = 0;
int board[8];
void queen(int n){
    if(n==8){
        printf("No. %d\n", ++count);
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                if(board[j]==i) printf("1 ");
                else printf("0 ");
            }
            printf("\n");
        }
        return;
    }
    unsigned char tleft = left; left = left >> 1;
    unsigned char tright = right; right = right << 1;
    unsigned char cur = left | mid | right;
    for(int i=0;i<8;++i){
        if((cur >> i) & 1) continue;
        board[n] = i;
        left |= 1 << i;
        right |= 1 << i;
        mid |= 1 << i;
        queen(n+1);
        left ^= 1 << i;
        right ^= 1 << i;
        mid ^= 1 << i;
    }
    left = tleft;
    right = tright;
}

int main(){
    memset(board, 0xFF, sizeof(board));
    queen(0);
}