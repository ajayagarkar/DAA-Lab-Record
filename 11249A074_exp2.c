#include<stdio.h>
void hanoi(int n,char s,char d,char a){
    if(n==1){
        printf("%c->%c\n",s,d);
        return;
    }
    hanoi(n-1,s,a,d);
    printf("%c->%c\n",s,d);
    hanoi(n-1,a,d,s);
}
int main(){
    int n;
    scanf("%d",&n);
    hanoi(n,'A','C','B');
}
