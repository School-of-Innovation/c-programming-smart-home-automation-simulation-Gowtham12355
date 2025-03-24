#include <Arduino.h>

#define MAX_ROOMS 3

struct Room {
    bool light;
    int temperature;
    bool motion;
    bool locked;
};

Room rooms[MAX_ROOMS];

void setup() {
    Serial.begin(9600);
    
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].light = false;
        rooms[i].temperature = 22 + (random(5)); // Random temp between 22-26°C
        rooms[i].motion = random(2); // Random motion detection
        rooms[i].locked = true;
    }
    
    Serial.println("Smart Home System Initialized");
}

void displayMenu() {
    Serial.println("\n===== Smart Home Menu =====");
    Serial.println("1. Toggle Light");
    Serial.println("2. Read Temperature");
    Serial.println("3. Check Motion Sensor");
    Serial.println("4. Lock/Unlock Security System");
    Serial.println("5. House Status Summary");
    Serial.println("6. Exit");
    Serial.print("Enter your choice: ");
}

void loop() {
    displayMenu();
    
    while (Serial.available() == 0) {}
    int choice = Serial.parseInt();
    
    int roomNum;
    switch (choice) {
        case 1:
            Serial.print("Enter room number (1-3): ");
            while (Serial.available() == 0) {}
            roomNum = Serial.parseInt();
            if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
                rooms[roomNum - 1].light = !rooms[roomNum - 1].light;
                Serial.print("Light in Room "); Serial.print(roomNum);
                Serial.println(rooms[roomNum - 1].light ? " is ON." : " is OFF.");
            }
            break;
        case 2:
            Serial.print("Enter room number (1-3): ");
            while (Serial.available() == 0) {}
            roomNum = Serial.parseInt();
            if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
                Serial.print("Temperature in Room "); Serial.print(roomNum);
                Serial.print(": "); Serial.print(rooms[roomNum - 1].temperature);
                Serial.println("°C");
            }
            break;
        case 3:
            Serial.print("Enter room number (1-3): ");
            while (Serial.available() == 0) {}
            roomNum = Serial.parseInt();
            if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
                Serial.print("Motion in Room "); Serial.print(roomNum);
                Serial.println(rooms[roomNum - 1].motion ? " Detected" : " No Motion");
            }
            break;
        case 4:
            Serial.print("Enter room number (1-3): ");
            while (Serial.available() == 0) {}
            roomNum = Serial.parseInt();
            if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
                rooms[roomNum - 1].locked = !rooms[roomNum - 1].locked;
                Serial.print("Security in Room "); Serial.print(roomNum);
                Serial.println(rooms[roomNum - 1].locked ? " is Locked." : " is Unlocked.");
            }
            break;
        case 5:
            Serial.println("\nHouse Status:");
            for (int i = 0; i < MAX_ROOMS; i++) {
                Serial.print("Room "); Serial.print(i + 1);
                Serial.print(": Light "); Serial.print(rooms[i].light ? "ON" : "OFF");
                Serial.print(", Temp "); Serial.print(rooms[i].temperature);
                Serial.print("°C, ");
                Serial.print(rooms[i].motion ? "Motion Detected" : "No Motion");
                Serial.print(", ");
                Serial.println(rooms[i].locked ? "Locked" : "Unlocked");
            }
            break;
        case 6:
            Serial.println("Exiting...");
            while (true);
            break;
        default:
            Serial.println("Invalid choice! Try again.");
    }
    delay(2000);
}
