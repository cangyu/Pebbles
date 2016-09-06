#ifndef SVGRECTANGLE_H
#define SVGRECTANGLE_H

#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"
#include "SVGContainerElement.h"

class SVGRectangle:public SVGElement ,public SVGStyleFill,public SVGStyleStroke{
	double x, y;
	double width, height;
	double rx, ry;//Ô²½Ç
public:
	// Constructor
	SVGRectangle(const std::string& id = "") :SVGElement("rect", id), SVGStyleFill(), SVGStyleStroke(), x(0), y(0), width(20), height(20), rx(2), ry(2) {}

    SVGRectangle& setPosition(double _x, double _y) {
        x = _x, y = _y;
        return *this;
    }

    SVGRectangle& setSize(double w, double h) {
        width = w, height = h;
        return *this;
    }

    SVGRectangle& setRadius(double _rx, double _ry) {
        rx = _rx, ry = _ry;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
		// Print the attributes of a rectangle
		SVGBase::print_attr(out, "x", x);
		SVGBase::print_attr(out, "y", y);
		SVGBase::print_attr(out, "width", width);
		SVGBase::print_attr(out, "height", height);
		SVGBase::print_attr(out, "rx", rx);
		SVGBase::print_attr(out, "ry", ry);
		// Print the styles of a rectangle
		SVGStyleFill::print_style(out);
		SVGStyleStroke::print_style(out);
        print_tag_close(out);
        return out;
    }

protected:
    virtual SVGElement* clone() const {
		// Since there's no pointer pointing to memory on heap,just use the default copy-constructor
		return new SVGRectangle(*this);
    }

};

#endif

