#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sortlib.h>

int main() {
    pid_t pid;

    pid = fork();
    int list[] = { 5, 2, 7, 3, 9, 1, 4, 6, 8, 0 };

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }


}