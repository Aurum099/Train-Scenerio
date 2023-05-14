#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
#include<cstdio>
using namespace std;

bool cover = true;
bool dayNight = false;
bool rainday = false;
float rain = 0.0;


//TEXT

const int font=(int)GLUT_BITMAP_HELVETICA_18 ;



void renderBitmapString(float x, float y, void *font,const char *str)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=str; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}







void setColor(string col)
{
    //day
    if(dayNight)
    {
        if(col == "background") glColor3ub (23, 201, 205);
        else if(col == "darkBlue") glColor3ub (0, 84, 120);
        else if(col == "navyBlue") glColor3ub (0, 66, 101);
        else if(col == "lightGreen") glColor3ub (122, 250, 137);
        else if(col == "darkGreen") glColor3ub (0, 146, 143);
        else if(col == "white") glColor3ub (255, 255, 255);
        else if(col == "window") glColor3ub (255, 255, 255);
        else if(col == "mediumGreen") glColor3ub (10, 176, 128);
        else if(col == "teal") glColor3ub (21, 177, 189);
        else if(col == "trainBody") glColor3ub (252, 195, 109);
        else if(col == "trainBodyDark") glColor3ub (227, 177, 102);
        else if(col == "trainBodyStripe") glColor3ub (255, 222, 173);
        else if(col == "darkerGreen") glColor3ub (10, 176, 128);
        else if(col == "blue") glColor3ub (0, 122, 171);
        else if(col == "sun") glColor3ub (246, 247, 193);
        else if(col == "rain") glColor3ub(255, 255, 255);
        else if(col == "humanSkin") glColor3ub(240, 215, 184);
        else if(col == "humanDetail") glColor3ub(59, 77, 87);
        else if(col == "humanPrimary") glColor3ub(192, 188, 99);
        else if(col == "humanSecondary") glColor3ub(119, 80, 51);
        else if(col == "humanSkinTrans") glColor3ub(77, 114, 128);
        else if(col == "humanDetailTrans") glColor3ub(19, 69, 95);

        else
        {
            cout<<"INVALID COLOR CODE: "<<col<<"\n";
            glColor3ub (0,0,0);
        }

    }
    //night
    else
    {
        if(col == "background") glColor3ub (106, 83, 77);
        else if(col == "darkBlue") glColor3ub (44, 37, 45);
        else if(col == "navyBlue") glColor3ub (37, 31, 31);
        else if(col == "lightGreen") glColor3ub (145, 95, 60);
        else if(col == "darkGreen") glColor3ub (58, 51, 45);
        else if(col == "white") glColor3ub (230, 120, 105);
        else if(col == "window") glColor3ub (247, 242, 171);
        else if(col == "mediumGreen") glColor3ub (83, 70, 53);
        else if(col == "teal") glColor3ub (95, 74, 71);
        else if(col == "trainBody") glColor3ub (201, 93, 64);
        else if(col == "trainBodyDark") glColor3ub (201, 93, 64);
        else if(col == "trainBodyStripe") glColor3ub (221, 106, 85);
        else if(col == "darkerGreen") glColor3ub (94, 76, 52);
        else if(col == "blue") glColor3ub (62, 52, 60);
        else if(col == "sun") glColor3ub (225, 115, 90);
        else if(col == "rain") glColor3ub(255, 255, 255);
        else if(col == "humanSkin") glColor3ub(211, 110, 91);
        else if(col == "humanDetail") glColor3ub(63, 38, 38);
        else if(col == "humanPrimary") glColor3ub(172, 94, 60);
        else if(col == "humanSecondary") glColor3ub(92, 42, 29);
        else if(col == "humanSkinTrans") glColor3ub(102, 90, 81);
        else if(col == "humanDetailTrans") glColor3ub(44, 46, 49);
        else
        {
            cout<<"INVALID COLOR CODE: "<<col<<"\n";
            glColor3ub (0,0,0);
        }
    }
}

//animate train
float trainSpeed = 0;
float trainPosition = 1400;
float trainFaceSpeed = 0;
float trainFacePosition = 1440;

//animate clouds
float cloud1Position = 250;
float cloud2Position = 210;
float cloud3Position = 1100;

float cloud1Speed = 1.0;
float cloud2Speed = 2.5;
float cloud3Speed = 2.0;


void drawCover()
{
    if(cover)
    {
        setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1280,0);
    glVertex2i(1280,620);
    glVertex2i(0,620);
    glEnd();

    setColor("white");
    renderBitmapString(400,400,(void *)font,"Minimalistic Train Scenerio");
    renderBitmapString(400,400-30,(void *)font,"Press C: To Open or Close Scenario");
    renderBitmapString(400,400-60,(void *)font,"Press X: To Start the Train");
    renderBitmapString(400,400-90,(void *)font,"Press R: To Stop the Train");
    renderBitmapString(400,400-120,(void *)font,"Press W: To Speed Up the Train");
    renderBitmapString(400,400-150,(void *)font,"Press S: To Speed Down the Train");
    renderBitmapString(400,400-180,(void *)font,"Press Q: To Make it Rain");
    renderBitmapString(400,400-210,(void *)font,"Press E: To Stop Rain");
    renderBitmapString(400,400-240,(void *)font,"Press T: To Toggle Between Day/Night");

    }

}

void drawBackground()
{
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1280,0);
    glVertex2i(1280,620);
    glVertex2i(0,620);
    glEnd();
}

