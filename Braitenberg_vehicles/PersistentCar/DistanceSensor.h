#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

class DistanceSensor
{
private:
    int triggerPin;
    int echoPin;

    static const long SENSE_INTERVAL = 100; // in millis

    unsigned long previousTime; // millis
    unsigned long senseTime;    // millis, for ping delay computation
    long updateInterval;        // millis, for update interval computation
    bool isReading;

    int latestDistance;

public:
    DistanceSensor(int triggerPin, int echoPin, long updateInterval);

    int read();

    void beginRead();

    void finishRead();

    void update();
};

#endif // DISTANCE_SENSOR_H