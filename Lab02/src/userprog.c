// userprog.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_ARGS 16

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    pid_t pid;
    int status;

    while (1) {
        printf("userprog> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int i = 0;
        char *token = strtok(input, " ");

        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid < 0) {
            perror("fork falhou");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            execlp(args[0], args[0], args[1], args[2], args[3], args[4], (char *)NULL);

            perror("execlp falhou");
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}