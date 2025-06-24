int16_t tmp102_read_temperature_raw() {
    uint8_t reg = 0x00;
    uint8_t data[2];

    i2c_start();
    i2c_write_address(TMP102_ADDR, I2C_WRITE);
    i2c_write(reg);
    i2c_start();
    i2c_write_address(TMP102_ADDR, I2C_READ);
    data[0] = i2c_read_ack();
    data[1] = i2c_read_nack();
    i2c_stop();

    return (data[0] << 8) | data[1];
}

float tmp102_raw_to_celsius(int16_t raw) {
    raw >>= 4;
    if (raw & 0x800) {
        raw |= 0xF000;
    }
    return raw * 0.0625f;
}

