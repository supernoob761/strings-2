#include <stdio.h>
#include <string.h>
struct doodle
{
    char words[100];
    int count;
};

int main(){
    struct doodle words[50];
    char subject[]={" b d g y q h a p h ft rh zk jf h z g m"};
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

    for (int i = 0; i < u - 1; i++) {
        for (int j = i + 1; j < u; j++) {
            if (strcmp(words[i].words, words[j].words) > 0) {
                char temp[100];
                strcpy(temp, words[i].words);
                strcpy(words[i].words, words[j].words);
                strcpy(words[j].words, temp);
            }
        }
    }

    for (int i = 0; i < u; i++) {
        printf("%s\n", words[i].words);
    }
}
