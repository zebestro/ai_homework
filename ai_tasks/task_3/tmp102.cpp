class TMP102 {

public:
    void init();
    float readTemperature();
    void startSampling(); // Starts RTOS task or timer
    void handleInterrupt(); // For interrupt-driven reads

private:
    int16_t buffer_[10];
    uint8_t index_ = 0;
    float averageTemperature();
};

