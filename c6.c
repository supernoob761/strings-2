#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

    char query[100];
    printf("search: ");
    scanf("%s", query);
    printf("loading...\n");
    sleep(10);

    int found = 0;
    for (int i = 0; i < u; i++) {
        if (strcmp(words[i].words, query) == 0) {
            printf("%s -> length: %d, occurrences: %d, positions: [",words[i].words, words[i].length, words[i].count);
            for (int j = 0; j < words[i].count; j++) {
                printf("%d", words[i].positions[j]);
                if (j < words[i].count - 1) printf(", ");
            }
            printf("]\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Word '%s' not found.\n", query);
    }

    return 0;
}

