#ifndef SVGELLIPSE_H
#define SVGELLIPSE_H

#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"
#include "SVGContainerElement.h"

class SVGEllipse : public SVGElement, public SVGStyleFill, public SVGStyleStroke {
    double cx, cy, rx, ry;
public:
    // Constructor
	SVGEllipse(const std::string& id="") :SVGElement("ellipse", id), SVGStyleFill(), SVGStyleStroke(), cx(0), cy(0), rx(10), ry(10) {}
	
    SVGEllipse& setPosition(double _x, double _y) {
        cx = _x, cy = _y;
        return *this;
    }

    SVGEllipse& setRadius(double _rx, double _ry) {
        rx = _rx, ry = _ry;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
		// Print the attributes
		SVGBase::print_attr(out, "cx", cx);
		SVGBase::print_attr(out, "cy", cy);
		SVGBase::print_attr(out, "rx", rx);
		SVGBase::print_attr(out, "ry", ry);
		// Print the styles
		SVGStyleFill::print_style(out);
		SVGStyleStroke::print_style(out);
        print_tag_close(out);
        return out;
    }

protected:
    virtual SVGElement* clone() const {
		return new SVGEllipse(*this);
    }

};

#endif
