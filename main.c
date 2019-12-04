#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define ERROR -1

int cpuMiner() {
    FILE *cpuInfo = fopen("/proc/cpuinfo", "rb");
    char line[1024];
    int count = 0;

    fgets(line, 1024, cpuInfo);
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
        count++;
    }

    if (strstr(line, "cpu MHz") != NULL) {
        printf("\n");
        puts(line);
    }

    return count;
}

void memoryMiner() {
    FILE *ramInfo = fopen("/proc/meminfo", "rb");
    char line[1024];

    for (int i = 0; i < 7; ++i) {
        fgets(line, 1024, ramInfo);
        puts(line);
    }
}

void networkMiner() {
    FILE *networkInfo = fopen("/proc/net/dev", "rb");
    char line[1024];

    for (int i = 0; i < 4; ++i) {
        fgets(line, 1024, networkInfo);
        puts(line);
    }
}

void diskMiner() {
    FILE *diskInfo = fopen("/proc/diskstats", "rb");
    char line[1024];

    for (int i = 8; i < 13; ++i) {
        fgets(line, 1024, diskInfo);
        puts(line);
    }
}

void minerAdminProcess(int minerId) {
    int cpuInfo;
    switch (minerId) {
        case 1:
            cpuInfo = cpuMiner();
            printf("cpuInformationPrint", cpuInfo);
            break;
        case 2:
            memoryMiner();
            break;
        case 3:
            networkMiner();
            break;
        case 4:
            diskMiner();
            break;
        default:
            printf("notRecogniceMinerProcessPrint");
            break;
    }
}

pid_t fatherProcessMiner(int newMinerId) {
    int minerId = newMinerId;
    pid_t childProcess;

    switch (childProcess = fork()) {
        case -1:
            return ERROR;
        case 0:
            minerAdminProcess(minerId);
            break;
        default:
            printf("fatherCreatedPrint");
            break;
    }
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-c") == 0) {
            fatherProcessMiner(1);
        } else if (strcmp(argv[i], "-m") == 0) {
            fatherProcessMiner(2);
        } else if (strcmp(argv[i], "-n") == 0) {
            fatherProcessMiner(3);
        } else if (strcmp(argv[i], "-d") == 0) {
            fatherProcessMiner(4);
        }
    }
}