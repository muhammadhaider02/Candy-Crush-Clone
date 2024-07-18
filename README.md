# Candy-Crush-Clone

**How To Play?**  <br>
Download all the files in a single folder on Ubntu  <br>
Open your terminal is that designated folder  <br>

**Run following commands:**  <br>
sudo apt-get update  <br>
sudo apt-get install libsfml-dev  <br>
g++ main1.cpp -o main1-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  <br>
./main1-app  <br>

**Functionalities Implemented:**  <br>
**1. Tile Swapping:**  <br>
Players can swap adjacent tiles to create matches of three or more tiles of the same kind.  <br>
A swap will only occur if it results in a valid match.  <br>

**2. Match Detection:**  <br>
The game detects matches of three or more tiles in a row or column.  <br>
Matching tiles are removed from the grid.  <br>

**3. Tile Dropping:**  <br>
After a match, tiles above the empty spaces drop down to fill the gaps.  <br>
New tiles are generated to fill the top rows of the grid.  <br>

**4. Score Tracking:**  <br>
The game tracks the player's score based on the number of matches made.  <br>
Each match increases the score by a defined amount.  <br>

**5. Move Counter:**  <br>
The game limits the number of moves a player can make (20 moves).  <br>
The game ends when the move counter reaches zero.  <br>

**6. Time Limit:**  <br>
The game also has a time limit of 60 seconds.  <br>
The game ends when the timer runs out.  <br>

**7. Background Music:**  <br>
Background music plays during the game.  <br>
The music loops and can be adjusted for volume and pitch.  <br>

**8. Graphical Interface:**  <br>
The game features a graphical interface using SFML.  <br>
The game grid, tiles, and background are rendered with textures.  <br>

**9. Game Initialization:**  <br>
The grid is initialized with random tiles at the start of the game.  <br>

**10. Resource Management:**  <br>
Textures and music are loaded from files and managed efficiently.  <br>

**Note:**  <br>
The game was developed for the sole purpose of entertainment.  <br>
With current settings, the game would end after 60 seconds or 20 moves.  <br>

**Enjoy :)**
