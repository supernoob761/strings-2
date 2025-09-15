#include <stdio.h>
#include <string.h>
struct doodle
{
    char words[100];
    int count;
};



int main(){
    struct doodle words[50];
char subject[]={"the sleeps black cat cat sleeps the dog plays sleeps"};
char *split=strtok(subject," ");
int u=0;
int total=0;

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
total++;
}
    for (int i = 0; i < u; i++) {
        for(int k=i+1;k<u;k++)
        if(words[i].count>words[k].count){
        int temp=words[i].count;
        words[i].count=words[k].count;
        words[k].count=temp;
        }

        
        
}
printf("total:%d\nunique:%d",total,u);
}