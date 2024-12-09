#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    double** engagementMatrix; 
    int numUsers;        
    int numCategories;        
} EngagementSystem;

typedef struct {
    char resolution[10];      
    int bandwidthUsage;     
    char playbackHistory[100]; 
} DevicePreferences;

typedef struct {
    DevicePreferences** deviceMatrix; 
    int numUsers;                  
    int maxDevicesPerUser;           
} DeviceSystem;

typedef struct {
    char title[50];   
    float rating;       
    int runtimeMinutes;
    char encoding[10];  
} ContentMetadata;

typedef struct {
    ContentMetadata*** contentMatrix;
    int numCategories;             
    int* numContentsPerCategory;     
} ContentSystem;


EngagementSystem* initEngagementSystem(int numUsers, int numCategories) {
    EngagementSystem* system = (EngagementSystem*)malloc(sizeof(EngagementSystem));
    system->numUsers = numUsers;
    system->numCategories = numCategories;
    system->engagementMatrix = (double**)malloc(numUsers * sizeof(double*));
    for (int i = 0; i < numUsers; i++) {
        system->engagementMatrix[i] = (double*)calloc(numCategories, sizeof(double));
    }
    return system;
}

void updateEngagement(EngagementSystem* system, int userIndex, int categoryIndex, double score) {
    if (userIndex < system->numUsers && categoryIndex < system->numCategories) {
        system->engagementMatrix[userIndex][categoryIndex] += score;
    }
}

void freeEngagementSystem(EngagementSystem* system) {
    for (int i = 0; i < system->numUsers; i++) {
        free(system->engagementMatrix[i]);
    }
    free(system->engagementMatrix);
    free(system);
}

DeviceSystem* initDeviceSystem(int numUsers, int maxDevicesPerUser) {
    DeviceSystem* system = (DeviceSystem*)malloc(sizeof(DeviceSystem));
    system->numUsers = numUsers;
    system->maxDevicesPerUser = maxDevicesPerUser;
    system->deviceMatrix = (DevicePreferences**)malloc(numUsers * sizeof(DevicePreferences*));
    for (int i = 0; i < numUsers; i++) {
        system->deviceMatrix[i] = (DevicePreferences*)malloc(maxDevicesPerUser * sizeof(DevicePreferences));
    }
    return system;
}

void updateDevicePreference(DevicePreferences* device, const char* resolution, int bandwidth, const char* playbackHistory) {
    strcpy(device->resolution, resolution);
    device->bandwidthUsage = bandwidth;
    strcpy(device->playbackHistory, playbackHistory);
}

void freeDeviceSystem(DeviceSystem* system) {
    for (int i = 0; i < system->numUsers; i++) {
        free(system->deviceMatrix[i]);
    }
    free(system->deviceMatrix);
    free(system);
}

ContentSystem* initContentSystem(int numCategories, int* numContentsPerCategory) {
    ContentSystem* system = (ContentSystem*)malloc(sizeof(ContentSystem));
    system->numCategories = numCategories;
    system->numContentsPerCategory = (int*)malloc(numCategories * sizeof(int));
    system->contentMatrix = (ContentMetadata***)malloc(numCategories * sizeof(ContentMetadata**));
    for (int i = 0; i < numCategories; i++) {
        system->numContentsPerCategory[i] = numContentsPerCategory[i];
        system->contentMatrix[i] = (ContentMetadata**)malloc(numContentsPerCategory[i] * sizeof(ContentMetadata*));
        for (int j = 0; j < numContentsPerCategory[i]; j++) {
            system->contentMatrix[i][j] = (ContentMetadata*)malloc(sizeof(ContentMetadata));
        }
    }
    return system;
}

void freeContentSystem(ContentSystem* system) {
    for (int i = 0; i < system->numCategories; i++) {
        for (int j = 0; j < system->numContentsPerCategory[i]; j++) {
            free(system->contentMatrix[i][j]);
        }
        free(system->contentMatrix[i]);
    }
    free(system->contentMatrix);
    free(system->numContentsPerCategory);
    free(system);
}

int main() {
    int numUsers = 3, numCategories = 4, maxDevicesPerUser = 2;
    int numContentsPerCategory[] = {3, 2, 4, 5};

    EngagementSystem* engagementSystem = initEngagementSystem(numUsers, numCategories);
    DeviceSystem* deviceSystem = initDeviceSystem(numUsers, maxDevicesPerUser);
    ContentSystem* contentSystem = initContentSystem(numCategories, numContentsPerCategory);

    updateEngagement(engagementSystem, 0, 1, 10.5); 
    updateDevicePreference(&deviceSystem->deviceMatrix[0][0], "1080p", 500, "Movie A");
    strcpy(contentSystem->contentMatrix[0][0]->title, "Action Movie");
    contentSystem->contentMatrix[0][0]->rating = 4.5;

    freeEngagementSystem(engagementSystem);
    freeDeviceSystem(deviceSystem);
    freeContentSystem(contentSystem);

    return 0;
}