void drawTrain()
{


    glPushMatrix();
    glTranslatef(trainPosition,-270, 0);
    glScalef(2.2,2.2,1);







    //main body
    setColor("trainBody");
    glBegin(GL_QUADS);
    glVertex2i(0,170);
    glVertex2i(440,170);
    glVertex2i(440,210);
    glVertex2i(0,210);
    glEnd();

    //upperLine main body
    setColor("trainBody");
    glBegin(GL_QUADS);
    glVertex2i(5,210);
    glVertex2i(435,210);
    glVertex2i(435,215);
    glVertex2i(5,215);
    glEnd();

    setColor("trainBody");
    glBegin(GL_QUADS);
    glVertex2i(5,210);
    glVertex2i(35,210);
    glVertex2i(35,215);
    glVertex2i(5,215);
    glEnd();



    //face
    setColor("trainBodyDark");
    glBegin(GL_QUADS);
    glVertex2i(0,170);
    glVertex2i(40,170);
    glVertex2i(40,205);
    glVertex2i(0,205);
    glEnd();

    //face stripe
    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(0,175);
    glVertex2i(40,175);
    glVertex2i(40,180);
    glVertex2i(0,180);
    glEnd();


    //lights
    if (dayNight) setColor("navyBlue");
    else setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(5,175);
    glVertex2i(10,175);
    glVertex2i(10,185);
    glVertex2i(5,185);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(30,175);
    glVertex2i(35,175);
    glVertex2i(35,185);
    glVertex2i(30,185);
    glEnd();

    //frontWindow
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(5,190);
    glVertex2i(35,190);
    glVertex2i(35,205);
    glVertex2i(5,205);
    glEnd();

    //long stripes
    //up
    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(40,205);
    glVertex2i(440,205);
    glVertex2i(440,210);
    glVertex2i(40,210);
    glEnd();


    //down
    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(40,175);
    glVertex2i(65,175);
    glVertex2i(65,180);
    glVertex2i(40,180);
    glEnd();

    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(100,175);
    glVertex2i(200,175);
    glVertex2i(200,180);
    glVertex2i(100,180);
    glEnd();

    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(235,175);
    glVertex2i(335,175);
    glVertex2i(335,180);
    glVertex2i(235,180);
    glEnd();

    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(370,175);
    glVertex2i(440,175);
    glVertex2i(440,180);
    glVertex2i(370,180);
    glEnd();



    //train windows and door component(1)
    //window
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(55,185);
    glVertex2i(65,185);
    glVertex2i(65,200);
    glVertex2i(55,200);
    glEnd();

    //doors
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(70,170);
    glVertex2i(80,170);
    glVertex2i(80,200);
    glVertex2i(70,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(85,170);
    glVertex2i(95,170);
    glVertex2i(95,200);
    glVertex2i(85,200);
    glEnd();
    //end doors

    //more windows
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(100,185);
    glVertex2i(110,185);
    glVertex2i(110,200);
    glVertex2i(100,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(115,185);
    glVertex2i(125,185);
    glVertex2i(125,200);
    glVertex2i(115,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(130,185);
    glVertex2i(140,185);
    glVertex2i(140,200);
    glVertex2i(130,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(145,185);
    glVertex2i(155,185);
    glVertex2i(155,200);
    glVertex2i(145,200);
    glEnd();
    //end of window + doors component(1)

    //train windows and door component(2)
    //window
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(185,185);
    glVertex2i(195,185);
    glVertex2i(195,200);
    glVertex2i(185,200);
    glEnd();

    //doors
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(200,170);
    glVertex2i(210,170);
    glVertex2i(210,200);
    glVertex2i(200,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(215,170);
    glVertex2i(225,170);
    glVertex2i(225,200);
    glVertex2i(215,200);
    glEnd();
    //end doors

    //more windows
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(230,185);
    glVertex2i(240,185);
    glVertex2i(240,200);
    glVertex2i(230,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(245,185);
    glVertex2i(255,185);
    glVertex2i(255,200);
    glVertex2i(245,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(260,185);
    glVertex2i(270,185);
    glVertex2i(270,200);
    glVertex2i(260,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(275,185);
    glVertex2i(285,185);
    glVertex2i(285,200);
    glVertex2i(275,200);
    glEnd();
    //end of window + doors component(2)

    //train windows and door component(3)
    //window
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(325,185);
    glVertex2i(335,185);
    glVertex2i(335,200);
    glVertex2i(325,200);
    glEnd();

    //doors
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(340,170);
    glVertex2i(350,170);
    glVertex2i(350,200);
    glVertex2i(340,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(355,170);
    glVertex2i(365,170);
    glVertex2i(365,200);
    glVertex2i(355,200);
    glEnd();
    //end doors

    //more windows
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(370,185);
    glVertex2i(380,185);
    glVertex2i(380,200);
    glVertex2i(370,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(385,185);
    glVertex2i(395,185);
    glVertex2i(395,200);
    glVertex2i(385,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(400,185);
    glVertex2i(410,185);
    glVertex2i(410,200);
    glVertex2i(400,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(415,185);
    glVertex2i(425,185);
    glVertex2i(425,200);
    glVertex2i(415,200);
    glEnd();
    //end of window + doors component(3)




    glPopMatrix();
}


void drawHumanOne(){
    //start human

    glPushMatrix();
    glTranslatef(145,145,0);
    glScalef(0.4,0.4,1);

    //frame
    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(0,30);
    glVertex2i(70,30);
    glVertex2i(70,55);
    glVertex2i(0,55);
    glEnd();

    //head
    setColor("humanSkin");
    glBegin(GL_QUADS);
    glVertex2i(10,0);
    glVertex2i(60,0);
    glVertex2i(60,55);
    glVertex2i(10,55);
    glEnd();

    //head extension
    setColor("humanSkin");
    glBegin(GL_QUADS);
    glVertex2i(0,30);
    glVertex2i(70,30);
    glVertex2i(70,40);
    glVertex2i(0,40);
    glEnd();


    //eyes

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(20,30);
    glVertex2i(30,30);
    glVertex2i(30,40);
    glVertex2i(20,40);
    glEnd();

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(40,30);
    glVertex2i(50,30);
    glVertex2i(50,40);
    glVertex2i(40,40);
    glEnd();

    //mouth
    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(20,10);
    glVertex2i(50,10);
    glVertex2i(50,20);
    glVertex2i(20,20);
    glEnd();


    //hair
    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(10,55);
    glVertex2i(60,55);
    glVertex2i(60,65);
    glVertex2i(10,65);
    glEnd();

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(40,65);
    glVertex2i(60,65);
    glVertex2i(60,75);
    glVertex2i(40,75);
    glEnd();

    //start of body



    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(20,-10);
    glVertex2i(50,-10);
    glVertex2i(50,0);
    glVertex2i(20,0);
    glEnd();

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(-10,-80);
    glVertex2i(70,-80);
    glVertex2i(70,-10);
    glVertex2i(-10,-10);
    glEnd();








    glPopMatrix();
    //end of human
}


void drawHumanTwo(){
    //start human

    glPushMatrix();
    glTranslatef(95,140,0);
    glScalef(0.4,0.4,1);

    //frame
    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(0,10);
    glVertex2i(70,10);
    glVertex2i(70,55);
    glVertex2i(0,55);
    glEnd();

    //head
    setColor("humanSkin");
    glBegin(GL_QUADS);
    glVertex2i(10,0);
    glVertex2i(60,0);
    glVertex2i(60,55);
    glVertex2i(10,55);
    glEnd();

    //head extension
    setColor("humanSkin");
    glBegin(GL_QUADS);
    glVertex2i(10,30);
    glVertex2i(60,30);
    glVertex2i(60,40);
    glVertex2i(10,40);
    glEnd();


    //eyes

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(20,30);
    glVertex2i(30,30);
    glVertex2i(30,40);
    glVertex2i(20,40);
    glEnd();

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(40,30);
    glVertex2i(50,30);
    glVertex2i(50,40);
    glVertex2i(40,40);
    glEnd();

    //mouth
    setColor("humanSecondary");
    glBegin(GL_QUADS);
    glVertex2i(30,10);
    glVertex2i(40,10);
    glVertex2i(40,20);
    glVertex2i(30,20);
    glEnd();


    //hair
    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(10,55);
    glVertex2i(60,55);
    glVertex2i(60,65);
    glVertex2i(10,65);
    glEnd();

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(30,65);
    glVertex2i(50,65);
    glVertex2i(50,75);
    glVertex2i(30,75);
    glEnd();

    //start of body



    setColor("humanPrimary");
    glBegin(GL_QUADS);
    glVertex2i(20,-10);
    glVertex2i(50,-10);
    glVertex2i(50,0);
    glVertex2i(20,0);
    glEnd();

    setColor("humanPrimary");
    glBegin(GL_QUADS);
    glVertex2i(-10,-80);
    glVertex2i(70,-80);
    glVertex2i(70,-10);
    glVertex2i(-10,-10);
    glEnd();








    glPopMatrix();
    //end of human
}


void drawHumanThree(){
    //start human

    glPushMatrix();
    glTranslatef(35,145,0);
    glScalef(0.4,0.4,1);

    //frame
    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(0,10);
    glVertex2i(70,10);
    glVertex2i(70,55);
    glVertex2i(0,55);
    glEnd();

    //head
    setColor("humanSkin");
    glBegin(GL_QUADS);
    glVertex2i(10,0);
    glVertex2i(60,0);
    glVertex2i(60,55);
    glVertex2i(10,55);
    glEnd();

    //head extension
    setColor("humanSkin");
    glBegin(GL_QUADS);
    glVertex2i(0,30);
    glVertex2i(70,30);
    glVertex2i(70,40);
    glVertex2i(0,40);
    glEnd();


    //eyes

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(20,30);
    glVertex2i(30,30);
    glVertex2i(30,40);
    glVertex2i(20,40);
    glEnd();

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(40,30);
    glVertex2i(50,30);
    glVertex2i(50,40);
    glVertex2i(40,40);
    glEnd();

    //mouth
    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(20,10);
    glVertex2i(50,10);
    glVertex2i(50,20);
    glVertex2i(20,20);
    glEnd();


    //hair
    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(10,55);
    glVertex2i(60,55);
    glVertex2i(60,65);
    glVertex2i(10,65);
    glEnd();

    setColor("humanDetail");
    glBegin(GL_QUADS);
    glVertex2i(20,65);
    glVertex2i(60,65);
    glVertex2i(60,75);
    glVertex2i(20,75);
    glEnd();

    //start of body



    setColor("humanSecondary");
    glBegin(GL_QUADS);
    glVertex2i(20,-10);
    glVertex2i(50,-10);
    glVertex2i(50,0);
    glVertex2i(20,0);
    glEnd();

    setColor("humanSecondary");
    glBegin(GL_QUADS);
    glVertex2i(-10,-80);
    glVertex2i(70,-80);
    glVertex2i(70,-10);
    glVertex2i(-10,-10);
    glEnd();








    glPopMatrix();
    //end of human
}







void drawTrainHuman(){

     //start human

    glPushMatrix();
    glTranslatef(trainFacePosition,150,0);
    glScalef(0.4,0.4,1);


    setColor("humanDetailTrans");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(70,0);
    glVertex2i(70,55);
    glVertex2i(0,55);
    glEnd();

    setColor("humanSkinTrans");
    glBegin(GL_QUADS);
    glVertex2i(10,0);
    glVertex2i(60,0);
    glVertex2i(60,55);
    glVertex2i(10,55);
    glEnd();


    setColor("humanSkinTrans");
    glBegin(GL_QUADS);
    glVertex2i(0,30);
    glVertex2i(70,30);
    glVertex2i(70,40);
    glVertex2i(0,40);
    glEnd();


    //eyes

    setColor("humanDetailTrans");
    glBegin(GL_QUADS);
    glVertex2i(20,30);
    glVertex2i(30,30);
    glVertex2i(30,40);
    glVertex2i(20,40);
    glEnd();

    setColor("humanDetailTrans");
    glBegin(GL_QUADS);
    glVertex2i(40,30);
    glVertex2i(50,30);
    glVertex2i(50,40);
    glVertex2i(40,40);
    glEnd();

    //mouth
    setColor("humanDetailTrans");
    glBegin(GL_QUADS);
    glVertex2i(20,10);
    glVertex2i(50,10);
    glVertex2i(50,20);
    glVertex2i(20,20);
    glEnd();


    //hair
    setColor("humanDetailTrans");
    glBegin(GL_QUADS);
    glVertex2i(10,55);
    glVertex2i(60,55);
    glVertex2i(60,65);
    glVertex2i(10,65);
    glEnd();

    setColor("humanDetailTrans");
    glBegin(GL_QUADS);
    glVertex2i(10,65);
    glVertex2i(50,65);
    glVertex2i(50,75);
    glVertex2i(10,75);
    glEnd();




    glPopMatrix();
    //end of human

}
void drawLeftBuilding()
{

    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(0,120);
    glVertex2i(140,120);
    glVertex2i(140,415);
    glVertex2i(0,415);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,120);
    glVertex2i(435,120);
    glVertex2i(435,135);
    glVertex2i(140,135);
    glEnd();
    //
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,135);
    glVertex2i(165,135);
    glVertex2i(165,165);
    glVertex2i(140,165);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(165,135);
    glVertex2i(185,135);
    glVertex2i(185,165);
    glVertex2i(165,165);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(185,135);
    glVertex2i(210,135);
    glVertex2i(210,165);
    glVertex2i(185,165);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(210,135);
    glVertex2i(230,135);
    glVertex2i(230,165);
    glVertex2i(210,165);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(230,135);
    glVertex2i(255,135);
    glVertex2i(255,165);
    glVertex2i(230,165);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(255,135);
    glVertex2i(275,135);
    glVertex2i(275,165);
    glVertex2i(255,165);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(275,135);
    glVertex2i(300,135);
    glVertex2i(300,165);
    glVertex2i(275,165);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(300,135);
    glVertex2i(320,135);
    glVertex2i(320,165);
    glVertex2i(300,165);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(320,135);
    glVertex2i(345,135);
    glVertex2i(345,165);
    glVertex2i(320,165);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(345,135);
    glVertex2i(365,135);
    glVertex2i(365,165);
    glVertex2i(345,165);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(365,135);
    glVertex2i(390,135);
    glVertex2i(390,165);
    glVertex2i(365,165);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(390,135);
    glVertex2i(410,135);
    glVertex2i(410,165);
    glVertex2i(390,165);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(410,135);
    glVertex2i(435,135);
    glVertex2i(435,165);
    glVertex2i(410,165);
    glEnd();

    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,165);
    glVertex2i(435,165);
    glVertex2i(435,180);
    glVertex2i(140,180);
    glEnd();
    //
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,180);
    glVertex2i(165,180);
    glVertex2i(165,210);
    glVertex2i(140,210);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(165,180);
    glVertex2i(185,180);
    glVertex2i(185,210);
    glVertex2i(165,210);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(185,180);
    glVertex2i(210,180);
    glVertex2i(210,210);
    glVertex2i(185,210);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(210,180);
    glVertex2i(230,180);
    glVertex2i(230,210);
    glVertex2i(210,210);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(230,180);
    glVertex2i(255,180);
    glVertex2i(255,210);
    glVertex2i(230,210);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(255,180);
    glVertex2i(275,180);
    glVertex2i(275,210);
    glVertex2i(255,210);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(275,180);
    glVertex2i(300,180);
    glVertex2i(300,210);
    glVertex2i(275,210);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(300,180);
    glVertex2i(320,180);
    glVertex2i(320,210);
    glVertex2i(300,210);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(320,180);
    glVertex2i(345,180);
    glVertex2i(345,210);
    glVertex2i(320,210);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(345,180);
    glVertex2i(365,180);
    glVertex2i(365,210);
    glVertex2i(345,210);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(365,180);
    glVertex2i(390,180);
    glVertex2i(390,210);
    glVertex2i(365,210);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(390,180);
    glVertex2i(410,180);
    glVertex2i(410,210);
    glVertex2i(390,210);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(410,180);
    glVertex2i(435,180);
    glVertex2i(435,210);
    glVertex2i(410,210);
    glEnd();

    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,210);
    glVertex2i(435,210);
    glVertex2i(435,225);
    glVertex2i(140,225);
    glEnd();
    //
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,225);
    glVertex2i(165,225);
    glVertex2i(165,255);
    glVertex2i(140,255);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(165,225);
    glVertex2i(185,225);
    glVertex2i(185,255);
    glVertex2i(165,255);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(185,225);
    glVertex2i(210,225);
    glVertex2i(210,255);
    glVertex2i(185,255);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(210,225);
    glVertex2i(230,225);
    glVertex2i(230,255);
    glVertex2i(210,255);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(230,225);
    glVertex2i(255,225);
    glVertex2i(255,255);
    glVertex2i(230,255);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(255,225);
    glVertex2i(275,225);
    glVertex2i(275,255);
    glVertex2i(255,255);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(275,225);
    glVertex2i(300,225);
    glVertex2i(300,255);
    glVertex2i(275,255);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(300,225);
    glVertex2i(320,225);
    glVertex2i(320,255);
    glVertex2i(300,255);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(320,225);
    glVertex2i(345,225);
    glVertex2i(345,255);
    glVertex2i(320,255);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(345,225);
    glVertex2i(365,225);
    glVertex2i(365,255);
    glVertex2i(345,255);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(365,225);
    glVertex2i(390,225);
    glVertex2i(390,255);
    glVertex2i(365,255);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(390,225);
    glVertex2i(410,225);
    glVertex2i(410,255);
    glVertex2i(390,255);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(410,225);
    glVertex2i(435,225);
    glVertex2i(435,255);
    glVertex2i(410,255);
    glEnd();

    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,255);
    glVertex2i(435,255);
    glVertex2i(435,270);
    glVertex2i(140,270);
    glEnd();
    //
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,270);
    glVertex2i(165,270);
    glVertex2i(165,300);
    glVertex2i(140,300);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(165,270);
    glVertex2i(185,270);
    glVertex2i(185,300);
    glVertex2i(165,300);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(185,270);
    glVertex2i(210,270);
    glVertex2i(210,300);
    glVertex2i(185,300);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(210,270);
    glVertex2i(230,270);
    glVertex2i(230,300);
    glVertex2i(210,300);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(230,270);
    glVertex2i(255,270);
    glVertex2i(255,300);
    glVertex2i(230,300);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(255,270);
    glVertex2i(275,270);
    glVertex2i(275,300);
    glVertex2i(255,300);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(275,270);
    glVertex2i(300,270);
    glVertex2i(300,300);
    glVertex2i(275,300);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(300,270);
    glVertex2i(320,270);
    glVertex2i(320,300);
    glVertex2i(300,300);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(320,270);
    glVertex2i(345,270);
    glVertex2i(345,300);
    glVertex2i(320,300);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(345,270);
    glVertex2i(365,270);
    glVertex2i(365,300);
    glVertex2i(345,300);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(365,270);
    glVertex2i(390,270);
    glVertex2i(390,300);
    glVertex2i(365,300);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(390,270);
    glVertex2i(410,270);
    glVertex2i(410,300);
    glVertex2i(390,300);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(410,270);
    glVertex2i(435,270);
    glVertex2i(435,300);
    glVertex2i(410,300);
    glEnd();

    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,300);
    glVertex2i(435,300);
    glVertex2i(435,315);
    glVertex2i(140,315);
    glEnd();
    //
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,315);
    glVertex2i(165,315);
    glVertex2i(165,345);
    glVertex2i(140,345);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(165,315);
    glVertex2i(185,315);
    glVertex2i(185,345);
    glVertex2i(165,345);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(185,315);
    glVertex2i(210,315);
    glVertex2i(210,345);
    glVertex2i(185,345);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(210,315);
    glVertex2i(230,315);
    glVertex2i(230,345);
    glVertex2i(210,345);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(230,315);
    glVertex2i(255,315);
    glVertex2i(255,345);
    glVertex2i(230,345);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(255,315);
    glVertex2i(275,315);
    glVertex2i(275,345);
    glVertex2i(255,345);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(275,315);
    glVertex2i(300,315);
    glVertex2i(300,345);
    glVertex2i(275,345);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(300,315);
    glVertex2i(320,315);
    glVertex2i(320,345);
    glVertex2i(300,345);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(320,315);
    glVertex2i(345,315);
    glVertex2i(345,345);
    glVertex2i(320,345);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(345,315);
    glVertex2i(365,315);
    glVertex2i(365,345);
    glVertex2i(345,345);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(365,315);
    glVertex2i(390,315);
    glVertex2i(390,345);
    glVertex2i(365,345);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(390,315);
    glVertex2i(410,315);
    glVertex2i(410,345);
    glVertex2i(390,345);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(410,315);
    glVertex2i(435,315);
    glVertex2i(435,345);
    glVertex2i(410,345);
    glEnd();

    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,345);
    glVertex2i(435,345);
    glVertex2i(435,360);
    glVertex2i(140,360);
    glEnd();
    //
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,360);
    glVertex2i(165,360);
    glVertex2i(165,390);
    glVertex2i(140,390);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(165,360);
    glVertex2i(185,360);
    glVertex2i(185,390);
    glVertex2i(165,390);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(185,360);
    glVertex2i(210,360);
    glVertex2i(210,390);
    glVertex2i(185,390);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(210,360);
    glVertex2i(230,360);
    glVertex2i(230,390);
    glVertex2i(210,390);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(230,360);
    glVertex2i(255,360);
    glVertex2i(255,390);
    glVertex2i(230,390);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(255,360);
    glVertex2i(275,360);
    glVertex2i(275,390);
    glVertex2i(255,390);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(275,360);
    glVertex2i(300,360);
    glVertex2i(300,390);
    glVertex2i(275,390);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(300,360);
    glVertex2i(320,360);
    glVertex2i(320,390);
    glVertex2i(300,390);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(320,360);
    glVertex2i(345,360);
    glVertex2i(345,390);
    glVertex2i(320,390);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(345,360);
    glVertex2i(365,360);
    glVertex2i(365,390);
    glVertex2i(345,390);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(365,360);
    glVertex2i(390,360);
    glVertex2i(390,390);
    glVertex2i(365,390);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(390,360);
    glVertex2i(410,360);
    glVertex2i(410,390);
    glVertex2i(390,390);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(410,360);
    glVertex2i(435,360);
    glVertex2i(435,390);
    glVertex2i(410,390);
    glEnd();

    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(140,390);
    glVertex2i(435,390);
    glVertex2i(435,405);
    glVertex2i(140,405);
    glEnd();

    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(140,405);
    glVertex2i(435,405);
    glVertex2i(435,415);
    glVertex2i(140,415);
    glEnd();

}

