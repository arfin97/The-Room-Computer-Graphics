#include <GL/gl.h>
#include <GL/glut.h>
double hh = 1000, ww = 1000;
//int d=20,p,gx=0,hy=0,hxc=495,gyc=795,ha,gb;

void showGrid(double h, double w, double dis){
/// Page grid vertical
    for(int i=0; i<=w; i+=dis){
        glColor3d(1, 0, 0);
        glBegin(GL_LINES);
        glVertex2d(i, 0);
        glVertex2d(i, 1000);
        glEnd();
    }

    /// Page grid horizontal
    for(int i=0; i<=h; i+=dis){
        glColor3d(1, 0, 0);
        glBegin(GL_LINES);
        glVertex2d(0, i);
        glVertex2d(1000, i);
        glEnd();
    }
}

void display(void) {
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) with corners at
    * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    */

/// Floor
    glColor3d(.9, .9, .9);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(1000, 0);
    glVertex2d(1000, 450);
    glVertex2d(400, 450);
    glVertex2d(0, 100);
    glEnd();

/// Floor horizontal lines
    int x, y, z=50;
    for(y=50; y<1000; y+=z, z-=2){
        glColor3d(.7, .7, .7);
        glBegin(GL_LINES);
        glVertex2d(0, y);
        glVertex2d(1000, y);
        glEnd();
    }

/// Floor vertical lines
    int x1, x2;
    for(x1 = 430, x2 = -30; x1<=1000; x1+=30, x2+=55){
        glColor3d(.7, .7, .7);
        glBegin(GL_LINES);
        glVertex2d(x1, 450);
        glVertex2d(x2, 0);
        glEnd();
    }

///  left Wall
    glColor3d(0.85, 0.85, 0.85);
    glBegin(GL_POLYGON);
    glVertex2d(0, 100);
    glVertex2d(400, 450);
    glVertex2d(400, 1000);
    glVertex2d(0, 1000);
    glVertex2d(0, 100);
    glEnd();

