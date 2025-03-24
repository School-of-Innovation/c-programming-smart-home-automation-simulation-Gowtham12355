/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 
 #define MAX_ROOMS 5  // Maximum number of rooms
 
 // Structure to store room details
 struct Room {
     bool light;
     int temperature;
     bool motion;
     bool locked;
 };
 
 struct Room rooms[MAX_ROOMS];
 
 // Function prototypes
 void initializeSystem();
 void displayMenu();
 void controlLights();
 void readTemperature();
 void detectMotion();
 void securitySystem();
 void analyzeHouseStatus();
 
 int main() {
     int choice;
     
     initializeSystem();
 
     
     while (1) {
         displayMenu();
         printf("Enter your choice: ");
         scanf("%d", &choice);
 
         switch (choice) {
             case 1: controlLights(); break;
             case 2: readTemperature(); break;
             case 3: detectMotion(); break;
             case 4: securitySystem(); break;
             case 5: analyzeHouseStatus(); break;
             case 6: 
                 printf("Exiting...\n");
                 exit(0);
             default: 
                 printf("Invalid choice! Please try again.\n");
         }
     }
 
     return 0;
 }
 

 void initializeSystem() {
     for (int i = 0; i < MAX_ROOMS; i++) {
         rooms[i].light = false;
         rooms[i].temperature = 22 + (rand() % 5); 
         rooms[i].motion = rand() % 2; 
         rooms[i].locked = true;
     }
     printf("Smart Home System Initialized!\n");
 }
 
 void displayMenu() {
     printf("\n===== Smart Home Menu =====\n");
     printf("1. Toggle Light\n");
     printf("2. Read Temperature\n");
     printf("3. Check Motion Sensor\n");
     printf("4. Lock/Unlock Security System\n");
     printf("5. House Status Summary\n");
     printf("6. Exit\n");
 }
 

 void controlLights() {
     int roomNum;
     printf("Enter room number (1-%d) to toggle light: ", MAX_ROOMS);
     scanf("%d", &roomNum);
 
     if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
         rooms[roomNum - 1].light = !rooms[roomNum - 1].light;
         printf("Light in Room %d is now %s.\n", roomNum, rooms[roomNum - 1].light ? "ON" : "OFF");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 
 void readTemperature() {
     int roomNum;
     printf("Enter room number (1-%d) to check temperature: ", MAX_ROOMS);
     scanf("%d", &roomNum);
 
     if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
         printf("Temperature in Room %d: %d°C\n", roomNum, rooms[roomNum - 1].temperature);
     } else {
         printf("Invalid room number!\n");
     }
 }
 

 void detectMotion() {
     int roomNum;
     printf("Enter room number (1-%d) to check motion sensor: ", MAX_ROOMS);
     scanf("%d", &roomNum);
 
     if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
         printf("Motion in Room %d: %s\n", roomNum, rooms[roomNum - 1].motion ? "Detected" : "No Motion");
     } else {
         printf("Invalid room number!\n");
     }
 }
 

 void securitySystem() {
     int roomNum;
     printf("Enter room number (1-%d) to lock/unlock: ", MAX_ROOMS);
     scanf("%d", &roomNum);
 
     if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
         rooms[roomNum - 1].locked = !rooms[roomNum - 1].locked;
         printf("Security in Room %d is now %s.\n", roomNum, rooms[roomNum - 1].locked ? "Locked" : "Unlocked");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 
 void analyzeHouseStatus() {
     printf("\n===== House Status =====\n");
     for (int i = 0; i < MAX_ROOMS; i++) {
         printf("Room %d: Light %s, Temp %d°C, %s, %s\n",
             i + 1,
             rooms[i].light ? "ON" : "OFF",
             rooms[i].temperature,
             rooms[i].motion ? "Motion Detected" : "No Motion",
             rooms[i].locked ? "Locked" : "Unlocked"
         );
     }
 }
 