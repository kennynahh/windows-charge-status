#include <windows.h>
#include <iostream>
#include <thread>   // For std::this_thread::sleep_for
#include <chrono>   // For std::chrono::seconds
using namespace std;

int main() {
    while (true) {  // Infinite loop to keep checking the battery status
        SYSTEM_POWER_STATUS sps;
        if (GetSystemPowerStatus(&sps)) {
            cout << "Battery Life: " << static_cast<int>(sps.BatteryLifePercent) << "%" << endl;
            cout << "AC Status: " << static_cast<int>(sps.ACLineStatus) << endl;


            // Check if battery percentage is above a specified limit, e.g., 80%
            if (sps.BatteryLifePercent > 80) {
                cout << "Battery above 80%. Ideally, pause charging here." << endl << endl;
                // Code to pause charging would go here if it were possible through standard APIs
            }
        } else {
            cout << "Error retrieving power status." << endl;
        }

        // Delay for a specified time before checking again. Here, it's set to delay for 60 seconds.
        this_thread::sleep_for(chrono::seconds(60));
    }
    return 0;
}