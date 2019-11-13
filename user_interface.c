#include <stdio.h>

void fatherCreatedPrint(){
    printf("The father process has been created...");
}

void notRecogniceMinerProcessPrint(){
    printf("Not recognize the file process number");
}

void lineBreak(){
    printf("\n");
}

void notContainsCpuCoresInfo(){
    printf("Does not contain cpu cores information");
}

void notContainsModelNameInfo(){
    printf("Does not contain model name info");
}

void notContainsCpuMHZInfo(){
    printf("Does not contain Mhz information");
}

void cpuInformationPrint(int count){
    printf("CPU cores is %d ", count);
}