void drawMidBuilding2()
{
    glPushMatrix();
    glTranslatef(135,-35,0);

    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(500,120);
    glVertex2i(530,120);
    glVertex2i(530,280);
    glVertex2i(500,280);
    glEnd();

    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,120);
    glVertex2i(580,120);
    glVertex2i(580,135);
    glVertex2i(530,135);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,135);
    glVertex2i(545,135);
    glVertex2i(545,160);
    glVertex2i(530,160);
    glEnd();
    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,135);
    glVertex2i(565,135);
    glVertex2i(565,160);
    glVertex2i(545,160);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,135);
    glVertex2i(580,135);
    glVertex2i(580,160);
    glVertex2i(565,160);
    glEnd();

    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,160);
    glVertex2i(580,160);
    glVertex2i(580,175);
    glVertex2i(530,175);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,175);
    glVertex2i(545,175);
    glVertex2i(545,200);
    glVertex2i(530,200);
    glEnd();
    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,175);
    glVertex2i(565,175);
    glVertex2i(565,200);
    glVertex2i(545,200);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,175);
    glVertex2i(580,175);
    glVertex2i(580,200);
    glVertex2i(565,200);
    glEnd();

    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,200);
    glVertex2i(580,200);
    glVertex2i(580,215);
    glVertex2i(530,215);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,215);
    glVertex2i(545,215);
    glVertex2i(545,240);
    glVertex2i(530,240);
    glEnd();
    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,215);
    glVertex2i(565,215);
    glVertex2i(565,240);
    glVertex2i(545,240);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,215);
    glVertex2i(580,215);
    glVertex2i(580,240);
    glVertex2i(565,240);
    glEnd();

    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,240);
    glVertex2i(580,240);
    glVertex2i(580,250);
    glVertex2i(530,250);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,250);
    glVertex2i(545,250);
    glVertex2i(545,270);
    glVertex2i(530,270);
    glEnd();
    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,250);
    glVertex2i(565,250);
    glVertex2i(565,270);
    glVertex2i(545,270);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,250);
    glVertex2i(580,250);
    glVertex2i(580,270);
    glVertex2i(565,270);
    glEnd();
    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,270);
    glVertex2i(580,270);
    glVertex2i(580,280);
    glVertex2i(530,280);
    glEnd();

    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(580,120);
    glVertex2i(610,120);
    glVertex2i(610,280);
    glVertex2i(580,280);
    glEnd();

    setColor("darkerGreen");
    glBegin(GL_TRIANGLES);
    glVertex2i(500,280);
    glVertex2i(610,280);
    glVertex2i(555,345);
    glEnd();

    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(610,120);
    glVertex2i(755,120);
    glVertex2i(755,280);
    glVertex2i(610,280);
    glEnd();

    setColor("darkGreen");
    glBegin(GL_QUADS);
    glVertex2i(610,280);
    glVertex2i(755,280);
    glVertex2i(700,345);
    glVertex2i(555,345);
    glEnd();

    glPopMatrix();


}


