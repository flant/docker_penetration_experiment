#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char **argv) {
  int pid = atoi(argv[1]);
  char pathbuf[100];

  snprintf(pathbuf, 100, "/proc/%d/ns/net", pid);
  setns(open(pathbuf, O_RDONLY), 0);

  snprintf(pathbuf, 100, "/proc/%d/ns/ipc", pid);
  setns(open(pathbuf, O_RDONLY), 0);

  snprintf(pathbuf, 100, "/proc/%d/ns/uts", pid);
  setns(open(pathbuf, O_RDONLY), 0);

  snprintf(pathbuf, 100, "/proc/%d/ns/pid", pid);
  setns(open(pathbuf, O_RDONLY), 0);

  snprintf(pathbuf, 100, "/proc/%d/ns/mnt", pid);
  setns(open(pathbuf, O_RDONLY), 0);

  if(fork()) {
    wait(NULL);
    return 0;
  }

  execl("/bin/bash", "/bin/bash", NULL);
}
