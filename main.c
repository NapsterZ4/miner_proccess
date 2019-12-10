#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include "queues_file.h" //Biblioteca de linux para colas

#define ERROR -1

static pthread_mutex_t mtx; //Sincronizacion de procesos

void handler1(int sig){
    printf("The parent process Death!!!!");
    exit(0);
}

char * cpuMiner() {
    FILE *cpuInfo = fopen("/proc/cpuinfo", "rb");
    static char line[1024];

    while (fgets(line, 1024, cpuInfo) != NULL) {
        if (strstr(line, "cpu cores") != NULL) {
            puts(line);
        }

        if (strstr(line, "model name") != NULL) {
            printf("\n");
            puts(line);
        }

        if (strstr(line, "processor") != NULL) {
            printf("\n");
            puts(line);
        }

        if (strstr(line, "cpu MHz") != NULL) {
            printf("\n");
            puts(line);
        }
    }
    return line;
}

char * memoryMiner() {
    FILE *ramInfo = fopen("/proc/meminfo", "rb");
    static char line[1024];

    for (int i = 0; i < 7; ++i) {
        fgets(line, 1024, ramInfo);
        puts(line);
    }
    return line;
}

char * networkMiner() {
    FILE *networkInfo = fopen("/proc/net/dev", "rb");
    static char line[1024];

    for (int i = 0; i < 4; ++i) {
        fgets(line, 1024, networkInfo);
        puts(line);
    }
    return line;
}

char * diskMiner() {
    FILE *diskInfo = fopen("/proc/diskstats", "rb");
    static char line[1024];

    for (int i = 8; i < 13; ++i) {
        fgets(line, 1024, diskInfo);
        puts(line);
    }
    return line;
}

void minerAdminProcess(int minerId) {
    char cpuInformation[1024];
    char memoryInformation[1024];
    char networkInformation[1024];
    char diskInformation[1024];
    switch (minerId) {
        case 1:
            strcpy(cpuInformation, cpuMiner());
            break;
        case 2:
            strcpy(memoryInformation, memoryMiner());
            break;
        case 3:
            strcpy(networkInformation, networkMiner());
            break;
        case 4:
            strcpy(diskInformation, diskMiner());
            break;
        default:
            printf("Not recognize miner process, please insert other entry");
            break;
    }
}

pid_t parentProcessMiner(int newMinerId) {
    int minerId = newMinerId;
    pid_t childProcess;

    switch (childProcess = fork()) {
        case -1:
            return ERROR;
        case 0:
            minerAdminProcess(minerId);
            break;
        default:
            kill(childProcess, SIGUSR1);
            signal(SIGCHLD, handler1);
            break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-c") == 0) {
            parentProcessMiner(1);
        } else if (strcmp(argv[i], "-m") == 0) {
            parentProcessMiner(2);
        } else if (strcmp(argv[i], "-n") == 0) {
            parentProcessMiner(3);
        } else if (strcmp(argv[i], "-d") == 0) {
            parentProcessMiner(4);
        }
    }
    signal(getppid(), (__sighandler_t) SIGKILL);
}