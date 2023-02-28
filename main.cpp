#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace sf;
using namespace std;

int main()
{
    srand(time(0));

    int playerY = 465;
    float x = 1100;
    bool intro = false;
    bool jump = false;
    bool gameOver = false;
    int direct = rand()%2;
    int arrowY = 465;
    int speed = 10;
    int score = 0;
    string gameScore = "";


    RenderWindow app(VideoMode(1100, 600), "Humble Tree");
    app.setFramerateLimit(60);

    Texture t1,t2,t3,t4,t5;
    t1.loadFromFile("images/bg.jpg");
    t2.loadFromFile("images/arrow.png");
    t3.loadFromFile("images/cartoon.png");
    t4.loadFromFile("images/gameover.png");
    t5.loadFromFile("images/intro.png");

    Sprite sBackground(t1), sArrow(t2), sPers(t3), sOver(t4), sIntro(t5);

    Font gameFont;
    gameFont.loadFromFile("font/game.ttf");

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }
    if(!gameOver && intro)
    {

        if(jump)
        {
            playerY+=300;
            jump = false;
        }
        if(x > - 20 )
        {
            x -= speed + 0.3 * score;
        }
        else
        {
            direct = rand()%2;
            x = 1100;
            score++;
            if(direct)  arrowY = 465;
            else    arrowY = 165;
        }
        if(Keyboard::isKeyPressed(Keyboard::Up) && jump == false)    jump = true;
        if(jump)
        {
            playerY-=300;
        }
    }
        if(x <= 180 && x >= 100 && playerY == arrowY)     gameOver = true;

    app.draw(sBackground);

    gameScore = "SCORE:" + to_string(score);
    Text gameText(gameScore, gameFont, 30);
    gameText.setPosition(940,550);

    if (!intro)
    {
        sIntro.setPosition(300, 180);
        app.draw(sIntro);
        if(Keyboard::isKeyPressed(Keyboard::Space))  intro = true;
    }
    else if(gameOver)
    {
        sOver.setPosition(380, 220);
        app.draw(sOver);
        app.draw(gameText);
    }
    else
    {
        sPers.setPosition(100,playerY);
        sArrow.setPosition(x,arrowY);
        app.draw(sArrow);
        app.draw(sPers);
        app.draw(gameText);
    }
    app.display();

    }

}


