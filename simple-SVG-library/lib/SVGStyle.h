#ifndef SVGSTYLE_H
#define SVGSTYLE_H

#include "SVGBase.h"

class SVGStyle: public SVGBase {
protected:
    virtual std::ostream& print_style(std::ostream& out) const = 0;
    
public:
    virtual ~SVGStyle() {}
};

#endif

/* You don't need to modify this file :-) */