#ifndef FIR_HPP
#define FIR_HPP

    #include<cpx.hpp>

    class FIR
    {
        public:
            FIR(cpxvec &coeffs);
            ~FIR();
            cpxvec filter(cpxvec &input);
            void filter(cpxvec &input, cpxvec &output);
        private:
            cpxvec coeffs;
            cpxvec buffer;

    };

    


#endif // FIR_HPP