void drawRightBuilding()
{
    glPushMatrix();
    glTranslatef(525,-60,0);
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(500,120);
    glVertex2i(530,120);
    glVertex2i(530,280);
    glVertex2i(500,280);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,120);
    glVertex2i(580,120);
    glVertex2i(580,135);
    glVertex2i(530,135);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,135);
    glVertex2i(545,135);
    glVertex2i(545,160);
    glVertex2i(530,160);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,135);
    glVertex2i(565,135);
    glVertex2i(565,160);
    glVertex2i(545,160);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,135);
    glVertex2i(580,135);
    glVertex2i(580,160);
    glVertex2i(565,160);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,160);
    glVertex2i(580,160);
    glVertex2i(580,175);
    glVertex2i(530,175);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,175);
    glVertex2i(545,175);
    glVertex2i(545,200);
    glVertex2i(530,200);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,175);
    glVertex2i(565,175);
    glVertex2i(565,200);
    glVertex2i(545,200);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,175);
    glVertex2i(580,175);
    glVertex2i(580,200);
    glVertex2i(565,200);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,200);
    glVertex2i(580,200);
    glVertex2i(580,215);
    glVertex2i(530,215);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,215);
    glVertex2i(545,215);
    glVertex2i(545,240);
    glVertex2i(530,240);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,215);
    glVertex2i(565,215);
    glVertex2i(565,240);
    glVertex2i(545,240);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,215);
    glVertex2i(580,215);
    glVertex2i(580,240);
    glVertex2i(565,240);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,240);
    glVertex2i(580,240);
    glVertex2i(580,250);
    glVertex2i(530,250);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,250);
    glVertex2i(545,250);
    glVertex2i(545,270);
    glVertex2i(530,270);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,250);
    glVertex2i(565,250);
    glVertex2i(565,270);
    glVertex2i(545,270);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,250);
    glVertex2i(580,250);
    glVertex2i(580,270);
    glVertex2i(565,270);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,270);
    glVertex2i(580,270);
    glVertex2i(580,280);
    glVertex2i(530,280);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(580,120);
    glVertex2i(610,120);
    glVertex2i(610,280);
    glVertex2i(580,280);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_TRIANGLES);
    glVertex2i(500,280);
    glVertex2i(610,280);
    glVertex2i(555,345);
    glEnd();

    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(610,120);
    glVertex2i(755,120);
    glVertex2i(755,280);
    glVertex2i(610,280);
    glEnd();

    setColor("darkGreen");
    glBegin(GL_QUADS);
    glVertex2i(610,280);
    glVertex2i(755,280);
    glVertex2i(700,345);
    glVertex2i(555,345);
    glEnd();

    glPopMatrix();




}
void drawMidBuilding1()
{
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(500,120);
    glVertex2i(530,120);
    glVertex2i(530,280);
    glVertex2i(500,280);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,120);
    glVertex2i(580,120);
    glVertex2i(580,135);
    glVertex2i(530,135);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,135);
    glVertex2i(545,135);
    glVertex2i(545,160);
    glVertex2i(530,160);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,135);
    glVertex2i(565,135);
    glVertex2i(565,160);
    glVertex2i(545,160);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,135);
    glVertex2i(580,135);
    glVertex2i(580,160);
    glVertex2i(565,160);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,160);
    glVertex2i(580,160);
    glVertex2i(580,175);
    glVertex2i(530,175);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,175);
    glVertex2i(545,175);
    glVertex2i(545,200);
    glVertex2i(530,200);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,175);
    glVertex2i(565,175);
    glVertex2i(565,200);
    glVertex2i(545,200);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,175);
    glVertex2i(580,175);
    glVertex2i(580,200);
    glVertex2i(565,200);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,200);
    glVertex2i(580,200);
    glVertex2i(580,215);
    glVertex2i(530,215);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,215);
    glVertex2i(545,215);
    glVertex2i(545,240);
    glVertex2i(530,240);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,215);
    glVertex2i(565,215);
    glVertex2i(565,240);
    glVertex2i(545,240);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,215);
    glVertex2i(580,215);
    glVertex2i(580,240);
    glVertex2i(565,240);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,240);
    glVertex2i(580,240);
    glVertex2i(580,250);
    glVertex2i(530,250);
    glEnd();
    //
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(530,250);
    glVertex2i(545,250);
    glVertex2i(545,270);
    glVertex2i(530,270);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(545,250);
    glVertex2i(565,250);
    glVertex2i(565,270);
    glVertex2i(545,270);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(565,250);
    glVertex2i(580,250);
    glVertex2i(580,270);
    glVertex2i(565,270);
    glEnd();
    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(530,270);
    glVertex2i(580,270);
    glVertex2i(580,280);
    glVertex2i(530,280);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_QUADS);
    glVertex2i(580,120);
    glVertex2i(610,120);
    glVertex2i(610,280);
    glVertex2i(580,280);
    glEnd();

    setColor("lightGreen");
    glBegin(GL_TRIANGLES);
    glVertex2i(500,280);
    glVertex2i(610,280);
    glVertex2i(555,345);
    glEnd();

    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(610,120);
    glVertex2i(755,120);
    glVertex2i(755,280);
    glVertex2i(610,280);
    glEnd();

    setColor("darkGreen");
    glBegin(GL_QUADS);
    glVertex2i(610,280);
    glVertex2i(755,280);
    glVertex2i(700,345);
    glVertex2i(555,345);
    glEnd();


}

