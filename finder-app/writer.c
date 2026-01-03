#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
    openlog("writer", LOG_PID, LOG_USER);
    if (argc != 3)
    {
        syslog(LOG_ERR,"arguments are not matching or not correct number of arguments: %s \n",argv[0]);
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    

    int FD = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (FD < 0)
    {
        syslog(LOG_ERR,"Error: unable to open file %s : erron %s",writefile,strerror(errno));
        close(FD);
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG,"Debug_log writing %s to %s ", writestr, writefile);
    size_t len = strlen(writestr);

    if(! write(FD, writestr,len))
    {
        syslog(LOG_ERR,"Erroe: unable to rile to file %s : errno %s",writestr,strerror(errno));
        close(FD);
        closelog();
        return 1;
    }

    if(close(FD) <0)
    {
        syslog(LOG_ERR, "Error : failed to close '%s' : errono %s ", writefile, strerror(errno));
        closelog();
        return 1;
    }

    closelog();
    return 0;
}