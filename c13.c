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
    int a = 0, b = 0, c = 0;
    for (int i = 1; i < u; i++) {
        if (words[i].length > words[a].length) a = i;
        if (words[i].length < words[b].length) b = i;
        if (words[i].count > words[c].count) c = i;
    }
    printf("Longest: %s (%d)\n", words[a].words, words[a].length);
    printf("Shortest: %s (%d)\n", words[b].words, words[b].length);
    printf("Most Frequent: %s (%d)\n", words[c].words, words[c].count);

    return 0;
}
