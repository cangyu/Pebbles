#ifndef SVGCIRCLE_H
#define SVGCIRCLE_H

#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"
#include "SVGContainerElement.h"

class SVGCircle: public SVGElement,public SVGStyleFill,public SVGStyleStroke {
    double cx, cy, r;
public:
    // Constructor
	SVGCircle(const std::string& id = "") :SVGElement("circle", id), SVGStyleFill(), SVGStyleStroke(), cx(0), cy(0), r(10) {}

    SVGCircle& setPosition(double _x, double _y) {
        cx = _x, cy = _y;
        return *this;
    }

    SVGCircle& setRadius(double _r) {
        r = _r;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
		// Print the attributes
		SVGBase::print_attr(out, "cx", cx);
		SVGBase::print_attr(out, "cy", cy);
		SVGBase::print_attr(out, "r", r);
        // Print the styles
		SVGStyleFill::print_style(out);
		SVGStyleStroke::print_style(out);
        print_tag_close(out);
        return out;
    }

protected:
    virtual SVGElement* clone() const {
		return new SVGCircle(*this);
    }

};

#endif
