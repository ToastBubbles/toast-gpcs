#include <Servo.h>

int sound_sensor = A2; // Assign to pin A2
Servo myServo; // Create a Servo object

unsigned long lastTriggerTime = 0; // Track the last time the servo was triggered
unsigned long soundStartTime = 0; // Track the start time of sound events
int soundEventCount = 0; // Count the number of sound events
bool cooldown = false; // To handle the cooldown state

void setup() 
{
  Serial.begin(9600); // Begin Serial Communication
  myServo.attach(9); // Attach the servo control to pin 9 (change if needed)
  myServo.write(15); // Initialize servo position to 0 degrees
}

void loop()
{
  int soundValue = 0; // Create variable to store readings
  for (int i = 0; i < 32; i++) // Create a for loop to read 
  { 
    soundValue += analogRead(sound_sensor); 
  }
 
  soundValue >>= 5; // Bit shift operation
  if(soundValue > 350){
    Serial.println(soundValue); // Print the value of the sound sensor
  }
  
  // Check if sound level exceeds threshold
  if (soundValue > 580) // THIS IS THE SOUND THRESHOLD, ADJUST ACCORDINGLY
  { 
    Serial.println(" ||||||||||||||||| ");
    // If it's the first sound event, initialize the start time
    if (soundEventCount == 0) {
      Serial.println(" FIRST ");
      Serial.println(soundValue);
      soundStartTime = millis();
    }
    Serial.println(soundValue);
    
    // Increment the count of sound events
    soundEventCount++;
  }
  
  // Check if 3 sound events occurred within 3 seconds
  if (soundEventCount >= 3 && millis() - soundStartTime <= 3000) 
  {
    if (millis() - lastTriggerTime > 45000 && !cooldown) 
    {
      delay(4500);
      // Trigger the servo to move
      myServo.write(0); // Move servo to 30 degrees
      delay(500); // Wait for the servo to reach the position
      myServo.write(15); // Move servo back to 0 degrees
      lastTriggerTime = millis(); // Update the last trigger time
      cooldown = true; // Start cooldown period
    }
    
    // Reset sound event count and cooldown timer
    soundEventCount = 0;
  }
  else if (millis() - soundStartTime > 4000) 
  {
    // Reset sound event count if 3 seconds have passed without reaching the threshold
    soundEventCount = 0;
  }

  // Manage cooldown period
  if (cooldown && millis() - lastTriggerTime > 45000) 
  {
    cooldown = false; // End cooldown period
  }

  delay(50); // A shorter delay between readings
}
