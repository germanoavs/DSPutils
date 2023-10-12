#include <iostream>
#include<tests.hpp>
#include "RingBuffer.hpp"
#include<cpx.hpp>

int main()
{
    int count = 0;

    count += testInitRingBuffer();
    count += testPushRingBuffer();
    count += testRingBuffer();

    std::cout << "Tests passed: " << count << std::endl;
}
