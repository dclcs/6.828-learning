// #include "../../../6.828-learning/labs/xv6-labs-2022/kernel/types.h"
// #include "../../../6.828-learning/labs/xv6-labs-2022/user/user.h"
#include <stdio.h>
#include <unistd.h>
int main()
{
    char *argv[] = { "echo", "this", "is", "echo", 0 };

    execv("/bin/echo", argv);

    printf("exec failed!\n");
 
    // exit(0);
    return 0;
}