void drawBridge()
{


    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(0,95);
    glVertex2i(1280,95);
    glVertex2i(1280,120);
    glVertex2i(0,120);
    glEnd();


    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(0,80);
    glVertex2i(1280,80);
    glVertex2i(1280,95);
    glVertex2i(0,95);
    glEnd();

    setColor("darkGreen");
    glBegin(GL_QUADS);
    glVertex2i(0,60);
    glVertex2i(1280,60);
    glVertex2i(1280,80);
    glVertex2i(0,80);
    glEnd();
    //under bridge
    setColor("teal");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1280,0);
    glVertex2i(1280,60);
    glVertex2i(0,60);
    glEnd();


    //pillars
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(285,0);
    glVertex2i(320,0);
    glVertex2i(320,80);
    glVertex2i(285,80);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(285+245,0);
    glVertex2i(320+245,0);
    glVertex2i(320+245,80);
    glVertex2i(285+245,80);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(285+490,0);
    glVertex2i(320+490,0);
    glVertex2i(320+490,80);
    glVertex2i(285+490,80);
    glEnd();



}
void drawStation()
{
    /*glPushMatrix();
    glTranslatef(50,-150,0);
    setColor("darkGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 275*sin(i);
        float y = 280*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();*/

    //Pillar 1
    glPushMatrix();
    glTranslatef(165,-190, 0);
    glScalef(.5,10,1);
    setColor("rain");

    glBegin(GL_QUADS);
    glVertex2i(50,20);
    glVertex2i(70,20);
    glVertex2i(70,40);
    glVertex2i(50,40);
    glEnd();
    glPopMatrix();

    //Pillar 2
    glPushMatrix();
    glTranslatef(50,-190, 0);
    glScalef(.5,10,1);
    setColor("rain");

    glBegin(GL_QUADS);
    glVertex2i(50,20);
    glVertex2i(70,20);
    glVertex2i(70,40);
    glVertex2i(50,40);
    glEnd();
    glPopMatrix();
    //Land Part
    glPushMatrix();
    glTranslatef(-500,-270, 0);
    glScalef(10,10,1);
    setColor("white");

    glBegin(GL_QUADS);
    glVertex2i(50,20);
    glVertex2i(70,20);
    glVertex2i(70,40);
    glVertex2i(50,40);
    glEnd();
    glPopMatrix();

    //Ceiling Part
    glPushMatrix();
    glTranslatef(-500,150, 0);
    glScalef(10,1.5,1);
    setColor("navyBlue");

    glBegin(GL_QUADS);
    glVertex2i(50,20);
    glVertex2i(70,20);
    glVertex2i(70,40);
    glVertex2i(50,40);
    glEnd();
    glPopMatrix();



}

