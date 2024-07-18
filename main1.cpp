#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

int ts = 54; //tile size
Vector2i offset(48, 24);

struct piece //used to position the tiles when updating
{
    int x, y, row, col, kind, match, alpha;
    piece() { match = 0; alpha = 255; }
} grid[10][10];

void swap(piece p1, piece p2) //used in swapping one tile with another to create a match
{
    swap(p1.col, p2.col);
    swap(p1.row, p2.row);

    grid[p1.row][p1.col] = p1;
    grid[p2.row][p2.col] = p2;
}

int main()
{
    srand(time(0));
    Clock clock;
    int mcounter = 0; //moves counter
    int scounter = 0; //score counter
    float second = 0; //time counter
    int hcounter = 1160; //highscore counter

    RenderWindow app(VideoMode(740, 480), "");
    app.setFramerateLimit(60);

    Texture t1, t2, t3;
    t1.loadFromFile("sprites/back.png");
    t2.loadFromFile("sprites/tiles.png");
    t3.loadFromFile("sprites/cursor.png");

    Font font, myfont;
    Text txt1, txt2, txt3, txt4, txt5, txt6, txt7, txt8, txt9, txt10, txt11;

    Sprite background(t1), gems(t2);

    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            grid[i][j].kind = rand() % 7; //For only one new piece
            grid[i][j].row = i; //displays rows in the grid
            grid[i][j].col = j; //displays columns in the grid
            grid[i][j].x = j * ts; //The tiles stay in place after a match because of this
            grid[i][j].y = i * ts;
        }

    int x, y, x0, y0;
    int click = 0;
    Vector2i pos;
    bool isSwap = false;
    bool isMoving = false;

    Music music; //Adding Music
    if (!music.openFromFile("music.ogg"))
    {
        cout << "ME";
    }

    music.setPosition(0, 1, 7); //Timeframe
    music.setPitch(1.2); //Playing speed
    music.setVolume(1000); //Volume of the music
    music.setLoop(true);

    music.play();

    while (app.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); //Timer for the time mode of the game
        clock.restart();
        second += time;
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();

            if (e.type == Event::MouseButtonPressed) //code of action to be performed on mouse click
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (!isSwap && !isMoving)
                    {
                        click++;
                    }
                    pos = Mouse::getPosition(app) - offset;
                }
        }

        if (second >= 60 || mcounter >= 20) //Time Controlled Mode
        {
            RenderWindow menu(VideoMode(740, 480), "GAME OVER");
            menu.setFramerateLimit(60);

            if (!myfont.loadFromFile("roman.ttf"))
            {
                cout << "HD";
            }
            txt3.setFont(myfont);
            txt3.setString("GAME OVER !!!"); //GameOver Heading
            txt3.setCharacterSize(40);
            txt3.setFillColor(Color::Red);
            txt3.setPosition(250, 130);

            stringstream ss; //Score Counter
            ss << scounter;
            txt8.setFont(myfont);
            txt8.setString(ss.str());
            txt8.setCharacterSize(25);
            txt8.setFillColor(Color::White);
            txt8.setPosition(365, 200);

            txt9.setFont(font); //Score Heading
            txt9.setString("SCORE:");
            txt9.setCharacterSize(25);
            txt9.setFillColor(Color::White);
            txt9.setPosition(250, 200);

            txt10.setFont(font); //Highscore Heading
            txt10.setString("HIGHSCORE:");
            txt10.setCharacterSize(25);
            txt10.setFillColor(Color::White);
            txt10.setPosition(250, 240);

            if (hcounter <= scounter)
            {
                hcounter = scounter;
            }

            stringstream hh; //Highscore Counter
            hh << hcounter;
            txt11.setFont(myfont);
            txt11.setString(hh.str());
            txt11.setCharacterSize(25);
            txt11.setFillColor(Color::White);
            txt11.setPosition(440, 240);

            while (menu.isOpen())
            {
                Event e1;
                while (app.pollEvent(e1))
                {
                    if (e1.type == Event::Closed)
                        menu.close();
                }

                menu.draw(txt3);
                menu.draw(txt8);
                menu.draw(txt9);
                menu.draw(txt10);
                menu.draw(txt11);
                menu.display();
            }

            app.draw(txt3);
            app.draw(txt8);
            app.draw(txt9);
            app.draw(txt10);
            app.draw(txt11);
            app.close();
        }

        //Adding font for Output

        if (!myfont.loadFromFile("roman.ttf"))
            cout << "HD";

        if (!font.loadFromFile("arial.ttf"))
            cout << "MH";

        stringstream ss; //Score Counter
        ss << scounter;
        txt1.setFont(myfont);
        txt1.setString(ss.str());
        txt1.setCharacterSize(25);
        txt1.setFillColor(Color::White);
        txt1.setPosition(595, 150);

        txt5.setFont(font); //Score Heading
        txt5.setString("SCORE");
        txt5.setCharacterSize(25);
        txt5.setFillColor(Color::White);
        txt5.setPosition(565, 120);

        stringstream mm; //Moves Counter
        mm << mcounter;
        txt2.setFont(myfont);
        txt2.setString(mm.str());
        txt2.setCharacterSize(25);
        txt2.setFillColor(Color::White);
        txt2.setPosition(605, 250);

        txt6.setFont(font); //Moves Heading
        txt6.setString("MOVES");
        txt6.setCharacterSize(25);
        txt6.setFillColor(Color::White);
        txt6.setPosition(565, 220);

        stringstream tt; //Time Counter
        tt << second;
        txt4.setFont(myfont);
        txt4.setString(tt.str());
        txt4.setCharacterSize(25);
        txt4.setFillColor(Color::White);
        txt4.setPosition(570, 340);

        txt7.setFont(font); //Time Heading
        txt7.setString("TIME");
        txt7.setCharacterSize(25);
        txt7.setFillColor(Color::White);
        txt7.setPosition(575, 310);

        //Mouse Click
        if (click == 1)
        {
            x0 = pos.x / ts + 1; //recognizes the first click and allows tile swapping in row-wise order
            y0 = pos.y / ts + 1; //recognizes the first click and allows tile swapping in column-wise order
        }

        if (click == 2)
        {
            x = pos.x / ts + 1; //the 2nd click and allows tile swapping with 1st click
            y = pos.y / ts + 1; //by using swap function

            if (abs(x - x0) + abs(y - y0) == 1)
            {
                swap(grid[y0][x0], grid[y][x]); //passes the 2d array values of grid to swap function
                isSwap = 1; //to swap the tile of 1st click and 2nd click
                click = 0;
                mcounter += 1; //counts total moves
            }
            else
            {
                click = 1;
            }
        }

        //Identifying Same Block
        for (int i = 1; i <= 8; i++)
            for (int j = 1; j <= 8; j++) //all this code does is that it use the "kind" function to first check
            { //if the i+1 & i-1 tiles are same as i then "match" function matches them.
                if (grid[i][j].kind == grid[i + 1][j].kind)
                    if (grid[i][j].kind == grid[i - 1][j].kind)
                        for (int n = -1; n <= 1; n++)
                        {
                            grid[i + n][j].match++; //row +1 & -1
                        }

                if (grid[i][j].kind == grid[i][j + 1].kind)
                    if (grid[i][j].kind == grid[i][j - 1].kind)
                        for (int n = -1; n <= 1; n++)
                        {
                            grid[i][j + n].match++; //col +1 & -1
                        }
            }

        //Moving Animation
        isMoving = false;
        for (int i = 1; i <= 8; i++)
            for (int j = 1; j <= 8; j++)
            {
                piece &p = grid[i][j]; //gives the location of the [i][j] tile which is used later
                int dx, dy; // in the animation part

                for (int n = 0; n < 4; n++) //4 - speed
                {
                    dx = p.x - p.col * ts; //multiplying by tile size (ts=54) to make the tiles appear on whole
                    dy = p.y - p.row * ts; //area and animating using formulas

                    if (dx)
                    {
                        p.x -= dx / abs(dx); //formula to animate the grid in terms of rows
                    }
                    if (dy)
                    {
                        p.y -= dy / abs(dy); //formula to animate the grid in terms of rows
                    }
                }

                if (dx || dy)
                {
                    isMoving = 1;
                }
            }

        //Deleting Animation
        if (!isMoving)
        {
            for (int i = 1; i <= 8; i++)
            {
                for (int j = 1; j <= 8; j++)
                {
                    if (grid[i][j].match)
                    {
                        if (grid[i][j].alpha > 10)
                        {
                            grid[i][j].alpha -= 10; //control for erasing tiles when matched
                            isMoving = true;
                        }
                    }
                }
            }
        }

        //Score
        int score = 0;
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                score += grid[i][j].match;
            }
        }

        //No Match
        if (isSwap && !isMoving)
        {
            if (!score)
            {
                swap(grid[y0][x0], grid[y][x]); //if tiles don't match by the swap function then
                isSwap = 0; // the isSwap changes to 0(false) and the tiles
            } //don't get erased
        }

        //Update Grid
        if (!isMoving) //check if the isMoving BOOL is false
        {
            for (int i = 8; i > 0; i--) //updates grid from the last row, so that there is symmetry
            {
                for (int j = 1; j <= 8; j++)
                {
                    if (grid[i][j].match)
                    {
                        for (int n = i; n > 0; n--)
                        {
                            if (!grid[n][j].match)
                            {
                                swap(grid[n][j], grid[i][j]);
                            }
                        }
                    }
                }
            }

            for (int j = 1; j <= 8; j++)
            {
                for (int i = 8, n = 0; i > 0; i--)
                {
                    if (grid[i][j].match)
                    {
                        scounter += 10; //Calculating score
                        grid[i][j].kind = rand() % 7; //same as used in the beginning, only this time we used
                        grid[i][j].y = -ts * n++; // %7 instead of %3 with rand so that the game shuffles
                        grid[i][j].match = 0; // better as we progress
                        grid[i][j].alpha = 255;
                    }
                }
            }
        }

        //Drawing function
        app.draw(background);

        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                piece p = grid[i][j];
                gems.setTextureRect(IntRect(p.kind * 49, 0, 49, 49));
                gems.setColor(Color(255, 255, 255, p.alpha));
                gems.setPosition(p.x, p.y);
                gems.move(offset.x - ts, offset.y - ts);
                app.draw(gems);
            }
        }

        app.draw(txt1);
        app.draw(txt2);
        app.draw(txt4);
        app.draw(txt5);
        app.draw(txt6);
        app.draw(txt7);

        app.display();
    }
    return 0;
}

