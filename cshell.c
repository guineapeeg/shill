#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char *name;
    char *value;

} EnvVar;

int print();

int main(int argc, char *argv[]){

    
}

int print(){

    printf("cshell$");

    return (0);

}

int exit(){

    kill(getpid(), SIGINT);

    return (0);
}