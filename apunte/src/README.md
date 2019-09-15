# Threads

## Compilar

Para compilar es necesario *cmake* y gcc compatible con C++11

Utilizar CMake para generar el makefile necesario para compilar las aplicaciones. En un entorno unix se puede hacer, desde la carpeta src:

~~~{.bash}
# deberias estar posicionado en el mismo lugar que este .md
cd src
mkdir build
cd build
cmake ..
make
~~~

## Aplicaciones

* *00-threads-c*: Ejemplo de threads POSIX en C.

* *01-contador*: Contador de letras secuencial.

* *02-contador*: Contador de letras multihilo.

* *03-contador*: Contador de letras, con race-condition.

* *04-contador*: Contador de letras sincronizado.

* *05-deadlock*: Ejemplo de deadlock.

* *06-not-deadlock*: Solución al problema de deadlock anterior.

* *07-monitor*: Ejemplo de monitor.

* *random-gen*: generador de texto aleatorio


### Ejemplo de ejecución

~~~{.bash}
# deberias estar posicionado en la carpeta build
./random-gen 1200400
time ./01-contador random.txt
~~~
