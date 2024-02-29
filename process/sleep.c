#include <time.h>
#include <internal/syscall.h>
#include <errno.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    return nanosleep(&req, NULL);
}
