#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/wait.h>

int main() {
  unshare(CLONE_NEWIPC | CLONE_NEWNS | CLONE_NEWNET | CLONE_NEWPID | CLONE_NEWUTS);

  if(fork()) {
    wait(NULL);
    return 0;
  }

  umount("/proc");
  mount("proc", "/proc", "proc", 0, 0);

  execl("/bin/bash", "/bin/bash", NULL);
}
