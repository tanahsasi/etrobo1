#ifndef H_LOW_PASS_FILTER_
#define H_LOW_PASS_FILTER_

class LowPassFilter {
    public:
        LowPassFilter();
        ~LowPassFilter();
        void addValue(double );
        double getFillteredValue();
        void setRate(double rate);

    private:
        double mRate;
        double prev;
};

#endif
