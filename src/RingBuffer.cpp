/*
 *   Copyright (c) 2023 
 *   All rights reserved.
 */
// Author: G Sobroza
// 07/06/2023

#include <cpx.hpp>
#include<RingBuffer.hpp>


RingBuffer::RingBuffer(size_t size): buffer(size), index(0), size_(size)
{
    // print_verbose("RingBuffer constructor called");
}

RingBuffer::~RingBuffer(){
}

void RingBuffer::push(cpx sample)
{
    
    buffer[index] = sample;
    index = (index +1) % buffer.size();

}

// overload [] operator
cpx RingBuffer::operator[](size_t idx) const
{
    return buffer[idx];
}

size_t RingBuffer::size() const
{
    return size_;
}

cpx RingBuffer::get() const
{
    if (index == 0)
    {
        return buffer[size_ - 1];
    }
    else
    {
        return buffer[index - 1];
    }
}