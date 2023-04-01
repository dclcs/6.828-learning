#include "../../../6.828-learning/labs/xv6-labs-2022/kernel/types.h"
#include "../../../6.828-learning/labs/xv6-labs-2022/user/user.h"

int main()
{
    int pid, status;
    pid = fork();

    if(pid == 0) {
        char *argv[] = { "echo" , "this", "is", "echo", 0 };
        exec("echo", argv);
        printf("exec failed!\n");
    } else {
        printf("parent waiting for child to exit...\n");
        wait(&status);
        printf("child exited with status %d\n", status);
    }
    exit(0);
}
