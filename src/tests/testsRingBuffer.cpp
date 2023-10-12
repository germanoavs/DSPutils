#include<RingBuffer.hpp>
#include<cpx.hpp>
#include<iostream>

int testInitRingBuffer()
{
    RingBuffer rb(10);

    try
    {
        int size = rb.size();
        if(size != 10){
            throw std::runtime_error("RingBuffer size is not 10");
            return 0;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 1;
}

int testPushRingBuffer()
{
    RingBuffer rb(10);
    cpx value(1, 1);

    try
    {
        rb.push(value);
        cpx value2 = rb.get();
        if(value2.real() != value.real() || value2.imag() != value.imag()){
            throw std::runtime_error("RingBuffer push failed");
            return 0;
        } else {
            return 1;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
       
}


int testRingBuffer()
{
    
    cpxvec seq = {cpx(1, 1), cpx(2, 2), cpx(3, 3), cpx(4, 4), cpx(5, 5), cpx(6, 6), cpx(7, 7), cpx(8, 8), cpx(9, 9), cpx(10, 10)};

    cpxvec expec = {cpx(10,10), cpx(2,2), cpx(3,3), cpx(4,4), cpx(5,5), cpx(6,6), cpx(7,7), cpx(8,8), cpx(9,9)};

    RingBuffer rb(9);

    for (size_t i = 0; i < seq.size(); i++)
        rb.push(seq[i]);


    

    for (size_t i = 0; i < expec.size(); i++){
        if (rb[i] != expec[i])
            throw std::runtime_error("RingBuffer failed");
    }

    return 1;
}