#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
char hello[]={"JUESGJEHLUIFHF"};
for(int i=0;i<15;i++){
hello[i]=tolower(hello[i]);
}
printf("%s",hello);

}