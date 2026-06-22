#include <Arduino.h>
#include <LedDisplay.h>

class ParkingSensor {
private:
    int trigPin, echoPin;
    LedDisplay display;
    static const int READ_INTERVAL = 100; 
    static const int MIN_DIST_CM = 10;
    static const int MAX_DIST_CM = 100;
    static const int FILTER_SIZE = 3;

    long lastRead;
    int distBuffer[FILTER_SIZE];
    int bufIdx;

    int readRawDistance();
    int getFilteredDistance();
    int distanceToLevel(int dist);

public:
    ParkingSensor(int trig, int echo, int ledCount, int ledPins[]);
    void begin();
    void update();
};
