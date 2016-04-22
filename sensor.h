#ifndef SENSOR_H
#define SENSOR_H

#define I2C_ADDRESS    		0x40
#define READ_TEMPERATURE    0xF3
#define READ_HUMIDITY    	0xF5
#define WRITE_REGISTER   	0xE6
#define READ_REGISTER    	0xE7
#define RESET      			0xFE

static const int resetDelay = 15;
static const int minDelay   = 10;
static const int retryDelay = 5;
static const float A = 8.1332;
static const float B = 1762.39;
static const float C = 235.66;

class Sensor {

public:

int open(char *bus);
void error(int fd, uint8_t address);
int crc(const uint8_t *data, uint16_t *convertedValue);
int readRegister(int fd, int *obtainedValue);
int writeRegister(int fd,int newValue);
int initialize(int fd);
int getValue(int fd, float *value, const uint8_t master);
float computeRelativeHumidity(float relativeHumidity,float tempCell);
float partialPressureTemperatureAmbient(float temperature);
float dewPoint(float temperature, float humidity);

virtual ~Sensor();

};

#endif