void drawRightLand()
{
    glPushMatrix();
    glTranslatef(1200,-180,0);
    setColor("darkGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 310*sin(i);
        float y = 320*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}

void drawTree1()
{
/*glPushMatrix();
glScalef(0.2,0.2,1);
glPushMatrix();
glTranslatef(200+5000,550,0);
setColor("lightGreen");
glBegin(GL_TRIANGLES);
glVertex2f(-150, 0);
glVertex2f(0, 150);
glVertex2f(150, 0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(200+5000,650,0);
setColor("lightGreen");
glBegin(GL_TRIANGLES);
glVertex2f(-120, 0);
glVertex2f(0, -120);
glVertex2f(120, 0);
glEnd();
glPopMatrix();
glPopMatrix();*/
    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(200+5000,550,0);
    setColor("lightGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 150*sin(i);
        float y = 150*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200+5000,650,0);
    setColor("lightGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 120*sin(i);
        float y = 120*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawTree2()
{

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(550+5000,470,0);
    setColor("darkerGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 150*sin(i);
        float y = 150*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(550+5000,570,0);
    setColor("darkerGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 120*sin(i);
        float y = 120*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawTree3()
{

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(900+4500,390,0);
    setColor("blue");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 150*sin(i);
        float y = 150*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(900+4500,490,0);
    setColor("blue");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 120*sin(i);
        float y = 120*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawTree4()
{

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(5900,400,0);
    setColor("lightGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 150*sin(i);
        float y = 150*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5900,500,0);
    setColor("lightGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 120*sin(i);
        float y = 120*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawTree5()
{

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(6240,470,0);
    setColor("darkerGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 150*sin(i);
        float y = 150*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6240,570,0);
    setColor("darkerGreen");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 120*sin(i);
        float y = 120*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void drawTallBuilding()
{
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(820,120);
    glVertex2i(840,120);
    glVertex2i(840,530);
    glVertex2i(820,530);
    glEnd();
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(840,120);
    glVertex2i(841,120);
    glVertex2i(841,530);
    glVertex2i(840,530);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(841,120);
    glVertex2i(850,120);
    glVertex2i(850,530);
    glVertex2i(841,530);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,120);
    glVertex2i(925,120);
    glVertex2i(925,145);
    glVertex2i(850,145);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,145);
    glVertex2i(925,145);
    glVertex2i(925,155);
    glVertex2i(850,155);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,155);
    glVertex2i(925,155);
    glVertex2i(925,180);
    glVertex2i(850,180);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,180);
    glVertex2i(925,180);
    glVertex2i(925,190);
    glVertex2i(850,190);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,190);
    glVertex2i(925,190);
    glVertex2i(925,215);
    glVertex2i(850,215);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,215);
    glVertex2i(925,215);
    glVertex2i(925,225);
    glVertex2i(850,225);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,225);
    glVertex2i(925,225);
    glVertex2i(925,250);
    glVertex2i(850,250);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,250);
    glVertex2i(925,250);
    glVertex2i(925,260);
    glVertex2i(850,260);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,260);
    glVertex2i(925,260);
    glVertex2i(925,285);
    glVertex2i(850,285);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,285);
    glVertex2i(925,285);
    glVertex2i(925,295);
    glVertex2i(850,295);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,295);
    glVertex2i(925,295);
    glVertex2i(925,320);
    glVertex2i(850,320);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,320);
    glVertex2i(925,320);
    glVertex2i(925,330);
    glVertex2i(850,330);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,330);
    glVertex2i(925,330);
    glVertex2i(925,355);
    glVertex2i(850,355);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,355);
    glVertex2i(925,355);
    glVertex2i(925,365);
    glVertex2i(850,365);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,365);
    glVertex2i(925,365);
    glVertex2i(925,390);
    glVertex2i(850,390);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,390);
    glVertex2i(925,390);
    glVertex2i(925,400);
    glVertex2i(850,400);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,400);
    glVertex2i(925,400);
    glVertex2i(925,425);
    glVertex2i(850,425);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,425);
    glVertex2i(925,425);
    glVertex2i(925,435);
    glVertex2i(850,435);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,435);
    glVertex2i(925,435);
    glVertex2i(925,460);
    glVertex2i(850,460);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,460);
    glVertex2i(925,460);
    glVertex2i(925,470);
    glVertex2i(850,470);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,470);
    glVertex2i(925,470);
    glVertex2i(925,495);
    glVertex2i(850,495);
    glEnd();
    setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(850,495);
    glVertex2i(925,495);
    glVertex2i(925,505);
    glVertex2i(850,505);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(850,505);
    glVertex2i(925,505);
    glVertex2i(925,530);
    glVertex2i(850,530);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(925,120);
    glVertex2i(935,120);
    glVertex2i(935,530);
    glVertex2i(925,530);
    glEnd();
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(935,120);
    glVertex2i(936,120);
    glVertex2i(936,530);
    glVertex2i(935,530);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(936,120);
    glVertex2i(955,120);
    glVertex2i(955,530);
    glVertex2i(936,530);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(955,120);
    glVertex2i(1090,120);
    glVertex2i(1090,530);
    glVertex2i(955,530);
    glEnd();
    setColor("mediumGreen");
    glBegin(GL_QUADS);
    glVertex2i(820,530);
    glVertex2i(1090,530);
    glVertex2i(1090,533);
    glVertex2i(820,533);
    glEnd();
    setColor("darkBlue");
    glBegin(GL_QUADS);
    glVertex2i(850,533);
    glVertex2i(1065,533);
    glVertex2i(1065,555);
    glVertex2i(850,555);
    glEnd();

}

