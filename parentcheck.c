#include<stdio.h>
#define Maxline 1000
int main(){
    int i,j=0,c,p[Maxline],wrong=0;
    p[0]=0;
    char s[Maxline];
    for(i=0;i<Maxline&&(s[i]=getchar())&&s[i]!=EOF;i++){
        if(j==0) c=0;
        else c=p[j-1];
        if(s[i]=='\'')
            if(s[c]!='\''||c==0){
                p[j]=i;
                j++;
            }
            else j--;
        else if(s[i]=='\"')
            if(s[c]!='\"'||c==0){
                p[j]=i;
                j++;
            }
            else j--;
        else if(s[i]==40){ //40='('
            p[j]=i;
            j++;
        }
        else if(s[i]==41) //41=')'
            if(s[c]!=40) {wrong=1;break;}
            else j--;

        else if(s[i]==91){ //[
            p[j]=i;
            j++;
        }
        else if(s[i]==93) //]
            if(s[c]!=91) {wrong=1;break;}
            else j--;

        else if(s[i]==123){ //{
            p[j]=i;
            j++;
        }
        else if(s[i]==125)  //}
            if(s[c]!=123) {wrong=1;break;}
            else j--;

        else;
    }
    if(j!=0||wrong==1)
        printf("%c <-- wrong parenthesis order at here\n",s[i]);
}
