#include <stdio.h>
#include <string.h>
int main(){
char subject[]={"the black cat sleeps. the dog plays!"};
char result[100];
char illegal[]="!.?,";
int j=0;
for(int i =0;subject[i]!='\0';i++){
if(strchr(illegal,subject[i])!=NULL){
   continue;}

   result[j]=subject[i];
   j++;
}
result[j] = '\0';
printf("%s",result);

}