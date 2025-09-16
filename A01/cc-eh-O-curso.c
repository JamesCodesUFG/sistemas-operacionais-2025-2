#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

#define BUFFER_SIZE  8
#define READ_END      0
#define WRITE_END     1

int flag = 0;

void comunicar_filhos(int sig) {
    flag = 1;
}

int main(void) {
    pid_t pid;

    int fd_a[2];
    int fd_b[2];
    int fd_c[2];

    char read_msg_a[BUFFER_SIZE];
    char read_msg_b[BUFFER_SIZE];
    char read_msg_c[BUFFER_SIZE];

    if(pipe(fd_a) == -1) {
        fprintf(stderr, "Pipe faliled");
        return 1;
    }

    if(pipe(fd_b) == -1) {
        fprintf(stderr, "Pipe faliled");
        return 1;
    }

    if(pipe(fd_c) == -1) {
        fprintf(stderr, "Pipe faliled");
        return 1;
    }

    pid = fork();

    if(pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if(pid == 0) {
        signal(SIGINT, SIG_IGN);

        close(fd_a[READ_END]);
        close(fd_b[READ_END]);
        close(fd_c[READ_END]);
        close(fd_b[WRITE_END]);
        close(fd_c[WRITE_END]);

        char write_msg[BUFFER_SIZE];

        snprintf(write_msg, BUFFER_SIZE, "%d", getpid());

        write(fd_a[WRITE_END], write_msg, strlen(write_msg)+1);

        close(fd_a[WRITE_END]);
    }
    else {
        pid = fork();

        if(pid < 0) {
            fprintf(stderr, "Fork failed");
            return 1;
        }

        if(pid == 0) {
            signal(SIGINT, SIG_IGN);

            close(fd_a[READ_END]);
            close(fd_b[READ_END]);
            close(fd_c[READ_END]);
            close(fd_a[WRITE_END]);
            close(fd_c[WRITE_END]);

            char write_msg[BUFFER_SIZE];

            snprintf(write_msg, BUFFER_SIZE, "%d", getpid());

            write(fd_b[WRITE_END], write_msg, strlen(write_msg)+1);

            close(fd_b[WRITE_END]);
        }
        else {
            pid = fork();

            if(pid < 0) {
                fprintf(stderr, "Fork failed");
                return 1;
            }

            if(pid == 0) {
                signal(SIGINT, SIG_IGN);

                close(fd_a[READ_END]);
                close(fd_b[READ_END]);
                close(fd_c[READ_END]);
                close(fd_a[WRITE_END]);
                close(fd_b[WRITE_END]);

                char write_msg[BUFFER_SIZE];

                snprintf(write_msg, BUFFER_SIZE, "%d", getpid());

                write(fd_c[WRITE_END], write_msg, strlen(write_msg)+1);

                close(fd_c[WRITE_END]);
            }
            else {
                if(signal(SIGINT, comunicar_filhos) == SIG_ERR)
                    fprintf(stderr, "Unable to pick up signal");

                while(1) {
                    if(flag == 1) {
                        printf("Parent PID: %d\n", getpid());

                        close(fd_a[WRITE_END]);
                        close(fd_b[WRITE_END]);
                        close(fd_c[WRITE_END]);

                        read(fd_a[READ_END], read_msg_a, BUFFER_SIZE);
                        read(fd_b[READ_END], read_msg_b, BUFFER_SIZE);
                        read(fd_c[READ_END], read_msg_c, BUFFER_SIZE);

                        printf("Child A PID: %s\n", read_msg_a);
                        printf("Child B PID: %s\n", read_msg_b);
                        printf("Child C PID: %s\n", read_msg_c);

                        close(fd_a[READ_END]);
                        close(fd_b[READ_END]);
                        close(fd_c[READ_END]);

                        return 0;
                    } else {
                        sleep(1);
                    }
                }
            }
        }
    }

    return 0;
}