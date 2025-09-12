#include <stdio.h>
#include <string.h>
struct doodle
{
    char words[100];
    int count;
};



int main(){
    struct doodle words[50];
char subject[]={"the black cat sleeps the dog plays"};
char *split=strtok(subject," ");
int u=0;

while (split!=NULL)
{
    int j=0;
    for(int i=0;i<u;i++){
        if(strcmp(words[i].words,split)==0){
    words[i].count++;
    j = 1;
    break;
        }
    }
if(!j){
    strcpy(words[u].words,split);
    words[u].count=1;
    u++;
}
split=strtok(NULL," ");
}
    for (int i = 0; i < u; i++) {
        int len=strlen(words[i].words);
        printf("%s: %d len: %d index : ", words[i].words, words[i].count,len);
        for(int k=0;k<u;k++){
        if(strstr(subject,words[i].words)!=NULL){
            printf("%d,",k);}
    }
     printf("\n");
}
}