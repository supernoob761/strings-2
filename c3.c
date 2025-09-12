#include <stdio.h>
#include <string.h>
int main(){
char subject[]={"the black cat sleeps the dog plays"};
char *count=strtok(subject," ");
int j=0;
while (count!=NULL)
{
    j++;
    count=strtok(NULL," ");
}
printf("%d",j);
}