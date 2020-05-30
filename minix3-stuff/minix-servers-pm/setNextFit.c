#include "pm.h"
#include <minix/callnr.h>
#include <minix/com.h>
#include <signal.h>
#include "mproc.h"
#include "setAlgorithm.c"

int do_NextFitAlg(){
    chosenAlgorithm = nextFit;
    return 0;
}