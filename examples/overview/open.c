#include "../../../6.828-learning/labs/xv6-labs-2022/kernel/types.h"
#include "../../../6.828-learning/labs/xv6-labs-2022/user/user.h"
#include "../../../6.828-learning/labs/xv6-labs-2022/kernel/fcntl.h"

int
main()
{
  int fd = open("out", O_WRONLY | O_CREATE | O_TRUNC);
  write(fd, "ooo fd out\n", 4);

  exit(0);
}