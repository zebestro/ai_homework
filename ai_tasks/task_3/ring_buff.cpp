class RingBuffer {
public:
    void push(int16_t value);
    float average() const;
    const int16_t* raw() const;

private:
    int16_t buffer_[10] = {};
    uint8_t head_ = 0;
    bool full_ = false;
};