///  Back-Glass outer frame
    glColor3d(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2d(400, 450);
    glVertex2d(1000, 450);
    glVertex2d(1000, 1000);
    glVertex2d(400, 1000);
    glVertex2d(400, 450);
    glEnd();

///  Back-Glass
    glColor3d(0.52, 0.80, 0.92);
    glBegin(GL_POLYGON);
    glVertex2d(420, 460);
    glVertex2d(1000, 460);
    glVertex2d(1000, 870);
    glVertex2d(420, 870);

    glEnd();

///  Back-Glass inner frame top
    glColor3d(0.45, 0.45, 0.45);
    glBegin(GL_POLYGON);
    glVertex2d(410, 870);
    glVertex2d(420, 860);
    glVertex2d(1000, 860);
    glVertex2d(1000, 870);
    glVertex2d(410, 870);
    glEnd();

///  Back-Glass inner frame left
    glColor3d(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(410, 870);
    glVertex2d(420, 860);
    glVertex2d(420, 470);
    glVertex2d(410, 460);
    glEnd();

///  Back-Glass inner frame bottom
    glColor3d(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2d(420, 470);
    glVertex2d(1000, 470);
    glVertex2d(1000, 460);
    glVertex2d(410, 460);
    glEnd();

///  Back-Glass inner frame middle frame
    glColor3d(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2d(700, 870);
    glVertex2d(710, 870);
    glVertex2d(710, 460);
    glVertex2d(700, 460);
    glEnd();

///  Back-Glass inner frame middle shade
    glColor3d(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(710, 870);
    glVertex2d(720, 860);
    glVertex2d(720, 470);
    glVertex2d(710, 460);
    glEnd();

///  Top-back Wall
    glColor3d(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2d(370, 900);
    glVertex2d(1000, 900);
    glVertex2d(1000, 1000);
    glVertex2d(370, 1000);
    glEnd();

///  Top-back wall shadow
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(370, 900);
    glVertex2d(400, 880);
    glVertex2d(1000, 880);
    glVertex2d(1000, 900);
    glVertex2d(400, 900);
    glEnd();

/// Clock
    double cl_x=405, cl_y=905, w=50, h=90;

/// Clock Outer
    glColor3d(0.21, 0.27, 0.31);
    glBegin(GL_POLYGON);
    glVertex2d(cl_x, cl_y);
    glVertex2d(cl_x+w, cl_y);
    glVertex2d(cl_x+w, cl_y+h);
    glVertex2d(cl_x, cl_y+h);
    glEnd();

/// Clock Inner
    glColor3d(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(cl_x+5, cl_y+5);
    glVertex2d(cl_x+w-5, cl_y+5);
    glVertex2d(cl_x+w-5, cl_y+h-5);
    glVertex2d(cl_x+5, cl_y+h-5);
    glEnd();

/// Clock Second
    glColor3d(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(cl_x+w/2, cl_y+h/2);
    glVertex2d(cl_x+10, cl_y+10);
    glEnd();

/// Clock Minute
    glColor3d(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(cl_x+w/2, cl_y+h/2);
    glVertex2d(cl_x+42, cl_y+60);
    glEnd();

/// Clock Hour
    glColor3d(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(cl_x+w/2, cl_y+h/2);
    glVertex2d(cl_x+12, cl_y+55);
    glEnd();

/// AC front
    glColor3d(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(620, 920);
    glVertex2d(770, 920);
    glVertex2d(770, 970);
    glVertex2d(620, 970);
    glEnd();

/// AC top
    glColor3d(.7, .7, .85);
    glBegin(GL_POLYGON);
    glVertex2d(630, 990);
    glVertex2d(780, 990);
    glVertex2d(770, 970);
    glVertex2d(620, 970);
    glEnd();

/// AC bottom
    glColor3d(0.27, 0.35, 0.39);
    glBegin(GL_POLYGON);
    glVertex2d(620, 920);
    glVertex2d(770, 920);
    glVertex2d(780, 910);
    glVertex2d(630, 910);
    glEnd();

/// AC side
    glColor3d(0.15, 0.19, 0.22);
    glBegin(GL_POLYGON);
    glVertex2d(780, 910);
    glVertex2d(770, 920);
    glVertex2d(770, 970);
    glVertex2d(780, 990);
    glEnd();

/// Table1 Left
    glColor3d(0.15, 0.19, 0.22);
    glBegin(GL_POLYGON);
    glVertex2d(180, 200);
    glVertex2d(250, 270);
    glVertex2d(250, 400);
    glVertex2d(180, 330);
    glEnd();

/// Table1 Middle
    glColor3d(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2d(210, 230);
    glVertex2d(390, 230);
    glVertex2d(390, 350);
    glVertex2d(210, 350);
    glEnd();

/// Table1 Right
    glColor3d(0.15, 0.19, 0.22);
    glBegin(GL_POLYGON);
    glVertex2d(380, 200);
    glVertex2d(435, 270);
    glVertex2d(435, 395);
    glVertex2d(380, 330);
    glEnd();

/// Table1 Desk
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(180, 330);
    glVertex2d(250, 400);
    glVertex2d(435, 395);
    glVertex2d(380, 330);
    glEnd();


    showGrid(hh, ww);

//
////wall left-right
//    glColor3ub (105,87,62);
//    glBegin(GL_POLYGON);
//    glVertex3f (0, 250, 0);
//    glVertex3f (390, 350, 0);
//    glVertex3f (390, 1000, 0);
//    glVertex3f (0, 1000, 0);
//    glEnd();
//
////wall right-left
//    glColor3ub (131,108,92);
//    glBegin(GL_POLYGON);
//    glVertex3f (390,350, 0);
//    glVertex3f (1000,250, 0);
//    glVertex3f (1000, 1000, 0);
//    glVertex3f (390, 1000, 0);
//    glEnd();
//
////photo frame - outer
//    glColor3ub (255,108,92);
//    glBegin(GL_POLYGON);
//    glVertex3f (450,700, 0);
//    glVertex3f (540,700, 0);
//    glVertex3f (540, 870, 0);
//    glVertex3f (450, 870, 0);
//    glEnd();
//
////photo frame - inner
//    glColor3ub (178,235,242);
//    glBegin(GL_POLYGON);
//    glVertex3f (455,705, 0);
//    glVertex3f (535,705, 0);
//    glVertex3f (535, 865, 0);
//    glVertex3f (455, 865, 0);
//    glEnd();
//
////photo frame - man
//    glColor3ub (171,39,176);
//    glBegin(GL_POLYGON);
//    glVertex3f (455,705, 0);
//    glVertex3f (535,705, 0);
//    glVertex3f (535, 745, 0);
//    glVertex3f (525, 770, 0);
//    glVertex3f (465, 770, 0);
//    glVertex3f (455, 745, 0);
//    glEnd();
//
//
////photo frame - man color
//    glColor3ub (178,235,242);
//    glBegin(GL_POLYGON);
//    glVertex3f (485, 770, 0);
//    glVertex3f (495, 750, 0);
//    glVertex3f (505, 770, 0);
//    glEnd();
//
////photo frame - man head
//    glColor3ub (97,97,97);
//    glBegin(GL_POLYGON);
//    glVertex3f (485, 770, 0);
//    glVertex3f (495, 750, 0);
//    glVertex3f (505, 770, 0);
//    glVertex3f (505, 795, 0);
//    glVertex3f (485, 795, 0);
//    glEnd();
//
////roof  top
//    glColor3ub (155,142,126);
//    glBegin(GL_POLYGON);
//    glVertex3f (650, 1000, 0);
//    glVertex3f (390, 950, 0);
//    glVertex3f (180, 1000, 0);
//    glEnd();
//
////wall right-right
//    glColor3ub (195,182,166);
//    glBegin(GL_POLYGON);
//    glVertex3f (600, 300, 0);
//    glVertex3f (1000, 250, 0);
//    glVertex3f (1000, 1000, 0);
//    glVertex3f (600, 1000, 0);
//    glEnd();
//
//
//
//// left wall - right
//    glColor3ub(201,192,183);
//    glBegin(GL_POLYGON);
//    glVertex3f (200, 250, 0);
//    glVertex3f (0, 250, 0);
//    glVertex3f (0, 1000, 0);
//    glVertex3f (200, 1000, 0);
//    glEnd();
//
//
////window left
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (230, 500, 0);
//    glVertex3f (325, 520, 0);
//    glVertex3f (325, 900, 0);
//    glVertex3f (230, 900, 0);
//    glEnd();
//
////window left - right inner
//    glColor3ub (131,102,92);
//    glBegin(GL_POLYGON);
//    glVertex3f (310, 890, 0);
//    glVertex3f (325, 900, 0);
//    glVertex3f (325, 520, 0);
//    glVertex3f (310, 525, 0);
//    glEnd();
//
////window left - bottom
//    glColor3ub (195,182,166);
//    glBegin(GL_POLYGON);
//    glVertex3f (230, 500, 0);
//    glVertex3f (325, 520, 0);
//    glVertex3f (310, 525, 0);
//    glVertex3f (230, 510, 0);
//    glEnd();
//
////window left - top
//    glColor3ub (195,182,166);
//    glBegin(GL_POLYGON);
//    glVertex3f (230, 900, 0);
//    glVertex3f (325, 900, 0);
//    glVertex3f (310, 890, 0);
//    glVertex3f (230, 890, 0);
//    glEnd();
//
////window left grill-middle-vertical
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (275, 512, 0);
//    glVertex3f (280, 512, 0);
//    glVertex3f (280, 895, 0);
//    glVertex3f (275, 895, 0);
//    glEnd();
//
////window left grill-bottom
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (230, 600, 0);
//    glVertex3f (320, 615, 0);
//    glVertex3f (320, 625, 0);
//    glVertex3f (230, 610, 0);
//    glEnd();
//
////window left grill-middle
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (230, 700, 0);
//    glVertex3f (320, 715, 0);
//    glVertex3f (320, 725, 0);
//    glVertex3f (230, 710, 0);
//    glEnd();
//
////window left grill-top-horizontal
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (230, 800, 0);
//    glVertex3f (320, 810, 0);
//    glVertex3f (320, 820, 0);
//    glVertex3f (230, 810, 0);
//    glEnd();
//
////wear drop front
//    glColor3ub (89,39,25);
//    glBegin(GL_POLYGON);
//    glVertex3f (460, 660, 0);
//    glVertex3f (470, 670, 0);
//    glVertex3f (330, 670,0);
//    glVertex3f (340, 660, 0);
//    glVertex3f (340, 320, 0);
//    glVertex3f (460, 320, 0);
//    glEnd();
//
////wear drop front-drawer 1 - outer
//    glColor3ub (42,23,15);
//    glBegin(GL_POLYGON);
//    glVertex3f (455, 431, 0);
//    glVertex3f (345, 431, 0);
//    glVertex3f (345, 324, 0);
//    glVertex3f (455, 324, 0);
//    glEnd();
//
////wear drop front-drawer 1 - handel
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (410, 381, 0);
//    glVertex3f (390, 381, 0);
//    glVertex3f (390, 375, 0);
//    glVertex3f (410, 375, 0);
//    glEnd();
//
////wear drop front-drawer 2 - outer
//    glColor3ub (42,23,15);
//    glBegin(GL_POLYGON);
//    glVertex3f (455, 435, 0);
//    glVertex3f (345, 435, 0);
//    glVertex3f (345, 541, 0);
//    glVertex3f (455, 541, 0);
//    glEnd();
//
////wear drop front-drawer 2 - handel
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (410, 481, 0);
//    glVertex3f (390, 481, 0);
//    glVertex3f (390, 475, 0);
//    glVertex3f (410, 475, 0);
//    glEnd();
////wear drop front-drawer 3 - outer
//    glColor3ub (42,23,15);
//    glBegin(GL_POLYGON);
//    glVertex3f (455, 653, 0);
//    glVertex3f (345, 653, 0);
//    glVertex3f (345, 545, 0);
//    glVertex3f (455, 545, 0);
//    glEnd();
//
////wear drop front-drawer 3 - handel
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (410, 585, 0);
//    glVertex3f (390, 585, 0);
//    glVertex3f (390, 579, 0);
//    glVertex3f (410, 579, 0);
//    glEnd();
//
////wear drop side
//    glColor3ub (39,32,21);
//    glBegin(GL_POLYGON);
//    glVertex3f (470, 670, 0);
//    glVertex3f (500, 667, 0);
//    glVertex3f (492, 657, 0);
//    glVertex3f (492, 330, 0);
//    glVertex3f (460, 320, 0);
//    glVertex3f (460, 660, 0);
//    glEnd();
//
////dressing table - front
//    glColor3ub (98,47,29);
//    glBegin(GL_POLYGON);
//    glVertex3f (50, 150,0);
//    glVertex3f (245, 230, 0);
//    glVertex3f (245, 460, 0);
//    glVertex3f (50, 400, 0);
//    glEnd();
//
////dressing table - front  - left part
//    glColor3ub (42,23,15);
//    glBegin(GL_POLYGON);
//    glVertex3f (55, 160,0);
//    glVertex3f (115, 185, 0);
//    glVertex3f (115, 410, 0);
//    glVertex3f (55, 390, 0);
//    glEnd();
////dressing table - front  - left part - front handel
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (70, 305,0);
//    glVertex3f (75, 305, 0);
//    glVertex3f (75, 255, 0);
//    glVertex3f (70, 255, 0);
//    glEnd();
//
////dressing table - front  - left part - handel bottom
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (64, 262,0);
//    glVertex3f (75, 262, 0);
//    glVertex3f (75, 255, 0);
//    glVertex3f (64, 255, 0);
//    glEnd();
//
////dressing table - front  - left part - handel top
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (64, 305,0);
//    glVertex3f (75, 305, 0);
//    glVertex3f (75, 310, 0);
//    glVertex3f (64, 310, 0);
//    glEnd();
//
////dressing table side
//    glColor3ub (42,23,15);
//    glBegin(GL_POLYGON);
//    glVertex3f (50, 150, 0);
//    glVertex3f (20, 170, 0);
//    glVertex3f (20, 420, 0);
//    glVertex3f (50, 400, 0);
//    glEnd();
//
////dressing table - front  - middle part
//    glColor3ub (42,23,15);
//    glBegin(GL_POLYGON);
//    glVertex3f (120, 185,0);
//    glVertex3f (180, 210, 0);
//    glVertex3f (180, 430, 0);
//    glVertex3f (120, 410, 0);
//    glEnd();
//
////dressing table - front  - middle part - handel - top
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (135, 275,0);
//    glVertex3f (140, 275, 0);
//    glVertex3f (140, 323, 0);
//    glVertex3f (135, 323, 0);
//    glEnd();
//
////dressing table - front  - middle part - handel - down
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (130, 328,0);
//    glVertex3f (140, 328, 0);
//    glVertex3f (140, 323, 0);
//    glVertex3f (130, 323, 0);
//    glEnd();
////dressing table - front  - middle part - handel - top-down
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (130, 275,0);
//    glVertex3f (140, 275, 0);
//    glVertex3f (140, 280, 0);
//    glVertex3f (130, 280, 0);
//    glEnd();
//
////dressing table - front  - right part
//    glColor3ub (42,23,15);
//    glBegin(GL_POLYGON);
//    glVertex3f (185, 213,0);
//    glVertex3f (240, 235, 0);
//    glVertex3f (240, 450, 0);
//    glVertex3f (185, 430, 0);
//    glEnd();
//
////dressing table - front  - right part - handel - top
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (200, 300,0);
//    glVertex3f (205, 300, 0);
//    glVertex3f (205, 343, 0);
//    glVertex3f (200, 343, 0);
//    glEnd();
//
////dressing table - front  - right part - handel - down
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (194, 300,0);
//    glVertex3f (205, 300, 0);
//    glVertex3f (205, 295, 0);
//    glVertex3f (194, 295, 0);
//    glEnd();
////dressing table - front  - right part - handel - top-down
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (194, 343,0);
//    glVertex3f (205, 343, 0);
//    glVertex3f (205, 348, 0);
//    glVertex3f (194, 348, 0);
//    glEnd();
//
////dressing table top
//    glColor3ub (128,55,36);
//    glBegin(GL_POLYGON);
//    glVertex3f (20, 420,0);
//    glVertex3f (50, 400, 0);
//    glVertex3f (245,460, 0);
//    glVertex3f (215,480, 0);
//    glEnd();
//
////dressing table glass frame
//    glColor3ub (128,55,36);
//    glBegin(GL_POLYGON);
//    glVertex3f (190, 470, 0);
//    glVertex3f (48, 427, 0);
//    glVertex3f (48, 770, 0);
//    glVertex3f (190, 800, 0);
//    glEnd();
//
////dressing table glass
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (180, 467, 0);
//    glVertex3f (58, 430, 0);
//    glVertex3f (58, 750, 0);
//    glVertex3f (180, 777, 0);
//    glEnd();
//
////object reflection
//    glColor3ub (158,158,158);
//    glBegin(GL_POLYGON);
//    glVertex3f (130, 460, 0);
//    glVertex3f (150, 460, 0);
//    glVertex3f (160, 575, 0);
//    glVertex3f (120, 570, 0);
//    glEnd();
////object flower1 reflection
//    glColor3ub (229,115,115);
//    glBegin(GL_POLYGON);
//    glVertex3f (140, 600, 0);
//    glVertex3f (150, 650, 0);
//    glVertex3f (130, 650, 0);
//    glEnd();
////object flower4 reflection
//    glColor3ub (255,213,79);
//    glBegin(GL_POLYGON);
//    glVertex3f (150, 690, 0);
//    glVertex3f (140, 740, 0);
//    glVertex3f (130, 690, 0);
//    glEnd();
//
////object flower2 reflection
//    glColor3ub (129,199,132);
//    glBegin(GL_POLYGON);
//    glVertex3f (130, 690, 0);
//    glVertex3f (100, 670, 0);
//    glVertex3f (130, 650, 0);
//    glEnd();
//
////object flower3 reflection
//    glColor3ub (2,136,209);
//    glBegin(GL_POLYGON);
//    glVertex3f (150, 690, 0);
//    glVertex3f (180, 670, 0);
//    glVertex3f (150, 650, 0);
//    glEnd();
//
//
////object flower5 - reflection
//    glColor3ub (206,140,216);
//    glBegin(GL_POLYGON);
//    glVertex3f (150, 690, 0);
//    glVertex3f (130, 690, 0);
//    glVertex3f (130, 650, 0);
//    glVertex3f (150, 650, 0);
//    glEnd();
//
////object flower stand reflection
//    glColor3ub (165,214,167);
//    glBegin(GL_POLYGON);
//    glVertex3f (137, 655, 0);
//    glVertex3f (143, 655, 0);
//    glVertex3f (143, 570, 0);
//    glVertex3f (137, 570, 0);
//    glEnd();
//
//
////dressing table glass frame-bottom
//    glColor3ub (128,55,36);
//    glBegin(GL_POLYGON);
//    glVertex3f (190, 470, 0);
//    glVertex3f (48, 427, 0);
//    glVertex3f (48, 442, 0);
//    glVertex3f (190, 485, 0);
//    glEnd();
//
////object
//    glColor3ub (117,117,117);
//    glBegin(GL_POLYGON);
//    glVertex3f (170, 450, 0);
//    glVertex3f (190, 455, 0);
//    glVertex3f (200, 575, 0);
//    glVertex3f (160, 570, 0);
//    glEnd();
//
////object flower stand
//    glColor3ub (76,175,80);
//    glBegin(GL_POLYGON);
//    glVertex3f (177, 650, 0);
//    glVertex3f (183, 650, 0);
//    glVertex3f (183, 570, 0);
//    glVertex3f (177, 570, 0);
//    glEnd();
//
////object flower1
//    glColor3ub (244,67,54);
//    glBegin(GL_POLYGON);
//    glVertex3f (180, 600, 0);
//    glVertex3f (190, 650, 0);
//    glVertex3f (170, 650, 0);
//    glEnd();
//
////object flower2
//    glColor3ub (27,94,32);
//    glBegin(GL_POLYGON);
//    glVertex3f (170, 690, 0);
//    glVertex3f (140, 670, 0);
//    glVertex3f (170, 650, 0);
//    glEnd();
//
////object flower3
//    glColor3ub (2,136,209);
//    glBegin(GL_POLYGON);
//    glVertex3f (190, 690, 0);
//    glVertex3f (220, 670, 0);
//    glVertex3f (190, 650, 0);
//    glEnd();
//
////object flower4
//    glColor3ub (251,140,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (190, 690, 0);
//    glVertex3f (180, 740, 0);
//    glVertex3f (170, 690, 0);
//    glEnd();
//
////object flower5
//    glColor3ub (123,31,62);
//    glBegin(GL_POLYGON);
//    glVertex3f (190, 690, 0);
//    glVertex3f (170, 690, 0);
//    glVertex3f (170, 650, 0);
//    glVertex3f (190, 650, 0);
//    glEnd();
//
//
////bed
////bed head
//    glColor3ub (77,40,26);
//    glBegin(GL_POLYGON);
//    glVertex3f (550, 650, 0);
//    glVertex3f (850, 600, 0);
//    glVertex3f (850, 250, 0);
//    glVertex3f (550, 300, 0);
//    glEnd();
//
////bed leg
//    glColor3ub (88,40,19);
//    glBegin(GL_POLYGON);
//    glVertex3f (250, 200, 0);
//    glVertex3f (550, 150, 0);
//    glVertex3f (550, 50, 0);
//    glVertex3f (250, 100, 0);
//    glEnd();
//
//
////bed right side
//    glColor3ub (128,55,36);
//    glBegin(GL_POLYGON);
//    glVertex3f (850, 250, 0);
//    glVertex3f (550, 50, 0);
//    glVertex3f (550, 150, 0);
//    glVertex3f (850, 350, 0);
//    glEnd();
//
////bed right side - box left
//    glColor3ub (77,40,26);
//    glBegin(GL_POLYGON);
//    glVertex3f (695, 160, 0);
//    glVertex3f (555, 65, 0);
//    glVertex3f (555, 140, 0);
//    glVertex3f (695, 235, 0);
//    glEnd();
//
////bed right side - box left - handle
//
//    glColor3ub (128,55,36);
//    glBegin(GL_POLYGON);
//    glVertex3f (650, 160, 0);
//    glVertex3f (600, 125, 0);
//    glVertex3f (600, 140, 0);
//    glVertex3f (650, 175, 0);
//    glEnd();
//
////bed right side - 2nd box
//    glColor3ub (77,40,26);
//    glBegin(GL_POLYGON);
//    glVertex3f (845, 260, 0);
//    glVertex3f (705, 165, 0);
//    glVertex3f (705, 240, 0);
//    glVertex3f (845, 335, 0);
//    glEnd();
//
////bed right side - 2nd box - handle
//
//    glColor3ub (128,55,36);
//    glBegin(GL_POLYGON);
//    glVertex3f (800, 260, 0);
//    glVertex3f (750, 225, 0);
//    glVertex3f (750, 240, 0);
//    glVertex3f (800, 275, 0);
//    glEnd();
//
////bed rig
////bed top right
//    glColor3ub (198,40,40);
//    glBegin(GL_POLYGON);
//    glVertex3f (550, 150, 0);
//    glVertex3f (850, 350, 0);
//    glVertex3f (850, 400, 0);
//    glVertex3f (550, 200, 0);
//    glEnd();
//
////bed leg left
//    glColor3ub (177,160,140);
//    glBegin(GL_POLYGON);
//    glVertex3f (250, 200, 0);
//    glVertex3f (250, 250, 0);
//    glVertex3f (550, 450, 0);
//    glVertex3f (550, 400, 0);
//
//    glEnd();
//
////bed leg top
//    glColor3ub (183,28,28);
//    glBegin(GL_POLYGON);
//    glVertex3f (250, 200, 0);
//    glVertex3f (550, 150, 0);
//    glVertex3f (550, 200, 0);
//    glVertex3f (250, 250, 0);
//    glEnd();
//
////bed sheet
//    glColor3ub (244,67,55);
//    glBegin(GL_POLYGON);
//    glVertex3f (550, 200, 0.0);
//    glVertex3f (250, 250, 0.0);
//    glVertex3f (550, 450, 0.0);
//    glVertex3f (850, 400, 0.0);
//    glEnd();
//
////bed pillo
//
////bed pillo - left
//    glColor3ub (255,245,157);
//    glBegin(GL_POLYGON);
//    glVertex3f (604, 375, 0.0);
//    glVertex3f (500, 395, 0.0);
//    glVertex3f (550, 435, 0.0);
//    glVertex3f (655, 415, 0.0);
//    glEnd();
//
//
////bed pillo - left - side
//    glColor3ub (255,145,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (604, 375, 0.0);
//    glVertex3f (655, 415, 0.0);
//    glVertex3f (655, 405, 0.0);
//    glVertex3f (604, 365, 0.0);
//    glEnd();
//
////bed pillo - left - bottom
//    glColor3ub (255,145,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (604, 375, 0.0);
//    glVertex3f (500, 395, 0.0);
//    glVertex3f (500, 385, 0.0);
//    glVertex3f (604, 365, 0.0);
//    glEnd();
//
////bed pillo right
//    glColor3ub (255,245,157);
//    glBegin(GL_POLYGON);
//    glVertex3f (737, 360, 0.0);
//    glVertex3f (624, 375, 0.0);
//    glVertex3f (675, 410, 0.0);
//    glVertex3f (790, 390, 0.0);
//    glEnd();
////bed pillo right-side
//    glColor3ub (255,145,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (737, 360, 0.0);
//    glVertex3f (790, 390, 0.0);
//    glVertex3f (790, 380, 0.0);
//    glVertex3f (737, 350, 0.0);
//    glEnd();
//
////bed pillo bottom
//    glColor3ub (255,145,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (737, 360, 0.0);
//    glVertex3f (624, 375, 0.0);
//    glVertex3f (624, 365, 0.0);
//    glVertex3f (737, 350, 0.0);
//    glEnd();
//
////bed blanket
//    glColor3ub (94,53,177);
//    glBegin(GL_POLYGON);
//    glVertex3f (550, 220, 0.0);
//    glVertex3f (280, 260, 0.0);
//    glVertex3f (400, 340, 0.0);
//    glVertex3f (670, 300, 0.0);
//    glEnd();
//
////window right
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (1000, 500, 0);
//    glVertex3f (900, 500, 0);
//    glVertex3f (900, 900,0);
//    glVertex3f (1000,900, 0);
//    glEnd();
////window right-inner bottom
//    glColor3ub (105,87,62);
//    glBegin(GL_POLYGON);
//    glVertex3f (1000, 500, 0);
//    glVertex3f (900, 500, 0);
//    glVertex3f (910, 510,0);
//    glVertex3f (1000,510, 0);
//    glEnd();
////window right-inner left
//    glColor3ub (131,102,92);
//    glBegin(GL_POLYGON);
//    glVertex3f (900, 900, 0);
//    glVertex3f (910, 890, 0);
//    glVertex3f (910, 510,0);
//    glVertex3f (900,500, 0);
//    glEnd();
//
////window right-inner top
//    glColor3ub (102,87,62);
//    glBegin(GL_POLYGON);
//    glVertex3f (900, 900, 0);
//    glVertex3f (910, 890, 0);
//    glVertex3f (1000, 890,0);
//    glVertex3f (1000,900, 0);
//    glEnd();
//
////window right grill bottom-vertical
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (905, 600, 0);
//    glVertex3f (1000, 600, 0);
//    glVertex3f (1000, 610,0);
//    glVertex3f (905,610, 0);
//    glEnd();
//
////window right grill middle-vertical
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (905, 700, 0);
//    glVertex3f (1000, 700, 0);
//    glVertex3f (1000, 710,0);
//    glVertex3f (905,710, 0);
//    glEnd();
//
////window right grill top-vertical
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (905, 800, 0);
//    glVertex3f (1000, 800, 0);
//    glVertex3f (1000, 810,0);
//    glVertex3f (905,810, 0);
//    glEnd();
//
////window right grill bottom-horizontal
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (965, 505, 0);
//    glVertex3f (965, 895, 0);
//    glVertex3f (970, 895,0);
//    glVertex3f (970,505, 0);
//    glEnd();
////bed side box front
//    glColor3ub (60,23,9);
//    glBegin(GL_POLYGON);
//    glVertex3f (960, 410,0);
//    glVertex3f (960, 120,0);
//    glVertex3f (830, 135,0);
//    glVertex3f (830, 415, 0);
//    glVertex3f (820, 435,0);
//    glVertex3f (970, 435, 0);
//    glEnd();
//
////bed side box front - box bottom
//    glColor3ub (128,55,36);
//    glBegin(GL_POLYGON);
//    glVertex3f (955, 260,0);
//    glVertex3f (955, 130,0);
//    glVertex3f (835, 145,0);
//    glVertex3f (835, 270, 0);
//    glEnd();
//
////bed side box front - box bottom - handel
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (907, 200,0);
//    glVertex3f (907, 190,0);
//    glVertex3f (883, 190,0);
//    glVertex3f (883, 200, 0);
//    glEnd();
//
////bed side box front - box top
//    glColor3ub (128,55,36);
//    glBegin(GL_POLYGON);
//    glVertex3f (955, 265,0);
//    glVertex3f (955, 400,0);
//    glVertex3f (835, 405,0);
//    glVertex3f (835, 275, 0);
//    glEnd();
//
////bed side box front - box top - handel
//    glColor3ub (255,255,255);
//    glBegin(GL_POLYGON);
//    glVertex3f (907, 337.5,0);
//    glVertex3f (907, 327.5,0);
//    glVertex3f (883, 327.5,0);
//    glVertex3f (883, 337.5, 0);
//    glEnd();
////bed side box side
//    glColor3ub (113,55,34);
//    glBegin(GL_POLYGON);
//    glVertex3f (970, 435,0);
//    glVertex3f (960, 410, 0);
//    glVertex3f (960, 120,0);
//    glVertex3f (985, 140, 0);
//    glVertex3f (985, 430, 0);
//    glVertex3f (995, 460, 0);
//    glEnd();
//
////bed side box top
//    glColor3ub (192,99,82);
//    glBegin(GL_POLYGON);
//    glVertex3f (820, 435,0);
//    glVertex3f (970, 435,0);
//    glVertex3f (995, 460,0);
//    glVertex3f (845, 460,0);
//    glEnd();
//
////bed side box lamp base
//    glColor3ub (0,0,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (875, 440,0);
//    glVertex3f (915, 440,0);
//    glVertex3f (910, 450,0);
//    glVertex3f (890, 450,0);
//    glEnd();
//
////bed side box lamp stand
//    glColor3ub (77,49,26);
//    glBegin(GL_POLYGON);
//    glVertex3f (895, 445,0);
//    glVertex3f (905, 445,0);
//    glVertex3f (905, 550,0);
//    glVertex3f (895, 550,0);
//    glEnd();
//
////bed side box lamp stand
//    glColor3ub (244,67,59);
//    glBegin(GL_POLYGON);
//    glVertex3f (875, 650,0);
//    glVertex3f (925, 650,0);
//    glVertex3f (935, 550,0);
//    glVertex3f (865, 550,0);
//    glEnd();
//
////bed right papos - 1
//    glColor3ub (213,0,249);
//    glBegin(GL_POLYGON);
//    glVertex3f (705, 150, 0);
//    glVertex3f (570, 60, 0);
//    glVertex3f (680, 60, 0);
//    glVertex3f (815, 150, 0);
//    glEnd();
//
//
////bed right papos - 2
//    glColor3ub (255,61,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (725, 150, 0);
//    glVertex3f (590, 60, 0);
//    glVertex3f (660, 60, 0);
//    glVertex3f (795, 150, 0);
//    glEnd();
//
//
////bed right papos - 2
//    glColor3ub (255,61,0);
//    glBegin(GL_POLYGON);
//    glVertex3f (725, 150, 0);
//    glVertex3f (590, 60, 0);
//    glVertex3f (660, 60, 0);
//    glVertex3f (795, 150, 0);
//    glEnd();
//
////bed right papos - 3
//    glColor3ub (57,73,171);
//    glBegin(GL_POLYGON);
//    glVertex3f (745, 150, 0);
//    glVertex3f (610, 60, 0);
//    glVertex3f (640, 60, 0);
//    glVertex3f (775, 150, 0);
//    glEnd();



    /* don't wait!
    * start processing buffered OpenGL routines
    */

//p = 1 - d;
//    if (p<0)
//    {
//        gx = gx+1;
//        hy = d;
//        p = p + (2*gx)+1;
//    }
//    else
//    {
//        gx = gx + 1;
//        hy = d - 1;
//        p = p + (2*gx)+1-(2*hy) ;
//    }
//    ha = gx ;
//       gb = hy ;
//        glColor3f (1.0, 0.0, 0.0);
//        //glBegin(GL_POINTS);
//               glBegin(GL_POLYGON);
//        glVertex2i (ha+hxc, gb+gyc);
//         glVertex2i ( gb+hxc,ha+gyc);
//        glVertex2i (ha+hxc,-1*gb+gyc);
//        glVertex2i (-1*ha+hxc,gb+gyc);
//        glVertex2i (-1*ha+hxc,-1*gb+gyc);
//        glVertex2i ( gb+hxc,-1*ha+gyc);
//        glVertex2i ( -1*gb+hxc,ha+gyc);
//        glVertex2i ( -1*gb+hxc,-1*ha+gyc);
//        glEnd();
//
//        while(gx<hy)
//     {
//         //printf("a=%d\tb=%d\tp=%d\n",a,b,p);
//        if (p<0)
//        {
//            gx = gx+1;
//            hy = hy;
//            p = p + (2*gx)+1;
//        }
//        else
//        {
//            gx = gx + 1;
//            hy = hy - 1;
//            p = p + (2*gx)+1-(2*hy) ;
//        }
//    //printf("%d %d ",x,y);
//        ha = gx ;
//       gb = hy ;
//        glColor3f (1.0, 0.0, 0.0);
//        //glBegin(GL_POINTS);
//        glBegin(GL_POLYGON);
//        glVertex2i (ha+hxc, gb+gyc);
//        glVertex2i ( gb+hxc,ha+gyc);
//        glVertex2i (ha+hxc,-1*gb+gyc);
//        glVertex2i (-1*ha+hxc,gb+gyc);
//        glVertex2i (-1*ha+hxc,-1*gb+gyc);
//        glVertex2i ( gb+hxc,-1*ha+gyc);
//        glVertex2i ( -1*gb+hxc,ha+gyc);
//        glVertex2i ( -1*gb+hxc,-1*ha+gyc);
//        glEnd();
//     }

    glFlush ();
}
void init (void) {
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, ww, 0.0, hh, 0.0, 1000.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 800);
    glutInitWindowPosition (10, 10);
    glutCreateWindow ("Abeer");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
