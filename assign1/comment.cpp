#include <cstdio>
#include <cstring>

int main(){
    char c;
    while((c=getchar())!=EOF){
        if(c=='\'' || c=='\"'){
            putchar(c);
            char s;
            while((s=getchar())!=EOF){
                if(s=='\\'){
                    putchar(s);
                    putchar(getchar());
                }
                else if(s==c){
                    putchar(s);
                    break;
                }
                else putchar(s);
            }
        }
        else if(c=='/'){
            char s = getchar();
            if(s=='*'){
                char a, b;
                a = getchar();
                b = getchar();
                while(a!='*'||b!='/'){
                    a = b;
                    b = getchar();
                }
            }
            else{
                putchar(c);
                putchar(s);
            }
        }
        else putchar(c);
    }
}