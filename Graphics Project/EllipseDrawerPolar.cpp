#include "EllipseDrawerPolar.h"
#include "EllipseData.h"
#include <algorithm>

#include <Windows.h>
#include <gl\GLu.h>
#include <valarray>
#include <iostream>
using namespace std;

#pragma comment(lib, "opengl32")
#pragma comment(lib, "glu32")


void EllipseDrawerPolar::draw(ShapeData* data)
{
    cout<<"Ellipse Polar algorithm selected."<<endl;
    EllipseData ellipseData = *(EllipseData *) data;
    int x1 = ellipseData.x1;
    int y1 = ellipseData.y1;
    int x2 = ellipseData.x2;
    int y2 = ellipseData.y2;
    int x3 = ellipseData.x3;
    int y3 = ellipseData.y3;
    COLORREF color = ellipseData.color;

    float r = (float)GetRValue(color)/255;
    float g = (float)GetGValue(color)/255;
    float b = (float)GetBValue(color)/255;

    glBegin(GL_POINTS);
    glColor3f(r, g, b);
    int RA = (int)sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    int RB = (int)sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
    int x = RA;
    double y = 0;
    double theta = 0;
    double dTheta = 1.0 / std::max(RA, RB);
    Draw4Points(x1, y1, x, (int)y);
    while (theta <= 45)
    {
        x = (int)round(RA * cos(theta));
        y = round(RB * sin(theta));
        Draw4Points(x1, y1, x, (int)y);
        theta += dTheta;
    }
    glEnd();
    glFlush();

}