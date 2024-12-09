#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float temperature;
    float rainfall;
    float wind_speed;
} WeatherForecast;

typedef struct {
    char cropType[20];
    char growthStage[20];
    float expectedYield;
    WeatherForecast* weather;
} Crop;

typedef struct {
    char equipmentType[20];
    char operationalStatus[10];
    float fuelLevel;
} Equipment;

typedef struct {
    float gpsLatitude;
    float gpsLongitude;
    float soilHealth[3];
    float moistureLevel;
    Crop* crops;     
    Equipment* equipment; 
    int numCrops;
    int numEquipment;
} Field;

typedef struct {
    Field* fields;    
    int numFields;
} RegionalHub;

typedef struct {
    RegionalHub* hubs;   
    int numHubs;
} CentralServer;


