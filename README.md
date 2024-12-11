# Candy-Crush-Clone

## **How To Play?**  
   - Download all the files in a single folder on Ubuntu.  
   - Open your terminal in that designated folder.  
   - Run the following commands:  
     ```bash
     sudo apt-get update
     sudo apt-get install libsfml-dev
     g++ main1.cpp -o main1-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
     ./main1-app
     ```

## **Functionalities Implemented**  
   1. **Tile Swapping**:  
      - Players can swap adjacent tiles to create matches of three or more tiles of the same kind.  
      - A swap will only occur if it results in a valid match.  

   2. **Match Detection**:  
      - The game detects matches of three or more tiles in a row or column.  
      - Matching tiles are removed from the grid.  

   3. **Tile Dropping**:  
      - After a match, tiles above the empty spaces drop down to fill the gaps.  
      - New tiles are generated to fill the top rows of the grid.  

   4. **Score Tracking**:  
      - The game tracks the player's score based on the number of matches made.  
      - Each match increases the score by a defined amount.  

   5. **Move Counter**:  
      - The game limits the number of moves a player can make (20 moves).  
      - The game ends when the move counter reaches zero.  

   6. **Time Limit**:  
      - The game also has a time limit of 60 seconds.  
      - The game ends when the timer runs out.  

   7. **Background Music**:  
      - Background music plays during the game.  
      - The music loops and can be adjusted for volume and pitch.  

   8. **Graphical Interface**:  
      - The game features a graphical interface using SFML.  
      - The game grid, tiles, and background are rendered with textures.  

   9. **Game Initialization**:  
      - The grid is initialized with random tiles at the start of the game.  

   10. **Resource Management**:  
       - Textures and music are loaded from files and managed efficiently.  

Enjoy :)

https://github.com/user-attachments/assets/5694670c-8016-48c3-ac13-9009d60c59cd
