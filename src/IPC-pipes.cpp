#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char writeMsg[] = "Hello from parent!";
    char readMsg[100];
    
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }
    
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    
    if (pid > 0) { // Parent process
        close(pipefd[0]);
        write(pipefd[1], writeMsg, strlen(writeMsg) + 1);
        close(pipefd[1]);
    } else { // Child process
        close(pipefd[1]);
        read(pipefd[0], readMsg, sizeof(readMsg));
        printf("Child received: %s\n", readMsg);
        close(pipefd[0]);
    }
    
    return 0;
}
