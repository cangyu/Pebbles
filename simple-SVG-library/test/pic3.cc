#include "../lib/SVG.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    SVGRoot svg;
    svg.setSize(325, 325);

    SVGPath p1;
    p1.moveToAbs(80, 80)
      .arcToAbs(45, 45, 0, 0, 0, 125, 125)
      .lineToAbs(125, 80)
      .closePath();
    p1.setFillColor("green");
    svg.add(p1);

    SVGPath p2;
    p2.moveToAbs(230, 80)
      .arcToAbs(45, 45, 0, 1, 0, 275, 125)
      .lineToAbs(275, 80)
      .closePath();
    p2.setFillColor("red");
    svg.add(p2);

    SVGPath p3;
    p3.moveToAbs(80, 230)
      .arcToAbs(45, 45, 0, 0, 1, 125, 275)
      .lineToAbs(125, 230)
      .closePath();
    p3.setFillColor("purple");
    svg.add(p3);

    SVGPath p4;
    p4.moveToAbs(230, 230)
      .arcToAbs(45, 45, 0, 1, 1, 275, 275)
      .lineToAbs(275, 230)
      .closePath();
    p4.setFillColor("blue");
    svg.add(p4);

    //svg.print(cout);
    ofstream fout("pic3.svg");
    fout << svg;
    cout << svg;
}
