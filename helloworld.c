#include <stdio.h>
#include <stdlib.h>

#define FILENAME "protected/data"

int main(void) {
    FILE* f;

    if ((f = fopen(FILENAME, "wb")) == NULL) {
        perror("first create failed");
        exit(1);
    }
    if (fwrite("data", 1, 4, f) != 4) {
        perror("first write failed");
        fclose(f);
        exit(1);
    }
    fclose(f);

    rename(FILENAME, FILENAME ".bak");

    if ((f = fopen(FILENAME, "wb")) == NULL) {
        perror("second create failed");
        exit(1);
    }
    if (fwrite("data", 1, 4, f) != 4) {
        perror("second write failed");
        fclose(f);
        exit(1);
    }

    fclose(f);

    return 0;
}
