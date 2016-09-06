#ifndef SVGBASE_H
#define SVGBASE_H

#include <string>
#include <ostream>

class SVGBase {
protected:
    template <typename T>
    static std::ostream& print_attr(std::ostream& out, const std::string& name, const T& value) {
        out << " " << name << "=\"" << value << "\"";
        return out;
    }

public:
    virtual ~SVGBase() {}
};

template <>
inline std::ostream& SVGBase::print_attr(std::ostream& out, const std::string& name, const double& value) {
    if (value) {
        out << " " << name << "=\"" << value << "\"";
    }
    return out;
}

template <>
inline std::ostream& SVGBase::print_attr(std::ostream& out, const std::string& name, const std::string& value) {
    if (!value.empty()) {
        out << " " << name << "=\"" << value << "\"";
    }
    return out;
}

#endif

/* You don't need to modify this file :-) */