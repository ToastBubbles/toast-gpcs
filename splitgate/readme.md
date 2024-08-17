My Splitgate method consists of two scripts:

-Sound Activator [Arduino]

-RTM (Return to Menu) [Titan Two]

RTM is just a standard script that will return you to the main menu and queue a search for a new game.

Sound Activator is a bit more complex, it is an Arduino sketch that detects loud sounds and will use that to trigger the RTM script. The Sound Activator can be omitted if you choose, but oyu will have to manually trigger the RTM script or find an alternate trigger. The Arduino one will require a few components:

-Arduino + wires and data cable
-Sound sensor
-Servo

To set everything up, do the following:

Arduino:
-Download the Arduino IDE
-Wire up all components, the data pins can be found in the code (my sound sensor was an assembly that was part of a student kit, so you may have to do additional adjustment to the code to get yours to work. Ask ChatGPT if you are having issues)
-Plug your Arduino into your computer
-Open the Sound Activator Script and click the arrow button on the top left of the IDE to load the script to your device.
-Go to tools > Serial Monitor to view live sound data and use this data to adjust the activation threshold in the script (I was using 580)
-Once it is all set up, place the sound sensor near a speaker (I used my subwoofer because mine picked up low frequencies better) and place your servo on your controller (I just electrical taped it to the controller, the activation button for my RTM script is Down on the D-Pad)
-Make some noise to test the servo

Titan Two:
-If using a Cronus, adjust/convert the script accordingly
-load the script to your device, change the activation button if desired (it is using Down on the D-Pad)
-Connect to your xbox/controller

Xbox settings (optional):
-Mute navigation and notification sounds to avoid false positives

In Game:
-Enable Crossplay (optional but recommended)
-Select all gamemodes except for FFA and Search and Survive
-Go to Settings > Audio and lower all sound bars to 0 except for Master and Announcer
-Then when ready, search for a match and if done right it should join a game, quit after the 5 second countdown, then re-queue

Monitor & Adjust:
-There are a few things you may need to adjust, for instance, Splitgate doesn't work on my Series X, so I made this script for a One, you may need to shorten or lengthen the loading wait-time in the RTM script for efficiency.
-The game would occationally crash, or trigger accidentally if a loud low-frequency sound is detected like a loud door, mowing, an airplane, etc. So it is a good idea to keep an eye on it so it doesn't go rogue and buy a bunch of games.
