#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid_a;

    pid_a = fork();

    if (pid_a < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid_a == 0) {
        pid_t pid_b;

        pid_b = fork();

        if (pid_b < 0) {
            perror("Fork failed\n");
            exit(1);
        }

        if (pid_b == 0) {
            printf("          Sou P_C com PID %d, filho de PID %d\n", getpid(), getppid());
            printf("          Eu P_C executei: ps\n");
            
            system("ps");
        } else {
            printf("     Sou P_B com PID %d, filho de PID %d\n", getpid(), getppid());
            printf("     Eu P_B criei P_C!\n");
            
            wait(NULL);
            
            printf("     Eu P_B aguardei P_C terminar!\n");
            printf("     Eu P_B executei: ps\n");
            
            system("ps");
        }
    } else {
        printf("Sou P_A com PID %d, filho de PID %d\n", getpid(), getppid());
        printf("Eu P_A criei P_B!\n");
        wait(NULL);

        printf("Eu P_A aguardei P_B terminar!\n");
        printf("Eu P_A executei: ps\n");

        system("ps");
    }

    return 0;
}