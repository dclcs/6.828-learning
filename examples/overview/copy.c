#include "../../../6.828-learning/labs/xv6-labs-2022/kernel/types.h"
#include "../../../6.828-learning/labs/xv6-labs-2022/user/user.h"

int main()
{
    char buf[64];

    while (1)
    {
        int n = read(0, buf, sizeof(buf));
        if (n <= 0)
        {
            break;
        }
        write(2, buf, n);
    }
    
    return 0;
}

