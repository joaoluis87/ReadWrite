#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    int pai = getpid();

    int pipeFileDescriptors[2];
    char writeMessage[20] = {"Mensagem do pai"};
    char readMessages[20];

    printf("pai: %d\n", pai);

    int returnPipe = pipe(pipeFileDescriptors);

    fork();

    

    if (returnPipe == -1) {
        printf("Erro ao criar o pipe\n");
        return 1;
    }

    if (getpid() == pai) {
        printf("Pai escrevendo a mensagem - %s\n", writeMessage);
        write(pipeFileDescriptors[1], writeMessage, sizeof(char) * 20);
    }
    else {
        read(pipeFileDescriptors[0], readMessages, sizeof(char) * 20);
        printf("Filho lendo a mensagem - %s\n", readMessages);
        printf("Filho: %d\n", getpid());
    }

}