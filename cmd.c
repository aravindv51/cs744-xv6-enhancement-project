#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{

    //check if there are enough arguments
    if (argc < 2)
    {
        printf(1, "Usage: %s <program> [arguments...]\n", argv[0]);
        exit();
    }

    //forking the process
    int pid;
    pid = fork();

    if(pid == 0) {

        //argv is just a pointer, so to remove first element just shift the head to first element
        argv++;
        exec(argv[0], argv);
        printf(1, "exec failed\n");
        exit();
    } else {
        wait();
    }

    exit();

}