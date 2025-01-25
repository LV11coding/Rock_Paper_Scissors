# -The game Rock Paper Scissors built for an Arduino Mega.
--Using an OLED display (**SH110X**).<br/>
--Printable 3D parts (box).<br/>
--On the box there are cutouts for the **speaker**, **buttons** and **LEDs**. Additional indications for showing which button is for what.<br/>
--**Custom driver and speaker** for music.<br/>
--**Custom PCB** to fit inside the 3D printed box.<br/>

# -Description:
--Press the **START** button.<br/>
--A player plays against the computer (aka the Arduino Mega).<br/>
--There are 3 buttons on the box and 3 LEDs with each of them according to one of the buttons. <br/>
--When the player turns on the game a message appears on screen telling him to choose rock, paper or scissors.<br/>
--When the player chooses an option (by pressing one of the buttons), the Mega randomly chooses and option too.<br/>
--A message is diplayed on the OLED screen, which indicates what the Mega chose and if the player has won or not.<br/>
--When the **START** button is pressed again the game is restarted.<br/>

# -Versions:
--**v2.0** - Full Rock Paper Scissors gameplay, booting display + test message. <br/>
--**v3.0** - Fixed bugs related to button presses (INPUT_PULLUP), added fully working display messages for all 3 states: **GAME_START**, **WAITING_FOR_PLAYER_CHOICE**, **SHOW_RESULT**. <br/>
--**v4.0(ALPHA)** - All bugs fixed, fixed and improved screen messages, added LEDs functions for **rock**, **paper**, **scissors** and **START** button, fixed soldiering issues and some short circuits, put everything inside of the box.<br/>

# -To-Do:
--Merge code for the speaker and music with the current code. <br/>
--Fix speaker amplifier. <br/>

### ALPHA code launched.
