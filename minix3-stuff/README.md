- New files created:
    - This is outside of the operating systems files:
        - testInputScript.c 
    - In /usr/src/minix/servers/pm
        - setAlgorithm.c
        - setBestFit.c
        - setWorstFit.c
        - setRandomFit.c
        - setNextFit.c
- Files changed:
    - In /usr/src/minix/servers/vm
        - alloc.c
    - In /usr/src/minix/servers/pm
        - proto.h
        - table.c
        - Makefile
    - In /usr/src/minix/include/minix
        - callnr.h

- http://www.inform.pucp.edu.pe/~inf232/Semestre-2009-2/Laboratorio-4/memoria.pdf
    - "The PM's process table is called mproc and its definition is given in src/servers/pm/mproc.h. It contains all the fields related to a
process' memory allocation, as well as some additional items"
    - This is why we chose to modify the Calls to PM rather than the Calls to VFS in callnr.h

    