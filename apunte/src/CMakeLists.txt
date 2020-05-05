project(threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++11 -Wall -Werror -pedantic -pedantic-errors")

add_executable(00-threads-c
  00-threads-posix-c/threads-c.c
)

add_executable(01-contador
  01-contador-single-thread/contador.cpp
)

add_executable(02-contador
  02-multiples-contadores/contador.cpp
)

add_executable(02b-contador
  02b-multiples-contadores-alt/contador.cpp
  02b-multiples-contadores-alt/CounterThread.cpp
  02b-multiples-contadores-alt/Thread.cpp
)

add_executable(03-contador 03-contador-race-condition/contador.cpp)

add_executable(04-contador 04-contador-protegido/contador.cpp)

add_executable(04b-contador 04b-contador-atomico/contador.cpp)

add_executable(05-deadlock
  05-transacciones-deadlock/main.cpp
  05-transacciones-deadlock/Account.cpp
)

add_executable(06-not-deadlock
  06-transacciones-ok/main.cpp
  06-transacciones-ok/Account.cpp
  06-transacciones-ok/Lock.cpp
)

add_executable(07-monitor
  07-monitor/main.cpp
  07-monitor/Account.cpp
  07-monitor/AccountMonitor.cpp
)

add_executable(08-cinema
  08-cinema/cinema.cpp
)

target_link_libraries(00-threads-c pthread)
target_link_libraries(02-contador pthread)
target_link_libraries(02b-contador pthread)
target_link_libraries(03-contador pthread)
target_link_libraries(04-contador pthread)
target_link_libraries(04b-contador pthread)
target_link_libraries(05-deadlock pthread)
target_link_libraries(06-not-deadlock pthread)
target_link_libraries(07-monitor pthread)
target_link_libraries(08-cinema pthread)
