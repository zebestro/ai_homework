TEST(RingBuffer, AveragesCorrectly) {
    RingBuffer rb;
    for (int i = 0; i < 10; ++i) {
        rb.push(i * 100); // simulate 0.0°C, 6.25°C, ...
    }
    ASSERT_EQ(rb.average(), 281.25f); // average of 0–9 * 0.0625
}

