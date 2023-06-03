#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef struct{

    char *name;
    char *value;

} EnvVar;

int print();
int exitShell();

int main(int argc, char *argv[]){

    print();
    //exitShell();
    readInput();

    
}

int print(){

    printf("cshell$");

    return (0);

}

int exitShell(){

    kill(getpid(), SIGINT);

    return (0);
}

int readInput(){

    char* prompt[30];

    scanf("%s", prompt);

    return 0;

}