#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include "queues_file.h" //Biblioteca de linux para colas

#define ERROR -1

static pthread_mutex_t mtx; //Sincronizacion de procesos

void handler1(){
    printf("Process control");
    exit(0);
}

int cpuMiner() {
    FILE *cpuInfo = fopen("/proc/stat", "rb");
    char line[1024];
    unsigned long int user, nice, system, idle, iowait, irq, softirt;
    int cpuUsage = 0;

    while (fgets(line, sizeof(line), cpuInfo) != NULL) {
        if (strstr(line, "cpu ") != NULL) {
            sscanf(line, "%lu %lu %lu %lu %lu %lu %lu", &user, &nice, &system, &idle, &iowait, &irq, &softirt);
            cpuUsage = (int) nice;
        }
    }

    fclose(cpuInfo);
    return cpuUsage;
}

int memoryMiner() {
    FILE *ramInfo = fopen("/proc/meminfo", "rb");
    char line[1024];
    unsigned long int memTotal, memF, memA;
    int totalMemAvailable = 0;

    for (int i = 2; i < 3; ++i) {
        fgets(line, sizeof(line), ramInfo);
        sscanf(line, "%lu %lu %lu", &memTotal, &memF, &memA);
        totalMemAvailable = (int) memF;
    }

    fclose(ramInfo);
    return totalMemAvailable;
}

int networkMiner() {
    FILE *networkInfo = fopen("/proc/net/dev", "rb");
    char line[1024];
    unsigned long int interface, bytesPackets;
    int netUsage = 0;

    for (int i = 0; i < 2; ++i) {
        fgets(line, sizeof(line), networkInfo);
        sscanf(line, "%lu %lu", &interface, &bytesPackets);
        netUsage = (int) bytesPackets;
    }

    fclose(networkInfo);
    return netUsage;
}

int diskMiner() {
    FILE *diskInfo = popen("df -k", "r");
    static char line[1024];
    unsigned long int fileSystem, kBlocks, used, available, use, mounted;
    int diskUsage = 0;

    while (fgets(line, sizeof(line), diskInfo) != NULL) {
        if (strstr(line, "home") != NULL) {
            sscanf(line, "%lu %lu %lu %lu %lu %lu", &fileSystem, &kBlocks, &used, &available, &use, &mounted);
            diskUsage = (int) used;
        }
    }

    fclose(diskInfo);
    return diskUsage;
}

void minerAdminProcess(int minerId) {
    int cpuInformation;
    int memoryInformation;
    int networkInformation;
    int diskInformation;
    switch (minerId) {
        case 1:
            cpuInformation = cpuMiner();
            printf("Cpu info: %d", cpuInformation);
            break;
        case 2:
            memoryInformation = memoryMiner();
            printf("Mem info: %d", memoryInformation);
            break;
        case 3:
            networkInformation = networkMiner();
            printf("Net info: %d", networkInformation);
            break;
        case 4:
            diskInformation = diskMiner();
            printf("Disk info: %d", diskInformation);
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
            signal(SIGCHLD, handler1); //Eliminar el proceso padre
            printf("\nSignal parent death exec\n");
            break;
        default:
            printf("The parent process was create\n");
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