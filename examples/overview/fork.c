#include "../../../6.828-learning/labs/xv6-labs-2022/kernel/types.h"
#include "../../../6.828-learning/labs/xv6-labs-2022/user/user.h"

int main(int argc, char const *argv[])
{
    int pid;
    pid = fork();
    printf("fork() returned %d\n", pid);

    if(pid == 0) {
        printf("child\n");
    } else {
        printf("parent\n");
    }
    return 0;
}
