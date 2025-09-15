#include <stdio.h>
#include <string.h>

struct doodle {
    char words[100];
    int count;
    int length;
    int positions[50];
};

int main() {
    struct doodle words[50];
    char subject[] = {"the black cat sleeps the dog plays"};
    char *split = strtok(subject, " ");
    int u = 0;
    int pos = 0;

    while (split != NULL) {
        int j = 0;

        for (int i = 0; i < u; i++) {
            if (strcmp(words[i].words, split) == 0) {
                words[i].count++;
                words[i].positions[words[i].count - 1] = pos;
                j = 1;
                break;
            }
        }

        if (!j) {
            strcpy(words[u].words, split);
            words[u].count = 1;
            words[u].length = strlen(split);
            words[u].positions[0] = pos;
            u++;
        }

        pos++;
        split = strtok(NULL, " ");
    }
    int total=0;
    for(int i=0;i<u;i++){
    total+=words[i].length;
    }

    float avr=(float) total/(u+1);

    printf("total: %d,unique: %d\naverage: %.2f",total,u+1,avr);
    return 0;
}