void drawBranches()
{
    //1

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+1000,30);
    glVertex2i(39+1000,30);
    glVertex2i(39+1000,120);
    glVertex2i(37+1000,120);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+1000,65);
    glVertex2i(39+1000,65);
    glVertex2i(53+1000,95);
    glVertex2i(50+1000,95);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(38+1000,75);
    glVertex2i(36+1000,75);
    glVertex2i(21+1000,105);
    glVertex2i(23+1000,105);
    glEnd();

    //2
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+70+1000,30-15);
    glVertex2i(39+70+1000,30-15);
    glVertex2i(39+70+1000,120-15);
    glVertex2i(37+70+1000,120-15);
    glEnd();

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+70+1000,65-15);
    glVertex2i(39+70+1000,65-15);
    glVertex2i(53+70+1000,95-15);
    glVertex2i(50+70+1000,95-15);
    glEnd();


    /*  setColor("white");
      glBegin(GL_QUADS);
      glVertex2i(38+70+1000,75-15);
      glVertex2i(36+70+1000,75-15);
      glVertex2i(21+70+1000,105-15);
      glVertex2i(23+70+1000,105-15);
      glEnd();
    */
    //3
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+140+900,30-20);
    glVertex2i(39+140+900,30-20);
    glVertex2i(39+140+900,120-20);
    glVertex2i(37+140+900,120-20);
    glEnd();

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+140+900,65-20);
    glVertex2i(39+140+900,65-20);
    glVertex2i(53+140+900,95-20);
    glVertex2i(50+140+900,95-20);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(38+140+900,75-20);
    glVertex2i(36+140+900,75-20);
    glVertex2i(21+140+900,105-20);
    glVertex2i(23+140+900,105-20);
    glEnd();

    //4
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+140+1000,30-20);
    glVertex2i(39+140+1000,30-20);
    glVertex2i(39+140+1000,120-20);
    glVertex2i(37+140+1000,120-20);
    glEnd();

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+140+1000,65-20);
    glVertex2i(39+140+1000,65-20);
    glVertex2i(53+140+1000,95-20);
    glVertex2i(50+140+1000,95-20);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(38+140+1000,75-20);
    glVertex2i(36+140+1000,75-20);
    glVertex2i(21+140+1000,105-20);
    glVertex2i(23+140+1000,105-20);
    glEnd();

    //4
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+210+1000,30-20);
    glVertex2i(39+210+1000,30-20);
    glVertex2i(39+210+1000,120-20);
    glVertex2i(37+210+1000,120-20);
    glEnd();

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+210+1000,65-20);
    glVertex2i(39+210+1000,65-20);
    glVertex2i(53+210+1000,95-20);
    glVertex2i(50+210+1000,95-20);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(38+210+1000,75-20);
    glVertex2i(36+210+1000,75-20);
    glVertex2i(21+210+1000,105-20);
    glVertex2i(23+210+1000,105-20);
    glEnd();




}


