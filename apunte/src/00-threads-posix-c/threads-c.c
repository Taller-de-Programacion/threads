// Compilar con 00-threads-c -lpthread
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// Struct con los parámetros que le paso a mi función concurrente
struct printer_param_t {
    int times;
    char* str;
};

// Función que correrá de forma concurrente
void* printString(void* printerParam) {
    struct printer_param_t *param = (struct printer_param_t *) printerParam;
    for (int i = 0; i < param->times; ++i) {
        printf("[%d] str: %s\n", i, param->str);
        sleep(1);
    }
}

int main (int argc, char** argv) {
    // Inicializo los parámetros
    struct printer_param_t printParams;
    printParams.times = 5;
    printParams.str = "Hola posix threads!";

    printf("Creando un thread\n");
    pthread_t printThread;
    pthread_create(&printThread, 0, printString, &printParams);

    
    printf("Thread lanzado, imprimiendo en main\n");
    struct printer_param_t printParams2;
    printParams2.times = 3;
    printParams2.str = "Hola, soy Main";

    printString(&printParams2);

    // Espero a que termine el hilo lanzado
    printf("Haciendo el join\n");
    pthread_join(printThread, 0);
    printf("Joined!\n");
}
