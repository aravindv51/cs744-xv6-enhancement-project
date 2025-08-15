#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define BUFSIZE 512

void ping_pong(int fd) 
{

    //find ping and print pong
    char buffer[BUFSIZE];
    char *s2 = "ping";
    int l1, l2, len, i, j, reads;
    l2 = strlen(s2);
    while((reads = read(fd, buffer, BUFSIZE)) != 0) {
        l1 = reads;
        for(i=0; i<l1-l2+1; i++) {
            len = 0;
            for(j=0; j<l2; j++) {
                if(buffer[i+j] == s2[j])
                    len++;
                else 
                    break;
            }
            if(len == l2)
                write(0, "pong\n", 5);
        }
    }
}

int main(int argc, char *argv[])
{

    //checking enough number of arguments
    if (argc != 2) {
        printf(1, "Usage: %s <input_file>\n", argv[0]);
        exit();
    }

    //open the file
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf(1, "Error opening file %s\n", argv[1]);
        exit();
    }

    ping_pong(fd);
    close(fd);

    exit();
}
