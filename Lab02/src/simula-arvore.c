#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid_logind;

    pid_logind = fork();

    if (pid_logind < 0) {
        perror("Fork failed");
        exit(1);
    }
    
    if (pid_logind == 0) {
        logind_node();
    } else {
        printf("Nó raiz -> pid = %d.\n", getpid());

        pid_t pid_python;

        pid_python = fork();

        if (pid_python < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid_python == 0) {
            python_node();
        } else {
            pid_t pid_sshd;

            pid_sshd = fork();

            if (pid_sshd < 0) {
                perror("Fork failed");
                exit(1);
            }

            if (pid_sshd == 0) {
                sshd_node();
            } else {
                wait(NULL);
                wait(NULL);
                wait(NULL);
            }
        }
    }

    return 0;
}

int logind_node() {
    printf("Nó logind -> pid = %d.\n", getpid());

    pid_t pid_bash;

    pid_bash = fork();

    if (pid_bash < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid_bash == 0) {
        bash_node();
    } else {
        wait(NULL);
    }

    return 0;
}

int bash_node() {
    printf("Nó bash -> pid = %d.\n", getpid());

    pid_t pid_vim;

    if (pid_vim < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid_vim == 0) {
        vim_node();
    } else {
        pid_t pid_ps;

        pid_ps = fork();

        if (pid_ps < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid_ps == 0) {
            ps_node();
        } else {
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}

int ps_node() {
    printf("Nó ps -> pid = %d.\n", getpid());
    return 0;
}

int vim_node() {
    printf("Nó vim -> pid = %d.\n", getpid());
    return 0;
}

int python_node() {
    printf("Nó python -> pid = %d.\n", getpid());
    return 0;
}

int sshd_node() {
    printf("Nó sshd -> pid = %d.\n", getpid());

    pid_t pid_sshd_child;

    pid_sshd_child = fork();

    if (pid_sshd_child < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid_sshd_child == 0) {
        sshd_child_node();
    } else {
        wait(NULL);
    }

    return 0;
}

int sshd_child_node() {
    printf("Nó filho do sshd -> pid = %d.\n", getpid());

    pid_t pid_tcsh;

    pid_tcsh = fork();

    if (pid_tcsh < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid_tcsh == 0) {
        tcsh_node();
    } else {
        wait(NULL);
    }

    return 0;
}

int tcsh_node() {
    printf("Nó tcsh -> pid = %d.\n", getpid());
    return 0;
}