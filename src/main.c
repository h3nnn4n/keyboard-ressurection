#include "setup.h"
#include "loop.h"

int main(void)
{
    setup();

    while (1)
    {
        loop();
    }
}
