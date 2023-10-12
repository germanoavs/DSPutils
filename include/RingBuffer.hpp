/**
 * @file RingBuffer.hpp
 * @author Germano Sobroza (germanoavs@gmail.com)
 * @brief Ring buffer for delay lines. 
 *        Could be used for other purposes and all data types.
 * @version 0.1
 * @date 2023-10-12
 * 
 */


#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

    #include <cpx.hpp>

    class RingBuffer
    {
        private:
            cpxvec buffer;
            size_t index;
            size_t size_;

        public:
            RingBuffer(size_t size);
            void push(cpx sample);
            cpx operator[](size_t index) const;
            size_t size() const;
            cpx get() const;
            ~RingBuffer();
    };

#endif // RINGBUFFER_HPP