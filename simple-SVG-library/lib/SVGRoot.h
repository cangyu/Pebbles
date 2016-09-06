#ifndef SVGROOT_H
#define SVGROOT_H

#include "SVGContainerElement.h"

class SVGRoot : public SVGContainerElement {
    double width, height;

protected:
    virtual SVGElement* clone() const {
		return new SVGRoot(*this);
    }

    virtual SVGContainerElement* clone_as_container() const {
		return new SVGRoot(*this);//Just differs in return type，the copy-constructor will do deep copy
    }

public:
    // Constructor
	SVGRoot(const std::string& id="") :SVGContainerElement("svg", id), width(100), height(20) {}

    // Copy-constructor
	SVGRoot(const SVGRoot& rhs) :SVGContainerElement("svg", rhs.id), width(rhs.width), height(rhs.height)	{
		clone_body_from(rhs);//有指针变量，要做深拷贝
	}

    SVGRoot& setSize(const double w, const double h) {
        width = w;
        height = h;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
		// Print attributes
		SVGBase::print_attr(out, "version", "1.1");
		SVGBase::print_attr(out, "baseProfile", "full");
		SVGBase::print_attr(out, "xmlns", "http://www.w3.org/2000/svg");
		SVGBase::print_attr(out, "width", width);
		SVGBase::print_attr(out, "height", height);
        out << ">" << std::endl; // close the opening tag
        // Print the body of the container
		print_body(out);
        print_tag_close(out);//Using the function defined in SVGContainerElement.h
        return out;
    }
};

#endif
