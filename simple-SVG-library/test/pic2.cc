#include "../lib/SVG.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    SVGRoot svg;
    svg.setSize(320, 320);

    SVGPath p;
    p.moveToAbs(10, 315)
     .lineToAbs(110, 215)
     .arcToAbs(30, 50, 0, 0, 1, 162.55, 162.45)
     .lineToAbs(172.55, 152.45)
     .arcToAbs(30, 50, -45, 0, 1, 215.1, 109.9)
     .lineToAbs(315, 10);
    p.setStrokeColor("black");
    p.setStrokeWidth(2);
    p.setFillOpacity(0.5);
    p.setFillColor("green");
    svg.add(p);

    //svg.print(cout);
    ofstream fout("pic2.svg");
    fout << svg;
    cout << svg;
}
