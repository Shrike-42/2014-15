LSM303 compass;
void initializeCompass()
{
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>){-32767, -32767, -32767};
  compass.m_max = (LSM303::vector<int16_t>){+32767, +32767, +32767};
  20 (SDA), 21 (SCL)
}

void updateCompass()
{
  compass.read();
  float heading = compass.heading(); // 0 = North, 90 = East, 180 = South, 270 = West
}
