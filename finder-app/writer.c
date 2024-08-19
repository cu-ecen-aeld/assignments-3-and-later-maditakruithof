#include <syslog.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        syslog(LOG_ERR , "Not enough arguments");
        return 1;
    }
    else
    {
        syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
        FILE *fptr;
        fptr = fopen(argv[1], "w");
        fprintf(fptr, "%s", argv[2]);
        fclose(fptr);
        return 0;
    } 
}