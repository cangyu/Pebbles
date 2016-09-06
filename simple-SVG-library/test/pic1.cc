#include <fstream>
#include <iostream>
#include "../lib/SVG.h"

using namespace std;

int main() {
    SVGRoot svg;
    svg.setSize(500, 600);

    SVGGroup g1("my-group");

    SVGRectangle rect1("rect-one");
    rect1.setSize(50, 50);
    rect1.setPosition(20, 20);
    rect1.setFillColor("#233");
    rect1.setFillOpacity(0.5);
    rect1.setStrokeWidth(10);
    rect1.setStrokeColor("red");
    g1.add(rect1);

    SVGEllipse ellipse1("ellipse-one");
    ellipse1.setPosition(100, 100);
    ellipse1.setRadius(50, 70);
    ellipse1.setFillColor("none");
    ellipse1.setStrokeColor("green");
    ellipse1.setStrokeWidth(5);
    g1.add(ellipse1);

    SVGEllipse ellipse2;
    ellipse2.setRadius(50, 70);
    ellipse2.setFillColor("none");
    ellipse2.setStrokeColor("green");
    ellipse2.setStrokeWidth(5);
    ellipse2.setPosition(200, 200);
    svg.add(ellipse2);

    SVGCircle circle1;
    circle1.setPosition(150, 150);
    circle1.setRadius(50);
    circle1.setFillColor("none");
    circle1.setStrokeColor("blue");
    circle1.setStrokeWidth(5);
    g1.add(circle1);

    SVGGroup g2("wrapper");
    g2.add(g1);
    svg.add(g2);

    svg.findContainer("wrapper")
       .findContainer("my-group")
       .remove("ellipse-one");

    //svg.print(cout);
    ofstream fout("pic1.svg");
    fout << svg;
    cout << svg;
}
