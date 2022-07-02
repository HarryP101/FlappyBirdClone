#include "FlappyBirdWorldEngine.h"

int main()
{
    FlappyBirdWorldEngine demo;

    if (demo.Construct(200, 200, 4, 4))
    {
        demo.Start();
    }
}