#include "../lib/SVG.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  SVGRoot svg;
  svg.setSize(300, 300);

  SVGGroup g;
  g.setTransform("translate(0.000000,300.000000) scale(0.100000,-0.100000)");
  g.setFillColor("#15377a");
  g.setStrokeColor("none");

  SVGPath p1;
  p1.moveToAbs(742, 2966)
      .cubicBezier(-5, -12, -13, -58, -16, -102)
      .cubicBezier(-29, -354, -41, -450, -116, -966)
      .cubicBezier(-11, -75, -20, -154, -20, -176)
      .cubicBezier(0, -38, -2, -41, -55, -67)
      .cubicBezier(-70, -34, -127, -107, -162, -206)
      .cubicBezier(-31, -89, -26, -150, 17, -226)
      .cubicBezier(27, -47, 112, -123, 138, -123)
      .cubicBezier(6, 0, 13, -4, 16, -9)
      .cubicBezier(7, -11, -96, -428, -119, -481)
      .cubicBezier(-8, -19, -33, -109, -55, -200)
      .cubicBezier(-22, -91, -49, -187, -60, -214)
      .cubicBezier(-30, -74, -27, -112, 12, -136)
      .cubicBezier(18, -11, 47, -20, 65, -20)
      .cubicBezier(37, 0, 113, 31, 132, 53)
      .cubicBezier(7, 9, 19, 58, 27, 109)
      .cubicBezier(15, 100, 82, 320, 100, 325)
      .cubicBezier(5, 2, 21, -23, 34, -54)
      .cubicBezier(31, -75, 72, -143, 86, -143)
      .cubicBezier(17, 0, 68, 113, 134, 295)
      .cubicBezier(89, 244, 133, 333, 144, 293)
      .cubicBezier(17, -63, 96, -402, 101, -433)
      .cubicBezier(10, -65, 17, -72, 62, -52)
      .cubicBezier(21, 9, 48, 19, 61, 22)
      .cubicBezier(14, 4, 22, 14, 22, 29)
      .cubicBezier(0, 32, -116, 376, -156, 465)
      .cubicBezier(-19, 41, -46, 89, -59, 107)
      .cubicBezier(-14, 18, -25, 35, -25, 37)
      .cubicBezier(0, 2, 29, 18, 63, 35)
      .cubicBezier(75, 37, 163, 110, 149, 124)
      .cubicBezier(-6, 6, -63, -12, -149, -46)
      .cubicBezier(-138, -55, -183, -65, -213, -46)
      .cubicBezier(-21, 13, -28, 393, -8, 417)
      .cubicBezier(10, 13, 27, 14, 95, 9)
      .cubicBezier(60, -4, 92, -2, 116, 8)
      .cubicBezier(41, 17, 70, 49, 65, 73)
      .cubicBezier(-3, 16, -12, 18, -70, 15)
      .lineTo(-66, -3)
      .lineTo(-7, 48)
      .cubicBezier(-4, 26, -22, 95, -40, 153)
      .cubicBezier(-19, 58, -43, 168, -55, 247)
      .cubicBezier(-26, 179, -137, 795, -150, 827)
      .cubicBezier(-13, 35, -26, 39, -38, 12)
      .closePath()
      .moveTo(91, -644)
      .cubicBezier(38, -220, 37, -233, -25, -213)
      .cubicBezier(-19, 6, -46, 23, -59, 37)
      .cubicBezier(-28, 29, -28, 65, -3, 244)
      .cubicBezier(16, 111, 29, 149, 45, 133)
      .cubicBezier(4, -4, 23, -95, 42, -201)
      .closePath()
      .moveTo(-20, -358)
      .cubicBezier(57, -37, 87, -97, 112, -219)
      .lineTo(6, -30)
      .lineTo(-83, -13)
      .cubicBezier(-134, -22, -205, -62, -239, -136)
      .cubicBezier(-26, -57, -24, -92, 11, -186)
      .cubicBezier(32, -87, 30, -108, -11, -130)
      .cubicBezier(-16, -9, -26, -8, -46, 5)
      .cubicBezier(-34, 23, -53, 73, -53, 143)
      .cubicBezier(0, 82, 24, 144, 80, 205)
      .cubicBezier(66, 73, 77, 99, 90, 216)
      .cubicBezier(20, 185, 39, 205, 133, 145)
      .closePath()
      .moveTo(-17, -369)
      .cubicBezier(23, -35, 17, -416, -7, -440)
      .cubicBezier(-31, -31, -148, 16, -123, 49)
      .cubicBezier(5, 7, 24, 32, 42, 56)
      .lineTo(32, 43)
      .lineTo(0, 153)
      .cubicBezier(0, 149, 2, 160, 32, 163)
      .cubicBezier(4, 1, 15, -10, 24, -24)
      .closePath()
      .moveTo(194, -524)
      .cubicBezier(0, -14, -75, -146, -107, -187)
      .cubicBezier(-16, -22, -47, -63, -68, -91)
      .cubicBezier(-22, -29, -44, -53, -51, -53)
      .cubicBezier(-26, 0, -154, 296, -139, 320)
      .cubicBezier(3, 4, 30, 3, 62, -2)
      .cubicBezier(59, -10, 178, -4, 243, 12)
      .cubicBezier(48, 11, 60, 11, 60, 1)
      .closePath();
  g.add(p1);

  SVGPath p2;
  p2.moveToAbs(1203, 2443)
      .cubicBezier(-8, -3, -13, -23, -13, -48)
      .cubicBezier(0, -52, -12, -61, -85, -66)
      .lineTo(-49, -4)
      .lineTo(-17, 45)
      .cubicBezier(-14, 37, -21, 45, -41, 43)
      .cubicBezier(-49, -6, -68, -14, -68, -31)
      .cubicBezier(1, -31, 38, -184, 48, -194)
      .cubicBezier(5, -5, 28, -2, 58, 9)
      .cubicBezier(40, 14, 82, 18, 224, 18)
      .cubicBezier(163, 0, 182, -2, 269, -28)
      .cubicBezier(115, -35, 227, -90, 317, -158)
      .cubicBezier(97, -72, 129, -103, 196, -194)
      .cubicBezier(122, -163, 185, -331, 196, -525)
      .lineTo(7, -115)
      .lineTo(110, 0)
      .lineTo(110, 0)
      .lineTo(3, 39)
      .cubicBezier(6, 72, -2, 86, -54, 86)
      .cubicBezier(-52, 0, -58, 9, -59, 85)
      .lineTo(0, 50)
      .lineTo(43, 14)
      .cubicBezier(48, 15, 48, 14, 21, 114)
      .lineTo(-10, 38)
      .lineTo(-54, -6)
      .lineTo(-55, -7)
      .lineTo(-20, 47)
      .cubicBezier(-11, 26, -20, 52, -20, 59)
      .cubicBezier(0, 8, 18, 26, 40, 41)
      .lineTo(40, 28)
      .lineTo(-27, 48)
      .cubicBezier(-39, 72, -46, 76, -95, 51)
      .lineTo(-42, -21)
      .lineTo(-33, 37)
      .cubicBezier(-49, 55, -50, 69, -12, 108)
      .lineTo(33, 34)
      .lineTo(-52, 52)
      .lineTo(-52, 52)
      .lineTo(-35, -34)
      .cubicBezier(-39, -38, -47, -36, -113, 18)
      .lineTo(-32, 27)
      .lineTo(20, 37)
      .cubicBezier(11, 21, 20, 43, 20, 48)
      .cubicBezier(0, 13, -89, 70, -109, 70)
      .cubicBezier(-9, 0, -26, -16, -39, -35)
      .cubicBezier(-25, -40, -40, -42, -100, -15)
      .lineTo(-43, 20)
      .lineTo(6, 53)
      .lineTo(7, 54)
      .lineTo(-66, 17)
      .cubicBezier(-36, 9, -67, 16, -69, 16)
      .cubicBezier(-3, 0, -10, -20, -17, -45)
      .cubicBezier(-7, -25, -16, -48, -20, -50)
      .cubicBezier(-4, -2, -35, 0, -69, 6)
      .lineTo(-61, 11)
      .lineTo(0, 42)
      .cubicBezier(0, 23, -5, 47, -12, 54)
      .cubicBezier(-12, 12, -100, 15, -125, 5)
      .closePath();
  g.add(p2);

  SVGPath p3;
  p3.moveToAbs(416, 2091)
      .lineTo(-48, -49)
      .lineTo(32, -41)
      .lineTo(32, -40)
      .lineTo(-37, -50)
      .cubicBezier(-20, -28, -40, -51, -43, -51)
      .cubicBezier(-4, 0, -22, 9, -40, 20)
      .cubicBezier(-18, 11, -38, 20, -45, 20)
      .cubicBezier(-7, 0, -27, -26, -45, -59)
      .lineTo(-32, -58)
      .lineTo(41, -28)
      .cubicBezier(44, -31, 44, -36, 14, -109)
      .lineTo(-16, -38)
      .lineTo(-54, 7)
      .lineTo(-54, 6)
      .lineTo(-15, -52)
      .cubicBezier(-23, -77, -22, -84, 25, -98)
      .cubicBezier(48, -15, 53, -25, 44, -96)
      .lineTo(-6, -54)
      .lineTo(-52, -3)
      .lineTo(-52, -3)
      .lineTo(0, -70)
      .lineTo(0, -70)
      .lineTo(50, -5)
      .cubicBezier(55, -6, 62, -16, 64, -95)
      .cubicBezier(1, -39, -1, -41, -41, -56)
      .cubicBezier(-41, -14, -43, -16, -41, -51)
      .cubicBezier(1, -20, 9, -53, 17, -72)
      .cubicBezier(14, -34, 15, -34, 57, -25)
      .cubicBezier(23, 6, 47, 8, 53, 6)
      .cubicBezier(6, -3, 20, -28, 30, -57)
      .cubicBezier(21, -59, 22, -57, -43, -100)
      .lineTo(-23, -15)
      .lineTo(36, -63)
      .lineTo(37, -62)
      .lineTo(57, 29)
      .cubicBezier(31, 16, 64, 37, 74, 47)
      .cubicBezier(25, 29, 33, 90, 16, 117)
      .cubicBezier(-34, 51, -82, 177, -99, 261)
      .cubicBezier(-24, 113, -26, 294, -4, 403)
      .cubicBezier(32, 158, 114, 325, 220, 448)
      .cubicBezier(45, 52, 54, 68, 64, 126)
      .cubicBezier(17, 100, 17, 101, -19, 81)
      .cubicBezier(-29, -17, -29, -17, -63, 16)
      .cubicBezier(-18, 17, -35, 32, -38, 32)
      .cubicBezier(-3, 0, -27, -22, -53, -49)
      .closePath();
  g.add(p3);

  SVGPath p4;
  p4.moveToAbs(993, 1525)
      .cubicBezier(-17, -7, -40, -26, -49, -41)
      .lineTo(-18, -27)
      .lineTo(73, -66)
      .lineTo(74, -67)
      .lineTo(-27, -21)
      .cubicBezier(-15, -12, -32, -23, -38, -25)
      .cubicBezier(-22, -8, 3, -28, 33, -28)
      .cubicBezier(58, 0, 123, 50, 117, 91)
      .cubicBezier(-2, 13, -22, 38, -48, 57)
      .cubicBezier(-62, 47, -66, 57, -36, 93)
      .cubicBezier(15, 17, 24, 35, 20, 40)
      .cubicBezier(-8, 13, -64, 10, -101, -6)
      .closePath();
  g.add(p4);

  SVGPath p5;
  p5.moveToAbs(1450, 1538)
      .cubicBezier(-1, -2, -2, -47, -3, -100)
      .lineTo(-2, -98)
      .lineTo(28, 0)
      .cubicBezier(16, 0, 38, 5, 50, 12)
      .cubicBezier(22, 12, 21, 12, -8, 18)
      .lineTo(-30, 5)
      .lineTo(-3, 83)
      .cubicBezier(-2, 64, -6, 82, -17, 82)
      .cubicBezier(-8, 0, -15, -1, -15, -2)
      .closePath();
  g.add(p5);

  SVGPath p6;
  p6.moveToAbs(1753, 1480)
      .cubicBezier(-14, -33, -31, -60, -37, -60)
      .cubicBezier(-32, 0, -48, 54, -23, 79)
      .cubicBezier(10, 10, 7, 11, -14, 6)
      .cubicBezier(-16, -4, -30, -2, -34, 4)
      .cubicBezier(-10, 18, -24, 3, -18, -19)
      .cubicBezier(6, -22, -12, -50, -31, -50)
      .cubicBezier(-7, 0, -18, 15, -24, 34)
      .cubicBezier(-13, 35, -38, 63, -48, 53)
      .cubicBezier(-3, -3, 3, -32, 14, -64)
      .cubicBezier(11, -32, 23, -73, 27, -90)
      .cubicBezier(9, -45, 27, -41, 53, 12)
      .cubicBezier(12, 25, 26, 45, 32, 45)
      .cubicBezier(5, 0, 19, -18, 30, -40)
      .cubicBezier(12, -23, 24, -38, 29, -36)
      .cubicBezier(8, 6, 63, 113, 80, 159)
      .cubicBezier(7, 18, 7, 27, 0, 27)
      .cubicBezier(-5, 0, -21, -27, -36, -60)
      .closePath();
  g.add(p6);

  SVGPath p7;
  p7.moveToAbs(1895, 1531)
      .cubicBezier(-4, -8, 5, -28, 24, -51)
      .cubicBezier(25, -32, 31, -48, 31, -89)
      .cubicBezier(0, -39, 4, -51, 15, -51)
      .cubicBezier(12, 0, 15, 13, 15, 60)
      .cubicBezier(0, 53, 3, 64, 26, 85)
      .cubicBezier(15, 14, 31, 25, 35, 25)
      .cubicBezier(5, 0, 9, 5, 9, 10)
      .cubicBezier(0, 19, -34, 10, -63, -17)
      .lineTo(-28, -28)
      .lineTo(-28, 34)
      .cubicBezier(-20, 24, -30, 30, -36, 22)
      .closePath();
  g.add(p7);

  SVGPath p8;
  p8.moveToAbs(1333, 1518)
      .cubicBezier(-22, -27, -93, -178, -84, -178)
      .cubicBezier(12, 0, 66, 77, 75, 108)
      .cubicBezier(9, 28, 28, 24, 36, -6)
      .cubicBezier(5, -23, 59, -96, 65, -90)
      .cubicBezier(6, 6, -63, 172, -73, 176)
      .cubicBezier(-5, 1, -14, -3, -19, -10)
      .closePath();
  g.add(p8);

  SVGPath p9;
  p9.moveToAbs(1826, 1508)
      .cubicBezier(-8, -13, -25, -45, -37, -73)
      .cubicBezier(-12, -27, -31, -60, -42, -72)
      .cubicBezier(-18, -20, -18, -23, -4, -23)
      .cubicBezier(10, 0, 26, 15, 37, 33)
      .cubicBezier(10, 17, 23, 37, 28, 43)
      .cubicBezier(5, 6, 13, 20, 16, 32)
      .cubicBezier(11, 34, 32, 26, 44, -16)
      .cubicBezier(7, -21, 24, -49, 38, -63)
      .cubicBezier(15, -13, 24, -17, 21, -9)
      .cubicBezier(-3, 8, -17, 42, -30, 75)
      .cubicBezier(-13, 33, -27, 68, -30, 78)
      .cubicBezier(-9, 23, -24, 21, -41, -5)
      .closePath();
  g.add(p9);

  SVGPath p10;
  p10.moveToAbs(2083, 1518)
      .cubicBezier(-32, -15, -29, -46, 10, -86)
      .cubicBezier(31, -33, 32, -34, 12, -48)
      .cubicBezier(-11, -8, -30, -17, -42, -21)
      .cubicBezier(-24, -5, -32, -23, -10, -23)
      .cubicBezier(25, 1, 98, 40, 104, 56)
      .cubicBezier(4, 12, -4, 26, -30, 48)
      .cubicBezier(-45, 38, -46, 52, -4, 70)
      .cubicBezier(30, 13, 30, 14, 7, 15)
      .cubicBezier(-14, 0, -35, -5, -47, -11)
      .closePath();
  g.add(p10);

  SVGPath p11;
  p11.moveToAbs(1330, 1410)
      .cubicBezier(0, -5, 5, -10, 10, -10)
      .cubicBezier(6, 0, 10, 5, 10, 10)
      .cubicBezier(0, 6, -4, 10, -10, 10)
      .cubicBezier(-5, 0, -10, -4, -10, -10)
      .closePath();
  g.add(p11);

  SVGPath p12;
  p12.moveToAbs(1830, 1410)
      .cubicBezier(0, -5, 5, -10, 10, -10)
      .cubicBezier(6, 0, 10, 5, 10, 10)
      .cubicBezier(0, 6, -4, 10, -10, 10)
      .cubicBezier(-5, 0, -10, -4, -10, -10)
      .closePath();
  g.add(p12);

  SVGPath p13;
  p13.moveToAbs(1616, 1129)
      .cubicBezier(-2, -8, -7, -56, -11, -106)
      .cubicBezier(-5, -77, -3, -93, 9, -93)
      .cubicBezier(9, 0, 16, 16, 20, 44)
      .cubicBezier(7, 44, 19, 56, 57, 56)
      .cubicBezier(15, 0, 19, -7, 19, -31)
      .cubicBezier(0, -38, 16, -69, 36, -69)
      .cubicBezier(13, 0, 15, 7, 8, 38)
      .cubicBezier(-10, 48, -10, 89, 0, 130)
      .cubicBezier(6, 25, 4, 32, -7, 32)
      .cubicBezier(-8, 0, -18, -15, -23, -32)
      .cubicBezier(-9, -29, -14, -33, -44, -33)
      .cubicBezier(-31, 0, -35, 3, -38, 30)
      .cubicBezier(-4, 35, -19, 55, -26, 34)
      .closePath();
  g.add(p13);

  SVGPath p14;
  p14.moveToAbs(2626, 1129)
      .cubicBezier(-16, -4, -44, -23, -63, -41)
      .lineTo(-33, -32)
      .lineTo(0, 33)
      .cubicBezier(0, 48, -24, 34, -28, -17)
      .cubicBezier(-2, -23, -6, -42, -10, -42)
      .cubicBezier(-4, 0, -25, 21, -48, 47)
      .cubicBezier(-25, 28, -45, 44, -52, 39)
      .cubicBezier(-7, -4, -12, -32, -12, -67)
      .cubicBezier(0, -65, -12, -99, -36, -99)
      .cubicBezier(-28, 0, -95, 41, -106, 65)
      .cubicBezier(-18, 41, 3, 63, 86, 90)
      .cubicBezier(13, 4, 16, 9, 9, 16)
      .cubicBezier(-16, 16, -85, -6, -112, -35)
      .cubicBezier(-23, -25, -25, -55, -7, -97)
      .cubicBezier(8, -19, -17, -32, -45, -24)
      .cubicBezier(-16, 6, -19, 17, -19, 86)
      .cubicBezier(0, 62, -3, 79, -14, 79)
      .cubicBezier(-11, 0, -15, -19, -18, -84)
      .cubicBezier(-2, -46, -2, -91, 0, -100)
      .cubicBezier(5, -23, 54, -21, 84, 4)
      .cubicBezier(25, 19, 25, 19, 64, 0)
      .cubicBezier(21, -11, 50, -20, 65, -20)
      .cubicBezier(15, 0, 29, -6, 32, -12)
      .cubicBezier(9, -25, 30, 9, 38, 63)
      .cubicBezier(5, 28, 11, 54, 14, 57)
      .cubicBezier(7, 8, 45, -29, 61, -60)
      .cubicBezier(17, -32, 44, -37, 44, -9)
      .cubicBezier(0, 49, 11, 50, 56, 4)
      .cubicBezier(39, -39, 49, -44, 82, -41)
      .cubicBezier(34, 3, 37, 6, 40, 37)
      .cubicBezier(2, 19, 11, 41, 20, 48)
      .cubicBezier(15, 11, 10, 12, -30, 13)
      .cubicBezier(-49, 0, -72, -14, -37, -23)
      .cubicBezier(15, -4, 20, -12, 17, -28)
      .cubicBezier(-5, -33, -19, -33, -61, 2)
      .cubicBezier(-42, 35, -48, 68, -17, 99)
      .cubicBezier(11, 11, 34, 23, 50, 27)
      .cubicBezier(29, 5, 39, 17, 23, 26)
      .cubicBezier(-5, 2, -21, 1, -37, -4)
      .closePath();
  g.add(p14);

  SVGPath p15;
  p15.moveToAbs(1479, 1105)
      .cubicBezier(-57, -38, -64, -76, -24, -123)
      .cubicBezier(29, -35, 78, -57, 102, -47)
      .cubicBezier(16, 6, 15, 8, -6, 16)
      .cubicBezier(-54, 21, -81, 49, -81, 84)
      .cubicBezier(0, 37, 21, 58, 73, 70)
      .cubicBezier(15, 4, 27, 11, 27, 16)
      .cubicBezier(0, 18, -56, 8, -91, -16)
      .closePath();
  g.add(p15);

  SVGPath p16;
  p16.moveToAbs(1888, 1113)
      .cubicBezier(-9, -10, -30, -47, -48, -83)
      .cubicBezier(-18, -36, -39, -73, -48, -82)
      .cubicBezier(-14, -16, -14, -18, 1, -18)
      .cubicBezier(17, 0, 69, 69, 81, 108)
      .cubicBezier(9, 28, 28, 24, 36, -6)
      .cubicBezier(7, -31, 59, -94, 71, -86)
      .cubicBezier(7, 4, 5, 12, -4, 22)
      .cubicBezier(-8, 10, -25, 46, -37, 82)
      .cubicBezier(-29, 80, -33, 85, -52, 63)
      .closePath();
  g.add(p16);

  SVGPath p17;
  p17.moveToAbs(2000, 1040)
      .cubicBezier(0, -49, -1, -93, -2, -97)
      .cubicBezier(-5, -13, 63, -15, 78, -2)
      .cubicBezier(19, 15, 18, 33, -1, 25)
      .cubicBezier(-36, -13, -45, 3, -45, 85)
      .cubicBezier(0, 64, -3, 79, -15, 79)
      .cubicBezier(-12, 0, -15, -17, -15, -90)
      .closePath();
  g.add(p17);

  SVGPath p18;
  p18.moveToAbs(2829, 1118)
      .cubicBezier(-40, -10, -73, -40, -83, -75)
      .cubicBezier(-10, -31, 57, -99, 107, -108)
      .cubicBezier(48, -9, 87, 4, 42, 15)
      .cubicBezier(-50, 11, -95, 40, -105, 66)
      .cubicBezier(-17, 43, 1, 61, 83, 88)
      .cubicBezier(10, 3, 15, 10, 12, 16)
      .cubicBezier(-7, 11, -7, 11, -56, -2)
      .closePath();
  g.add(p18);

  SVGPath p19;
  p19.moveToAbs(2267, 1044)
      .cubicBezier(-17, -17, -4, -25, 36, -22)
      .cubicBezier(23, 2, 42, 8, 42, 13)
      .cubicBezier(0, 12, -67, 19, -78, 9)
      .closePath();
  g.add(p19);

  SVGPath p20;
  p20.moveToAbs(2817, 1043)
      .cubicBezier(-17, -16, -4, -24, 35, -21)
      .cubicBezier(55, 4, 64, 28, 11, 28)
      .cubicBezier(-22, 0, -43, -3, -46, -7)
      .closePath();
  g.add(p20);

  SVGPath p21;
  p21.moveToAbs(1880, 1000)
      .cubicBezier(0, -5, 5, -10, 10, -10)
      .cubicBezier(6, 0, 10, 5, 10, 10)
      .cubicBezier(0, 6, -4, 10, -10, 10)
      .cubicBezier(-5, 0, -10, -4, -10, -10)
      .closePath();
  g.add(p21);

  SVGPath p22;
  p22.moveToAbs(1397, 753)
      .cubicBezier(-4, -3, -7, -48, -7, -100)
      .cubicBezier(0, -85, 2, -93, 19, -93)
      .cubicBezier(17, 0, 19, 7, 18, 44)
      .cubicBezier(-3, 59, 8, 66, 41, 27)
      .lineTo(27, -33)
      .lineTo(24, 26)
      .cubicBezier(14, 14, 28, 26, 32, 26)
      .cubicBezier(4, 0, 11, -20, 15, -45)
      .cubicBezier(5, -35, 10, -45, 25, -45)
      .cubicBezier(17, 0, 18, 3, 8, 21)
      .cubicBezier(-6, 12, -14, 54, -18, 93)
      .cubicBezier(-8, 91, -28, 100, -59, 26)
      .cubicBezier(-11, -27, -25, -50, -29, -50)
      .cubicBezier(-5, 0, -21, 25, -36, 55)
      .cubicBezier(-25, 51, -43, 65, -60, 48)
      .closePath();
  g.add(p22);

  SVGPath p23;
  p23.moveToAbs(1696, 751)
      .cubicBezier(-5, -7, 2, -11, 18, -11)
      .cubicBezier(26, 0, 66, -31, 66, -50)
      .cubicBezier(0, -12, -60, -44, -61, -33)
      .cubicBezier(-1, 5, 0, 18, 1, 31)
      .cubicBezier(2, 35, -19, 26, -24, -10)
      .cubicBezier(-14, -93, -14, -118, 0, -118)
      .cubicBezier(8, 0, 17, 13, 21, 30)
      .cubicBezier(7, 38, 19, 38, 60, -2)
      .cubicBezier(44, -42, 54, -28, 14, 18)
      .lineTo(-32, 36)
      .lineTo(20, 22)
      .cubicBezier(26, 27, 27, 48, 3, 69)
      .cubicBezier(-24, 21, -77, 33, -86, 18)
      .closePath();
  g.add(p23);

  SVGPath p24;
  p24.moveToAbs(2135, 748)
      .cubicBezier(-39, -21, -75, -62, -75, -85)
      .cubicBezier(0, -36, 58, -93, 103, -100)
      .cubicBezier(41, -6, 53, 11, 14, 21)
      .cubicBezier(-41, 10, -77, 45, -77, 75)
      .cubicBezier(0, 32, 21, 54, 73, 76)
      .cubicBezier(20, 8, 37, 17, 37, 20)
      .cubicBezier(0, 9, -55, 4, -75, -7)
      .closePath();
  g.add(p24);

  SVGPath p25;
  p25.moveToAbs(2237, 754)
      .cubicBezier(-4, -4, -7, -49, -7, -101)
      .lineTo(0, -93)
      .lineTo(33, 0)
      .cubicBezier(18, 0, 43, 7, 55, 16)
      .cubicBezier(20, 14, 26, 14, 66, -1)
      .cubicBezier(77, -30, 215, -1, 224, 47)
      .cubicBezier(2, 9, -14, 28, -37, 44)
      .cubicBezier(-22, 16, -41, 32, -41, 36)
      .cubicBezier(0, 4, 14, 14, 30, 23)
      .cubicBezier(43, 22, 37, 38, -7, 20)
      .cubicBezier(-63, -27, -67, -45, -18, -88)
      .cubicBezier(19, -17, 35, -34, 35, -39)
      .cubicBezier(0, -19, -65, -40, -110, -36)
      .cubicBezier(-125, 12, -152, 115, -37, 144)
      .cubicBezier(34, 8, 30, 30, -4, 26)
      .cubicBezier(-72, -11, -123, -67, -100, -110)
      .cubicBezier(20, -37, 14, -54, -16, -50)
      .cubicBezier(-27, 3, -28, 5, -33, 82)
      .cubicBezier(-5, 73, -15, 98, -33, 80)
      .closePath();
  g.add(p25);

  SVGPath p26;
  p26.moveToAbs(1638, 738)
      .cubicBezier(-1, -7, -2, -52, -2, -100)
      .cubicBezier(-1, -64, 2, -88, 12, -88)
      .cubicBezier(9, 0, 12, 27, 12, 100)
      .cubicBezier(0, 60, -4, 100, -10, 100)
      .cubicBezier(-5, 0, -11, -6, -12, -12)
      .closePath();
  g.add(p26);

  SVGPath p27;
  p27.moveToAbs(1947, 732)
      .cubicBezier(-9, -10, -28, -44, -43, -77)
      .cubicBezier(-15, -33, -34, -68, -42, -78)
      .cubicBezier(-8, -9, -12, -20, -9, -23)
      .cubicBezier(9, -10, 53, 43, 76, 92)
      .cubicBezier(12, 24, 25, 44, 29, 44)
      .cubicBezier(5, 0, 14, -17, 20, -38)
      .cubicBezier(11, -35, 62, -98, 62, -77)
      .cubicBezier(0, 16, -65, 175, -71, 175)
      .cubicBezier(-3, 0, -13, -8, -22, -18)
      .closePath();
  g.add(p27);

  SVGPath p28;
  p28.moveToAbs(2370, 660)
      .cubicBezier(0, -5, 20, -10, 45, -10)
      .cubicBezier(25, 0, 45, 5, 45, 10)
      .cubicBezier(0, 6, -20, 10, -45, 10)
      .cubicBezier(-25, 0, -45, -4, -45, -10)
      .closePath();
  g.add(p28);

  SVGPath p29;
  p29.moveToAbs(1945, 630)
      .cubicBezier(3, -5, 8, -10, 11, -10)
      .cubicBezier(2, 0, 4, 5, 4, 10)
      .cubicBezier(0, 6, -5, 10, -11, 10)
      .cubicBezier(-5, 0, -7, -4, -4, -10)
      .closePath();
  g.add(p29);

  SVGPath p30;
  p30.moveToAbs(996, 376)
      .cubicBezier(-60, -56, -46, -111, 42, -158)
      .cubicBezier(42, -22, 44, -67, 6, -97)
      .cubicBezier(-29, -23, -24, -41, 11, -41)
      .cubicBezier(48, 0, 82, 80, 55, 131)
      .cubicBezier(-6, 10, -28, 28, -50, 39)
      .cubicBezier(-47, 24, -60, 58, -36, 95)
      .cubicBezier(9, 13, 25, 29, 36, 35)
      .cubicBezier(11, 6, 18, 15, 15, 21)
      .cubicBezier(-12, 18, -44, 8, -79, -25)
      .closePath();
  g.add(p30);

  SVGPath p31;
  p31.moveToAbs(1173, 350)
      .cubicBezier(-8, -11, -19, -17, -28, -14)
      .cubicBezier(-19, 8, -19, -3, 0, -22)
      .cubicBezier(8, -8, 12, -20, 9, -27)
      .cubicBezier(-3, -9, 8, -12, 34, -12)
      .cubicBezier(31, 0, 38, 3, 35, 16)
      .cubicBezier(-3, 9, 0, 20, 6, 23)
      .cubicBezier(6, 4, 11, 12, 11, 17)
      .cubicBezier(0, 6, -5, 7, -11, 3)
      .cubicBezier(-7, -4, -19, 3, -28, 15)
      .cubicBezier(-16, 21, -16, 21, -28, 1)
      .closePath();
  g.add(p31);

  SVGPath p32;
  p32.moveToAbs(1910, 340)
      .cubicBezier(0, -5, 9, -14, 20, -20)
      .cubicBezier(13, -7, 20, -21, 20, -40)
      .cubicBezier(0, -24, -8, -35, -41, -55)
      .cubicBezier(-39, -25, -40, -27, -37, -78)
      .lineTo(3, -52)
      .lineTo(38, -3)
      .cubicBezier(44, -4, 46, 2, 12, 34)
      .cubicBezier(-14, 13, -25, 28, -25, 35)
      .cubicBezier(0, 6, 21, 30, 46, 54)
      .cubicBezier(43, 39, 46, 46, 40, 75)
      .cubicBezier(-3, 18, -11, 39, -17, 47)
      .cubicBezier(-13, 15, -59, 18, -59, 3)
      .closePath();
  g.add(p32);

  SVGPath p33;
  p33.moveToAbs(2040, 330)
      .cubicBezier(-16, -16, -20, -34, -21, -92)
      .cubicBezier(-1, -40, 0, -82, 1, -93)
      .cubicBezier(5, -53, 75, -75, 104, -33)
      .cubicBezier(12, 16, 16, 47, 16, 110)
      .cubicBezier(0, 75, -3, 91, -20, 108)
      .cubicBezier(-11, 11, -29, 20, -40, 20)
      .cubicBezier(-11, 0, -29, -9, -40, -20)
      .closePath()
      .moveTo(70, -110)
      .cubicBezier(0, -65, -20, -104, -42, -82)
      .cubicBezier(-19, 19, -18, 150, 2, 162)
      .cubicBezier(24, 15, 40, -17, 40, -80)
      .closePath();
  g.add(p33);

  SVGPath p34;
  p34.moveToAbs(2201, 331)
      .cubicBezier(-25, -25, -35, -78, -28, -148)
      .cubicBezier(7, -63, 28, -93, 67, -93)
      .cubicBezier(39, 0, 60, 30, 67, 93)
      .cubicBezier(10, 99, -17, 167, -67, 167)
      .cubicBezier(-11, 0, -29, -9, -39, -19)
      .closePath()
      .moveTo(59, -40)
      .cubicBezier(15, -29, 12, -124, -4, -147)
      .cubicBezier(-21, -28, -36, -8, -43, 57)
      .cubicBezier(-8, 82, 21, 138, 47, 90)
      .closePath();
  g.add(p34);

  SVGPath p35;
  p35.moveToAbs(2387, 328)
      .cubicBezier(11, -13, 23, -28, 27, -35)
      .cubicBezier(10, -19, -15, -61, -44, -73)
      .cubicBezier(-28, -12, -40, -34, -40, -80)
      .cubicBezier(0, -35, 17, -50, 57, -50)
      .cubicBezier(40, 0, 41, 6, 8, 32)
      .cubicBezier(-37, 29, -32, 61, 15, 92)
      .cubicBezier(35, 23, 40, 31, 40, 65)
      .cubicBezier(0, 43, -23, 71, -60, 71)
      .lineTo(-23, 0)
      .lineTo(20, -22)
      .closePath();
  g.add(p35);

  SVGPath p36;
  p36.moveToAbs(1505, 261)
      .cubicBezier(-50, -21, -72, -74, -52, -124)
      .cubicBezier(17, -39, 70, -68, 90, -48)
      .cubicBezier(9, 9, 5, 17, -15, 34)
      .cubicBezier(-29, 24, -42, 55, -30, 74)
      .cubicBezier(4, 7, 24, 19, 45, 28)
      .cubicBezier(42, 17, 47, 30, 15, 39)
      .cubicBezier(-27, 7, -28, 7, -53, -3)
      .closePath();
  g.add(p36);

  SVGPath p37;
  p37.moveToAbs(1654, 260)
      .cubicBezier(-31, -12, -54, -49, -54, -86)
      .cubicBezier(0, -35, 30, -80, 60, -89)
      .cubicBezier(28, -9, 60, 12, 60, 39)
      .cubicBezier(0, 13, 9, 31, 20, 41)
      .cubicBezier(26, 24, 25, 47, -2, 72)
      .cubicBezier(-29, 26, -57, 34, -84, 23)
      .closePath()
      .moveTo(51, -70)
      .cubicBezier(0, -18, -6, -26, -21, -28)
      .cubicBezier(-26, -4, -40, 24, -23, 45)
      .cubicBezier(18, 21, 44, 11, 44, -17)
      .closePath();
  g.add(p37);

  SVGPath p38;
  p38.moveToAbs(1250, 220)
      .cubicBezier(-14, -33, -9, -115, 8, -132)
      .cubicBezier(17, -17, 32, 1, 32, 38)
      .cubicBezier(0, 38, 15, 74, 30, 74)
      .cubicBezier(5, 0, 22, -24, 36, -52)
      .cubicBezier(33, -65, 33, -66, 44, -48)
      .cubicBezier(19, 30, 11, 87, -16, 119)
      .cubicBezier(-22, 27, -32, 31, -74, 31)
      .cubicBezier(-44, 0, -49, -3, -60, -30)
      .closePath();
  g.add(p38);

  SVGPath p39;
  p39.moveToAbs(1166, 224)
      .cubicBezier(-12, -31, -6, -121, 8, -133)
      .cubicBezier(12, -10, 17, -8, 25, 8)
      .cubicBezier(12, 22, 14, 83, 5, 119)
      .cubicBezier(-7, 25, -29, 29, -38, 6)
      .closePath();
  g.add(p39);

  svg.add(g);

  // svg.print(cout);
  ofstream fout("pic5.svg");
  fout << svg;
  cout << svg;
}
