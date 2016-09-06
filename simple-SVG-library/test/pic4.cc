#include "../lib/SVG.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    SVGRoot svg;
    svg.setSize(100, 100);

    SVGRectangle rect1("background");
    rect1.setFillColor("#FF9900");
    rect1.setSize(100, 100);
    rect1.setRadius(4, 4);
    svg.add(rect1);

    SVGRectangle rect2("top-left");
    rect2.setFillColor("#FFB13B");
    rect2.setSize(50, 50);
    rect2.setRadius(4, 4);
    svg.add(rect2);

    SVGRectangle rect3("top-left");
    rect3.setFillColor("#DE8500");
    rect3.setSize(50, 50);
    rect3.setRadius(4, 4);
    svg.add(rect3);

    SVGGroup g1("circles");
    g1.setFillColor("#FF9900");
    g1.add(SVGCircle("n") .setPosition(50.0, 18.4).setRadius(18.4));
    g1.add(SVGCircle("ne").setPosition(72.4, 27.6).setRadius(18.4));
    g1.add(SVGCircle("e") .setPosition(81.6, 50.0).setRadius(18.4));
    g1.add(SVGCircle("se").setPosition(72.4, 72.4).setRadius(18.4));
    g1.add(SVGCircle("s") .setPosition(50.0, 81.6).setRadius(18.4));
    g1.add(SVGCircle("sw").setPosition(27.6, 72.4).setRadius(18.4));
    g1.add(SVGCircle("w") .setPosition(18.4, 50.0).setRadius(18.4));
    g1.add(SVGCircle("nw").setPosition(27.6, 27.6).setRadius(18.4));
    svg.add(g1);

    SVGGroup g2("stars");
    SVGPath g2p1("black-star");
    g2p1.moveToAbs(63.086, 18.385)
        .cubicBezier(0.000, -7.227, -5.859, -13.086, -13.100, -13.086)
        .cubicBezier(-7.235, 0.000, -13.096, 5.859, -13.096, 13.086)
        .cubicBezier(-5.100, -5.110, -13.395, -5.110, -18.497, 0.000)
        .cubicBezier(-5.119, 5.120, -5.119, 13.408, 0.000, 18.524)
        .cubicBezier(-7.234, 0.000, -13.103, 5.859, -13.103, 13.085)
        .cubicBezier(0.000, 7.230, 5.870, 13.098, 13.103, 13.098)
        .cubicBezier(-5.119, 5.110, -5.119, 13.395, 0.000, 18.515)
        .cubicBezier(5.102, 5.104, 13.397, 5.104, 18.497, 0.000)
        .cubicBezier(0.000, 7.228, 5.860, 13.083, 13.096, 13.083)
        .cubicBezier(7.240, 0.000, 13.100, -5.855, 13.100, -13.083)
        .cubicBezier(5.118, 5.104, 13.416, 5.104, 18.513, 0.000)
        .cubicBezier(5.101, -5.120, 5.101, -13.410, 0.000, -18.515)
        .cubicBezier(7.216, 0.000, 13.081, -5.869, 13.081, -13.098)
        .cubicBezier(0.000, -7.227, -5.865, -13.085, -13.081, -13.085)
        .cubicBezier(5.101, -5.119, 5.101, -13.406, 0.000, -18.524)
        .cubicBezierAbs(76.502, 13.275, 68.206, 13.275, 63.086, 18.385)
        .closePath();
    g2.add(g2p1);
    SVGPath g2p2("white-star");
    g2p2.moveToAbs(55.003, 23.405)
        .vLine(14.488)
        .lineToAbs(65.260, 27.640)
        .cubicBezier(0.000, -1.812, 0.691, -3.618, 2.066, -5.005)
        .cubicBezier(2.780, -2.771, 7.275, -2.771, 10.024, 0.000)
        .cubicBezier(2.771, 2.766, 2.771, 7.255, 0.000, 10.027)
        .cubicBezier(-1.377, 1.375, -3.195, 2.072, -5.015, 2.072)
        .lineToAbs(62.101, 44.982)
        .hLineAbs(76.590)
        .cubicBezier(1.290, -1.280, 3.054, -2.076, 5.011, -2.076)
        .cubicBezier(3.900, 0.000, 7.078, 3.179, 7.078, 7.087)
        .cubicBezier(0.000, 3.906, -3.178, 7.088, -7.078, 7.088)
        .cubicBezier(-1.957, 0.000, -3.721, -0.798, -5.011, -2.072)
        .hLineAbs(62.100)
        .lineTo(10.229, 10.244)
        .cubicBezier(1.824, 0.000, 3.642, 0.694, 5.015, 2.086)
        .cubicBezier(2.774, 2.759, 2.774, 7.250, 0.000, 10.010)
        .cubicBezier(-2.750, 2.774, -7.239, 2.774, -10.025, 0.000)
        .cubicBezier(-1.372, -1.372, -2.064, -3.192, -2.064, -5.003)
        .lineToAbs(55.000, 62.094)
        .vLine(14.499)
        .cubicBezier(1.271, 1.276, 2.084, 3.054, 2.084, 5.013)
        .cubicBezier(0.000, 3.906, -3.177, 7.077, -7.098, 7.077)
        .cubicBezier(-3.919, 0.000, -7.094, -3.167, -7.094, -7.077)
        .cubicBezier(0.000, -1.959, 0.811, -3.732, 2.081, -5.013)
        .vLineAbs(62.094)
        .lineToAbs(34.738, 72.346)
        .cubicBezier(0.000, 1.812, -0.705, 3.627, -2.084, 5.003)
        .cubicBezier(-2.769, 2.772, -7.251, 2.772, -10.024, 0.000)
        .cubicBezier(-2.775, -2.764, -2.775, -7.253, 0.000, -10.012)
        .cubicBezier(1.377, -1.390, 3.214, -2.086, 5.012, -2.086)
        .lineTo(10.257, -10.242)
        .hLineAbs(23.414)
        .cubicBezier(-1.289, 1.276, -3.072, 2.072, -5.015, 2.072)
        .cubicBezier(-3.917, 0.000, -7.096, -3.180, -7.096, -7.088)
        .stringCubicBezier(3.177, -7.087, 7.096, -7.087)
        .cubicBezier(1.940, 0.000, 3.725, 0.796, 5.015, 2.076)
        .hLine(14.488)
        .lineToAbs(27.646, 34.736)
        .cubicBezier(-1.797, 0.000, -3.632, -0.697, -5.012, -2.071)
        .cubicBezier(-2.775, -2.772, -2.775, -7.260, 0.000, -10.027)
        .cubicBezier(2.773, -2.771, 7.256, -2.771, 10.027, 0.000)
        .cubicBezier(1.375, 1.386, 2.083, 3.195, 2.083, 5.005)
        .lineTo(10.235, 10.252)
        .vLineAbs(23.407)
        .cubicBezier(-1.270, -1.287, -2.082, -3.053, -2.082, -5.023)
        .cubicBezier(0.000, -3.908, 3.175, -7.079, 7.096, -7.079)
        .cubicBezier(3.919, 0.000, 7.097, 3.168, 7.097, 7.079)
        .cubicBezierAbs(57.088, 20.356, 56.274, 22.119, 55.003, 23.405)
        .closePath();
    g2p2.setFillColor("#FFF");
    g2.add(g2p2);
    svg.add(g2);

    SVGGroup g3("svg-textbox");
    SVGPath g3p1("text-backdrop");
    g3p1.setFillColor("black");
    g3p1.moveToAbs(5.30, 50.00)
        .hLineAbs(94.68)
        .vLineAbs(90.00)
        .quadBezierAbs(94.68, 95.00, 89.68, 95.00)
        .hLineAbs(10.30)
        .quadBezierAbs(5.30, 95.00, 5.30, 90.00)
        .closePath();
    g3.add(g3p1);
    SVGPath g3p2("shine");
    g3p2.setFillColor("#3F3F3F");
    g3p2.moveToAbs(14.657, 54.211)
        .hLine(71.394)
        .cubicBezier(2.908, 0.000, 5.312, 2.385, 5.312, 5.315)
        .vLine(17.910)
        .cubicBezier(-27.584, -3.403, -54.926, -8.125, -82.011, -7.683)
        .vLineAbs(59.526)
        .cubicBezierAbs(9.353, 56.596, 11.743, 54.211, 14.657, 54.211)
        .lineToAbs(14.657, 54.211)
        .closePath();
    g3.add(g3p2);
    svg.add(g3);

    SVGGroup g4("svg-text");
    SVGPath g4p1("S");
    g4p1.setFillColor("#FFFFFF");
    g4p1.setStrokeColor("#000000");
    g4p1.setStrokeWidth(0.5035);
    g4p1.moveToAbs(18.312, 72.927)
        .cubicBezier(-2.103, -2.107, -3.407, -5.028, -3.407, -8.253)
        .cubicBezier(0.000, -6.445, 5.223, -11.672, 11.666, -11.672)
        .cubicBezier(6.446, 0.000, 11.667, 5.225, 11.667, 11.672)
        .hLine(-6.832)
        .cubicBezier(0.000, -2.674, -2.168, -4.837, -4.835, -4.837)
        .cubicBezier(-2.663, 0.000, -4.838, 2.163, -4.838, 4.837)
        .cubicBezier(0.000, 1.338, 0.549, 2.536, 1.415, 3.420)
        .lineTo(0.000, 0.000)
        .cubicBezier(0.883, 0.874, 2.101, 1.405, 3.423, 1.405)
        .vLine(0.012)
        .cubicBezier(3.232, 0.000, 6.145, 1.309, 8.243, 3.416)
        .lineTo(0.000, 0.000)
        .cubicBezier(2.118, 2.111, 3.424, 5.034, 3.424, 8.248)
        .cubicBezier(0.000, 6.454, -5.221, 11.680, -11.667, 11.680)
        .cubicBezier(-6.442, 0.000, -11.666, -5.222, -11.666, -11.680)
        .hLine(6.828)
        .cubicBezier(0.000, 2.679, 2.175, 4.835, 4.838, 4.835)
        .cubicBezier(2.667, 0.000, 4.835, -2.156, 4.835, -4.835)
        .cubicBezier(0.000, -1.329, -0.545, -2.527, -1.429, -3.407)
        .lineTo(0.000, 0.000)
        .cubicBezier(-0.864, -0.880, -2.082, -1.418, -3.406, -1.418)
        .lineTo(0.000, 0.000)
        .cubicBezierAbs(23.341, 76.350, 20.429, 75.036, 18.312, 72.927)
        .lineToAbs(18.312, 72.927)
        .lineToAbs(18.312, 72.927)
        .closePath();
    g4.add(g4p1);

    SVGPath g4p2("V");
    g4p2.setFillColor("#FFFFFF");
    g4p2.setStrokeColor("#000000");
    g4p2.setStrokeWidth(0.5035);
    g4p2.moveToAbs(61.588, 53.005)
        .lineToAbs(53.344, 92.854)
        .lineToAbs(46.494, 92.854)
        .lineToAbs(38.236, 53.005)
        .lineToAbs(45.082, 53.005)
        .lineToAbs(49.920, 76.342)
        .lineToAbs(54.755, 53.005)
        .closePath();
    g4.add(g4p2);

    SVGPath g4p3("G");
    g4p3.setFillColor("#FFFFFF");
    g4p3.setStrokeColor("#000000");
    g4p3.setStrokeWidth(0.5035);
    g4p3.moveToAbs(73.255, 69.513)
        .hLine(11.683)
        .vLine(11.664)
        .lineTo(0.000, 0.000)
        .cubicBezier(0.000, 6.452, -5.226, 11.678, -11.669, 11.678)
        .cubicBezier(-6.441, 0.000, -11.666, -5.226, -11.666, -11.678)
        .lineTo(0.000, 0.000)
        .vLineAbs(64.676)
        .hLine(-0.017)
        .cubicBezierAbs(61.586, 58.229, 66.827, 53.000, 73.253, 53.000)
        .cubicBezier(6.459, 0.000, 11.683, 5.225, 11.683, 11.676)
        .hLine(-6.849)
        .cubicBezier(0.000, -2.674, -2.152, -4.837, -4.834, -4.837)
        .cubicBezier(-2.647, 0.000, -4.820, 2.163, -4.820, 4.837)
        .vLine(16.501)
        .lineTo(0.000, 0.000)
        .cubicBezier(0.000, 2.675, 2.173, 4.837, 4.820, 4.837)
        .cubicBezier(2.682, 0.000, 4.834, -2.162, 4.834, -4.827)
        .vLine(-0.012)
        .vLine(-4.827)
        .hLine(-4.834)
        .lineToAbs(73.255, 69.513)
        .lineToAbs(73.255, 69.513)
        .closePath();
    g4.add(g4p3);
    svg.add(g4);

    //svg.print(cout);
    ofstream fout("pic4.svg");
    fout << svg;
    cout << svg;
}
