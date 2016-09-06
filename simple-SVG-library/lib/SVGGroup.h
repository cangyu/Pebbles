#ifndef SVGGROUP_H
#define SVGGROUP_H

#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"
#include "SVGStyleTransform.h"
#include "SVGContainerElement.h"

class SVGGroup :public SVGContainerElement,public SVGStyleFill, public SVGStyleStroke,public SVGStyleTransform {
protected:
    virtual SVGElement* clone() const {
		return new SVGGroup(*this);
    }

    virtual SVGContainerElement* clone_as_container() const {
		return new SVGGroup(*this);
    }

public:
    // Constructor
	SVGGroup(const std::string& id="") : SVGContainerElement("g", id), SVGStyleFill(), SVGStyleStroke(), SVGStyleTransform() {}

	//Copy-constructor
	SVGGroup(const SVGGroup& rhs) :SVGContainerElement("g", rhs.id), SVGStyleFill(rhs), SVGStyleStroke(rhs), SVGStyleTransform(rhs) {
		clone_body_from(rhs);//有指针变量，要做深拷贝，新对象里面的的elements等变量是空的
	}

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
		// Print style
		SVGStyleFill::print_style(out);
		SVGStyleStroke::print_style(out);
		SVGStyleTransform::print_style(out);
        out << ">" << std::endl; // close the opening tag
        // Print body
		SVGContainerElement::print_body(out);
        print_tag_close(out);
        return out;
    }
};

#endif