void drawBackBuilding()
{

    setColor("teal");
    glBegin(GL_QUADS);
    glVertex2i(435,120);
    glVertex2i(820,120);
    glVertex2i(820,335);
    glVertex2i(435,335);
    glEnd();
    setColor("teal");
    glBegin(GL_QUADS);
    glVertex2i(460,335);
    glVertex2i(520,335);
    glVertex2i(520,355);
    glVertex2i(460,355);
    glEnd();
    setColor("teal");
    glBegin(GL_QUADS);
    glVertex2i(590,335);
    glVertex2i(820,335);
    glVertex2i(820,385);
    glVertex2i(590,385);
    glEnd();
    setColor("teal");
    glBegin(GL_QUADS);
    glVertex2i(730,385);
    glVertex2i(820,385);
    glVertex2i(820,430);
    glVertex2i(730,430);
    glEnd();
    setColor("teal");
    glBegin(GL_QUADS);
    glVertex2i(1065,250);
    glVertex2i(1200,250);
    glVertex2i(1200,400);
    glVertex2i(1065,400);
    glEnd();


}

void drawClouds1()
{
    glPushMatrix();
    glTranslatef(cloud1Position,-90,0);
    glScalef(1,1,1);

    glPushMatrix();
    glTranslatef(200,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 30*sin(i);
        float y = 40*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 35*sin(i);
        float y = 45*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 35*sin(i);
        float y = 45*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(170,570-70);
    glVertex2i(340,570-70);
    glVertex2i(340,615-70+20);
    glVertex2i(170,615-70+20);

    glEnd();
    glPopMatrix();

}

void drawClouds2()
{
    glPushMatrix();
    glTranslatef(cloud2Position,250,0);
    glScalef(0.5,0.4,1);

    glPushMatrix();
    glTranslatef(200,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 30*sin(i);
        float y = 40*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 35*sin(i);
        float y = 45*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 35*sin(i);
        float y = 45*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(170,570-70);
    glVertex2i(340,570-70);
    glVertex2i(340,615-70+20);
    glVertex2i(170,615-70+20);

    glEnd();
    glPopMatrix();

}

void drawClouds3()
{
    glPushMatrix();
    glTranslatef(cloud3Position,250,0);
    glScalef(0.5,0.4,1);

    glPushMatrix();
    glTranslatef(200,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 30*sin(i);
        float y = 40*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 35*sin(i);
        float y = 45*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 35*sin(i);
        float y = 45*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(170,570-70);
    glVertex2i(340,570-70);
    glVertex2i(340,615-70+20);
    glVertex2i(170,615-70+20);

    glEnd();
    glPopMatrix();

}


void drawSun()
{
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(200,550,0);
    setColor("sun");
    glBegin(GL_TRIANGLE_FAN);
    for(float i=0; i<=2*3.14; i+=0.001)
    {
        float x = 30*sin(i);
        float y = 30*cos(i);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}
void drawStars()
{


    glPushMatrix();
    glTranslatef(50,520,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,515,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,540,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150,560,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,500,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(280,490,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,490,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,510,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(500,530,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(650,510,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(700,500,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(760,540,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(800,520,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(760+100,530,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(800+100,505,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(760+200,530,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(850+200,550,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(760+300,560,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();










}



void Rain(int value)
{

    if(rainday)
    {

        rain += 0.01f;

        glBegin(GL_POINTS);
        for(int i=1; i<=1000; i++)
        {
            int x=rand(),y=rand();
            x%=1300;
            y%=650;
            glBegin(GL_LINES);
            setColor("rain");
            glVertex2d(x,y);
            glVertex2d(x+5,y+5);
            glEnd();
        }

        glutPostRedisplay();
        glutTimerFunc(20, Rain, 0);

        glFlush();

    }
}



void update(int val)
{
    //animate train
    if(trainPosition < -1050) trainPosition = 1400;
    trainPosition -= trainSpeed;
    if(trainFacePosition < -1010) trainFacePosition = 1440;
    trainFacePosition -= trainFaceSpeed;


    //animate clouds
    if(cloud1Position > 1280) cloud1Position = -500;
    cloud1Position += cloud1Speed;

    if(cloud2Position < -300) cloud2Position = 1300;
    cloud2Position -= cloud2Speed;

    if(cloud3Position < -300) cloud3Position = 1300;
    cloud3Position -= cloud3Speed;
    glutPostRedisplay();
    glutTimerFunc(10, update,0);
}

void playMusic(){
    PlaySound("music.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}


void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    drawBackground();
    if(!dayNight) drawStars();
    drawSun();
    drawClouds1();
    drawClouds2();
    drawClouds3();


    drawBackBuilding();
    drawLeftBuilding();
    drawMidBuilding1();
    drawMidBuilding2();
    drawBridge();
    drawTallBuilding();
    drawTrain();
    drawTrainHuman();

    drawHumanOne();
    drawHumanTwo();
    drawHumanThree();
    drawStation();

    drawRightLand();
    drawRightBuilding();
    drawTree1();
    drawTree2();
    drawTree3();
    drawTree4();
    drawTree5();
    drawBranches();
    drawCover();
    glFlush ();
}

void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1280.0, 0.0, 620.0);
}

void handleKeypress(unsigned char key, int x, int y)
{

    switch (key)
    {
    case 's':
        if(trainSpeed >= 1) trainSpeed -= 1;
        if(trainFaceSpeed >= 1) trainFaceSpeed -= 1;
        break;

    case 'w':
        trainSpeed += 1;
        trainFaceSpeed += 1;
        break;

    case 't':
        dayNight = !dayNight;
        break;

    case 'r':
        trainSpeed = 0;
        trainFaceSpeed = 0;
        break;

    case 'x':
        trainSpeed = 5;
        trainFaceSpeed = 5;
        break;

    case 'q':
        rainday = true;
        Rain(rain);
        break;

    case 'e':
        rainday = false;
        Rain(rain);
        break;
    case 'c':
        cover = !cover;

        glutPostRedisplay();

    }

}




int main(int argc, char** argv)
{
    cout<< "Minimalistic Train Scenerio"<<endl;
    cout<< "Press C: To Open or Close Scenario"<<endl;
    cout<< "Press X: To start the train"<<endl;
    cout<< "Press R: To stop the train"<<endl;
    cout<< "Press W: To speed up the train"<<endl;
    cout<< "Press S: To speed down the train"<<endl;
    cout<< "Press Q: To Make it rain"<<endl;
    cout<< "Press E: To Stop rain"<<endl;
    cout<< "Press T: To Cycle between Day/Night"<<endl;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1280, 620);
    glutInitWindowPosition (120, 60);
    glutCreateWindow ("Train Scene");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(0, update, 0);
    playMusic();
    glutMainLoop();
}
